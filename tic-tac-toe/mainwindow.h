#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include<QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onButtonClicked();
    void checkWin();
private:
    Ui::MainWindow *ui;
    QString currentPlayer;
    QPushButton* buttons[9];
    QLabel* resultLabel;
    int movesCount;
};
#endif // MAINWINDOW_H
