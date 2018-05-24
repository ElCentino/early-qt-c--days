#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent) : QDialog(parent)
{

    searchLabel = new QLabel(tr("Find What"));
    searchBox = new QLineEdit(this);
    search = new QPushButton(tr("Sea&rch"));
    search->setEnabled(false);
    cancel = new QPushButton(tr("Cancel"));
    matchCase = new QCheckBox(tr("Match Case"));
    searchBackward = new QCheckBox(tr("Search Backward"));

    connect(searchBox, SIGNAL(textChanged(QString)), this, SLOT(enableCancelButton()));
    connect(search, SIGNAL(clicked()), this, SLOT(findText()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));

    topLeft = new QHBoxLayout();
    topLeft->addWidget(searchLabel);
    topLeft->addWidget(searchBox);

    leftLayout = new QVBoxLayout();
    leftLayout->addLayout(topLeft);
    leftLayout->addWidget(matchCase);
    leftLayout->addWidget(searchBackward);

    rightLayout = new QVBoxLayout();
    rightLayout->addWidget(search);
    rightLayout->addWidget(cancel);
    rightLayout->addStretch();

    mainLayout = new QHBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    window = new MainWindow();
    window->edittedText(window->getPlainTextText());

    connect(window, SIGNAL(editedText(QString)), this, SLOT(isEdited(QString)));

    setLayout(mainLayout);
    setFixedHeight(sizeHint().height());
    setWindowTitle("Find");

}

void FindDialog::enableCancelButton()
{
    QString text = searchBox->text();

    search->setEnabled(!text.isEmpty());
}

void FindDialog::findText()
{
    qDebug() << window->file_text;

}

void FindDialog::isEdited(QString text)
{
    maintext = text;
}

FindDialog::~FindDialog()
{

}
