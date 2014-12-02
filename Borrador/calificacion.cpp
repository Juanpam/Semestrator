#include "calificacion.h"


Calificacion::Calificacion(QString nombre, int porcentaje, float nota, enum DIFICULTAD dificultad,QObject *parent):
    QObject(parent),m_nombre(nombre),m_notaReal(nota),m_notaEstimada(0.0),m_porcentaje(porcentaje),m_dificultad(dificultad)
{
    //qDebug() << "La nota que se paso es " << nota << endl;
    if(nota==0)
    {
        esEstimada=true;
        //qDebug() << "La nota fue estimada" << endl;
    }
    else
    {
        esEstimada=false;
        //qDebug() << "La nota no fue estimada" << endl;
    }
}


Calificacion::~Calificacion()
{}
float Calificacion::getNotaReal()  const
{
    //qDebug()<< m_notaReal<< endl;
    return m_notaReal;
}
int Calificacion::getPorcentaje() const
{
    //cout << m_porcentaje << endl;
    return m_porcentaje;
}

QString Calificacion::getNombre() const
{
    //cout << m_nombre << m_notaEstimada << endl;
    return m_nombre;
}
float Calificacion::getNotaEstimada()
{
    if(m_notaEstimada!=0)
    {
        return m_notaEstimada;
    }
    else
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
        //qDebug() << m_notaEstimada <<endl;
        return m_notaEstimada;
    }
}
bool Calificacion::getEsEstimada() const
{
    return esEstimada;
}
void Calificacion::setMateria(Materia *materia)
{
    m_materia=materia;
}
Materia * Calificacion::getMateria() const
{
    return m_materia;
}
