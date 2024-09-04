#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QStringListModel>
#include <Code/ui/gobang.h>
#include "Code/net/gobang_network.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Gobang_Network *gn, QWidget *parent = nullptr);
    ~MainWindow();
public:
    void draw_chess();
public slots:
    void slotClicked(const QModelIndex &index);
private:
    Ui::MainWindow *ui;
    Gobang *gb;
    QListView *listview;
private:
    void update_window();
};

#endif // MAINWINDOW_H
