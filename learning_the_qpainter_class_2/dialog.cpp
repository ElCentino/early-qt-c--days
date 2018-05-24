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

    QRect rect(10, 10, 200, 200);

    QPen framepen(Qt::red);
    framepen.setWidth(4);

    QBrush brush(Qt::blue, Qt::DiagCrossPattern);

    painter.setPen(framepen);
    painter.drawRect(rect);
    painter.drawEllipse(rect);
    painter.fillRect(rect, brush);
}

Dialog::~Dialog()
{
    delete ui;
}
