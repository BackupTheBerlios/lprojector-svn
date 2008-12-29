
#include "ProjectItem.h"
#include "Project.h"
#include "Logger.h"
#include "ApplicationVersion.h"
#include "FileManager.h"
#include <QDebug>

        QString	m_name;
        Version m_version;
        QDir m_rootPath;
        ProjectItem* m_rootItem;
        QList<ProjectItem*> m_items;
        ProjectItem* m_masterDocument;

Project::Project() : m_name(), m_version(Version::currentVersion()),
        m_rootPath(), m_rootItem(0), m_masterDocument(0), m_fileMap()  {
    qDebug() << "Initialized empty Project instance";
    Q_ASSERT(false);
}
Project::Project(const QString& name, const QString& rootPath) :
        m_name(name), m_version(Version::currentVersion()),
        m_rootPath(), m_masterDocument(0), m_fileMap()  {
    m_rootPath = FileManager::cleanPath(rootPath);
    m_rootItem = new ProjectItem(this,ProjectItem::Type_Project,m_rootPath.dirName(),0);
    qDebug() << "Initialized Project instance for"  << m_rootPath.absolutePath();
}
Project::~Project() {
    delete rootItem();
}
bool Project::isValid() {
    //TODO: Add more checks
    return m_version.isValid() && m_rootItem != 0;
}
bool Project::addFile(QString path) {
    path = FileManager::cleanPath(path);
//    qDebug() << "Project: Adding file" << path;
//    qDebug() << "   ->rootpath =" << rootPath().absolutePath();
//    qDebug() << "   ->relpath  =" << rootPath().relativeFilePath(path);
//    qDebug() << "   ->rootname =" << rootItem()->name();
    QFileInfo file(path);

    //Check if it is a file
    if(!file.isFile())
        return false;
    if(m_fileMap.contains(path))
        return false;//TODO:Or better true?!

    //Reset root Item if needed
    if(rootPath().relativeFilePath(path).startsWith("..")) {
        setCommonRoot(path);
    }

    //Split name in parts
    QStringList parts = rootPath().relativeFilePath(path).split("/",QString::SkipEmptyParts);
    if(parts.empty())
        return false;

    //Modify Project tree
    QStringList::const_iterator it = parts.begin();
    ProjectItem* currentItem = rootItem();
    ProjectItem* nextItem = currentItem->childWithName(*it);
//    if(nextItem)
//        qDebug() << "   found child with name" << *(it);
//    else{
//        qDebug() << "   no child found with name" << *(it);
//        qDebug() << "  => children are:";
//        for(int x = 0; x < currentItem->childCount(); ++x)
//            qDebug() << "  ..." << currentItem->child(x)->name();
//    }
        //First iterate through existing dirs but stop before current is 0
    while(nextItem != 0 && ++it != parts.end()) {
        currentItem = nextItem;
        nextItem = currentItem->childWithName(*it);
//        if(nextItem)
//            qDebug() << "   found child with name" << *(it);
//        else
//            qDebug() << "   no child found with name" << *(it);
    }
        //Append new dirs
    while(it != parts.end()) {
        nextItem = new ProjectItem(this,ProjectItem::Type_Dir,*it++);
        currentItem->appendChild(nextItem);
        currentItem = nextItem;
    }
        //currentItem is now the new one. Modify it.
    currentItem->setType(ProjectItem::Type_File);

        //Putting it into the map
    m_fileMap.insert(path,currentItem);

    setCommonRoot();
    Q_ASSERT_X(rootItem()->parent()==0,"addFile() (end)","rootItem's parent should be zero!");
    return true;
}

//QString Project::filename() const {
//    return QFileInfo(rootPath().absolutePath() + "/" + m_name).absoluteFilePath();
//}

void Project::setCommonRoot(QDir path) {
    Q_ASSERT_X(rootItem()->parent()==0,"setCommonRoot(QDir path)","should be zero!");
    QString newroot = FileManager::cleanPath(path.absolutePath());
    while(!QDir(newroot).isRoot() && rootPath().relativeFilePath(newroot).startsWith(".."))
        newroot = QDir(newroot + "/..").absolutePath();
    path = QDir(newroot);
    path.makeAbsolute();

    qDebug() << "Project::setRootPath(" << path.absolutePath() <<")";
    Q_ASSERT_X(
        !path.relativeFilePath(rootPath().absolutePath()).startsWith(".."),
        "Project::setRootPath(QDir path)",
        "The project root must be the utmost path of all contained files!");
    Q_ASSERT(rootPath() != path);

    //Directory steps from new to old root
    QStringList newdirs = path.relativeFilePath(rootPath().absolutePath()).split("/",QString::SkipEmptyParts);
    newdirs.removeLast(); //This is the old root
    ProjectItem* oldRootItem = rootItem();
    m_rootItem = new ProjectItem(this,ProjectItem::Type_Project,path.dirName());
    ProjectItem* parent = m_rootItem;
    ProjectItem* current;
//    for(siterator it = newdirs.begin(); it < newdirs.end() - 1; ++it) {
//        current = new ProjectItem(this,ProjectItem::Type_Dir,*it);
//        parent->appendChild(current);
//        parent = current;
//    }
    for(QStringList::const_iterator it = newdirs.begin(); it < newdirs.end(); ++it) {
        current = new ProjectItem(this,ProjectItem::Type_Dir,*it);
        parent->appendChild(current);
        parent = current;
    }
    oldRootItem->setType(ProjectItem::Type_Dir);
    parent->appendChild(oldRootItem);
    m_rootPath = path;
    Q_ASSERT_X(rootItem()->parent()==0,"setCommonRoot(QDir path) (end)","should be zero!");
}
void Project::setCommonRoot() {
    Q_ASSERT_X(rootItem()->parent()==0,"setCommonRoot()","should be zero!");
    qDebug() << "Project::setCommonRoot()";
    while(rootItem()->childCount() == 1 &&
    rootItem()->child(0)->type() == ProjectItem::Type_Dir) {
//        qDebug() << "  ..New root will be:" << m_rootPath.absolutePath() + "/" + rootItem()->child(0)->name();
        ProjectItem* oldRootItem = rootItem();
        ProjectItem* newRootItem = oldRootItem->child(0);
        //Change type of new rootItem
        newRootItem->setType(ProjectItem::Type_Project);
        newRootItem->setParent(0);
        //Change path
        m_rootPath = m_rootPath.absolutePath() + "/" + newRootItem->name();
        //Delete old rootItem
        oldRootItem->releaseAll();
        delete oldRootItem;
        //Replace rootItem
        m_rootItem = newRootItem;
//        qDebug() << "  ..New root is:" << m_rootPath.absolutePath();
    }
    Q_ASSERT_X(rootItem()->parent()==0,"setCommonRoot(QDir path) (end)","should be zero!");
}

//void Project::itemInserted(ProjectItem* item) {
//    //This should only be necessary for debugging because it would be a
//    //logical error:
//    Q_ASSERT((!m_items.contains(item)));
//    syslog.send("Project: New ProjectItem appended to project.",Logger::Informative);
//    m_items.append(item);
//}
