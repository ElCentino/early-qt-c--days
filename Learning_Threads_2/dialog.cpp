#include "dialog.h"
#include "ui_dialog.h"
#include "threading.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setFixedSize(sizeHint().width() + 40, sizeHint().height());

    thread = new Threading();

    connect(thread, SIGNAL(numberSent(int)), this, SLOT(numberRecieved(int)));

    setWindowTitle("Thread Timmer");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::numberRecieved(int num)
{
    ui->label->setText(QString::number(num));
}

void Dialog::on_start_clicked()
{
    thread->stop = false;
    thread->start();
}

void Dialog::on_stop_clicked()
{
    thread->stop = true;
}
