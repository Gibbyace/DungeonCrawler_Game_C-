#include "abstractui.h"

AbstractUI::AbstractUI()
{

}

void AbstractUI::printDirectionOptions() {

}

bool AbstractUI::getUserWantsToEndThisApp() const
{
    return userWantsToEndThisApp;
}

void AbstractUI::setUserWantsToEndThisApp(bool value)
{
    userWantsToEndThisApp = value;
}
