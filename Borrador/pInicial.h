#ifndef PINICIAL_H
#define PINICIAL_H

#include <QMainWindow>
#include "pPrincipal.h"
namespace Ui {
class inicial;
}

class pInicial : public QMainWindow
{
    Q_OBJECT

public:
    explicit pInicial(QWidget *parent = 0);
    ~pInicial();

private slots:

    void on_Crear_clicked();

    void on_Cargar_clicked();

private:
    Ui::inicial *ui;
    pPrincipal * userScreen;
    Estudiante * estudianteActual;
};

#endif // PINICIAL_H
