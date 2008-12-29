#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include <QAbstractItemModel>
class Project;
class ProjectItem;

class ProjectModel : public QAbstractItemModel {

    Q_OBJECT

    public:
//        ProjectModel(Project* project, QObject* parent=0);
        ProjectModel(QObject* parent=0);
        ~ProjectModel();

        int columnCount(const QModelIndex &parent=QModelIndex()) const;
        int rowCount(const QModelIndex &parent=QModelIndex()) const;
//        bool hasChildren(const QModelIndex &parent=QModelIndex()) const;
        QModelIndex parent(const QModelIndex &index) const;

        QModelIndex index(int row, int column, const QModelIndex &parent=QModelIndex()) const;

        QVariant data(const QModelIndex &index, int role) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;
        Qt::ItemFlags flags(const QModelIndex &index) const;

    private:
//        Project* m_project;
};

#endif // PROJECTMODEL_H
