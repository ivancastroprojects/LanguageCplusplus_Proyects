#ifndef ALGORITMO1_H
#define ALGORITMO1_H
#include <vector>
#include <QMainWindow>

namespace Ui {
class Algoritmo1;
}

class Algoritmo1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Algoritmo1(QWidget *parent = 0);
    ~Algoritmo1();
    double t_ordenacion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



private:
    Ui::Algoritmo1 *ui;
    std::vector <int> numeros;

};

#endif // ALGORITMO1_H
