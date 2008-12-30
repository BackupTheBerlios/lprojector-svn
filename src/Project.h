#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include "ApplicationVersion.h"

#include <QString>
#include <QList>
#include <QDir>
#include <QMap>
#include <QDebug>

class ProjectItem;
class QIODevice;

class Project {

    /// \@name Properties
    private:
        QString	m_name;
        QString	m_filename;
        Version m_version;
        bool m_isModified;
        QDir m_rootPath;
        ProjectItem* m_rootItem;
        ProjectItem* m_masterDocument;
        QMap<QString,ProjectItem*> m_fileMap;
    public:
        Project();
        Project(const QString& name, const QString& rootPath);
        ~Project();
        bool isValid();

    /// \@name Property Getters
        const QString& name() const    {return m_name;}
        const QString& filename() const{return m_filename;}
        const Version& version() const {return m_version;}
        bool isModified() const        {return m_isModified;}
        const QDir& rootPath() const   {return m_rootPath;}
        ProjectItem* rootItem() const  {return m_rootItem;}
        ProjectItem* masterDocument()  {return m_masterDocument;}
        const QMap<QString,ProjectItem*>& fileMap() const {return m_fileMap;}

    /// \@name Property Setters
        void setName(const QString&	name)           {m_name = name;}
        void setFilename(const QString&	name)       {m_filename = name;}
        void setVersion(const Version& version)     {m_version = version;}
        void setIsModified(bool modified)           {m_isModified = modified;};
        void setMasterDocument(ProjectItem* master) {m_masterDocument = master;}
        bool addFile(QString path);

//        QString filename() const;

    /// \@name Serialization and Deserialization
//        Project(const QByteArray& utf8);
//        QByteArray toUtf8() const;
        static Project* fromXml(QIODevice* device, const QString& rootPath, QString* error=0);
        QByteArray toXml();
        void toXml(QIODevice* buffer);

    private:
        void setCommonRoot(QDir path);
        void setCommonRoot();


//    public slots:
//        void itemInserted(ProjectItem* item);
};

#endif // PROJECT_H_INCLUDED
