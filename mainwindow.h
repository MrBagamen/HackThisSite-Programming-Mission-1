#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QVector>
#include <QtAlgorithms>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void ButtonClickHandler();
    void ButtonClickHandler2();
    
private:
    Ui::MainWindow *ui;
    QVector<QString> vecUnsorted;
    QVector<QString> vecSorted;
    bool wordlistLoaded;
};

#endif // MAINWINDOW_H
