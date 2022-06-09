#include "abstractui.h"

AbstractUI::AbstractUI()
{

}

//TODO: kann wahrscheinlich weg
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
