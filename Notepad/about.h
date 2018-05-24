#ifndef ABOUT_H
#define ABOUT_H

#include <QtGui>
#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class About : public QDialog
{
    Q_OBJECT

public:
    About(QWidget *parent = 0);
    ~About();

private:
    void createContextMenu();
    QLabel *title;
    QLabel *dialogText;
    QLabel *img;
    QString text;
    QAction *version;
    QAction *exit;
    QAction *separator;
    QHBoxLayout *top;
    QVBoxLayout *butt;
    QVBoxLayout *cen;
    QSpacerItem *sp;
    QSpacerItem *sp2;
private slots:
    void versionDialog();
};

#endif // ABOUT_H
