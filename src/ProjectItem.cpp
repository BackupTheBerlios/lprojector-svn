
#include "Project.h"
#include "ProjectItem.h"
#include "Logger.h"
#include <QDebug>
#include <QStringList>

ProjectItem::ProjectItem(Project* p, ItemType t, const QString& name, ProjectItem* parent)
    : m_project(p) , m_type(t), m_name(name), m_isOpen(false), m_parent(parent) {

}
ProjectItem::~ProjectItem() {
    typedef ProjectItemList::const_iterator iterator;
    for(iterator it = m_children.begin(); it != m_children.end(); ++it)
        delete *it;
    m_children.clear();
}

void ProjectItem::appendChild(ProjectItem* child) {
//    qDebug() << "ProjectItem::appendChild()";

    child->setProject(m_project);//TODO:Is unnecessary
    child->setParent(this);
    m_children.append(child);
}
ProjectItem* ProjectItem::childWithName(const QString& name) {
//    qDebug() << "ProjectItem::childWithName()";

    typedef ProjectItemList::const_iterator iterator;
    for(iterator it = m_children.begin(); it != m_children.end(); ++it)
        if((*it)->name() == name)
            return *it;
    return 0;
}
ProjectItem* ProjectItem::child(int row) const {
//    qDebug() << "ProjectItem::child()";

    if(row >= childCount() || row < 0)
        return 0;
    return m_children.at(row);
}
int ProjectItem::childCount() const {
//    qDebug() << "ProjectItem::childCount()";

    return m_children.count();
}
void ProjectItem::releaseAll() {
//    qDebug() << "ProjectItem::releaseAll()";

    m_children.clear();
}
QString ProjectItem::absolutePath() const {
//    qDebug() << "ProjectItem::absolutePath() of" << name();
    Q_ASSERT_X(project()!=0,"ProjectItem::absolutePath()","No project set!");

    if(parent() == 0)
        return QDir(project()->rootPath().absolutePath() + "/" + name()).absolutePath();
    else
        return QDir(parent()->absolutePath() + "/" + name()).absolutePath();
//    QStringList elements;
//    elements << name();
//    for(ProjectItem* p = parent(); p != 0; p = p->parent()){
//        qDebug() << p->name();
//        elements.prepend(p->name());
//    }
//    qDebug() << "ProjectItem::absolutePath() scanned parents";
//    elements.prepend(project()->rootPath().absolutePath());
//    qDebug() << "ProjectItem::absolutePath() ready";
//    return  elements.join("/");
}
QString ProjectItem::relativePath() const {
//    qDebug() << "ProjectItem::relativePath()";
    Q_ASSERT_X(project()!=0,"ProjectItem::relativePath()","No project set!");

    //One could even use the QDir.relativePath(to) method
    if(parent() == 0)
        return name();
    else
        return parent()->relativePath() + "/" + name();
//    QStringList elements;
//    elements << name();
//    for(ProjectItem* p = parent(); p != 0; p = p->parent())
//        elements.prepend(p->name());
////    elements.prepend(project()->rootPath().absolutePath());
//    qDebug() << "ProjectItem::relativePath() ready";
//    return  elements.join("/");
    return "/";
}
int ProjectItem::row() const {
//    qDebug() << "ProjectItem::row()";

    if(m_parent)//TODO: I don't know if it's ok to return -1 on invalid requests
        return m_parent->m_children.indexOf(const_cast<ProjectItem*>(this));
    return 0;
}
