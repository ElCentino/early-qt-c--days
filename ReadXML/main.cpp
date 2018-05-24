#include <QCoreApplication>
#include <QDebug>
#include <QtCore>
#include <QtXml>
#include <iostream>

void loadDom(QDomElement root, QString tagname, QString attr);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDomDocument document;

    QFile file("C:/Users/User/Desktop/books.xml");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    qDebug() << "File existance : " << file.exists() << "\n";

    document.setContent(&file);

    QTextStream in(&file);

    in >> document.toString();

    qDebug() << "File contents set to : " << file.fileName() << "\n";

    QDomElement root = document.firstChildElement();

    loadDom(root, "Book", "Name");

    QDomNodeList node = root.elementsByTagName("Book");

    qDebug() << "Number of inner elements : " << node.count() << "\n";

    for(int i = 0; i < node.count(); i++)
    {
        QDomNode note = node.at(i);

        QDomElement book = note.toElement();

        qDebug() << "Chapter in " << book.attribute("Name") << "\n";

        loadDom(book, "Chapter", "Name");
    }

    return a.exec();
}

void loadDom(QDomElement root, QString tagname, QString attr) {

    QDomNodeList node = root.elementsByTagName(tagname);

    qDebug() << "Top Level Elements : " << node.count() << "\n";

    for(int i = 0; i < node.count(); i++)
    {
        QDomNode note = node.at(i);

        qDebug() << note.toElement().attribute(attr) << " \t||\t ID " << note.toElement().attribute("ID") << "\n";
    }
}
