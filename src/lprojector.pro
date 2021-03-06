######################################################################
# Automatically generated by qmake (2.01a) Mi 26. Nov 10:20:14 2008
######################################################################

TEMPLATE = app
TARGET =
MOC_DIR = ../tmp
OBJECTS_DIR = ../tmp
DESTDIR = ../bin
RCC_DIR = ../tmp
#INCLUDEPATH += C:\programmierung\boost\boost_1_37_0
QT += xml

# Input
HEADERS += \
    ApplicationManager.h \
    ApplicationVersion.h \
    FileManager.h \
    Settings.h \
    Mainwindow.h \
    CodeEdit.h \
    Document.h \
    LineNumberWidget.h \
    DocumentInfo.h \
    Logger.h \
    EncodingDetector.h \
    DocStatusWidget.h \
    Project.h \
    ProjectItem.h \
    ProjectModel.h \
    version.h

FORMS += Mainwindow.ui \
    DocStatusWidget.ui

    # Highlighter.h
    # Highlighter.cpp

SOURCES += main.cpp \
    ApplicationManager.cpp \
    ApplicationVersion.cpp \
    FileManager.cpp \
    Settings.cpp \
    Mainwindow.cpp \
    Mainwindow_File.cpp \
    Mainwindow_Project.cpp \
    CodeEdit.cpp \
    Document.cpp \
    LineNumberWidget.cpp \
    DocumentInfo.cpp \
    Logger.cpp \
    EncodingDetector.cpp \
    DocStatusWidget.cpp \
    Project.cpp \
    Project_serializations.cpp \
    ProjectItem.cpp \
    ProjectModel.cpp

RESOURCES = resource.qrc

CONFIG(debug, debug|release) {
	CONFIG += console
	CONFIG += qt debug
	CONFIG += warn_on
}else{
}
