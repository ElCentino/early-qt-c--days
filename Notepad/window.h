#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QPlainTextEdit>
#include <QStatusBar>
#include <QFont>
#include <QtCore>
#include <QFile>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include "settings.h"

class QMenuBar;
class QMenu;
class QAction;
class QPlainTextEdit;
class QFont;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString initText = 0, QWidget *parent = 0);
    ~MainWindow();
    QString getCurrentFile();
    QString file_text;
    void setCurrentFile(QString currentFile);
    QString getPlainTextText();
    void edittedText(QString);

private slots:
    void createNewFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void copyText();
    void cutText();
    void pasteText();
    void redoAction();
    void undoAction();
    void selectFont();
    void wrapWords();
    void aboutMyApp();
    void displayToolBar();
    void displayStatusBar();
    void openFindDialog();
    void openReplaceDialog();
    void openGotoLineDialog();
    void printPage();
    void getAllText();

signals:
    void editedText(QString);

private:
    Ui::MainWindow *ui;
    void Initialize();
    void createContextMenu();
    void readInitFile(QString initText = 0);

    Settings *settings;

    QString Dfile;
    QString title;
    QString currentFile;
    QString edittext;

    QMenuBar *menu;
    QMenu *file;
    QMenu *edit;
    QMenu *format;
    QMenu *view;
    QMenu *help;

    QAction *exit;
    QAction *save;
    QAction *paste;
    QAction *copy;
    QAction *newFile;
    QAction *open;
    QAction *saveAs;
    QAction *cut;
    QAction *undo;
    QAction *redo;
    QAction *wordWrap;
    QAction *font;
    QAction *gotoline;
    QAction *replace;
    QAction *find;
    QAction *about;
    QAction *showToolBar;
    QAction *showStatusBar;
    QAction *separator;
    QAction *separatorb;

    QPlainTextEdit *plaintext;

    QFile *fileToWtrite;
    QFile *settingsFile;

};

#endif // MAINWINDOW_H
