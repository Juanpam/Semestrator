#ifndef MATERIA_H
#define MATERIA_H

#include <QObject>
#include <QList>
#include "calificacion.h"
class Materia : public QObject
{
    Q_OBJECT
public:
    explicit Materia(QString nombre,QObject *parent = 0);

signals:

public slots:
private:
    QString m_nombre;
    QList<Calificacion> m_calificaciones;
    float m_promedioReal;
    float m_promedioEstimado;
};

#endif // MATERIA_H
