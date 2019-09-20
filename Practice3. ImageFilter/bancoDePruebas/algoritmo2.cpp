#include "algoritmo2.h"
#include "ui_algoritmo2.h"
#include <QDir>
#include <QFileDialog>
#include <time.h>
#include <QColor>

using namespace std;


Algoritmo2::Algoritmo2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Algoritmo2)
{
    ui->setupUi(this);
}

Algoritmo2::~Algoritmo2()
{
    delete ui;
}

//Guarda en dir el path de la carpeta elegida
void Algoritmo2::on_buscarCarpeta_clicked()
{
    dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                            "/home",
                                            QFileDialog::ShowDirsOnly
                                            | QFileDialog::DontResolveSymlinks);
    ui->path->setText(dir);

}

QImage Algoritmo2::tratar_imagenes(QImage img){
    QSize sizeImage=img.size();
    int width=sizeImage.width(), height=sizeImage.height();
    for(int j=0; j<5; j++){

        QRgb color;
        for (int f=0; f<width; f++) {
            for (int i=0; i<height; i++){
                color=img.pixel(f,i);
               // blue=(qRed(color)+qGreen(color)+qBlue(color))/3;
               int r = qRed(color);
                int g = qGreen(color);
                int b = qBlue(color);
                int tr = (int)(0.493*r + 0.369*g + 0.189*b);
                int tb = (int)(0.272*r + 0.534*g + 0.431*b);
                 if(tr > 255){
                  r = 255;
                }else{
                  r = tr;
                }
                 /*if(tg > 255){
                  g = 255;
                }else{
                  g = tg;
                }*/
               if(tb > 255){
                  b = 255;
                }else{
                  b = tb;
                }
                img.setPixel(f,i,qRgb(r,g,b));
                //img.setPixel(f,i,qRgb(blue,blue,blue));


            }
        }

    }



    return img;



}


void Algoritmo2::recorrerCarpeta(){
    //Guarda en list (QFileINfoList) todas las imagenes que haya en path(QDir)
    QDir path(dir);
    QStringList nameFilter;
    nameFilter << "*.png" << "*.jpg" << "*.gif";
    QFileInfoList list = path.entryInfoList( nameFilter, QDir::Files );

    img.clear();


    //Creamos la carpeta donde se guardarn los resultados;
   int nuevaCarpeta = 0;
   bool exist = true;
   QString newDir;
   do{
       newDir = dir;
       QString nueva = QString::number(nuevaCarpeta);
       newDir.append("/");
       newDir.append(nueva);
       nuevaCarpeta++;
       exist = QDir(newDir).exists();
   }while(exist == true);
   QDir().mkdir(newDir);

    //Recorremos lista
    for(int i=0;i<(int)list.size();i++){
        QString path = list.at(i).absoluteFilePath();
        QImage image(path);
        QImage nueva = this->tratar_imagenes(image);
        QString s = newDir;
        s.append("/");
        QString aux = QString::number(i);
        s.append(aux);
        s.append(".png");
        nueva.save(s);
        img.push_back(image);

    }


}


void Algoritmo2::on_tBut1_clicked()
{
    clock_t t1, t2;
    t1 = clock();
    recorrerCarpeta();
    t2 = clock();

    double time = (double)(t2-t1)/CLK_TCK;
    QString s = QString::number(time);

    ui->tText1->setText(s);

}

void Algoritmo2::on_pushButton_clicked()
{
    clock_t t1, t2;
    t1 = clock();
    recorrerCarpeta();
    t2 = clock();

    double time = (double)(t2-t1)/CLK_TCK;

    QString s = QString::number(time);

    ui->lineEdit_2->setText(s);

}

void Algoritmo2::on_pushButton_2_clicked()
{
    clock_t t1, t2;
    t1 = clock();
    recorrerCarpeta();
    t2 = clock();

    double time = (double)(t2-t1)/CLK_TCK;

    QString s = QString::number(time);

    ui->lineEdit->setText(s);

}

void Algoritmo2::on_pushButton_3_clicked()
{
    clock_t t1, t2;
    t1 = clock();
    recorrerCarpeta();
    t2 = clock();

    double time = (double)(t2-t1)/CLK_TCK;

    QString s = QString::number(time);

    ui->lineEdit_3->setText(s);

}

void Algoritmo2::on_pushButton_4_clicked()
{
    clock_t t1, t2;
    t1 = clock();
    recorrerCarpeta();
    t2 = clock();

    double time = (double)(t2-t1)/CLK_TCK;

    QString s = QString::number(time);

    ui->lineEdit_4->setText(s);

}
