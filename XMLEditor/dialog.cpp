#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    file_name = "C:/Users/User/Desktop/books.xml";

    model = new QStandardItemModel(0, 1, this);

    readFile();

    ui->treeView->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::readFile()
{
   QStandardItem *root = new QStandardItem("Books");
   model->appendRow(root);

   QDomDocument document;

   QFile file(file_name);

   if(file.open(QIODevice::ReadOnly | QIODevice::Text))
   {
       document.setContent(&file);
       file.close();
   }

   QDomElement xmlroot = document.firstChildElement();

   QDomNodeList books = xmlroot.elementsByTagName("Book");

   for(int i = 0; i < books.count(); i++)
   {
       QDomElement book = books.at(i).toElement();

       QStandardItem *bookitem = new QStandardItem(book.attribute("Name"));

       QDomNodeList chapters = book.elementsByTagName("Chapter");

       for(int h = 0; h < chapters.count(); h++)
       {
           QDomElement chapter = chapters.at(h).toElement();
           QStandardItem *chapterItem = new QStandardItem(chapter.attribute("Name"));

           bookitem->appendRow(chapterItem);
       }

       root->appendRow(bookitem);
   }
}

void Dialog::saveFile()
{
    QDomDocument document;

    QDomElement xmlroot = document.createElement("Books");
    document.appendChild(xmlroot);

    QStandardItem *root = model->item(0,0);

    for(int i = 0; i < root->row(); i++)
    {
        QStandardItem *book = root->child(i, 0);

        QDomElement xmlbook = document.createElement("Book");
        xmlbook.setAttribute("Name", book->text());
        xmlbook.setAttribute("ID", i);

        xmlroot.appendChild(xmlbook);

        for(int h = 0; h < book->rowCount(); h++)
        {
            QStandardItem *chapter = book->child(h, 0);
            QDomElement xmlchapter = document.createElement("Chapter");
            xmlchapter.setAttribute("Name", chapter->text());
            xmlchapter.setAttribute("ID", h);

            xmlbook.appendChild(xmlchapter);

        }
    }

    QFile file(file_name);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Error reading file";
    } else
    {

    QTextStream out(&file);
    out << document.toString();
    file.close();

    }
}

void Dialog::on_pushButton_clicked()
{
    saveFile();
}
