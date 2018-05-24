#include "about.h"
#include <QSpacerItem>
#include <QAction>
#include <QMessageBox>

About::About(QWidget *parent) : QDialog(parent)
{

    resize(400, 300);

    createContextMenu();

    title = new QLabel("<p style='font-family:comic sans ms; color:blue; font-size:18px;'><b><u>Notepad CS</u></b>");

    img = new QLabel();

    QPixmap pmap(":/images/images/notepadWall.png");

    img->setPixmap(pmap);
    img->resize(200, 200);

    text = tr("<p style='font-size:14px;'>Copyright &copy; 2014 <b>Dol Inc</b>.</p>"
              "<p style='font-size:14px;'>Notepad CS is a small and simple text editor that</p>"
              "<p style='font-size:14px;'>demonstrates the effective use of Qt in C++ programming</p>"
              "<p></p>"
              "<p style = 'color:green;'><b>Created By Favour Tchid</b></p>");

    dialogText = new QLabel(text);

    sp = new QSpacerItem(10, 0);
    sp2 = new QSpacerItem(0, 30);

    top = new QHBoxLayout();
    top->addSpacerItem(sp2);
    top->addSpacerItem(sp);
    top->addWidget(img);
    top->addSpacerItem(sp);
    top->addWidget(title);
    top->addSpacerItem(sp);

    cen = new QVBoxLayout();
    cen->addSpacerItem(sp2);

    butt = new QVBoxLayout();
    butt->addLayout(top);
    butt->addLayout(cen);
    butt->addWidget(dialogText);
    cen->addSpacerItem(sp2);

    setLayout(butt);

    setWindowTitle("About Notepad CS");
    setWindowIcon(QIcon(":/images/images/About.png"));
}

void About::versionDialog()
{
    QMessageBox::information(this, "Version", "Notepad CS 1.0v");
}

void About::createContextMenu()
{
    version = new QAction("Version", this);
    version->setIcon(QIcon(":/images/images/About.png"));
    connect(version, SIGNAL(triggered()), this, SLOT(versionDialog()));

    exit = new QAction("Close", this);
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));

    separator = new QAction(this);
    separator->setSeparator(true);

    addAction(version);
    addAction(separator);
    addAction(exit);

    setContextMenuPolicy(Qt::ActionsContextMenu);
}

About::~About()
{
    delete title;
    delete dialogText;
    delete top;
    delete sp;
    delete sp2;
    delete cen;
    delete butt;
}
