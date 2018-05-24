#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QtGui>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include "window.h"

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);
    ~FindDialog();

private:
    QLabel *searchLabel;
    QLineEdit *searchBox;
    QPushButton *search;
    QPushButton *cancel;
    QCheckBox *matchCase;
    QCheckBox *searchBackward;
    QHBoxLayout *topLeft;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QHBoxLayout *mainLayout;

    MainWindow *window;

    QString maintext;

private slots:
    void enableCancelButton();
    void findText();
    void isEdited(QString);
};

#endif // FINDDIALOG_H
