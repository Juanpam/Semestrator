#ifndef SEMESTRE_H
#define SEMESTRE_H

#include <QObject>
#include "materia.h"


class Semestre : public QObject
{
    Q_OBJECT
public:
    explicit Semestre(int No=1,QObject *parent = 0);
    ~Semestre();
    void addMateria(Materia *);
    int removeMateria(QString nombre);
    int getCantidadMaterias() const;
    int getMateriasAprovadas();
    int getMateriasPerdidas();
    int getMateriasPorPasar() const;
    float getPromedioReal() const;
    float getPromedioEstimado() const;
    float calcPromedioReal();
    float calcPromedioEstimado();
    QList<Materia *> getMaterias () const;

signals:

public slots:
private:
    int m_numeroSem;
    int m_creditos;
    QList<Materia *> m_materias;
    float m_promedioReal;
    float m_promedioEstimado;
    int m_cantidadM;
    int m_mGanadas;
    int m_mPerdidas;

};

#endif // SEMESTRE_H
