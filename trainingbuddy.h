
#ifndef TRAININGBUDDY_H
#define TRAININGBUDDY_H


#include <QObject>
#include "globalVariables.h"

#define REPETITION_MODE 0
#define SEQUENCE_MODE 1
#define GAME_MODE 2
#define REGULAR 0
#define RANDOMIZED 1

class trainingBuddy : public QObject
{
    Q_OBJECT

public:
    trainingBuddy(QObject *parent = nullptr);

public slots:


    int getSpin() ;
    void setSpin(int newSpin);

    int getFrequency() ;
    void setFrequency(int newFrequency);

    int getSpeed() ;
    void setSpeed(int newSpeed);

    int getHorizontal() ;
    void setHorizontal(int newHorizontal);

    int getVertical() ;
    void setVertical(int newVertical);

    int getOperationMode() ;
    void setOperationMode(int newOperationMode);

    int getRandom() ;
    void setRandom(int newRandom);

    QString getMessage();

private:
    int spin;
    int frequency;
    int speed;
    int horizontal;
    int vertical;
    int operationMode;
    int random;

signals:

};

#endif // TRAININGBUDDY_H
