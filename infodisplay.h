#ifndef INFODISPLAY_H
#define INFODISPLAY_H

#include <QDialog>
#include <QDebug>
namespace Ui {
class infoDisplay;
}

class infoDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit infoDisplay(QWidget *parent = nullptr);
    ~infoDisplay();

public slots:
    void updateTable();

    void setTable(QString throws, QString returns);
private:
    Ui::infoDisplay *ui;
    int frequencyThrown[3] = {0,0,0};
    int frequencyReturn[3] = {0,0,0};

    int spinThrown[5]= {0,0,0,0,0};
    int spinReturn[5]= {0,0,0,0,0};

    int speedThrown[3]= {0,0,0};
    int speedReturn[3]= {0,0,0};

    int horizontalThrown[5] = {0,0,0,0,0};
    int horizontalReturn[5] = {0,0,0,0,0};

    int verticalThrown[5] = {0,0,0,0,0};
    int verticalReturn[5] = {0,0,0,0,0};

};

#endif // INFODISPLAY_H
