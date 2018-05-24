#include "window.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QFontDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "about.h"
#include "finddialog.h"
#include "replacedialog.h"
#include "gotoline.h"

MainWindow::MainWindow(QString initText, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(780,530);

    Initialize();
    createContextMenu();
    readInitFile(initText);

    title = "Notepad CS";
}

void MainWindow::readInitFile(QString initText)
{
    if(initText.contains("!This program cannot be run in DOS mode.") || initText.endsWith("1È1è1") || initText.startsWith("MZ"))
    {
        plaintext->setPlainText("");
        qDebug() << "true";
        return;
    }

    plaintext->setPlainText(initText);
}

void MainWindow::Initialize()
{
    menu = new QMenuBar(this);

    newFile = new QAction("New", this);
    newFile->setIcon(QIcon(":/images/images/New document.png"));
    newFile->setShortcut(QKeySequence::New);
    newFile->setStatusTip("New");
    connect(newFile, SIGNAL(triggered()), this, SLOT(createNewFile()));

    open = new QAction("Open", this);
    open->setIcon(QIcon(":/images/images/Folder.png"));
    open->setShortcut(QKeySequence::Open);
    open->setStatusTip("Open");
    connect(open, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAs = new QAction("Save As", this);
    saveAs->setIcon(QIcon(":/images/images/Save.png"));
    saveAs->setShortcut(QKeySequence::SaveAs);
    saveAs->setStatusTip("Save As");
    connect(saveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    save = new QAction("Save", this);
    save->setIcon(QIcon(":/images/images/Save.png"));
    save->setShortcut(QKeySequence::Save);
    save->setStatusTip("Save");
    connect(save, SIGNAL(triggered()), this, SLOT(saveFile()));

    paste = new QAction("Paste", this);
    paste->setIcon(QIcon(":/images/images/Paste.png"));
    paste->setShortcut(QKeySequence::Paste);
    paste->setStatusTip("Paste");
    connect(paste, SIGNAL(triggered()), this, SLOT(pasteText()));

    copy = new QAction("Copy", this);
    copy->setIcon(QIcon(":/images/images/Copy.png"));
    copy->setShortcut(QKeySequence::Copy);
    copy->setStatusTip("Copy");
    connect(copy, SIGNAL(triggered()), this, SLOT(copyText()));

    cut = new QAction("Cut", this);
    cut->setIcon(QIcon(":/images/images/Cut.png"));
    cut->setShortcut(QKeySequence::Cut);
    cut->setStatusTip("Cut");
    connect(cut, SIGNAL(triggered()), this, SLOT(cutText()));

    undo = new QAction("Undo", this);
    undo->setIcon(QIcon(":/images/images/Undo.png"));
    undo->setShortcut(QKeySequence::Undo);
    undo->setStatusTip("Undo");
    connect(undo, SIGNAL(triggered()), this, SLOT(undoAction()));

    redo = new QAction("Redo", this);
    redo->setIcon(QIcon(":/images/images/Redo.png"));
    redo->setShortcut(QKeySequence::Redo);
    redo->setStatusTip("Redo");
    connect(redo, SIGNAL(triggered()), this, SLOT(redoAction()));

    wordWrap = new QAction("Word wrap", this);
    wordWrap->setCheckable(true);
    wordWrap->setChecked(true);
    wordWrap->setStatusTip("Enable Word Wrap");
    connect(wordWrap, SIGNAL(triggered()), this, SLOT(wrapWords()));

    font = new QAction("Font...", this);
    font->setStatusTip("Set Font");
    connect(font, SIGNAL(triggered()), this, SLOT(selectFont()));

    separator = new QAction(this);
    separator->setSeparator(true);

    separatorb = new QAction(this);
    separatorb->setSeparator(true);

    showToolBar = new QAction("Show Toolbar", this);
    showToolBar->setCheckable(true);
    showToolBar->setChecked(true);
    showToolBar->setStatusTip("Show Toolbar");
    connect(showToolBar, SIGNAL(triggered()), this, SLOT(displayToolBar()));

    showStatusBar = new QAction("Show Statusbar", this);
    showStatusBar->setCheckable(true);
    showStatusBar->setChecked(true);
    showStatusBar->setStatusTip("Show Statusbar");
    connect(showStatusBar, SIGNAL(triggered()), this, SLOT(displayStatusBar()));

    find = new QAction("Find...", this);
    find->setShortcut(QKeySequence::Find);
    find->setStatusTip("Find");
    connect(find, SIGNAL(triggered()), this, SLOT(openFindDialog()));

    gotoline = new QAction("Go To...", this);
    gotoline->setShortcut(tr("Ctrl+G"));
    gotoline->setStatusTip("Goto Line");
    connect(gotoline,SIGNAL(triggered()), this, SLOT(openGotoLineDialog()));

    replace = new QAction("Replace...", this);
    replace->setShortcut(tr("Ctrl+R"));
    replace->setStatusTip("Replace");
    connect(replace, SIGNAL(triggered()), this, SLOT(openReplaceDialog()));

    about = new QAction("About Notepad", this);
    about->setIcon(QIcon(":/images/images/About.png"));
    about->setStatusTip("About Notepad");
    connect(about, SIGNAL(triggered()), this, SLOT(aboutMyApp()));

    exit = new QAction("Exit", this);
    exit->setIcon(QIcon(":/images/images/Exit.png"));
    exit->setStatusTip("Exit");
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));

    file = new QMenu("File", this);
    file->addAction(newFile);
    file->addAction(open);
    file->addSeparator();
    file->addAction(save);
    file->addAction(saveAs);
    file->addSeparator();
    file->addAction(exit);

    edit = new QMenu("Edit", this);
    edit->addAction(copy);
    edit->addAction(cut);
    edit->addAction(paste);
    edit->addSeparator();
    edit->addAction(find);
    edit->addAction(replace);
    edit->addAction(gotoline);
    edit->addSeparator();
    edit->addAction(undo);
    edit->addAction(redo);

    format = new QMenu("Format", this);
    format->addAction(wordWrap);
    format->addAction(font);

    view = new QMenu("View", this);
    view->addAction(showToolBar);
    view->addAction(showStatusBar);

    help = new QMenu("Help", this);
    help->addAction(about);

    ui->mainToolBar->addAction(newFile);
    ui->mainToolBar->addAction(open);
    ui->mainToolBar->addAction(save);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(copy);
    ui->mainToolBar->addAction(cut);
    ui->mainToolBar->addAction(paste);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(undo);
    ui->mainToolBar->addAction(redo);

    menu->addMenu(file);
    menu->addMenu(edit);
    menu->addMenu(format);
    menu->addMenu(view);
    menu->addMenu(help);

    plaintext = new QPlainTextEdit();
    plaintext->setFont(QFont("Consolas", 13));
    connect(plaintext, SIGNAL(textChanged()), this, SLOT(getAllText()));

    QTextCursor textcursor = plaintext->textCursor();
    textcursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);

    setStatusTip("Ready");
    setCentralWidget(plaintext);
    setMenuBar(menu);

}

void MainWindow::createNewFile()
{
    currentFile = "";

    plaintext->setPlainText("");

    if(currentFile.isEmpty())
        currentFile = "untitled - Notepad CS";
    setWindowTitle(currentFile);
}

void  MainWindow::openFile()
{
    QString file = QFileDialog::getOpenFileName(this, "Open", "C:/", "Text Documents(*.txt);; Notepad CS Documents(*.ncs);; All Files(*.*)");

    currentFile = file;

    setWindowTitle(currentFile);

    fileToWtrite = new QFile(currentFile);

    if(!fileToWtrite->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        currentFile = "untitled - Notepad CS";

        setWindowTitle(currentFile);
    } else
    {
        QTextStream in(fileToWtrite);

        edittext = in.readAll();

        plaintext->setPlainText(edittext);
    }

    setCurrentFile(file);

    fileToWtrite->close();
}

void  MainWindow::saveFile()
{
    if(currentFile == "" || currentFile == "untitled - Notepad CS")
        saveFileAs();

    fileToWtrite = new QFile(currentFile);

    if(!fileToWtrite->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        currentFile = "untitled - Notepad CS";

        setWindowTitle(currentFile);

    } else
    {

        QTextStream out(fileToWtrite);

        out << plaintext->toPlainText();
    }

    fileToWtrite->flush();


    fileToWtrite->close();

    setCurrentFile(currentFile);

    ui->statusBar->showMessage("Saved", 3000);
}

void  MainWindow::saveFileAs()
{

     QString file = QFileDialog::getSaveFileName(this, "Save As", QDir::currentPath(), "Notepad CS(*.ncs);; Text Documents(*.txt) ;; All Files(*.*)");

     currentFile = file;

     fileToWtrite = new QFile(currentFile);

     if(!fileToWtrite->open(QIODevice::WriteOnly | QIODevice::Text))
     {
         currentFile = "untitled - Notepad CS";
         setWindowTitle(currentFile);
     } else
     {
         QTextStream out(fileToWtrite);

         out << plaintext->toPlainText();
     }

     fileToWtrite->flush();
     fileToWtrite->close();

     setWindowTitle(currentFile);
     setCurrentFile(file);
     ui->statusBar->showMessage("Saved", 3000);
}

void  MainWindow::copyText()
{
    plaintext->copy();
}

void  MainWindow::cutText()
{
    plaintext->cut();
}

void  MainWindow::pasteText()
{
    plaintext->paste();
}

void  MainWindow::redoAction()
{
    plaintext->redo();
}

void  MainWindow::undoAction()
{
    plaintext->undo();
}

void  MainWindow::selectFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Consolas", 13), this);

    if(ok)
    {
        plaintext->setFont(font);
    }
}

void  MainWindow::wrapWords()
{
    if(wordWrap->isChecked())
    {
        plaintext->setWordWrapMode(QTextOption::WrapAnywhere);
    } else
    {
        plaintext->setWordWrapMode(QTextOption::NoWrap);
    }
}

void  MainWindow::aboutMyApp()
{
    About *about = new About(this);
    about->setModal(true);
    about->show();
}

void MainWindow::displayToolBar()
{
    if(showToolBar->isChecked())
    {
        ui->mainToolBar->setVisible(true);
    } else
    {
        ui->mainToolBar->setVisible(false);
    }
}

void MainWindow::displayStatusBar()
{
    ui->statusBar->setVisible(showStatusBar->isChecked());
}

void MainWindow::openFindDialog()
{
    FindDialog *find = new FindDialog(this);
    find->setModal(true);
    find->show();
}

void MainWindow::openGotoLineDialog()
{
    GotoLine *gotoline = new GotoLine(this);
    gotoline->setModal(true);
    gotoline->show();
}

void MainWindow::printPage()
{

}

void MainWindow::getAllText()
{
    file_text = plaintext->toPlainText();

    qDebug() << file_text;
}

void MainWindow::openReplaceDialog()
{
    ReplaceDialog *replace = new ReplaceDialog(this);
    replace->setModal(true);
    replace->show();
}

void MainWindow::createContextMenu()
{
    addAction(copy);
    addAction(cut);
    addAction(paste);
    addAction(separator);
    addAction(undo);
    addAction(redo);
    addAction(separatorb);
    addAction(showToolBar);
    addAction(showStatusBar);

    setContextMenuPolicy(Qt::ActionsContextMenu);
}

QString MainWindow::getCurrentFile()
{
    return currentFile;
}

void MainWindow::setCurrentFile(QString currentFile)
{
    this->currentFile = currentFile;
}

QString MainWindow::getPlainTextText()
{
    return plaintext->toPlainText();
}

void MainWindow::edittedText(QString text)
{
    text = file_text;

    qDebug() << text;
    emit editedText(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}
