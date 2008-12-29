#include "ApplicationVersion.h"

#include <QString>
#include <QStringList>

#include "autoversion.h"

#ifdef major
#undef major
#undef minor
#endif 

Version::Version(const QString& s) {
    QStringList l = s.split('.');
    if(l.count() == 4){
        m_major = l.at(0).toLong();
        m_minor = l.at(1).toLong();
        m_build = l.at(2).toLong();
        m_revision = l.at(3).toLong();
    }
    else{
        m_major = 0;
        m_minor = 0;
        m_build = 0;
        m_revision = 0;
    }
}
Version::Version(long major, long minor, long build, long revision)
    : m_major(major), m_minor(minor), m_build(build), m_revision(revision) {
}
QString Version::toString() const {
    QStringList l;
    l << QString::number(m_major);
    l << QString::number(m_minor);
    l << QString::number(m_build);
    l << QString::number(m_revision);
    return l.join(".");
}

bool Version::isValid() {
    return !(m_major==0&&m_minor==0&&m_build==0&&m_revision==0);
}

Version Version::currentVersion() {
//     using namespace AutoVersion;
    return Version(AutoVersion::MAJOR,AutoVersion::MINOR,AutoVersion::BUILD,AutoVersion::REVISION);
}

bool operator<(const Version& left, const Version& right) {
    if(left.major() > right.major())
        return false;
    if(left.minor() > right.minor())
        return false;
    if(left.build() > right.build())
        return false;
    return left.revision() < right.revision();
}

bool operator==(const Version& left, const Version& right) {
    return left.major() == right.major()
        && left.minor() == right.minor()
        && left.build() == right.build()
        && left.revision() == right.revision();
}
