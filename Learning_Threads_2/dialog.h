#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "threading.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    Threading *thread;

private slots:
    void numberRecieved(int);
    void on_start_clicked();
    void on_stop_clicked();
};

#endif // DIALOG_H
