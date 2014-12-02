#include <QApplication>
#include "semestre.h"
#include "pInicial.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pInicial w;
    w.show();
    return a.exec();
}


/*
    Materia mat1(QString("Matematicas"),3);
    QList<float> xD;
    xD.append(4.3);
    xD.append(4.3);
    xD.append(4.1);
    xD.append(3.8);
    for(int a=0; a<3;a++)
    {
        mat1.addCalificacion(new Calificacion((QString("Nota ")+QString::number(a)),25,4));

    }
    mat1.addCalificacion(new Calificacion(QString("Nota 67"),25,0,FACIL));
    Materia mat2(QString("lal"),3);
    mat2.addCalificacion(new Calificacion(QString("lel"),100,4));
    Materia mat3(QString("Diarrea"),4);
    Semestre sem1;
    sem1.addMateria(&mat1);
    sem1.addMateria(&mat2);
    sem1.addMateria(&mat3);
    /*xD = mat1.getCalificaciones();
    for(int a=0;a<=3;a++)
    {
        qDebug()<< a << endl;
        qDebug()<<xD[a]->getNombre() << " " << (xD[a]->getPorcentaje()*xD[a]->getNotaEstimada())/100 << endl;
    }
    //Calificacion * lal = new Calificacion(QString("Parcial 28"),5,20,DIFICIL);
    //mat1.addCalificacion(lal);
    qDebug()<<mat1.calcPromedioEstimado() <<"mat1";
    qDebug()<<mat2.calcPromedioEstimado();
    qDebug()<<mat3.calcPromedioEstimado();
    mat1.getPromedioReal();
    qDebug()<<mat1.esAprovada();
    qDebug()<<mat1.esPerdida();
    qDebug()<<mat2.esAprovada();
    qDebug()<<mat2.esPerdida();
    qDebug()<<mat3.esAprovada();
    qDebug()<<mat3.esPerdida();
    qDebug() << sem1.getCantidadMaterias();
    qDebug() << sem1.getMateriasAprovadas();
    qDebug() << sem1.getMateriasPerdidas();
    qDebug() << sem1.getMateriasPorPasar();
    qDebug() << sem1.calcPromedioReal();*/
