#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QDialog>

namespace Ui {
class endscreen;
}

class endscreen : public QDialog
{
    Q_OBJECT

public:
    explicit endscreen(QWidget *parent = nullptr);
    ~endscreen();
    bool buttonboxpressed();

private:
    Ui::endscreen *ui;
};

#endif // ENDSCREEN_H
