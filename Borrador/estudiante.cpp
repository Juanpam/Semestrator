#include "estudiante.h"

Estudiante::Estudiante(QString nombre,QObject *parent) :
    QObject(parent),m_nombre(nombre),m_cantidadSemestres(0)
{}
Estudiante::~Estudiante()
{
    qDeleteAll(m_semestres);
    m_semestres.clear();
}

QString Estudiante::getNombre() const
{
    return m_nombre;
}

float Estudiante::calcPromedioReal()
{
    float promedio=0;
        if (!m_semestres.isEmpty())
        {
            QList<Semestre *>::iterator i;
            for(i=m_semestres.begin();i!=m_semestres.end();i++)
            {
                promedio+=(*i)->calcPromedioReal();
            }
        }
        //qDebug() << promedio << endl;
        m_promedioReal=promedio/m_cantidadSemestres;
        return m_promedioReal;
}
float Estudiante::calcPromedioEstimado()
{
    this->calcPromedioReal();
    float promedio=0;
        if (!m_semestres.isEmpty())
        {
            QList<Semestre *>::iterator i;
            for(i=m_semestres.begin();i!=m_semestres.end();i++)
            {
                promedio+=(*i)->calcPromedioEstimado();
            }
        }
        //qDebug() << promedio << endl;
        m_promedioEstimado=promedio/m_cantidadSemestres;
        return m_promedioReal;
}

float Estudiante::getPromedioReal () const
{
    return m_promedioReal;
}
float Estudiante::getPromedioEstimado () const
{
    return m_promedioEstimado;
}
QList<Semestre *> Estudiante::getSemestres() const
{
    return m_semestres;
}
void Estudiante::addSemestre(Semestre * semestre)
{
    m_semestres.append(semestre);
}
