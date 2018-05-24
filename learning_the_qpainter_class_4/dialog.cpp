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

     QPen pen(Qt::black);
     pen.setWidth(15);

     QPoint p1(20, 30);
     QPoint p2(200, 30);

     pen.setCapStyle(Qt::SquareCap);
     painter.setPen(pen);
     painter.drawLine(p1, p2);

}

Dialog::~Dialog()
{
    delete ui;
}
