#include "materia.h"

Materia::Materia(QString nombre,int creditos,QObject *parent) :
    QObject(parent),m_nombre(nombre),m_promedioReal(0),m_promedioEstimado(0),m_creditos(creditos)
{}
Materia::~Materia(){}
int Materia::addCalificacion(Calificacion *calificacion)
{   m_calificaciones.append(calificacion);
    QList<Calificacion *>::iterator i;
    int sPorcentaje=0;
    for(i=m_calificaciones.begin();i!=m_calificaciones.end() && sPorcentaje<=100;i++)
    {
        sPorcentaje+=(*i)->getPorcentaje();
    }
    if (sPorcentaje<=100)
    {
        return 0; //Se ingresa satisfactoriamente
    }
    else
    {
        m_calificaciones.pop_back();
        return 1; //No se pudo ingresar la calificacion debido a que los porcentajes se salen del rango
    }
}
float Materia::getPromedioReal()
{
    if (m_promedioReal!=0)
    {
        return m_promedioReal;
    }
    float promedio=0;
    if (!m_calificaciones.isEmpty())
    {
        QList<Calificacion *>::iterator i;
        for(i=m_calificaciones.begin();i!=m_calificaciones.end();i++)
        {
            promedio+=((*i)->getNotaReal()*(*i)->getPorcentaje())/100;
        }
    }
    qDebug() << promedio << endl;
    m_promedioReal=promedio;
    return m_promedioReal;
}
int Materia::removeCalificacion(QString nombre)
{
    QList<Calificacion *>::iterator i;
    for(i=m_calificaciones.begin();i!=m_calificaciones.end();i++)
    {
        if((*i)->getNombre()==nombre)
        {
            m_calificaciones.removeAt(i-m_calificaciones.begin());
            return 0;
        }
    }
    return 1;//No encontrado
}
QList<Calificacion *> Materia::getCalificaciones() const
{
    return m_calificaciones;
}
