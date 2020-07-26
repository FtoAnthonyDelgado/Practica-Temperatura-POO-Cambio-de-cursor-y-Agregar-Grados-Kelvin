#include "temperatura.h"
#include "ui_temperatura.h"
#include <QDebug>
#include <QMouseEvent>

Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);

    // Conexion de signal/slots
    connect(ui->dialCent,SIGNAL(valueChanged(int)),
            this,SLOT(cent2Fahr(int)));
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this,SLOT(fahr2Cent(int)));
    connect(ui->dialKelv,SIGNAL(valueChanged(int)),
                this,SLOT(kelv2Cent(int)));

    //Cambio de cursor
       connect(ui->dialCent, SIGNAL(sliderPressed()),
               this,SLOT(cambioCursor()));

       connect(ui->dialFahr, SIGNAL(sliderPressed()),
               this,SLOT(cambioCursor()));

       connect(ui->dialKelv, SIGNAL(sliderPressed()),
               this,SLOT(cambioCursor()));

    // establecer el valor inicial de F.
    ui->dialFahr->setValue(32);
    ui->dialKelv->setValue(273);
}

Temperatura::~Temperatura()
{
    delete ui;
}

void Temperatura::cent2Fahr(int valor)
{
    if (ui->dialCent->hasFocus()){
        float f = valor * 9.0/5 + 32;
        ui->dialFahr->setValue(f);
    }
}

void Temperatura::fahr2Cent(int valor)
{
    if (ui->dialFahr->hasFocus()){
        float c = (valor - 32) * 5.0/9;
        ui->dialCent->setValue(c);
    }
}
void Temperatura::kelv2Cent(int valor)
{
    if (ui->dialKelv->hasFocus()){
        float c = (valor - 273.15);
        float f = (valor -273.15)*9/5.0+32;
        QString fahr = QString::number(f);
        QString kelvin = QString::number(valor);
        QString centi = QString::number(c);

        ui->dialFahr->setValue(f);
        ui->dialCent->setValue(c);

    }

}
void Temperatura::cambioCursor()
{
    if(ui->dialCent->hasFocus()){
        if(ui->dialCent->cursor() == Qt::OpenHandCursor){
            ui->dialCent->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialCent->setCursor(Qt::OpenHandCursor);
        }
    }else if (ui->dialFahr->hasFocus()){
        if(ui->dialFahr->cursor() == Qt::OpenHandCursor){
            ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialFahr->setCursor(Qt::OpenHandCursor);
        }
    }else if (ui->dialKelv->hasFocus()){
        if(ui->dialKelv->cursor() == Qt::OpenHandCursor){
            ui->dialKelv->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialKelv->setCursor(Qt::OpenHandCursor);
        }
    }

}


