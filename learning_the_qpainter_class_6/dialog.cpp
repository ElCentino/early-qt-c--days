#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPen redPen(Qt::red);
    redPen.setWidth(5);

    QPen greenPen(Qt::green);
    greenPen.setWidth(5);

    QBrush yellow(Qt::yellow);
    QBrush blue(Qt::blue);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);

    ellipse = scene->addEllipse(10, 10, 100, 100, redPen, yellow);

    rectangle = scene->addRect(-100, -100, 50, 50, greenPen, blue);

    QThread t(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    ui->graphicsView->rotate(-10);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->graphicsView->rotate(10);
}
