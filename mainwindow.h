#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Code/ui/gobang.h>
#include "Code/net/gobang_network.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void draw_chess();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
