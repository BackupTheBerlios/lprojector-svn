
#include "Logger.h"

#include <QFile>
#include <QMessageBox>
#include <QApplication>

#include <stdio.h>
#include <QDebug>

//Logger* Logger::instance_(0);
Logger syslog(0);

//Logger& Logger::I() {
//    if(instance_ == 0) {
//        instance_ = new Logger(qApp);
//    }
//    return *instance_;
//}

Logger::Logger(QObject* parent) : QObject(parent) {
    logfile_ = new QFile(this);

    logLevel_ = Informative;
    notifyLevel_ = Medium;
    messageLevel_ = Warning;

    logfile_->open(stdout, QIODevice::WriteOnly|QIODevice::Unbuffered);
    qDebug() << "Logger: Initialized instance";
}

//void Logger::send(const char* message, MessageSeverity sev){
//    send(QString(message), sev);
//}

void Logger::send(const QString& message, MessageSeverity sev) {
    if(sev >= logLevel_) {
        logfile_->write(message.toLocal8Bit());
        logfile_->write("\n");
    }
    if(sev >= messageLevel_) {
        if(sev == Logger::Critical) {
            QMessageBox::critical(
                QApplication::activeWindow(),
                "Critical Warning", message);
        }
        else if(sev == Logger::High) {
            QMessageBox::warning(
                QApplication::activeWindow(),
                "Important", message);
        }
        else if(sev == Logger::Warning) {
            QMessageBox::warning(
                QApplication::activeWindow(),
                "Warning", message);
        }
        else {//sev <= Medium
            QMessageBox::information(
                QApplication::activeWindow(),
                "Information", message);
        }
    }
    else if(sev >= notifyLevel_) {
        emit notify(message);
    }
}
void Logger::setLogLevel(MessageSeverity sev) {
    logLevel_ = sev;
}
void Logger::setNotifyLevel(MessageSeverity sev) {
    notifyLevel_ = sev;
}
void Logger::setMessageLevel(MessageSeverity sev) {
    messageLevel_ = sev;
}
