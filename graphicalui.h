#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QDialog>

namespace Ui {
class GraphicalUI;
}

class GraphicalUI : public QDialog
{
    Q_OBJECT

public:
    explicit GraphicalUI(QWidget *parent = nullptr);
    //Public slot soll hier rein für button push
    ~GraphicalUI();

private:
    Ui::GraphicalUI *ui;
};

#endif // GRAPHICALUI_H
