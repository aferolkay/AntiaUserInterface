#include "infodisplay.h"
#include "ui_infodisplay.h"

infoDisplay::infoDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoDisplay)
{
    ui->setupUi(this);
    updateTable();
}

infoDisplay::~infoDisplay()
{
    delete ui;
}

void infoDisplay::updateTable()
{
    ui->freq0->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(frequencyReturn[0]).arg(frequencyThrown[0] )  );
    ui->freq1->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(frequencyReturn[1]).arg(frequencyThrown[1] )  );
    ui->freq2->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(frequencyReturn[2]).arg(frequencyThrown[2] )  );

    ui->spin0->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(spinReturn[0]).arg(spinThrown[0] )  );
    ui->spin1->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(spinReturn[1]).arg(spinThrown[1] )  );
    ui->spin2->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(spinReturn[2]).arg(spinThrown[2] )  );
    ui->spin3->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(spinReturn[3]).arg(spinThrown[3] )  );
    ui->spin4->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(spinReturn[4]).arg(spinThrown[4] )  );

    ui->speed0->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(speedReturn[0]).arg(speedThrown[0] )  );
    ui->speed1->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(speedReturn[1]).arg(speedThrown[1] )  );
    ui->speed2->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(speedReturn[2]).arg(speedThrown[2] )  );

    ui->horizontal0->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(horizontalReturn[0]).arg(horizontalThrown[0] )  );
    ui->horizontal1->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(horizontalReturn[1]).arg(horizontalThrown[1] )  );
    ui->horizontal2->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(horizontalReturn[2]).arg(horizontalThrown[2] )  );
    ui->horizontal3->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(horizontalReturn[3]).arg(horizontalThrown[3] )  );
    ui->horizontal4->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(horizontalReturn[4]).arg(horizontalThrown[4] )  );

    ui->vertical0->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(verticalReturn[0]).arg(verticalThrown[0] )  );
    ui->vertical1->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(verticalReturn[1]).arg(verticalThrown[1] )  );
    ui->vertical2->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(verticalReturn[2]).arg(verticalThrown[2] )  );
    ui->vertical3->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(verticalReturn[3]).arg(verticalThrown[3] )  );
    ui->vertical4->setText( QString("<html><head/><body><p align=\"center\">%1 / %2</p></body></html>").arg(verticalReturn[4]).arg(verticalThrown[4] )  );

}


void infoDisplay::setThrows(QString throws )
{


    qInfo() << QString("throws infosu geldi ve bu şekil ilettim: %1").arg(throws);
               QStringList throws_parsed = throws.remove("[").remove("]").remove(",").split(" ");

    spinThrown[0] = throws_parsed[0].toInt();
    spinThrown[1] = throws_parsed[1].toInt();
    spinThrown[2] = throws_parsed[2].toInt();
    spinThrown[3] = throws_parsed[3].toInt();
    spinThrown[4] = throws_parsed[4].toInt();

    frequencyThrown[0] = throws_parsed[5].toInt();
    frequencyThrown[1] = throws_parsed[6].toInt();
    frequencyThrown[2] = throws_parsed[7].toInt();

    speedThrown[0] = throws_parsed[8].toInt();
    speedThrown[1] = throws_parsed[9].toInt();
    speedThrown[2] = throws_parsed[10].toInt();

    horizontalThrown[0] = throws_parsed[11].toInt();
    horizontalThrown[1] = throws_parsed[12].toInt();
    horizontalThrown[2] = throws_parsed[13].toInt();
    horizontalThrown[3] = throws_parsed[14].toInt();
    horizontalThrown[4] = throws_parsed[15].toInt();

    verticalThrown[0] = throws_parsed[16].toInt();
    verticalThrown[1] = throws_parsed[17].toInt();
    verticalThrown[2] = throws_parsed[18].toInt();
    verticalThrown[3] = throws_parsed[19].toInt();
    verticalThrown[4] = throws_parsed[20].toInt();
    updateTable();
}

void infoDisplay::setReturns( QString returns )
{

    qInfo() << QString("returned infosu geldi ve bu şekil ilettim: %1").arg(returns);
               QStringList returns_parsed = returns.remove("[").remove("]").remove(",").split(" ");

    spinReturn[0] = returns_parsed[0].toInt();
    spinReturn[1] = returns_parsed[1].toInt();
    spinReturn[2] = returns_parsed[2].toInt();
    spinReturn[3] = returns_parsed[3].toInt();
    spinReturn[4] = returns_parsed[4].toInt();

    frequencyReturn[0] = returns_parsed[5].toInt();
    frequencyReturn[1] = returns_parsed[6].toInt();
    frequencyReturn[2] = returns_parsed[7].toInt();

    speedReturn[0] = returns_parsed[8].toInt();
    speedReturn[1] = returns_parsed[9].toInt();
    speedReturn[2] = returns_parsed[10].toInt();

    horizontalReturn[0] = returns_parsed[11].toInt();
    horizontalReturn[1] =     returns_parsed[12].toInt();
    horizontalReturn[2] = returns_parsed[13].toInt();
    horizontalReturn[3] = returns_parsed[14].toInt();
    horizontalReturn[4] = returns_parsed[15].toInt();

    verticalReturn[0] = returns_parsed[16].toInt();
    verticalReturn[1] = returns_parsed[17].toInt();
    verticalReturn[2] = returns_parsed[18].toInt();
    verticalReturn[3] = returns_parsed[19].toInt();
    verticalReturn[4] = returns_parsed[20].toInt();

    updateTable();
}


