#include "semestre.h"

Semestre::Semestre(int No,QObject *parent) :
    QObject(parent),m_numeroSem(No),m_creditos(0),m_promedioReal(0),m_promedioEstimado(0),m_cantidadM(0),m_mGanadas(0),m_mPerdidas(0)
{}
Semestre::~Semestre()
{
    qDeleteAll(m_materias);
    m_materias.clear();
}

void Semestre::addMateria(Materia * mat)
{
    m_materias.append(mat);
    m_cantidadM+=1;
    m_creditos+=mat->getCreditos();
    mat->setSemestre(this);
}
int Semestre::getCantidadMaterias() const
{
    return m_cantidadM;
}
int Semestre::getMateriasAprovadas()
{
    int materiasAprovadas=0;
    QList<Materia *>::iterator i;
    for(i=m_materias.begin();i!=m_materias.end();++i)
    {
        if((*i)->esAprovada())
        {
            materiasAprovadas+=1;
        }
    }
    m_mGanadas=materiasAprovadas;
    return m_mGanadas;
}
int Semestre::getMateriasPerdidas()
{
    int materiasPerdidas=0;
    QList<Materia *>::iterator i;
    for(i=m_materias.begin();i!=m_materias.end();++i)
    {
        if((*i)->esPerdida())
        {
            materiasPerdidas+=1;
        }
    }
    m_mPerdidas=materiasPerdidas;
    return m_mPerdidas;
}
int Semestre::getMateriasPorPasar() const
{
    return m_cantidadM-(m_mGanadas+m_mPerdidas);
}
float Semestre::getPromedioReal() const
{
    return m_promedioReal;
}
float Semestre::getPromedioEstimado() const
{
    return m_promedioEstimado;
}
float Semestre::calcPromedioReal()
{
    float promedio=0;
        if (!m_materias.isEmpty())
        {
            QList<Materia *>::iterator i;
            for(i=m_materias.begin();i!=m_materias.end();i++)
            {
                promedio+=((*i)->calcPromedioReal()*(*i)->getCreditos());
            }
        }
        //qDebug() << promedio << endl;
        m_promedioReal=promedio/m_creditos;
        return m_promedioReal;
}
float Semestre::calcPromedioEstimado()
{
    this->calcPromedioReal();
    float promedio=0;
        if (!m_materias.isEmpty())
        {
            QList<Materia *>::iterator i;
            for(i=m_materias.begin();i!=m_materias.end();i++)
            {
                promedio+=((*i)->calcPromedioEstimado()*(*i)->getCreditos());
            }
        }
        //qDebug() << promedio << endl;
        m_promedioEstimado=promedio/m_creditos;
        return m_promedioEstimado;
}

QList<Materia *> Semestre::getMaterias() const
{
    return m_materias;
}
int Semestre::removeMateria(QString nombre)
{
    QList<Materia *>::iterator i;
    for(i=m_materias.begin();i!=m_materias.end();i++)
    {
        if((*i)->getNombre()==nombre)
        {
            delete (*i);
            m_materias.removeAt(i-m_materias.begin());
            (*i)->setSemestre(0);
            return 0;
        }
    }
    return 1;//No encontrado
}
