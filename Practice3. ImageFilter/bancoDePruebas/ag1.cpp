#include "ag1.h"
#include "ui_ag1.h"

ag1::ag1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ag1)
{
    ui->setupUi(this);
}

ag1::~ag1()
{
    delete ui;
}
