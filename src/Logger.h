#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <QObject>
class QFile;

class Logger : public QObject {
    Q_OBJECT

    public:
        enum MessageSeverity {
            Informative=1,    //Only for debugging.
            Low=2,            //Hardly worth mentioning.
            Medium=3,         //Not important but may even interest users.
            Warning=4,        //There is some Problem the user should know.
            High=5,           //High priority Message seriously affecting the user.
            Critical=6,       //Really critical. The Application may crash.
        };

        Logger(QObject* parent = 0);
//        static Logger& I();

        void send(const QString& message, MessageSeverity sev);
//        void send(const char* message, MessageSeverity sev);
        void setLogLevel(MessageSeverity sev);
        void setNotifyLevel(MessageSeverity sev);
        void setMessageLevel(MessageSeverity sev);

    signals:
        void notify(const QString& message);

    private:
//        static Logger* instance_;

        ///The minimum severity for a message to be send to the logfile.
        MessageSeverity logLevel_;
        ///The minimum severity for a message to raise a notify signal.
        MessageSeverity notifyLevel_;
        ///The minimum severity for a message to be shown via MessageBox.
        MessageSeverity messageLevel_;

        ///The used logfile;
        QFile* logfile_;
};

extern Logger syslog;

#endif // LOGGER_H_INCLUDED
