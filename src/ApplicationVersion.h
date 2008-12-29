
#ifndef VERSION_H
#define VERSION_H

class QString;

class Version
{
    private:
        long m_major;
        long m_minor;
        long m_build;
        long m_revision;
    public:
        Version(const QString&);
        Version(long major, long minor, long build, long revision);
        Version() {};
        ~Version() {};
        bool isValid();
        QString toString() const;

        void setMajor(long x)   {m_major = x;}
        void setMinor(long x)   {m_minor = x;}
        void setBuild(long x)   {m_build = x;}
        void setRevision(long x){m_revision = x;}
        long major() const    {return m_major;}
        long minor() const    {return m_minor;}
        long build() const    {return m_build;}
        long revision() const {return m_revision;}

        static Version currentVersion();
};

bool operator<(const Version& left, const Version& right);
bool operator==(const Version& left, const Version& right);

#endif // VERSION_H
