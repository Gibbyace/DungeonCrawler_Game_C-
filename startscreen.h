#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QDialog>

namespace Ui {
class StartScreen;
}

class GraphicalUI;

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(QWidget *parent = nullptr);
    ~StartScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StartScreen *ui;
};

#endif // STARTSCREEN_H
