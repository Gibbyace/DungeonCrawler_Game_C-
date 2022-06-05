#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QDialog>
#include <graphicalui.h>

namespace Ui {
class StartScreen;
}

class GraphicalUI;

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(GraphicalUI *parent = nullptr);
    ~StartScreen();

private slots:
    //void on_pushButton_clicked();

private:
    Ui::StartScreen *ui;
};

#endif // STARTSCREEN_H
