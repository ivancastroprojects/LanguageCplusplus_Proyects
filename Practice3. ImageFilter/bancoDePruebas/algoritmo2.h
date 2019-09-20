#ifndef ALGORITMO2_H
#define ALGORITMO2_H

#include <QMainWindow>
#include <vector>
#include <qimage.h>
using namespace std;

namespace Ui {
class Algoritmo2;
}

class Algoritmo2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Algoritmo2(QWidget *parent = 0);
    ~Algoritmo2();
     void recorrerCarpeta();
     void setImages();
     QImage tratar_imagenes(QImage img);


private slots:
    void on_buscarCarpeta_clicked();

    void on_tBut1_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Algoritmo2 *ui;
    vector <QString> images_path;
    vector <QImage> img;
    QString dir;
};

#endif // ALGORITMO2_H
