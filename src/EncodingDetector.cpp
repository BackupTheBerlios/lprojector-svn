
//Note: This is a copied and modified version of the encoding detector from the 
//Codeblocks IDE which is distributed under the GNU LGPL on codeblocks.org

#include "EncodingDetector.h"
#include "ApplicationManager.h"
#include "Settings.h"

#include <QByteArray>
#include <QTextCodec>
#include <qendian.h>


EncodingDetector::EncodingDetector(const QByteArray& buffer)
    : m_IsOK(false),
    m_UseBOM(false),
    m_BOMSizeInBytes(0)
{
    m_Encoding = ApplicationManager::settings()->defaultEncoding();
    m_IsOK = DetectEncoding(buffer);
}

EncodingDetector::EncodingDetector(const EncodingDetector& rhs)
    : m_IsOK(rhs.m_IsOK),
    m_UseBOM(rhs.m_UseBOM),
    m_BOMSizeInBytes(rhs.m_BOMSizeInBytes),
    m_Encoding(rhs.m_Encoding)
{

}

EncodingDetector::~EncodingDetector()
{
}

bool EncodingDetector::IsOK() const
{
    return m_IsOK;
}

bool EncodingDetector::UsesBOM() const
{
    return m_UseBOM;
}

int EncodingDetector::GetBOMSizeInBytes() const
{
    return m_BOMSizeInBytes;
}

QTextCodec* EncodingDetector::GetFontEncoding() const
{
    return m_Encoding;
}

bool EncodingDetector::DetectEncoding(const QByteArray& buffer)
{
    if (buffer.isEmpty())
        return false;
    if (buffer.size() >= 4)
    {
        // BOM is max 4 bytes
        char buff[4] = {'\0'};
        memcpy(buff, buffer.constData(), 4);

        if (memcmp(buff, "\xEF\xBB\xBF", 3) == 0)
        {
            m_UseBOM = true;
            m_BOMSizeInBytes = 3;
            m_Encoding = QTextCodec::codecForName("UTF-8");
        }
        else if (memcmp(buff, "\x00\x00\xFE\xFF", 4) == 0)
        {
            m_UseBOM = true;
            m_BOMSizeInBytes = 4;
            m_Encoding = QTextCodec::codecForName("UTF-32BE");
        }
        else if (memcmp(buff, "\xFF\xFE\x00\x00", 4) == 0)
        {
            m_UseBOM = true;
            m_BOMSizeInBytes = 4;
            m_Encoding = QTextCodec::codecForName("UTF-32LE");
        }
        else if (memcmp(buff, "\xFE\xFF", 2) == 0)
        {
            m_UseBOM = true;
            m_BOMSizeInBytes = 2;
            m_Encoding = QTextCodec::codecForName("UTF-16BE");
        }
        else if (memcmp(buff, "\xFF\xFE", 2) == 0)
        {
            m_UseBOM = true;
            m_BOMSizeInBytes = 2;
            m_Encoding = QTextCodec::codecForName("UTF-16LE");
        }
    }


    if (!m_UseBOM)
    {
        if (DetectUTF8(buffer))
        {
            m_Encoding = QTextCodec::codecForName("UTF-8");
        }
        else if (!DetectUTF16(buffer) && !DetectUTF32(buffer))
        {
            // Use default encoding
            m_Encoding = ApplicationManager::settings()->defaultEncoding();
        }

        m_UseBOM = false;
        m_BOMSizeInBytes = 0;
    }

    return true;
} // end of DetectEncoding


bool EncodingDetector::DetectUTF8(const QByteArray& text)
{
    /* The following detection code is based on modified code
    *  of MadEdit
    */
    int i = 0;

    if (text.isEmpty())
        return false;
    const quint8* byt = reinterpret_cast<const quint8*>(text.constData());

    while (i < text.size())
    {
        if (byt[i] < 0x80)
        {
            ++i; // Continue searching for any possible UTF-8 encoded characters
        }
        else if (byt[i] <= 0xDF) // 1110xxxx 10xxxxxx
        {
            if (++i < text.size() && IsUTF8Tail(byt[i]))
            {
                return true; // We would stop our search assuming the whole file is UTF-8
            }
            else if (i != text.size()) // Possibly a malformed UTF-8 file
            {
                return false;
            }
        }
        else if (byt[i] <= 0xEF) // 1110xxxx 10xxxxxx 10xxxxxx
        {
            if ((++i < text.size() && IsUTF8Tail(byt[i]))
                && (++i < text.size() && IsUTF8Tail(byt[i])))
            {
                return true; // We would stop our search assuming the whole file is UTF-8
            }
            else if(text.size() != i)
            {
                return false;
            }
        }
        else if (byt[i] <= 0xF4) // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        {
            if ((++i < text.size() && IsUTF8Tail(byt[i]))
                && (++i < text.size() && IsUTF8Tail(byt[i]))
                && (++i < text.size() && IsUTF8Tail(byt[i])))
            {
                return true;
            }
            else if(text.size() != i)
            {
                return false;
            }
        }
        /* Begin: Extra code (not from MadEdit) */
        else if (byt[i] <= 0xFB)  // 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
        {
            if ((++i < text.size() && IsUTF8Tail(byt[i]))
                && (++i < text.size() && IsUTF8Tail(byt[i]))
                && (++i < text.size() && IsUTF8Tail(byt[i]))
                && (++i < text.size() && IsUTF8Tail(byt[i])))
            {
                return true;
            }
            else if(text.size() != i)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        /* End: Extra code (not from MadEdit) */
    }

    return false;
}

bool EncodingDetector::IsTextUTF16LE(const QByteArray& text)
{
    if (text.size() < 2)
        return false;

    bool ok = false;
    bool highsurrogate = false;

    int size = text.size() & 0x1FFFFFFE;   // to even
    const quint8* textp = reinterpret_cast<const quint8*>(text.constData());

    while(size > 0)
    {
        if(textp[1] == 0)
        {
            if(textp[0] == 0)
                return false;
            ok = true;
        }
        else if(textp[1] >= 0xD8 && textp[1] <= 0xDB)
        {
            if(highsurrogate)
                return false;
            highsurrogate = true;
        }
        else if(textp[1] >= 0xDC && textp[1] <= 0xDF)
        {
            if(!highsurrogate)
                return false;
            highsurrogate = false;
        }

        size -= 2;
        textp += 2;
    }

    return ok;
}

bool EncodingDetector::IsTextUTF16BE(const QByteArray& buf)
{
    if (buf.size() < 2)
        return false;

    bool ok = false;
    bool highsurrogate = false;

    int size = buf.size() & 0x1FFFFFFE;     // to even
    const quint8* text = reinterpret_cast<const quint8*>(buf.constData());

    while(size > 0)
    {
        if(text[0] == 0)
        {
            if(text[1] == 0)
                return false;
            ok = true;
        }
        else if(text[0] >= 0xD8 && text[0] <= 0xDB)
        {
            if(highsurrogate)
                return false;
            highsurrogate = true;
        }
        else if(text[0] >= 0xDC && text[0] <= 0xDF)
        {
            if(!highsurrogate)
                return false;
            highsurrogate = false;
        }

        size -= 2;
        text += 2;
    }

    return ok;
}

bool EncodingDetector::DetectUTF16(const QByteArray& text)
{
    if (IsTextUTF16BE(text))
    {
        m_Encoding = QTextCodec::codecForName("UTF-16BE");
        return true;
    }
    else if (IsTextUTF16LE(text))
    {
        m_Encoding = QTextCodec::codecForName("UTF-16LE");
        return true;
    }
    return false;
}

bool EncodingDetector::IsTextUTF32LE(const QByteArray& text)
{
    int size = text.size() >> 2;   // to count
    if (size < 4)
        return false;

    quint32 ucs4;
    const quint32 *p = reinterpret_cast<const quint32*>(text.constData());

    for(int i = 0; i < size; i++, p++)
    {
        //wxINT32_SWAP_ON_BE
        ucs4 = qToLittleEndian(*p);

        if(ucs4 <= 0 || ucs4 > 0x10FFFF)
            return false;
    }

    return true;
}

bool EncodingDetector::IsTextUTF32BE(const QByteArray& text)
{
    int size = text.size() >> 2;   // to count
    if (size < 4)
        return false;

    quint32 ucs4;
    const quint32 *p = reinterpret_cast<const quint32*>(text.constData());

    for (int i = 0; i < size; i++, p++)
    {
        //wxINT32_SWAP_ON_LE
        ucs4 = qToBigEndian(*p);

        if (ucs4 <= 0 || ucs4 > 0x10FFFF)
            return false;
    }

    return true;
}

bool EncodingDetector::DetectUTF32(const QByteArray& byt)
{
    if (IsTextUTF32BE(byt))
    {
        m_Encoding = QTextCodec::codecForName("UTF-32BE");
        return true;
    }
    else if (IsTextUTF32LE(byt))
    {
        m_Encoding = QTextCodec::codecForName("UTF-32LE");
        return true;
    }
    return false;
}
