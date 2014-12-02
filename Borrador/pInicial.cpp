#include "pInicial.h"
#include "ui_inicial.h"

pInicial::pInicial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inicial),userScreen(0),estudianteActual(0)
{
    ui->setupUi(this);
}

pInicial::~pInicial()
{
    delete userScreen;
    delete ui;
}

void pInicial::on_Crear_clicked()
{
    //QTextStream cout(stdout);
    //QString filename = QFileDialog::getSaveFileName(this,tr("Selecciona donde guardar tu perfil"),"",tr("All Files (*);;Text Files (*.txt)"));
    //cout << filename << endl;
    bool ok;
    QString nombre = QInputDialog::getText(this, tr("Nuevo Usuario"),
                                         tr("Digita tu nombre, porfavor: "), QLineEdit::Normal,
                                         tr("Estudiante"), &ok);
    if(ok && !nombre.isEmpty())
    {
        estudianteActual=new Estudiante(nombre);
        //qDebug() << estudianteActual->getNombre();
        userScreen=new pPrincipal(estudianteActual);
        userScreen->showMaximized();
        this->close();
    }
    else if(ok)
    {
        QMessageBox::information(this, tr("Nombre de estudiante no valido"), tr("Porfavor digita el nombre del estudiante"));
        pInicial::on_Crear_clicked();
    }
    else
    {}
}
void pInicial::on_Cargar_clicked()
{
    QTextStream cout(stdout);
    QString filename = QFileDialog::getOpenFileName(this,tr("Selecciona tu perfil"),"",tr("All Files (*);;Text Files (*.txt)"));
    //cout << filename << endl;
    //userScreen->show();
    this->close();
}

