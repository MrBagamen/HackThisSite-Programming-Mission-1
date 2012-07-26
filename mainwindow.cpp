#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QVector>
#include <QtAlgorithms>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ButtonClickHandler()
{
    ui->plainTextEdit->clear();
    QFileDialog fd(this);
    QStringList fileName;
    QString temp;
    QVector<QString> vector;

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
        qSort(temp.begin(), temp.end());
        vector.push_back(temp);
        temp.clear();
    }


    for(int i = 0; i < vector.size(); i++)
    {
        ui->plainTextEdit->setPlainText(ui->plainTextEdit->toPlainText() + vector.at(i));
    }
}

void MainWindow::ButtonClickHandler2()
{

}
