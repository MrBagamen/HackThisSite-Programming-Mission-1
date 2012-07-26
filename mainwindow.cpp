#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    wordlistLoaded = false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ButtonClickHandler()
{
    vecUnsorted.clear();
    vecSorted.clear();

    QFileDialog fd(this);
    QStringList fileName;
    QString temp;


    fd.setFileMode(QFileDialog::AnyFile);
    fd.setViewMode(QFileDialog::Detail);
    if(fd.exec())
    {
        fileName = fd.selectedFiles();
    }
    else
    {
        return;
    }

    QFile file(fileName.at(0));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){return;}
    while(!file.atEnd())
    {
        temp = file.readLine();
        vecUnsorted.push_back(temp);
        qSort(temp.begin(), temp.end());
        vecSorted.push_back(temp);
        temp.clear();
    }

    ui->label_3->setText("Loaded: " + fileName.at(0));
    wordlistLoaded = true;
}

void MainWindow::ButtonClickHandler2()
{
    if(!wordlistLoaded)
    {
        QMessageBox::information(this, "Hurr Durr?!?", "You gotta load wordlist first!", QMessageBox::Ok);
        return;
    }
    else
    {
        QString input = ui->plainTextEdit->toPlainText();
        QString temp;
        QVector<QString> tempVec;
        QVector<QString> unscrambledVec;

        for(int i = 0; i < input.length(); i++)
        {
            temp += input.at(i);
            if(input.at(i) == '\n' || input.at(i) == '\0')
            {
                qSort(temp.begin(), temp.end());
                tempVec.push_back(temp);
                temp.clear();
            }

        }

        //Unscramble n shit
        for(int i = 0; i < tempVec.size(); i++)
        {
            for(int j = 0; j < vecSorted.size(); j++)
            {
                if(tempVec.at(i) == vecSorted.at(j))
                {
                    unscrambledVec.push_back(vecUnsorted.at(j));
                }
            }
        }

        QString unscrambledStr;
        ui->lineEdit->clear();
        for(int i = 0; i < unscrambledVec.size(); i++)
        {
            if(i == unscrambledVec.size()-1)
            {
                unscrambledStr += unscrambledVec.at(i);
                unscrambledStr = unscrambledStr.simplified();
                unscrambledStr.replace( " ", "" );
            }
            else
            {
                unscrambledStr += unscrambledVec.at(i);
                unscrambledStr = unscrambledStr.simplified() + ',';
                unscrambledStr.replace( " ", "" );
            }
        }
        ui->lineEdit->setText(unscrambledStr);
    }
}
