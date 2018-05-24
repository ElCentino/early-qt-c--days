#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
public:
    Settings();
    void setShowToolbar(bool showToolbar);
    bool getShowToolbar();
    void setShowStatusbar(bool showStatusbar);
    bool getShowStatusbar();
    void setEnableWordwrap(bool enableWordWrap);
    bool getEnableWordWrap();

private:
    bool showToolbar;
    bool showStatusbar;
    bool enableWordWrap;
};

#endif // SETTINGS_H
