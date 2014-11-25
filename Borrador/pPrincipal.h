#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class principal;
}

class pPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit pPrincipal(QWidget *parent = 0);
    ~pPrincipal();

private slots:
    void on_InsertarC_clicked();

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
