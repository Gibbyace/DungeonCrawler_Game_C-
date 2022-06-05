#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <level.h>
#include <array>
#include <graphicalui.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Level* level, GraphicalUI *parent = nullptr);
    ~MainWindow();
    void draw(Level* level);

public slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
