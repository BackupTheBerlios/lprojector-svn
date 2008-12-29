#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

class QTextCodec;
class QColor;
class QSettings;

class Settings {
    public:
        Settings();
        ~Settings();

        void reload();
        void save();

        QTextCodec* defaultEncoding();
        bool highlightCurrentLine();
        QColor currentLineHighlightColor();
        QColor lineNumberBackgroundColor();
        QColor lineNumberColor();

    private:
        QSettings* m_qsettings;
};

#endif // SETTINGS_H_INCLUDED
