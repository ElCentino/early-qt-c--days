#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QConicalGradient grad1(QPoint(100, 100), 90);

    grad1.setColorAt(0.0, Qt::white);
    grad1.setColorAt(0.5, Qt::green);
    grad1.setColorAt(1.0, Qt::black);

    QRect rect(10, 10, 200, 200);
    painter.fillRect(rect, grad1);
}

Dialog::~Dialog()
{
    delete ui;
}
