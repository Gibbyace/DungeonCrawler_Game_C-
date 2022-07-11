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

    void setUserWantsToEndThisApp(bool value);
    void setInputProcessed(bool value);
    void setLoadRequested(bool newLoadRequested);
    void setSaveRequested(bool newSaveRequested);
    void setResetRequested(bool value);

    bool getUserWantsToEndThisApp() const;
    bool getInputProcessed() const;
    bool getLoadRequested() const;
    bool getSaveRequested() const;
    bool getKaboomRequested() const;

private:
    bool userWantsToEndThisApp = false;

protected:
    bool inputProcessed = false;
    bool loadRequested = false;
    bool saveRequested = false;
    bool resetRequested = false;
};

#endif // ABSTRACTUI_H
