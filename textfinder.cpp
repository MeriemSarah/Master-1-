#include "textfinder.h"
#include "ui_textfinder.h"


TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);

}


void TextFinder::loadTextFile()
{

    QFile inputFile;
    inputFile.setFileName(ui->lineEdit_2->text());
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line=in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor=ui->textEdit->textCursor();

}

void TextFinder::on_findButton_clicked()
{
    //QString searchString =ui->lineEdit->text();
    //ui->textEdit->find(searchString,QTextDocument::FindWholeWords);
    int occurence;
    occurence=0;
    QString searchString = ui->lineEdit->text();
    QTextDocument *document = ui->textEdit->document();

    bool found = false;
    bool isFirstTime = false ;

    if (isFirstTime == false)
        document->undo();

    if (searchString.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                "The search field is empty. Please enter a word and click Find.");
    } else {

        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchString, highlightCursor, QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                       QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);
                occurence++;
            }
        }

        cursor.endEditBlock();
        ui->lineEdit_3->setText(QString::number(occurence));
        isFirstTime = false;

                  if (found == false) {
                      QMessageBox::information(this, tr("Word Not Found"),
                          "Sorry, the word cannot be found.");
                  }
              }

}

void TextFinder::on_openButton_clicked(){

    TextFinder::maRecherche();


}

void TextFinder::maRecherche(){
    QString myOpenFile = QFileDialog::getOpenFileName(this, tr("Open File"), "/Documents", tr("Texte (*.txt)"));

     ui->lineEdit_2->setText(myOpenFile);
     ui->findButton->setEnabled(true);
     loadTextFile();

}


TextFinder::~TextFinder()
{
    delete ui;
}

