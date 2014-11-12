#include <QApplication>
#include "calificacion.h"
#include "materia.h"
#include "mainwindow.h"
#include "principal.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Calificacion lel(QString("Materia 1"),0,20,FACIL);
    lel.getNotaEstimada();
    Materia mat1(QString("Matematicas"));
    return a.exec();
}
