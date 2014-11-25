#include <QApplication>
#include "materia.h"
#include "pInicial.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pInicial w;
    w.show();
    /*Materia mat1(QString("Matematicas"),4);
    QList<Calificacion*> xD;
    for(int a=0; a<5;a++)
    {
        mat1.addCalificacion(new Calificacion((QString("Nota ")+QString::number(a)),a,20,FACIL));
    }
    xD = mat1.getCalificaciones();
    for(int a=0;a<5;a++)
    {
        qDebug()<<xD[a]->getNombre() << " " << (xD[a]->getPorcentaje()*xD[a]->getNotaReal())/100 << endl;
    }
    //Calificacion * lal = new Calificacion(QString("Parcial 28"),5,20,DIFICIL);
    //mat1.addCalificacion(lal);
    mat1.getPromedioReal();*/
    return a.exec();
}
