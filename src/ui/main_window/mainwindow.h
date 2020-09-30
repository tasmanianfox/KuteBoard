#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCoreApplication>
#include <QMainWindow>


#include "src/ui/main_window/board.h"
#include "src/game/game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_openGLWidget_frameSwapped();

    void on_openGLWidget_resized();

private:
    Ui::MainWindow *ui;

    Game game;
};
#endif // MAINWINDOW_H
