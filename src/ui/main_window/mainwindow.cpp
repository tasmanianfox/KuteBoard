#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->game.newGame();
    Board *board = this->findChild<Board*>(QString("board"));
    board->game = &this->game;
}

MainWindow::~MainWindow()
{
    delete ui;
}
