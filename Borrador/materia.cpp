#include "materia.h"

Materia::Materia(QString nombre,QObject *parent) :
    m_nombre(nombre),QObject(parent)
{
    QTextStream cout (stdout);
    QTextStream cin (stdin);

    cout<< m_calificaciones.isEmpty()<<endl;
}
