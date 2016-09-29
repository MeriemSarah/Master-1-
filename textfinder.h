#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QTextCursor>
#include <QIODevice>
#include <QString>
#include <QTextDocument>
#include <QMessageBox>
#include <QTextCharFormat>
#include <QFileDialog>

namespace Ui {
class TextFinder;
}

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = 0);
    ~TextFinder();
private slots:
    void on_findButton_clicked();
    void on_openButton_clicked();
    void maRecherche();


private:
    Ui::TextFinder *ui;
    void loadTextFile();

};

#endif // TEXTFINDER_H
