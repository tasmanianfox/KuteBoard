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


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_openGLWidget_frameSwapped()
{

}

void MainWindow::on_openGLWidget_resized()
{

}
