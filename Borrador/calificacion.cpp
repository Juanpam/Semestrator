#include "calificacion.h"

QTextStream cout (stdout);
QTextStream cin (stdin);

Calificacion::Calificacion(QString nombre, float nota,int porcentaje, enum DIFICULTAD dificultad,QObject *parent):
    QObject(parent),m_nombre(nombre),m_notaReal(nota),m_notaEstimada(0.0),m_porcentaje(porcentaje),m_dificultad(dificultad)
{
}

Calificacion::Calificacion(QString nombre,int porcentaje,enum DIFICULTAD dificultad,QObject *parent):
   QObject(parent),m_nombre(nombre),m_notaReal(0.0),m_notaEstimada(0.0),m_porcentaje(porcentaje),m_dificultad(dificultad)
{
}

Calificacion::Calificacion(QString nombre, int porcentaje,QObject *parent):
    QObject(parent),m_nombre(nombre),m_notaReal(0.0),m_notaEstimada(0),m_porcentaje(porcentaje),m_dificultad(MEDIO)
{}
Calificacion::~Calificacion()
{}
float Calificacion::getNotaReal()  const
{
    cout << m_notaReal<< endl;
    return m_notaReal;
}
int Calificacion::getPorcentaje() const
{
    cout << m_porcentaje << endl;
    return m_porcentaje;
}

QString Calificacion::getNombre() const
{
    cout << m_nombre << m_notaEstimada << endl;
    return m_nombre;
}
float Calificacion::getNotaEstimada()
{
    switch(m_dificultad){
    case FACIL:
        m_notaEstimada=4.5;
        break;
    case MEDIO:
        m_notaEstimada=3.5;
        break;
    case DIFICIL:
        m_notaEstimada=2.0;
        break;
    default:
        m_notaEstimada=0;
        break;
    }
    cout << m_notaEstimada <<endl;
    return m_notaEstimada;
}

