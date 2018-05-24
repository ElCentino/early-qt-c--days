#include "settings.h"
#include "overloads.h"

Settings::Settings()
{

}

void Settings::setShowToolbar(bool showToolbar)
{
    this->showToolbar = showToolbar;
}

bool Settings::getShowToolbar()
{
    return showToolbar;
}

void Settings::setShowStatusbar(bool showStatusbar)
{
    this->showStatusbar = showStatusbar;
}

bool Settings::getShowStatusbar()
{
    return showStatusbar;
}

void Settings::setEnableWordwrap(bool enableWordWrap)
{
    this->enableWordWrap = enableWordWrap;
}

bool Settings::getEnableWordWrap()
{
    return enableWordWrap;
}
