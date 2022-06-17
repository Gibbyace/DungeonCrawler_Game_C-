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

bool AbstractUI::getInputProcessed() const
{
    return inputProcessed;
}

void AbstractUI::setInputProcessed(bool value)
{
    inputProcessed = value;
}
