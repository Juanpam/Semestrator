#ifndef SEMESTRE_H
#define SEMESTRE_H

#include <QObject>
#include "materia.h"
class Semestre : public QObject
{
    Q_OBJECT
public:
    explicit Semestre(QObject *parent = 0, int No=1,int creditos=18);
    int addMateria(Materia *);
    float getPonderadoReal() const;
    float getPonderadoEstimado() const;

signals:

public slots:
private:
    int m_numero;
    int m_creditos;
    QList<Materia *> m_materias;
    float m_ponderadoReal;
    float m_ponderadoEstimado;
    int m_mPerdidas;

};

#endif // SEMESTRE_H
