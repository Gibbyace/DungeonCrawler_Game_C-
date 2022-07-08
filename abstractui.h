#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H
#include <level.h>


class AbstractUI
{

public:
    AbstractUI();
    virtual ~AbstractUI() = default;
    virtual void draw(Level* level) = 0;
    virtual void printDirectionOptions();

    bool getUserWantsToEndThisApp() const;
    void setUserWantsToEndThisApp(bool value);

    bool getInputProcessed() const;

    void setInputProcessed(bool value);

    bool loadRequested = false;
    bool saveRequested = false;

    void setLoadRequested(bool newLoadRequested);

    void setSaveRequested(bool newSaveRequested);

private:
    bool userWantsToEndThisApp = false;

protected:
    bool inputProcessed = false;
};

#endif // ABSTRACTUI_H
