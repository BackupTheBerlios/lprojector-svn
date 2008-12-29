#ifndef DOCUMENTINFO_H_INCLUDED
#define DOCUMENTINFO_H_INCLUDED

#include <QString>

class DocumentInfo {
    protected:
        QString m_absPath;
        QString m_encodingName;
        bool m_isModified;
        qint64 m_filesize;

    public:
        const QString& absoluteFilePath() const;
        const QString& encodingName() const;
        qint64 filesize() const;
        bool isModified() const;

        void setAbsoluteFilePath(const QString& name);
        void setEncodingName(const QString& name);
        void setFilesize(qint64 size);
        void setIsModified(bool modified);

        QString fileName() const;

        DocumentInfo(const QString& absolutePath, const QString& encodingName, qint64 m_filesize);
};

#endif // DOCUMENTINFO_H_INCLUDED
