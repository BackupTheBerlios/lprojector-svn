#include "Settings.h"
#include "ApplicationManager.h"

#include <QSettings>
#include <QTextCodec>
#include <QColor>
#include <QDebug>
#include <QMutex>
#include <QReadWriteLock>

///Here the settings are stored in memory. This doesn't look nice on the first
///glance but it is a simple method which allows to have a clean header without
///a need for another private class.
namespace m_storage {
//    static QMutex storageLock;
//    static QReadWriteLock storageLock;

    static QTextCodec* defaultEncoding = 0;
    static bool highlightCurrentLine = true;
    static QColor currentLineHighlightColor = Qt::yellow;
    static QColor lineNumberBackgroundColor = Qt::lightGray;
    static QColor lineNumberColor = Qt::black;
}

Settings::Settings() {
    m_qsettings = new QSettings("test/settings.ini", QSettings::IniFormat, 0);
    reload();
}
Settings::~Settings() {
    qDebug() << "Settings destructor";
    delete m_qsettings;
}
void Settings::reload() {
//    m_storage::storageLock.lockForWrite();
    //m_storage::storageLock.lock();

    //General Settings
        //Default file encoding
    if(m_qsettings->contains("Common/defaultEncoding"))
        m_storage::defaultEncoding =
            QTextCodec::codecForName(
                m_qsettings->value("Common/defaultEncoding").toByteArray());
    else
        m_storage::defaultEncoding = QTextCodec::codecForLocale();

    //Styles
        //Should the cursor's current line be highlighted?
    if(m_qsettings->contains("Styles/highlightCurrentLine"))
        m_storage::highlightCurrentLine =
            m_qsettings->value("Styles/highlightCurrentLine").toBool();
    if(m_qsettings->contains("Styles/currentLineHighlightColor"))
        m_storage::currentLineHighlightColor =
            m_qsettings->value("Styles/currentLineHighlightColor").value<QColor>();
        //Line number format
    if(m_qsettings->contains("Styles/lineNumberBackgroundColor"))
        m_storage::lineNumberBackgroundColor =
            m_qsettings->value("Styles/lineNumberBackgroundColor").value<QColor>();
    if(m_qsettings->contains("Styles/lineNumberColor"))
        m_storage::lineNumberColor =
            m_qsettings->value("Styles/lineNumberColor").value<QColor>();

   // m_storage::storageLock.unlock();
}
void Settings::save() {
//    m_storage::storageLock.lockForWrite();
    //m_storage::storageLock.lock();

    qDebug() << "Saving settings.";

    //General Settings
        //Default file encoding
    m_qsettings->setValue("Common/defaultEncoding", m_storage::defaultEncoding->name());

    //Styles
        //Should the cursor's current line be highlighted?
    m_qsettings->setValue("Styles/highlightCurrentLine", m_storage::highlightCurrentLine);
    m_qsettings->setValue("Styles/currentLineHighlightColor", m_storage::currentLineHighlightColor);
        //Line number format
    m_qsettings->setValue("Styles/lineNumberBackgroundColor", m_storage::lineNumberBackgroundColor);
    m_qsettings->setValue("Styles/lineNumberColor", m_storage::lineNumberColor);

    m_qsettings->sync();
    qDebug() << "Saved.";

   // m_storage::storageLock.unlock();
}

QTextCodec* Settings::defaultEncoding() {
    //m_storage::storageLock.lockForRead();
    return m_storage::defaultEncoding;
   // m_storage::storageLock.unlock();
}
//QTextCodec* Settings::setDefaultEncoding(QTextCodec* c) {
//    m_qsettings->setValue("General/defaultEncoding", c->name());
//}
bool Settings::highlightCurrentLine() {
    //m_storage::storageLock.lockForRead();
    //m_storage::storageLock.lock();
    return m_storage::highlightCurrentLine;
   // m_storage::storageLock.unlock();
}
QColor Settings::currentLineHighlightColor() {
    //m_storage::storageLock.lockForRead();
    //m_storage::storageLock.lock();
    return m_storage::currentLineHighlightColor;
   // m_storage::storageLock.unlock();
}
QColor Settings::lineNumberBackgroundColor() {
    //m_storage::storageLock.lockForRead();
    //m_storage::storageLock.lock();
    return m_storage::lineNumberBackgroundColor;
   // m_storage::storageLock.unlock();
}
QColor Settings::lineNumberColor() {
    //m_storage::storageLock.lockForRead();
    //m_storage::storageLock.lock();
    return m_storage::lineNumberColor;
   // m_storage::storageLock.unlock();
}
