/********************************************************************************
** Form generated from reading UI file 'algoritmo2.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALGORITMO2_H
#define UI_ALGORITMO2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Algoritmo2
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QPushButton *buscarCarpeta;
    QLineEdit *path;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QPushButton *tBut1;
    QLineEdit *tText1;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Algoritmo2)
    {
        if (Algoritmo2->objectName().isEmpty())
            Algoritmo2->setObjectName(QStringLiteral("Algoritmo2"));
        Algoritmo2->resize(474, 353);
        centralwidget = new QWidget(Algoritmo2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        buscarCarpeta = new QPushButton(centralwidget);
        buscarCarpeta->setObjectName(QStringLiteral("buscarCarpeta"));

        formLayout->setWidget(1, QFormLayout::LabelRole, buscarCarpeta);

        path = new QLineEdit(centralwidget);
        path->setObjectName(QStringLiteral("path"));

        formLayout->setWidget(1, QFormLayout::FieldRole, path);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        tBut1 = new QPushButton(centralwidget);
        tBut1->setObjectName(QStringLiteral("tBut1"));

        formLayout->setWidget(4, QFormLayout::LabelRole, tBut1);

        tText1 = new QLineEdit(centralwidget);
        tText1->setObjectName(QStringLiteral("tText1"));

        formLayout->setWidget(4, QFormLayout::FieldRole, tText1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(5, QFormLayout::LabelRole, pushButton);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_2);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        formLayout->setWidget(6, QFormLayout::LabelRole, pushButton_2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        formLayout->setWidget(7, QFormLayout::LabelRole, pushButton_3);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        formLayout->setWidget(8, QFormLayout::LabelRole, pushButton_4);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_4);


        verticalLayout->addLayout(formLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        Algoritmo2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Algoritmo2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 474, 21));
        Algoritmo2->setMenuBar(menubar);
        statusbar = new QStatusBar(Algoritmo2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Algoritmo2->setStatusBar(statusbar);

        retranslateUi(Algoritmo2);

        QMetaObject::connectSlotsByName(Algoritmo2);
    } // setupUi

    void retranslateUi(QMainWindow *Algoritmo2)
    {
        Algoritmo2->setWindowTitle(QApplication::translate("Algoritmo2", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("Algoritmo2", "Carpeta:", Q_NULLPTR));
        buscarCarpeta->setText(QApplication::translate("Algoritmo2", "Busca", Q_NULLPTR));
        label_2->setText(QApplication::translate("Algoritmo2", "Tiempo de ejecucion:", Q_NULLPTR));
        tBut1->setText(QApplication::translate("Algoritmo2", "Ejecutar", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Algoritmo2", "Ejecutar", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Algoritmo2", "Ejecutar", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Algoritmo2", "Ejecutar", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Algoritmo2", "Ejecutar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Algoritmo2: public Ui_Algoritmo2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALGORITMO2_H
