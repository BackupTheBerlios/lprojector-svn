#ifndef PROJECTITEM_H_INCLUDED
#define PROJECTITEM_H_INCLUDED

#include <QObject>
#include <QString>
#include <QList>

class Project;
class Document;
class ProjectItem;
typedef QList<ProjectItem*> ProjectItemList;

class ProjectItem : public QObject {
    Q_OBJECT

    public:
        enum ItemType {
            Type_Undefined=0, Type_Project, Type_Dir, Type_File, Type_Dummy
        };

    public:
        ProjectItem(Project* p, ItemType t, const QString& name, ProjectItem* parent=0);
        ~ProjectItem();

    private:
	    Project*            m_project;      //!<Pointer to the owning project
        ItemType            m_type;         //!<Item Type
        QString             m_name;         //!<Filename or whatever
        //TODO: Make a function of it:
        bool                m_isOpen;       //!<Opened in the editor
        Document*           m_document;     //!<Related Document if open else 0
        ProjectItem*        m_parent;       //!<Parent node
        ProjectItemList     m_children;     //!<Child nodes

    public:
        const Project* project() const  {return m_project;}
        ItemType type() const           {return m_type;}
        const QString& name() const     {return m_name;}
        bool isOpen() const             {return m_isOpen;}
        Document* document() const      {return m_document;}
        ProjectItem* parent() const     {return m_parent;}

	    void setProject(Project* p)     {m_project = p;}
        void setType(ItemType t)        {m_type = t;}
        void setName(const QString& n)  {m_name = n;}
        void setIsOpen(bool open)       {m_isOpen = open;}
        void setDocument(Document* doc) {m_document = doc;}
        void setParent(ProjectItem* p)  {m_parent = p;}

        void appendChild(ProjectItem* child);
        ProjectItem* childWithName(const QString& name);
        ProjectItem* child(int row) const;
        int childCount() const;
        void releaseAll();//!<Clear the children Table without deletion
        QString absolutePath() const;
        QString relativePath() const;
        int row() const; //!<The row of this item in the parent's list.

//    signals:
//        void childAdded(ProjectItem* item);
};

#endif // PROJECTITEM_H_INCLUDED
