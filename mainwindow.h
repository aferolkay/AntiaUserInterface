
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "server.h"
#include "trainingbuddy.h"
#include<QDebug>
#include "globalVariables.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT
    //QList<QLabel *> ballList;
    QList<QGraphicsEllipseItem*> ballList;
    QGraphicsScene *scene;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    trainingBuddy* myTrainingBuddy;

public slots:
    void placeBall();
    void clearBall();

private slots:
    void on_pushButton_clicked();

    void on_spinSlider_valueChanged(int value);

    void on_speedSlider_valueChanged(int value);

    void on_vertical_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_frequencySlider_valueChanged(int value);

    void on_randomButton_clicked();

    void on_repetitionButton_clicked();

    void on_sequenceButton_clicked();

    void on_gameModeButton_clicked();

signals:
    void newUserInput(QString message);

private:
    Ui::MainWindow *ui;
    Server* server;

};

#endif // MAINWINDOW_H
