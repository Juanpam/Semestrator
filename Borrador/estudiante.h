#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QObject>
#include "semestre.h"
class Estudiante : public QObject
{
    Q_OBJECT
public:
    explicit Estudiante(QObject *parent = 0);

signals:

public slots:
private:
    QString m_nombre;
    QList<Semestre *> m_semestres;
    float m_promedioReal;
    float m_promedioEstimado;


};

#endif // ESTUDIANTE_H
