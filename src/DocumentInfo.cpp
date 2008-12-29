
#include "DocumentInfo.h"

#include <QFileInfo>
#include <QDebug>

DocumentInfo::DocumentInfo(
    const QString& absolutePath, const QString& encodingName, qint64 filesize)
    : m_absPath(absolutePath),
        m_encodingName(encodingName),
        m_isModified(false),
        m_filesize(filesize) {
    qDebug() << "DocumentInfo: Initialized instance";
}


const QString& DocumentInfo::absoluteFilePath() const {
    return m_absPath;
}
const QString& DocumentInfo::encodingName() const {
    return m_encodingName;
}
qint64 DocumentInfo::filesize() const {
    return m_filesize;
}
bool DocumentInfo::isModified() const {
    return m_isModified;
}

void DocumentInfo::setAbsoluteFilePath(const QString& name) {
    m_absPath = name;
}
void DocumentInfo::setEncodingName(const QString& name) {
    m_encodingName = name;
}
void DocumentInfo::setFilesize(qint64 size) {
    m_filesize = size;
}
void DocumentInfo::setIsModified(bool modified) {
    m_isModified = modified;
}

QString DocumentInfo::fileName() const {
    return QFileInfo(absoluteFilePath()).fileName();
}
