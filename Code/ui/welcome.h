#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

namespace Ui {
class welcome;
}

class welcome : public QWidget
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();
    Ui::welcome *ui;
private:

};

#endif // WELCOME_H
