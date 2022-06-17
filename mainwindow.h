#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <level.h>
#include <vector>
#include <graphicalui.h>
#include <QLabel>

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

    std::map<int, QLabel*> characterLabels;

    void setupArrowButtons(TextureContainer* texturecontainer, GraphicalUI* parent);
    void setupPlayingField(TextureContainer* texturecontainer, Level* level);

    QPixmap* setCharacterPixmapFromDirection(int moveDirection, TextureContainer* texturecontainer);
    void setStatusbarMessage(Level* level);

    void closeEvent(QCloseEvent* event);
};

#endif // MAINWINDOW_H
