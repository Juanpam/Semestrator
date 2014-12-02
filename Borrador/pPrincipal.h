#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QtGui>
#include <estudiante.h>
#include <modelosemestre.h>
namespace Ui {
class principal;
}

class pPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit pPrincipal(Estudiante * estudiante=0,QWidget *parent = 0);
    ~pPrincipal();
private slots:
    void on_InsertarC_clicked();

    void on_columnView_clicked(const QModelIndex &index);

    void on_siguienteSemestre_clicked();

    void on_agregarSemestre_clicked();

    void on_anteriorSemetre_clicked();

    void on_InsertarM_clicked();

    void on_EstimarPonderadoM_clicked();

private:
    void actualizarModelo();
    Ui::principal *ui;
    Estudiante * estudianteActual;
    Semestre * semestreActual;
    ModeloSemestre * modelo;
    QModelIndex indiceActual;
};

#endif // PRINCIPAL_H
