#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <QObject>

class Settings;
class FileManager;
class QApplication;

class ApplicationManager : public QObject
{
    Q_OBJECT

    /// Public Interface
    public:
        static ApplicationManager* instance();
        static Settings* settings();
        static FileManager* fileManager();

    signals:
        void settingsChanged();

    /// Member variables
    private slots:
        void onSettingsChanged();
        void beforeShutdown();

    private:
        Settings* m_settings;
        FileManager* m_fileManager;

    /// Singleton implementation
    private:
        ApplicationManager();
        ApplicationManager(const ApplicationManager&);
        ~ApplicationManager();

        static ApplicationManager* m_instance;///< The unique instance-pointer.

        /// A friend class with the only aim to ensure cleanup of the singleton
        /// when the application terminates.
        class Guard
        {
            public:
               ~Guard();
        };
        friend class Guard;
};


#endif // APPLICATIONMANAGER_H
