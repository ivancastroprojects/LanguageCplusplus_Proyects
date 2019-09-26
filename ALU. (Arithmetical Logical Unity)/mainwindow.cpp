#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

QString MainWindow::ponerEnHexa(QString v){

        float f = v.toFloat();
        union valor x;
        x.valorReal = f;
        QString hex = QString::number(x.valorEntero, 16);
        hex = hex.toUpper();
        if(x.valorReal <= 1.1754942E-38){
            hex = hex.rightJustified(8, '0');
        }
        else {
            hex = hex.leftJustified(8, '0');
        }

        hex = "0x" + hex;

        return hex;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enHex1_clicked()
{
    ui->valor1Hex->setText(ponerEnHexa(ui->valor1Dec->text()));
}

void MainWindow::on_enHex2_clicked()
{
    ui->valor2Hex->setText(ponerEnHexa(ui->valor2Dec->text()));
}

void MainWindow::on_enIEEE754_1_clicked()
{
    asignarValoresUnion();

    myAlu.setValoresA(a.campos.s, a.campos.e, a.campos.f);

    QString ieeeS = QString::number(a.campos.s,2);
    QString ieeeE = QString::number(a.campos.e,2);
    ieeeE = ieeeE.leftJustified(8, '0');
    QString ieeeF = QString::number(a.campos.f,2);
    ieeeF = ieeeF.rightJustified(23, '0');

    ui->valor1IEEE754->setText(ieeeS+ieeeE+ieeeF);
}

void MainWindow::on_enIEEE754_2_clicked()
{
    asignarValoresUnion();

    myAlu.setValoresB(b.campos.s, b.campos.e, b.campos.f);

    QString ieeeS = QString::number(b.campos.s,2);
    QString ieeeE = QString::number(b.campos.e,2);
    ieeeE = ieeeE.leftJustified(8, '0');
    QString ieeeF = QString::number(b.campos.f,2);
    ieeeF = ieeeF.rightJustified(23, '0');

    ui->valor2IEEE754->setText(ieeeS+ieeeE+ieeeF);
}


void MainWindow::on_bCalcula_clicked()
{
    on_enHex1_clicked();
    on_enHex2_clicked();
    on_enIEEE754_1_clicked();
    on_enIEEE754_2_clicked();

    asignarValoresUnion();

    myAlu.setValoresA(a.campos.s, a.campos.e, a.campos.f);
    myAlu.setValoresB(b.campos.s, b.campos.e, b.campos.f);
    myAlu.setValoresEnteros(a.valorEntero, b.valorEntero);

    if(ui->rBSum->isChecked()){

        // SUMA

        myAlu.suma();
        resultado.campos.s = myAlu.getSignoResultado();
        resultado.campos.e = myAlu.getExponenteResultado();
        resultado.campos.f = myAlu.getFraccionariaResultado();

        /*
         * accedemos a los valores del resultado en float e int de la union
         * donde ya metimos los campos por separado
         */

        // sacamos los resultados en la interfaz
        if(ui->valor1Hex->text() == "0x7FFFFFFF" || ui->valor2Hex->text() == "0x7FFFFFFF"){
            ui->resultDec->setText("NaN");
            ui->resultHex->setText("0x7FFFFFFF");
            ui->resultIEEE754->setText("01111111111111111111111111111111");
        }
        else {
        ui->resultDec->setText(QString::number(resultado.valorReal));
        QString resultHex = "0x" + QString::number(resultado.valorEntero, 16);
        resultHex = resultHex.leftJustified(10, '0');
        ui->resultHex->setText(resultHex.toUpper());
        QString ieee = QString::number(resultado.campos.s,2)+QString::number(resultado.campos.e,2)+QString::number(resultado.campos.f,2);
        ieee = ieee.leftJustified(32, '0');
        ui->resultIEEE754->setText(ieee);}

    } else if(ui->rBPro->isChecked()){

        // PRODUCTO

        myAlu.producto();
        if(myAlu.checkResultadoIndeterminado()){
            ui->resultDec->setText("Indeterminado(NaN)");
            ui->resultHex->setText("0x7FFFFFFF");
            ui->resultIEEE754->setText("01111111111111111111111111111111");
        } else if(myAlu.checkResultadoNaN()){
            ui->resultDec->setText("NaN");
            ui->resultHex->setText("0x7FFFFFFF");
            ui->resultIEEE754->setText("01111111111111111111111111111111");
        } else
        if(myAlu.checkResultadoInfinito()){
            ui->resultDec->setText("OVERFLOW(Infinito)");
            ui->resultHex->setText("0x7F800000");
            ui->resultIEEE754->setText("01111111100000000000000000000000");}
        else if(myAlu.checkResultadoUnderflow()){
            ui->resultDec->setText("UNDERFLOW");
            ui->resultHex->setText("0");
        } else {
            resultado.campos.s = myAlu.getSignoResultado();
            resultado.campos.e = myAlu.getExponenteResultado();
            resultado.campos.f = myAlu.getFraccionariaResultado();

            /*
             * accedemos a los valores del resultado en float e int de la union
             * donde ya metimos los campos por separado
             */

            // sacamos los resultados en la interfaz
            if(ui->valor1Hex->text() == "0x7FFFFFFF" || ui->valor2Hex->text() == "0x7FFFFFFF"){
                ui->resultDec->setText("NaN");
                ui->resultHex->setText("0x7FFFFFFF");
                ui->resultIEEE754->setText("01111111111111111111111111111111");
            }
            else{
            ui->resultDec->setText(QString::number(resultado.valorReal));
            QString resultHex = "0x" + QString::number(resultado.valorEntero, 16);
            resultHex = resultHex.leftJustified(10, '0');
            ui->resultHex->setText(resultHex.toUpper());
            QString ieee = QString::number(resultado.campos.s,2)+QString::number(resultado.campos.e,2)+QString::number(resultado.campos.f,2);
            ieee = ieee.leftJustified(32, '0');
            ui->resultIEEE754->setText(ieee);}

        }
}

     else {

        // DIVISIÓN

        myAlu.division();
        if(myAlu.checkResultadoInfinito()){
            ui->resultDec->setText("Infinito");
            ui->resultHex->setText("0x7F800000");
            ui->resultIEEE754->setText("01111111100000000000000000000000");
        } else if(myAlu.checkResultadoNaN()){
            ui->resultDec->setText("NaN");
            ui->resultHex->setText("0x7FFFFFFF");
            ui->resultIEEE754->setText("01111111111111111111111111111111");
        } else {
            resultado.campos.s = myAlu.getSignoResultado();
            resultado.campos.e = myAlu.getExponenteResultado();
            resultado.campos.f = myAlu.getFraccionariaResultado();

            /*
             * accedemos a los valores del resultado en float e int de la union
             * donde ya metimos los campos por separado
             */

            // sacamos los resultados en la interfaz
            if(ui->valor1Hex->text() == "0x7FFFFFFF" || ui->valor2Hex->text() == "0x7FFFFFFF"){
                ui->resultDec->setText("NaN");
                ui->resultHex->setText("0x7FFFFFFF");
                ui->resultIEEE754->setText("01111111111111111111111111111111");
            }
            else{
            ui->resultDec->setText(QString::number(resultado.valorReal));
            QString resultHex = "0x" + QString::number(resultado.valorEntero, 16);
            resultHex = resultHex.leftJustified(10, '0');
            ui->resultHex->setText(resultHex.toUpper());
            QString ieee = QString::number(resultado.campos.s,2)+QString::number(resultado.campos.e,2)+QString::number(resultado.campos.f,2);
            ieee = ieee.leftJustified(32, '0');
            ui->resultIEEE754->setText(ieee);}
        }
    }
}

void MainWindow::asignarValoresUnion(){
    bool ok1, ok2;

    float vf1 = ui->valor1Dec->text().toFloat(&ok1);
    if (!ok1){
        ui->valor1Dec->setText("NaN or Text Overflow");
        ui->valor1Hex->setText("0x7FFFFFFF");
        ui->valor1IEEE754->setText("01111111111111111111111111111111");
    }
    float vf2 = ui->valor2Dec->text().toFloat(&ok2);
    if (!ok2){
        ui->valor2Dec->setText("NaN or Text Overflow");
        ui->valor2Hex->setText("0x7FFFFFFF");
        ui->valor2IEEE754->setText("01111111111111111111111111111111");
    }


    a.valorReal = vf1;
    b.valorReal = vf2;
}
