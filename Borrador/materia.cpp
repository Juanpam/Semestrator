#include "materia.h"

Materia::Materia(QString nombre,int creditos,QObject *parent) :
    QObject(parent),m_nombre(nombre),m_promedioReal(0),m_promedioEstimado(0),m_creditos(creditos)
{}
Materia::~Materia()
{
    qDeleteAll(m_calificaciones);
    m_calificaciones.clear();
}
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
        calificacion->setMateria(this);
        return 0; //Se ingresa satisfactoriamente
    }
    else
    {
        m_calificaciones.pop_back();
        return 1; //No se pudo ingresar la calificacion debido a que los porcentajes se salen del rango
    }
}
float Materia::getPromedioReal() const
{
   return m_promedioReal;
}
float Materia::getPromedioEstimado() const
{
    return m_promedioEstimado;
}
float Materia::calcPromedioReal()
{
    float promedio=0;
    if (!m_calificaciones.isEmpty())
    {
        QList<Calificacion *>::iterator i;
        for(i=m_calificaciones.begin();i!=m_calificaciones.end();i++)
        {
            promedio+=((*i)->getNotaReal()*(*i)->getPorcentaje())/100;
        }
    }
    //qDebug() << promedio << endl;
    m_promedioReal=promedio;
    return m_promedioReal;
}
float Materia::calcPromedioEstimado()
{
    this->calcPromedioReal();
    float promedioE=0;
    if (!m_calificaciones.isEmpty())
    {
        QList<Calificacion *>::iterator i;
        for(i=m_calificaciones.begin();i!=m_calificaciones.end();i++)
        {
            if((*i)->getEsEstimada())
            {
                promedioE+=((*i)->getNotaEstimada()*(*i)->getPorcentaje())/100;
            }
        }
    }
    //qDebug() << promedioE << endl;
    m_promedioEstimado=promedioE+m_promedioReal;
    return m_promedioEstimado;
}

int Materia::removeCalificacion(QString nombre)
{
    QList<Calificacion *>::iterator i;
    for(i=m_calificaciones.begin();i!=m_calificaciones.end();i++)
    {
        if((*i)->getNombre()==nombre)
        {
            delete (*i);
            m_calificaciones.removeAt(i-m_calificaciones.begin());
            (*i)->setMateria(0);
            return 0;
        }
    }
    return 1;//No encontrado
}
QList<Calificacion *> Materia::getCalificaciones() const
{
    return m_calificaciones;
}
bool Materia::esAprovada() const
{
    if(this->getPromedioReal()>=3)
    {
        return true;
    }
    else
        return false;
}
bool Materia::esPerdida() const
{
    if(!this->esAprovada())
    {
        int porcentajeAcumulado=0;
        float necesario=0;
        QList<Calificacion *>::const_iterator i;
        for(i=m_calificaciones.begin();i!=m_calificaciones.end();++i)
        {
            if( !(*i)->getEsEstimada() )
            {
                porcentajeAcumulado+=(*i)->getPorcentaje();
            }
        }
        necesario=(2.95-(this->getPromedioReal()))/((100.0-porcentajeAcumulado)/100);
        //qDebug() <<"necesario es "<< necesario << porcentajeAcumulado << endl;
        if (necesario>5.0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
int Materia::getCreditos() const
{
    return m_creditos;
}
QString Materia::getNombre() const
{
    return m_nombre;
}
void Materia::setSemestre(Semestre *semestre)
{
    m_semestre=semestre;
}
