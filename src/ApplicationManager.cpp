#include "ApplicationManager.h"
#include "Settings.h"
#include "FileManager.h"

#include <QApplication>
#include <QDebug>

ApplicationManager* ApplicationManager::instance () {
    static Guard g;   // Speicherbereinigung
    if (!m_instance)
        m_instance = new ApplicationManager();
    return m_instance;
}

Settings* ApplicationManager::settings() {
    return instance()->m_settings;
}
FileManager* ApplicationManager::fileManager() {
    return instance()->m_fileManager;
}

void ApplicationManager::onSettingsChanged() {
    emit settingsChanged();
}
void ApplicationManager::beforeShutdown() {
    m_settings->save();
}

ApplicationManager::ApplicationManager()
        : m_settings(new Settings()), m_fileManager(new FileManager()) {
    Q_ASSERT_X(qApp != 0, "ApplicationManager()", "First initialize a QApplication");
    connect(qApp, SIGNAL(lastWindowClosed()), this, SLOT(beforeShutdown()));
    qDebug() << "ApplicationManager: Initialized instance";
}

ApplicationManager::~ApplicationManager() {
    delete m_fileManager;
    delete m_settings;
}


ApplicationManager* ApplicationManager::m_instance = 0;

ApplicationManager::Guard::~Guard() {
    if ( 0 != ApplicationManager::m_instance ) {
        delete ApplicationManager::m_instance;
        ApplicationManager::m_instance = 0;
    }
}
