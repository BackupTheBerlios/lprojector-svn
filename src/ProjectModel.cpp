
//#include "ProjectModelItem.h"
#include "ApplicationManager.h"
#include "FileManager.h"
#include "ProjectModel.h"
#include "ProjectItem.h"
#include "Project.h"

#include <QList>
#include <QMap>
#include <QMapIterator>
#include <QIcon>
#include <QFile>
#include <QDebug>

ProjectModel::ProjectModel(QObject *parent) : QAbstractItemModel(parent) {
    qDebug() << "New ProjectModel initialized";
}

ProjectModel::~ProjectModel() {
}

int ProjectModel::columnCount(const QModelIndex &parent) const {
//    qDebug() << "ProjectModel::columnCount()";
    return 1;
//    if (parent.isValid())
//        return static_cast<ProjectModelItem*>(parent.internalPointer())->columnCount();
//    else
//        return rootItem_->columnCount();
}
///Return the number of child items for a given parent or the number of top-level
///items for invalid indexes
int ProjectModel::rowCount(const QModelIndex &parent) const {
//    qDebug() << "ProjectModel::rowCount("<<parent<<")";

    //Only the first column is defined
    if(parent.column() > 0)
        return 0;

    //For invalid indizes return the number of top level items
    if(!parent.isValid())
        return ApplicationManager::fileManager()->projectCount();

    //Now report the number of child items
    if(parent.internalPointer() == this)
        return ApplicationManager::fileManager()->projectCount();
    return static_cast<const ProjectItem*>(parent.internalPointer())->childCount();
}
//bool ProjectModel::hasChildren(const QModelIndex &parent) const {
//    qDebug() << "ProjectModel::hasChildren()";
//    return rowCount(parent) > 0;
//}

///(1) Returns the parent of the model item with the given index, or QModelIndex()
///if it has no parent.
///(2) A common convention used in models that expose tree data
///structures is that only items in the first column have children. For that
///case, when reimplementing this function in a subclass the column of the
///returned QModelIndex would be 0.
///(3) We only need to ensure that we never return a model index corresponding to
///the root item.
QModelIndex ProjectModel::parent(const QModelIndex &index) const {
//    qDebug() << "ProjectModel::parent(" << index.internalPointer() <<")";

    //Invalid or root -> No parent (1)
    if((!index.isValid()) || index.internalPointer() == this)
        return QModelIndex();

    const ProjectItem* childItem = static_cast<const ProjectItem*>(index.internalPointer());
    Q_ASSERT(childItem);
    ProjectItem* parentItem = childItem->parent();

    //Never return the root item (1) und (3)
    if(parentItem == 0)
        return QModelIndex();

    //Find the row of the parent
        //This is for usual items
    int row = parentItem->row();
        //This is for project items
    if(parentItem->parent() == 0)
        row = ApplicationManager::fileManager()->indexOfProject(parentItem->project());

    //Return the parent, but only with column 0. (2)
    return createIndex(row, 0, parentItem);
}

///(1) Returns the index of the item in the model specified by the given row,
///column and parent index.
///(2) If an invalid model index is specified as the parent, it is up to the model
///to return an index that corresponds to a top-level item in the model.
///(3) We should guarantee that any valid model indexes that we receive will
///contain a valid data pointer.
QModelIndex ProjectModel::index(int row, int column, const QModelIndex &parent) const {
//    qDebug() << "ProjectModel::index(" << row <<","<< column <<","<< parent.internalPointer() <<")";

    Q_ASSERT(column == 0);//Test:Shouldn't be tried because of columnCount() = 1?!

    if(!hasIndex(row, column, parent))
        return QModelIndex();

    //For invalid indizes return the corresponding top level item (2)
    if(!parent.isValid()) {
        Q_ASSERT(row >= 0 && row < rowCount() && column == 0);
        return createIndex(row, 0, static_cast<void*>(//col=0!
            ApplicationManager::fileManager()->projects().at(row)->rootItem()));
    }

    //Return the child in the given row of parent
    ProjectItem* parentItem = static_cast<ProjectItem*>(parent.internalPointer());
    Q_ASSERT(parentItem);
    ProjectItem* childItem = parentItem->child(row);
    Q_ASSERT(childItem);
    return createIndex(row, 0, static_cast<void*>(childItem));
}

///Returns the data stored under the given role for the item referred to by
///the index.
///Note: If you do not have a value to return, return an empty QVariant()
///instead of returning 0.
QVariant ProjectModel::data(const QModelIndex &index, int role) const {
//    qDebug() << "ProjectModel::data()";

    //If you do not have a value to return, return an empty QVariant()
    if(!index.isValid())
        return QVariant();
    if(index.column() != 0)
        return QVariant();

    Q_ASSERT(index.internalPointer() != this);//Zum testen.
        //Das kommt doch nicht vor, weil der index nie ausgeliefert wird, oder?

    if(index.internalPointer() == this)
        return QVariant();
    const ProjectItem* item = static_cast<const ProjectItem*>(index.internalPointer());
    if(!item)
        return QVariant();

    if(role == Qt::DisplayRole) {
        return item->name();
    }
    else if(role == Qt::ToolTipRole) {
        return item->absolutePath();
    }
    else if(role == Qt::DecorationRole) {
        if(item->type() == ProjectItem::Type_Project) {
            if(item->project() == ApplicationManager::fileManager()->activeProject())
                return QIcon(":/icons/folder_red.png");
            return QIcon(":/icons/folder_grey.png");
        }
        if(item->type() == ProjectItem::Type_Dir) {
            return QIcon(":/icons/folder.png");
        }
        if(item->type() == ProjectItem::Type_File) {
            if(QFile::exists(item->absolutePath()))
                return QIcon(":/icons/file_doc.png");
            return QIcon(":/icons/file_broken.png");
        }
        return QIcon(":/icons/file.png");
    }
    return QVariant();
}

///Returns the data for the given role and section in the header with the
///specified orientation.
///For horizontal headers, the section number corresponds to the column number
///of items shown beneath it. For vertical headers, the section number
///typically to the row number of items shown alongside it.
QVariant ProjectModel::headerData(int section, Qt::Orientation orientation, int role) const {
//    qDebug() << "ProjectModel::headerData()";

    if (orientation == Qt::Horizontal && section == 0) {
        if(role == Qt::DisplayRole)
            return tr("Open Projects");
        if(role == Qt::ToolTipRole)
            return tr("The currently opened projects");
        if(role == Qt::DecorationRole)
            return QIcon(":/icons/project.png");
    }
    return QVariant();
}

Qt::ItemFlags ProjectModel::flags(const QModelIndex &index) const {
//    qDebug() << "ProjectModel::flags()";

    if(!index.isValid())
        return 0;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
