#include "window.h"
#include <QApplication>
#include <QtCore>
#include <QDebug>

int main(int argc, char *argv[])
{
    QString initText;
    QString titletest;
    QString title;

    QApplication a(argc, argv);

    for(int i = 0; i < argc; i++)
    {

        titletest = (QString)argv[0];

        QString the = (QString)argv[i];

        QFile file(the);

        title = the;

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {

        } else
        {
            QTextStream in(&file);

            QString text = in.readAll();

            initText = text;
        }

        file.close();

    }

    qDebug() << initText;

    MainWindow w(initText);

    if(title == titletest)
    {
        w.setWindowTitle("untitled - Notepad CS");
    } else
    {
        w.setWindowTitle(title);
    }


    w.show();

    return a.exec();
}
