#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include "texturecontainer.h"
#include <QDialog>

namespace Ui {
class endscreen;
}

class Endscreen : public QDialog
{
    Q_OBJECT

public:
    explicit Endscreen(QString message, TextureContainer* texturecontainer, QWidget *parent = nullptr);
    ~Endscreen();
    bool buttonboxpressed();

private:
    Ui::endscreen *ui;
};

#endif // ENDSCREEN_H
