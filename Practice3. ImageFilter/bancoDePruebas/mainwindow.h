#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "algoritmo1.h"
#include "algoritmo2.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_2_pressed();

private:
    Ui::MainWindow *ui;
    Algoritmo1 ag1;
    Algoritmo2 ag2;
};

#endif // MAINWINDOW_H
