#ifndef CALIFICACION_H
#define CALIFICACION_H

#include <QObject>
#include <QString>
#include <QTextStream>
#include <QDebug>

//QTextStream cout (stdout);
//QTextStream cin (stdin);

class Materia;
enum DIFICULTAD{
    FACIL,MEDIO,DIFICIL
};

class Calificacion : public QObject
{
    Q_OBJECT
public:

    explicit Calificacion(QString nombre, int porcentaje,float nota=0.0, enum DIFICULTAD dificultad=MEDIO,QObject *parent = 0);
    float getNotaReal() const;
    float getNotaEstimada();
    int getPorcentaje() const;
    QString getNombre() const;
    bool getEsEstimada() const;
    void setNombre(QString nombre);
    void setNotaReal(float nota);
    void setPorcentaje(int porcentaje);
    void setDificultad(enum DIFICULTAD dificultad);
    void setMateria(Materia * materia);
    Materia * getMateria() const;
    ~Calificacion();


signals:

public slots:
private:
    QString m_nombre;
    float m_notaReal;
    float m_notaEstimada;
    int m_porcentaje;
    enum DIFICULTAD m_dificultad;
    bool esEstimada;
    Materia * m_materia;



};

#endif  //CALIFICACION_H

