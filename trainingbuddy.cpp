
#include "trainingbuddy.h"
#include <QDebug>
trainingBuddy::trainingBuddy(QObject *parent)
    : QObject{parent}
{
    spin = 0 ;
    frequency = 0;
    speed = 0;
    horizontal = 0;
    vertical = 0;
    operationMode = REPETITION_MODE;
    random = REGULAR;
}

int trainingBuddy::getSpin()
{
    return spin;
}

void trainingBuddy::setSpin(int newSpin)
{
    spin = newSpin;
}

int trainingBuddy::getFrequency()
{
    return frequency;
}

void trainingBuddy::setFrequency(int newFrequency)
{
    frequency = newFrequency;
}

int trainingBuddy::getSpeed()
{
    return speed;
}

void trainingBuddy::setSpeed(int newSpeed)
{
    speed = newSpeed;
}

int trainingBuddy::getRandom()
{
    return random;
}

void trainingBuddy::setRandom(int newRandom)
{
    random = newRandom;
}

QString trainingBuddy::getMessage()
{
    QString message;
    message = QString("[%1 %2 %3 %4 %5 %6 %7]") .arg(
                    QString::number(spin+2),
                    QString::number(frequency+2),
                    QString::number(speed+2),
                    QString::number(horizontal+2),
                    QString::number(vertical+2),
                    QString::number(operationMode+2),
                    QString::number(random+2));
    qInfo() << message;
    return message;
}

int trainingBuddy::getOperationMode()
{
    return operationMode;
}

void trainingBuddy::setOperationMode(int newOperationMode)
{
    operationMode = newOperationMode;
}

int trainingBuddy::getVertical()
{
    return vertical;
}

void trainingBuddy::setVertical(int newVertical)
{
    vertical = newVertical;
}

int trainingBuddy::getHorizontal()
{
    return horizontal;
}

void trainingBuddy::setHorizontal(int newHorizontal)
{
    horizontal = newHorizontal;
}

