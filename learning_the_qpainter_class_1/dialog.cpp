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

    QPen pen1;
    pen1.setWidth(4);
    pen1.setColor(Qt::red);

    QPen pen2;
    pen2.setWidth(6);
    pen2.setColor(Qt::blue);

    QPoint p1;
    p1.setX(10);
    p1.setY(10);

    QPoint p2;
    p2.setX(100);
    p2.setY(100);

    painter.setPen(pen1);
    painter.drawLine(p1, p2);

    painter.setPen(pen2);
    painter.drawPoint(p1);
    painter.drawPoint(p2);
}

Dialog::~Dialog()
{
    delete ui;
}
