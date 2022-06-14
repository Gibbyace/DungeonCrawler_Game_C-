#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <level.h>
#include <array>
#include <graphicalui.h>

namespace Ui {
class MainWindow;
}

class GraphicalUI;
class TextureContainer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Level* level, TextureContainer* texturecontainer, GraphicalUI *parent = nullptr);
    ~MainWindow();
    void draw(Level* level, TextureContainer* texturecontainer);

public slots:

private:
    Ui::MainWindow *ui;
    QPixmap characterPixmapCopy;

    void setupArrowButtons(TextureContainer* texturecontainer, GraphicalUI* parent);
    void setupPlayingField(TextureContainer* texturecontainer, Level* level);

    void setCharacterPixmapFromDirection(int moveDirection, TextureContainer* texturecontainer);
    void setStatusbarMessage(Level* level);

    void closeEvent(QCloseEvent* event);
};

#endif // MAINWINDOW_H
