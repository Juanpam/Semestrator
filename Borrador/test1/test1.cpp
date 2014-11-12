#include <QtTest>
#include <QtCore>
#include "calificacion.h"
class testCalificacion: public QObject
{
    Q_OBJECT
private slots:
    void testNombre();
    void testEstimado();
};
 
void testCalificacion::testNombre()
{
    // Testear calificacion
    Calificacion nota1(QString("Parcial"),4.5,80,DIFICIL);
    QCOMPARE(nota1.getNombre(), QString("Parcial"));
}

void testCalificacion::testEstimado()
{
    // Testear calificacion
    Calificacion nota1(QString("Parcial"),4.5,80,DIFICIL);
    QCOMPARE(nota1.getNotaEstimada(), (float)2.0);
}
QTEST_MAIN(testCalificacion)
#include "test1.moc"