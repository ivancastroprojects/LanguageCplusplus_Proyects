#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoritmo1.h"
#include "algoritmo2.h"
#include "ag1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    ag1.show();
}
void MainWindow::on_pushButton_2_clicked()
{

    ag2.show();
}

void MainWindow::on_pushButton_2_pressed()
{

}
