#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QObject>
#include "semestre.h"
class Estudiante : public QObject
{
    Q_OBJECT
public:
    explicit Estudiante(QString nombre,QObject *parent = 0);
    QString getNombre () const;
    float calcPromedioReal();
    float calcPromedioEstimado();
    float getPromedioReal () const;
    float getPromedioEstimado () const;
    QList<Semestre *> getSemestres() const;
    void addSemestre(Semestre *);
    ~Estudiante();

signals:

public slots:
private:
    QString m_nombre;
    QList<Semestre *> m_semestres;
    float m_promedioReal;
    float m_promedioEstimado;
    int m_cantidadSemestres;


};

#endif // ESTUDIANTE_H
