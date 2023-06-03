#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new Server(this);
    connect(server, &Server::newLocation, this, &MainWindow::placeBall );


    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,304,548);
    QPixmap pixmap(":/logo/resources/table.png");
    scene->setBackgroundBrush(pixmap.scaled(304,548,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->graphicsView->setScene(scene);
    ui->perde->hide();

    myTrainingBuddy = new trainingBuddy(this);
    connect( this , &MainWindow::newUserInput , server , &Server::broadcastMessage );
    connect( this , &MainWindow::newUserInput , myTrainingBuddy , &trainingBuddy::getMessage );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::placeBall(){
    int x = (server->last_x)*2 ;
    int y = (server->last_y)*2 ;

    qDebug() << QString("last_x = %1 | last_y = %2").arg(x).arg(y);

    QGraphicsEllipseItem* circle = new QGraphicsEllipseItem(x,y,10,10);
    y < 274 ?  circle->setBrush(Qt::red) : circle->setBrush(Qt::green)  ;
    scene->addItem(circle);
    ballList.append(circle);

}

void MainWindow::clearBall(){
    for(int i=0 ; i<ballList.length() ; i++)
        delete ballList[i];
    ballList.clear();
}

void MainWindow::on_pushButton_clicked()
{
    clearBall();
}

void MainWindow::on_spinSlider_valueChanged(int value)
{
    myTrainingBuddy->setSpin(value);
    emit newUserInput(myTrainingBuddy->getMessage());
}

void MainWindow::on_speedSlider_valueChanged(int value)
{
    myTrainingBuddy->setSpeed(value);
    emit newUserInput(myTrainingBuddy->getMessage());
}

void MainWindow::on_vertical_valueChanged(int value)
{
    myTrainingBuddy->setVertical(value);
    emit newUserInput(myTrainingBuddy->getMessage());
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    myTrainingBuddy->setHorizontal(value);
    emit newUserInput(myTrainingBuddy->getMessage());
}

void MainWindow::on_frequencySlider_valueChanged(int value)
{
    myTrainingBuddy->setFrequency(value);
    emit newUserInput(myTrainingBuddy->getMessage());
}


void MainWindow::on_randomButton_clicked()
{
    if (myTrainingBuddy->getRandom() ){
        myTrainingBuddy->setRandom(0);
        ui->randomButton->setStyleSheet(
            "QPushButton {   font-size: 14pt;  font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(85, 103, 104); };");
        ui->perde->hide();
    }
    else {
        myTrainingBuddy->setRandom(1);
        ui->randomButton->setStyleSheet(
            "QPushButton {   font-size: 14pt;  font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(15, 63, 139); };");
        ui->perde->show();
    }
    emit newUserInput(myTrainingBuddy->getMessage());



}


void MainWindow::on_repetitionButton_clicked()
{
    myTrainingBuddy->setOperationMode(REPETITION_MODE);
    ui->repetitionButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(15, 63, 139);};" );
    ui->sequenceButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(85, 103, 104);};" );
    ui->gameModeButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(85, 103, 104);};" );
    emit newUserInput(myTrainingBuddy->getMessage());
}


void MainWindow::on_sequenceButton_clicked()
{
    myTrainingBuddy->setOperationMode(SEQUENCE_MODE);
    ui->repetitionButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(85, 103, 104);};" );
    ui->sequenceButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(15, 63, 139);};" );
    ui->gameModeButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(85, 103, 104);};" );
    emit newUserInput(myTrainingBuddy->getMessage());
}


void MainWindow::on_gameModeButton_clicked()
{
    myTrainingBuddy->setOperationMode(GAME_MODE);
    ui->repetitionButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(85, 103, 104);};" );
    ui->sequenceButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(85, 103, 104);};" );
    ui->gameModeButton->setStyleSheet(
        "QPushButton { font-size: 14pt; font-weight: bold; color: rgb(217, 217, 217);  background-color: rgb(15, 63, 139);};" );
    emit newUserInput(myTrainingBuddy->getMessage());
}


