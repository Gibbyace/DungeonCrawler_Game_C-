#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QDialog>
#include <graphicalui.h>

namespace Ui {
class StartScreen;
}

class GraphicalUI;
class TextureContainer;

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(TextureContainer* texturecontainer, GraphicalUI *parent = nullptr);
    ~StartScreen();

private:
    Ui::StartScreen *ui;
};

#endif // STARTSCREEN_H
