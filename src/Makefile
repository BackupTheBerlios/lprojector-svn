#############################################################################
# Makefile for building: ../bin/lprojector
# Generated by qmake (2.01a) (Qt 4.4.3) on: Di Dez 30 12:43:22 2008
# Project:  lprojector.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -unix -o Makefile lprojector.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/qt4/QtXml -I/usr/include/qt4 -I../tmp -I.
LINK          = g++
LFLAGS        = -Wl,--no-undefined
LIBS          = $(SUBLIBS)  -L/usr/lib -lQtXml -lQtGui -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ../tmp/

####### Files

SOURCES       = main.cpp \
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
		ProjectModel.cpp ../tmp/moc_ApplicationManager.cpp \
		../tmp/moc_FileManager.cpp \
		../tmp/moc_Mainwindow.cpp \
		../tmp/moc_CodeEdit.cpp \
		../tmp/moc_Document.cpp \
		../tmp/moc_Logger.cpp \
		../tmp/moc_DocStatusWidget.cpp \
		../tmp/moc_ProjectItem.cpp \
		../tmp/moc_ProjectModel.cpp \
		../tmp/qrc_resource.cpp
OBJECTS       = ../tmp/main.o \
		../tmp/ApplicationManager.o \
		../tmp/ApplicationVersion.o \
		../tmp/FileManager.o \
		../tmp/Settings.o \
		../tmp/Mainwindow.o \
		../tmp/Mainwindow_File.o \
		../tmp/Mainwindow_Project.o \
		../tmp/CodeEdit.o \
		../tmp/Document.o \
		../tmp/LineNumberWidget.o \
		../tmp/DocumentInfo.o \
		../tmp/Logger.o \
		../tmp/EncodingDetector.o \
		../tmp/DocStatusWidget.o \
		../tmp/Project.o \
		../tmp/Project_serializations.o \
		../tmp/ProjectItem.o \
		../tmp/ProjectModel.o \
		../tmp/moc_ApplicationManager.o \
		../tmp/moc_FileManager.o \
		../tmp/moc_Mainwindow.o \
		../tmp/moc_CodeEdit.o \
		../tmp/moc_Document.o \
		../tmp/moc_Logger.o \
		../tmp/moc_DocStatusWidget.o \
		../tmp/moc_ProjectItem.o \
		../tmp/moc_ProjectModel.o \
		../tmp/qrc_resource.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		lprojector.pro
QMAKE_TARGET  = lprojector
DESTDIR       = ../bin/
TARGET        = ../bin/lprojector

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_Mainwindow.h ui_DocStatusWidget.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) ../bin/ || $(MKDIR) ../bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: lprojector.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtXml.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile lprojector.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtXml.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile lprojector.pro

dist: 
	@$(CHK_DIR_EXISTS) ../tmp/lprojector1.0.0 || $(MKDIR) ../tmp/lprojector1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) ../tmp/lprojector1.0.0/ && $(COPY_FILE) --parents ApplicationManager.h ApplicationVersion.h FileManager.h Settings.h Mainwindow.h CodeEdit.h Document.h LineNumberWidget.h DocumentInfo.h Logger.h EncodingDetector.h DocStatusWidget.h Project.h ProjectItem.h ProjectModel.h version.h ../tmp/lprojector1.0.0/ && $(COPY_FILE) --parents resource.qrc ../tmp/lprojector1.0.0/ && $(COPY_FILE) --parents main.cpp ApplicationManager.cpp ApplicationVersion.cpp FileManager.cpp Settings.cpp Mainwindow.cpp Mainwindow_File.cpp Mainwindow_Project.cpp CodeEdit.cpp Document.cpp LineNumberWidget.cpp DocumentInfo.cpp Logger.cpp EncodingDetector.cpp DocStatusWidget.cpp Project.cpp Project_serializations.cpp ProjectItem.cpp ProjectModel.cpp ../tmp/lprojector1.0.0/ && $(COPY_FILE) --parents Mainwindow.ui DocStatusWidget.ui ../tmp/lprojector1.0.0/ && (cd `dirname ../tmp/lprojector1.0.0` && $(TAR) lprojector1.0.0.tar lprojector1.0.0 && $(COMPRESS) lprojector1.0.0.tar) && $(MOVE) `dirname ../tmp/lprojector1.0.0`/lprojector1.0.0.tar.gz . && $(DEL_FILE) -r ../tmp/lprojector1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: ../tmp/moc_ApplicationManager.cpp ../tmp/moc_FileManager.cpp ../tmp/moc_Mainwindow.cpp ../tmp/moc_CodeEdit.cpp ../tmp/moc_Document.cpp ../tmp/moc_Logger.cpp ../tmp/moc_DocStatusWidget.cpp ../tmp/moc_ProjectItem.cpp ../tmp/moc_ProjectModel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) ../tmp/moc_ApplicationManager.cpp ../tmp/moc_FileManager.cpp ../tmp/moc_Mainwindow.cpp ../tmp/moc_CodeEdit.cpp ../tmp/moc_Document.cpp ../tmp/moc_Logger.cpp ../tmp/moc_DocStatusWidget.cpp ../tmp/moc_ProjectItem.cpp ../tmp/moc_ProjectModel.cpp
../tmp/moc_ApplicationManager.cpp: ApplicationManager.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ApplicationManager.h -o ../tmp/moc_ApplicationManager.cpp

../tmp/moc_FileManager.cpp: FileManager.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) FileManager.h -o ../tmp/moc_FileManager.cpp

../tmp/moc_Mainwindow.cpp: Project.h \
		ApplicationVersion.h \
		ProjectItem.h \
		ui_Mainwindow.h \
		Mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Mainwindow.h -o ../tmp/moc_Mainwindow.cpp

../tmp/moc_CodeEdit.cpp: LineNumberWidget.h \
		CodeEdit.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) CodeEdit.h -o ../tmp/moc_CodeEdit.cpp

../tmp/moc_Document.cpp: DocumentInfo.h \
		Document.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Document.h -o ../tmp/moc_Document.cpp

../tmp/moc_Logger.cpp: Logger.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) Logger.h -o ../tmp/moc_Logger.cpp

../tmp/moc_DocStatusWidget.cpp: ui_DocStatusWidget.h \
		DocStatusWidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) DocStatusWidget.h -o ../tmp/moc_DocStatusWidget.cpp

../tmp/moc_ProjectItem.cpp: ProjectItem.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ProjectItem.h -o ../tmp/moc_ProjectItem.cpp

../tmp/moc_ProjectModel.cpp: ProjectModel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ProjectModel.h -o ../tmp/moc_ProjectModel.cpp

compiler_rcc_make_all: ../tmp/qrc_resource.cpp
compiler_rcc_clean:
	-$(DEL_FILE) ../tmp/qrc_resource.cpp
../tmp/qrc_resource.cpp: resource.qrc \
		../icons/folder_red.png \
		../icons/file.png \
		../icons/file_broken.png \
		../icons/project.png \
		../icons/file_doc.png \
		../icons/folder.png \
		../icons/folder_grey.png
	/usr/bin/rcc -name resource resource.qrc -o ../tmp/qrc_resource.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_Mainwindow.h ui_DocStatusWidget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_Mainwindow.h ui_DocStatusWidget.h
ui_Mainwindow.h: Mainwindow.ui
	/usr/bin/uic-qt4 Mainwindow.ui -o ui_Mainwindow.h

ui_DocStatusWidget.h: DocStatusWidget.ui
	/usr/bin/uic-qt4 DocStatusWidget.ui -o ui_DocStatusWidget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

../tmp/main.o: main.cpp ApplicationManager.h \
		Mainwindow.h \
		Project.h \
		ApplicationVersion.h \
		ProjectItem.h \
		ui_Mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/main.o main.cpp

../tmp/ApplicationManager.o: ApplicationManager.cpp ApplicationManager.h \
		Settings.h \
		FileManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/ApplicationManager.o ApplicationManager.cpp

../tmp/ApplicationVersion.o: ApplicationVersion.cpp ApplicationVersion.h \
		autoversion.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/ApplicationVersion.o ApplicationVersion.cpp

../tmp/FileManager.o: FileManager.cpp FileManager.h \
		DocumentInfo.h \
		Document.h \
		Project.h \
		ApplicationVersion.h \
		ProjectItem.h \
		EncodingDetector.h \
		ApplicationManager.h \
		Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/FileManager.o FileManager.cpp

../tmp/Settings.o: Settings.cpp Settings.h \
		ApplicationManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/Settings.o Settings.cpp

../tmp/Mainwindow.o: Mainwindow.cpp Mainwindow.h \
		Project.h \
		ApplicationVersion.h \
		ProjectItem.h \
		ui_Mainwindow.h \
		Logger.h \
		Document.h \
		DocumentInfo.h \
		DocStatusWidget.h \
		ui_DocStatusWidget.h \
		ProjectModel.h \
		ApplicationManager.h \
		FileManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/Mainwindow.o Mainwindow.cpp

../tmp/Mainwindow_File.o: Mainwindow_File.cpp Mainwindow.h \
		Project.h \
		ApplicationVersion.h \
		ProjectItem.h \
		ui_Mainwindow.h \
		Document.h \
		DocumentInfo.h \
		ApplicationManager.h \
		FileManager.h \
		Logger.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/Mainwindow_File.o Mainwindow_File.cpp

../tmp/Mainwindow_Project.o: Mainwindow_Project.cpp Mainwindow.h \
		Project.h \
		ApplicationVersion.h \
		ProjectItem.h \
		ui_Mainwindow.h \
		ApplicationManager.h \
		FileManager.h \
		Logger.h \
		Document.h \
		DocumentInfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/Mainwindow_Project.o Mainwindow_Project.cpp

../tmp/CodeEdit.o: CodeEdit.cpp CodeEdit.h \
		LineNumberWidget.h \
		ApplicationManager.h \
		Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/CodeEdit.o CodeEdit.cpp

../tmp/Document.o: Document.cpp CodeEdit.h \
		LineNumberWidget.h \
		Document.h \
		DocumentInfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/Document.o Document.cpp

../tmp/LineNumberWidget.o: LineNumberWidget.cpp CodeEdit.h \
		LineNumberWidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/LineNumberWidget.o LineNumberWidget.cpp

../tmp/DocumentInfo.o: DocumentInfo.cpp DocumentInfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/DocumentInfo.o DocumentInfo.cpp

../tmp/Logger.o: Logger.cpp Logger.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/Logger.o Logger.cpp

../tmp/EncodingDetector.o: EncodingDetector.cpp EncodingDetector.h \
		ApplicationManager.h \
		Settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/EncodingDetector.o EncodingDetector.cpp

../tmp/DocStatusWidget.o: DocStatusWidget.cpp DocStatusWidget.h \
		ui_DocStatusWidget.h \
		Logger.h \
		Document.h \
		DocumentInfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/DocStatusWidget.o DocStatusWidget.cpp

../tmp/Project.o: Project.cpp ProjectItem.h \
		Project.h \
		ApplicationVersion.h \
		Logger.h \
		FileManager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/Project.o Project.cpp

../tmp/Project_serializations.o: Project_serializations.cpp Project.h \
		ApplicationVersion.h \
		ProjectItem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/Project_serializations.o Project_serializations.cpp

../tmp/ProjectItem.o: ProjectItem.cpp Project.h \
		ApplicationVersion.h \
		ProjectItem.h \
		Logger.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/ProjectItem.o ProjectItem.cpp

../tmp/ProjectModel.o: ProjectModel.cpp ApplicationManager.h \
		FileManager.h \
		ProjectModel.h \
		ProjectItem.h \
		Project.h \
		ApplicationVersion.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/ProjectModel.o ProjectModel.cpp

../tmp/moc_ApplicationManager.o: ../tmp/moc_ApplicationManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_ApplicationManager.o ../tmp/moc_ApplicationManager.cpp

../tmp/moc_FileManager.o: ../tmp/moc_FileManager.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_FileManager.o ../tmp/moc_FileManager.cpp

../tmp/moc_Mainwindow.o: ../tmp/moc_Mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_Mainwindow.o ../tmp/moc_Mainwindow.cpp

../tmp/moc_CodeEdit.o: ../tmp/moc_CodeEdit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_CodeEdit.o ../tmp/moc_CodeEdit.cpp

../tmp/moc_Document.o: ../tmp/moc_Document.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_Document.o ../tmp/moc_Document.cpp

../tmp/moc_Logger.o: ../tmp/moc_Logger.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_Logger.o ../tmp/moc_Logger.cpp

../tmp/moc_DocStatusWidget.o: ../tmp/moc_DocStatusWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_DocStatusWidget.o ../tmp/moc_DocStatusWidget.cpp

../tmp/moc_ProjectItem.o: ../tmp/moc_ProjectItem.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_ProjectItem.o ../tmp/moc_ProjectItem.cpp

../tmp/moc_ProjectModel.o: ../tmp/moc_ProjectModel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/moc_ProjectModel.o ../tmp/moc_ProjectModel.cpp

../tmp/qrc_resource.o: ../tmp/qrc_resource.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ../tmp/qrc_resource.o ../tmp/qrc_resource.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

