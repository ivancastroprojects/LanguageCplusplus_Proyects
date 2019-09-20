#ifndef AG1_H
#define AG1_H

#include <QWidget>

namespace Ui {
class ag1;
}

class ag1 : public QWidget
{
    Q_OBJECT

public:
    explicit ag1(QWidget *parent = 0);
    ~ag1();

private:
    Ui::ag1 *ui;
};

#endif // AG1_H
