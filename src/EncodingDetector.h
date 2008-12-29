

#ifndef ENCODINGDETECTOR_H
#define ENCODINGDETECTOR_H

class QByteArray;
class QTextCodec;

//TODO: Repair Multibyte support

/** Try to detect the encoding of a file on disk. */
class EncodingDetector
{
	public:
		EncodingDetector(const QByteArray& buffer);
		EncodingDetector(const EncodingDetector& rhs);
		~EncodingDetector();

        /** @return True if file was read, false if not. */
        bool IsOK() const;
        /** @return True if the file contains a BOM (Byte Order Mark), false if not. */
		bool UsesBOM() const;
		/** @return The BOM size in bytes. Returns zero if no BOM. */
		int GetBOMSizeInBytes() const;
		/** @return The detected encoding. Currently ISO8859-1 is returned if no BOM is present. */
		QTextCodec* GetFontEncoding() const;
//		wxString GetWxStr() const;
	protected:
        /** @return True if succeeded, false if not (e.g. file didn't exist). */
//		bool DetectEncoding(const wxString& filename, bool ConvertToWxString = true);
		bool DetectEncoding(const QByteArray& buffer);

        bool m_IsOK;
		bool m_UseBOM;
		int m_BOMSizeInBytes;
		QTextCodec* m_Encoding;
	private:
//        wxString m_ConvStr;
//        bool ConvertToWxStr(const wxByte* buffer, size_t size);
        inline bool IsUTF8Tail(char b) { return ((b & 0xC0) == 0x80); };
        bool DetectUTF8(const QByteArray& buffer);
        bool IsTextUTF16BE(const QByteArray& buffer);
        bool IsTextUTF16LE(const QByteArray& buffer);
        bool DetectUTF16(const QByteArray& buffer);
        bool IsTextUTF32BE(const QByteArray& buffer);
        bool IsTextUTF32LE(const QByteArray& buffer);
        bool DetectUTF32(const QByteArray& buffer);
};

#endif // ENCODINGDETECTOR_H
