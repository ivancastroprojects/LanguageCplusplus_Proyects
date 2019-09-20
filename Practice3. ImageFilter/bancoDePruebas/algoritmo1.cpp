#include "algoritmo1.h"
#include "ui_algoritmo1.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <vector>
#include <ctype.h>
#include<cstring>
#include <iostream>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <dos.h>
#include <windows.h>

using namespace std;
//constructor
Algoritmo1::Algoritmo1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Algoritmo1)
{
    ui->setupUi(this);
}

Algoritmo1::~Algoritmo1()
{
    delete ui;
}
/*
  Abre ventana para elegir el archivo que vamos a ordenar
  Lee el QFile y lo transforma en QString
  Guarda los valores en el vector numeros
*/

void Algoritmo1::on_pushButton_clicked()
{
    //fileName : ruta del archivo que eliges. QFileDialog abre una ventana en la que eliges el archivo
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open file"), "",
                                                    tr(".txt (*)"));
    QString line;
    //Abres un archivo con la ruta
    QFile file(fileName);
    //Lo abrimos, si funciona lo pasamos a QString line.
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }else{
        //Con qtextstream obtenemos el texto que haya en file(por eso se lo pasamos como argumento)
        //SE va leyendo cada linea con readLine y se guarda en line
        QTextStream in(&file);
        while (!in.atEnd())
        {
            line = in.readLine();

        }
    }
    //para vaciar numeros
    numeros.clear();


    std::string aux= "";
    //Añade los valores al vector de numeros
    for(int i=0;i<(int)line.length();i++){
        if(line[i].isNumber()){
            if((line[i+1]== ' ')||(i+1 == (int)line.length())){
                if(aux ==""){
                    int b = line[i].digitValue();
                    numeros.push_back(b);
                }else{
                    std::string cadena = "";
                    int b = line[i].digitValue();
                    cadena = std::to_string(b);
                    aux.append(cadena);
                    int def =atoi( aux.c_str() );
                    numeros.push_back(def);


                    aux="";
                }
            }else{
                std::string cadena = "";
                int b = line[i].digitValue();
                cadena = std::to_string(b);
                aux.append(cadena);

            }

        }
    }

}

/*Ordena numeros
 *Devuelve el tiempo que tarda en hacerlo
 *Pone el resultado en el espacio de texto
 */

double Algoritmo1::t_ordenacion(){
    int temp;
    //LARGE_INTEGER t_ini, t_fin;
    clock_t t1, t2;
    //QueryPerformanceCounter(&t_ini);
    t1 = clock();
    for (int i=0; i<(int)numeros.size(); i++){
        for (int  j=0 ; j<(int)numeros.size() - 1; j++){
            if (numeros[j] > numeros[j+1]){
                temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temp;
            }
        }
    }
    t2 = clock();

    double time = (double)(t2-t1)/CLK_TCK;

    QString result;
    for (int i=0; i<(int)numeros.size(); i++){
        QString s = QString::number(numeros[i]);
        result.append(s);
        result.append(" ");
    }
    //pongo resultado en el cuadrado grande
    ui->textEdit->setText(result);

    return time;
}

//5 botones para obtener resultados
void Algoritmo1::on_pushButton_2_clicked()
{
    double t = t_ordenacion();
    QString s = QString::number(t);

    ui->lineEdit->setText(s);
}


void Algoritmo1::on_pushButton_3_clicked()
{
    double t = t_ordenacion();
    QString s = QString::number(t);

    ui->lineEdit_2->setText(s);
}

void Algoritmo1::on_pushButton_4_clicked()
{
    double t = t_ordenacion();
    QString s = QString::number(t);

    ui->lineEdit_3->setText(s);
}
void Algoritmo1::on_pushButton_5_clicked()
{
    double t = t_ordenacion();
    QString s = QString::number(t);

    ui->lineEdit_4->setText(s);
}
void Algoritmo1::on_pushButton_6_clicked()
{
    double t = t_ordenacion();
    QString s = QString::number(t);

    ui->lineEdit_5->setText(s);
}
