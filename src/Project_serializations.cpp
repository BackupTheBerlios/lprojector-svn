#include "Project.h"
#include "ProjectItem.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QByteArray>
#include <QBuffer>
#include <QDebug>

class QIODevice;

//xml.writeStartElement("LProject");
//    xml.writeAttribute("FileFormatVersion","1");
//    xml.writeAttribute("ApplicationVersion"version().toString());
//    xml.writeAttribute("Name", name());
//foreach(const ProjectItem* i, m_fileMap.values()) {
//    xml.writeEmptyElement("Item");
//        xml.writeAttribute("Id",QString::number(reinterpret_cast<ulong>(i)));

Project* Project::fromXml(QIODevice* device, const QString& rootPath, QString* error) {
    enum ParserState {SInitial, SProject};

    QXmlStreamReader xml(device);
    ParserState state = SInitial;
    QString tempname;
    QString temp;
    bool ok;
    unsigned fileFormatVersion;
    Version version;
    ProjectItem::ItemType itype;
    Project* project = new Project("Unnamed",rootPath);

    bool projectfound = false;

    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.isStartElement()) {
//            qDebug() << "xml tag:" << xml.name().toString();
            switch(state) {
                case SInitial:
                    if(xml.name() == "LProject") {
                        temp = xml.attributes().value("FileFormatVersion").toString();
                        fileFormatVersion = temp.toUInt(&ok);
                        if(temp.isEmpty() || !ok || fileFormatVersion == 0){
                            qDebug() << "Unable to retrieve the FileFormatVersion";
                            if(error)
                                *error = device->tr("Unable to retrieve the FileFormatVersion");
                            delete project;
                            return 0;
                        }
                        temp = xml.attributes().value("ApplicationVersion").toString();
                        version = Version(temp);
                        if(temp.isEmpty() || !version.isValid()){
                            qDebug() << "Unable to retrieve the ApplicationVersion";
                            if(error)
                                *error = device->tr("Unable to retrieve the ApplicationVersion");
                            delete project;
                            return 0;
                        }
                        temp = xml.attributes().value("Name").toString();
                        if(temp.isNull()){
                            qDebug() << "Unable to retrieve the Project name";
                            if(error)
                                *error = device->tr("Unable to retrieve the Project name");
                            delete project;
                            return 0;
                        }
                        project->setName(temp);
                        state = SProject;
                        projectfound = true;
                    }
                    else {
                        qDebug() << "Unexpected Tag. LProject expected.";
                        if(error)
                            *error = device->tr("Unexpected Tag. LProject expected.");
                        delete project;
                        return 0;
                    }
                    break;
                case SProject:
                    if(xml.name() == "Item") {
                        temp = xml.attributes().value("Type").toString();
                        itype = static_cast<ProjectItem::ItemType>(temp.toInt(&ok));
                        if(temp.isNull() || !ok){
                            qDebug() << "Unable to retrieve an item's type";
                            if(error)
                                *error = device->tr("Unable to retrieve an item's type");
                            delete project;
                            return 0;
                        }
                        if(itype == ProjectItem::Type_File) {
                            tempname = xml.attributes().value("Name").toString();
                            if(tempname.isEmpty()){
                                qDebug() << "Unable to retrieve a file's Name";
                                if(error)
                                    *error = device->tr("Unable to retrieve a file's Name");
                                delete project;
                                return 0;
                            }
                            temp = xml.attributes().value("Path").toString();
                            if(temp.isEmpty()){
                                qDebug() << "Unable to retrieve a file's Path";
                                if(error)
                                    *error = device->tr("Unable to retrieve a file's Path");
                                delete project;
                                return 0;
                            }
                            project->addFile(temp);
                        }else{
                            qDebug() << "Invalid item type";
                            if(error)
                                *error = device->tr("Invalid item type");
                            delete project;
                            return 0;
                        }
                    }
                    else {
                        qDebug() << "Unexpected tag. Item expected.";
                        if(error)
                            *error = device->tr("Unexpected tag. Item expected.");
                        delete project;
                        return 0;
                    }
                    break;
            }
        }
//        else{
//            qDebug() << "xml token:" << xml.tokenString();
//        }
    }
    if (xml.error()) {// && xml.error() != QXmlStreamReader::PrematureEndOfDocumentError) {
        qWarning() << "XML ERROR:" << xml.lineNumber() << ": " << xml.errorString();
        if(error)
            *error = device->tr("XML ERROR.");
        delete project;
        return 0;
    }
    if(!projectfound){
        qDebug() << "Invalid Xml file. Expected LProject.";
        if(error)
            *error = device->tr("Invalid Xml file. Expected LProject.");
        delete project;
        return 0;
    }
    return project;
}

QByteArray Project::toXml() {
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::Text|QIODevice::WriteOnly);
    toXml(&buffer);
    return byteArray;
}
void Project::toXml(QIODevice* buffer) {
    QXmlStreamWriter xml(buffer);
    xml.setAutoFormatting(true);

    xml.writeStartDocument();
    xml.writeStartElement("LProject");
        xml.writeAttribute("FileFormatVersion","1");
        xml.writeAttribute("ApplicationVersion", version().toString());
        xml.writeAttribute("Name", name());
    foreach(const ProjectItem* i, m_fileMap.values()) {
        xml.writeEmptyElement("Item");
            xml.writeAttribute("Id",QString::number(reinterpret_cast<ulong>(i)));
            xml.writeAttribute("Name",i->name());
            xml.writeAttribute("Path",i->relativePath());
            xml.writeAttribute("Type",QString::number(i->type()));
    }
    xml.writeEndElement();
    xml.writeEndDocument();
//    return byteArray;
}
