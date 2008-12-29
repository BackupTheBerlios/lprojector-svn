
#include "ApplicationManager.h"
#include "Mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
//    ApplicationManager* appmanager =
    ApplicationManager::instance();

//    QTranslator translator;
//    translator.load("lang_en");
//    app.installTranslator(&translator);

    Mainwindow h(0);
    h.show();

    int i = app.exec();
    return i;
}
