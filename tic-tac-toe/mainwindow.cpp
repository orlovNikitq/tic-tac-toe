#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentPlayer = "X";
    movesCount = 0;
    resultLabel = ui->resultLabel;
    buttons[0] = ui->Button1;
    buttons[1] = ui->Button2;
    buttons[2] = ui->Button3;
    buttons[3] = ui->Button4;
    buttons[4] = ui->Button5;
    buttons[5] = ui->Button6;
    buttons[6] = ui->Button7;
    buttons[7] = ui->Button8;
    buttons[8] = ui->Button9;
    connect(ui->Button1, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->Button2, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->Button3, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->Button4, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->Button5, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->Button6, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->Button7, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->Button8, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->Button9, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
       if (button) {
           QString buttonText = button->text();
           if (buttonText.isEmpty()) {
               button->setText(currentPlayer);
               movesCount++;
               if (movesCount >= 5) {
                   checkWin();
               }
               if (movesCount == 9) {
                   resultLabel->setText("ничья!");
               }

               currentPlayer = (currentPlayer == "X") ? "O" : "X";
           }
       }
}
void MainWindow::checkWin(){
    for (int i = 0; i < 3; i++) {
           if (buttons[i * 3]->text() == currentPlayer &&
               buttons[i * 3 + 1]->text() == currentPlayer &&
               buttons[i * 3 + 2]->text() == currentPlayer) {
               resultLabel->setText(currentPlayer + " победил!");
               for (int i = 0; i < 9; i++) {
                   buttons[i]->setEnabled(false);
               }
           }
       }
       for (int i = 0; i < 3; i++) {
           if (buttons[i]->text() == currentPlayer &&
               buttons[i + 3]->text() == currentPlayer &&
               buttons[i + 6]->text() == currentPlayer) {
               resultLabel->setText(currentPlayer + " победил!");
               for (int i = 0; i < 9; i++) {
                   buttons[i]->setEnabled(false);
               }
               return;
           }
       }
       if (buttons[0]->text() == currentPlayer &&
           buttons[4]->text() == currentPlayer &&
           buttons[8]->text() == currentPlayer) {
           resultLabel->setText(currentPlayer + " победил!");
           for (int i = 0; i < 9; i++) {
               buttons[i]->setEnabled(false);
           }
           return;
       }
       if (buttons[2]->text() == currentPlayer &&
           buttons[4]->text() == currentPlayer &&
           buttons[6]->text() == currentPlayer) {
           resultLabel->setText(currentPlayer + " победил!");
           for (int i = 0; i < 9; i++) {
               buttons[i]->setEnabled(false);
           }
           return;
       }
}

