#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QLinearGradient>
#include <QRadialGradient>
#include <QConicalGradient>

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

protected:
    void paintEvent(QPaintEvent *e);
};

#endif // DIALOG_H
