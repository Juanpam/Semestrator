#include "pInicial.h"
#include "ui_inicial.h"
#include <QtGui>
pInicial::pInicial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inicial),userScreen(new pPrincipal)
{
    ui->setupUi(this);
}

pInicial::~pInicial()
{
    delete ui;
}

void pInicial::on_Crear_clicked()
{
    QTextStream cout(stdout);
    QString filename = QFileDialog::getSaveFileName(this,tr("Selecciona donde guardar tu perfil"),"",tr("All Files (*);;Text Files (*.txt)"));
    //cout << filename << endl;
    userScreen->show();
    this->close();
}
void pInicial::on_Cargar_clicked()
{
    QTextStream cout(stdout);
    QString filename = QFileDialog::getOpenFileName(this,tr("Selecciona tu perfil"),"",tr("All Files (*);;Text Files (*.txt)"));
    //cout << filename << endl;
    userScreen->show();
    this->close();
}

