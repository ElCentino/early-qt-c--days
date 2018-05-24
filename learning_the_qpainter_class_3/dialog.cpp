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

    QPen pen(Qt::blue);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setWidth(4);

    QPolygon poly;

    poly << QPoint(10, 10);
    poly << QPoint(10, 100);
    poly << QPoint(100, 10);
    poly << QPoint(100, 100);

    QBrush brush(Qt::green, Qt::SolidPattern);

    QPainterPath path;
    path.addPolygon(poly);

    painter.setPen(pen);
    painter.drawPolygon(poly);
    painter.fillPath(path, brush);

}

Dialog::~Dialog()
{
    delete ui;
}
