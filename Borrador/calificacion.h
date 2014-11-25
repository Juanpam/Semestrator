#ifndef CALIFICACION_H
#define CALIFICACION_H

#include <QObject>
#include <QString>
#include <QTextStream>
#include <QDebug>

//QTextStream cout (stdout);
//QTextStream cin (stdin);


enum DIFICULTAD{
    FACIL,MEDIO,DIFICIL,NIVELDIOS
};

class Calificacion : public QObject
{
    Q_OBJECT
public:

    explicit Calificacion(QString nombre, float nota,int porcentaje, enum DIFICULTAD dificultad,QObject *parent = 0);
    explicit Calificacion(QString nombre, int porcentaje, enum DIFICULTAD dificultad,QObject *parent = 0);
    explicit Calificacion(QString nombre,int porcentaje ,QObject *parent = 0);
    float getNotaReal() const;
    float getNotaEstimada();
    int getPorcentaje() const;
    QString getNombre() const;
    ~Calificacion();


signals:

public slots:
private:
    QString m_nombre;
    float m_notaReal;
    float m_notaEstimada;
    int m_porcentaje;
    enum DIFICULTAD m_dificultad;




};

#endif  //CALIFICACION_H

