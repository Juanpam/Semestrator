#ifndef MATERIA_H
#define MATERIA_H

#include <QObject>
#include <QList>
#include "calificacion.h"

class Semestre;
class Materia : public QObject
{
    Q_OBJECT
public:
    explicit Materia(QString nombre,int creditos,QObject *parent = 0);
    float getPromedioReal()  const;
    float getPromedioEstimado() const;
    int getCreditos() const;
    QString getNombre() const;
    float calcPromedioReal();
    float calcPromedioEstimado(); //Con el objetivo de optimizar, se divide el calculo de el promedio y obtener el ultimo promedio calculado
    int addCalificacion(Calificacion * calificacion);
    int removeCalificacion(QString nombre);
    QList<Calificacion *> getCalificaciones() const;
    bool esAprovada() const;
    bool esPerdida() const;
    void setSemestre(Semestre * semestre);
    ~Materia();
signals:

public slots:
private:
    QString m_nombre;
    QList<Calificacion *> m_calificaciones;
    float m_promedioReal;
    float m_promedioEstimado;
    int m_creditos;
    Semestre * m_semestre;
};

#endif // MATERIA_H
