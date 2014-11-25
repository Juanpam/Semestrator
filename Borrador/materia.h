#ifndef MATERIA_H
#define MATERIA_H

#include <QObject>
#include <QList>
#include "calificacion.h"
class Materia : public QObject
{
    Q_OBJECT
public:
    explicit Materia(QString nombre,int creditos,QObject *parent = 0);
    float getPromedioReal();
    float getPromedioEstimado();
    int addCalificacion(Calificacion * calificacion);
    int removeCalificacion(QString nombre);
    QList<Calificacion *> getCalificaciones() const;
    ~Materia();
signals:

public slots:
private:
    QString m_nombre;
    QList<Calificacion *> m_calificaciones;
    float m_promedioReal;
    float m_promedioEstimado;
    int m_creditos;
};

#endif // MATERIA_H
