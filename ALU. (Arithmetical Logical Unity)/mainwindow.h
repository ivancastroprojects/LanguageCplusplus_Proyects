#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <alu.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // el struct son los campos
    struct ieee754{
        unsigned int f:23;
        unsigned int e:8;
        unsigned int s:1;
    };

    QString ponerEnHexa(QString v);

    void asignarValoresUnion();


private slots:
    void on_enHex1_clicked();

    void on_enHex2_clicked();

    void on_bCalcula_clicked();

    void on_enIEEE754_2_clicked();

    void on_enIEEE754_1_clicked();

private:
    Ui::MainWindow *ui;

    alu myAlu;
    // union que contiene el numero metido en valorReal y en lo demás
    union valor{
        struct ieee754 campos;
        float valorReal;
        unsigned int valorEntero;
    };

    union valor a;
    union valor b;
    union valor resultado;
};

#endif // MAINWINDOW_H
