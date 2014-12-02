#include "pPrincipal.h"
#include "ui_principal.h"
pPrincipal::pPrincipal(Estudiante * estudiante,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal),estudianteActual(estudiante),semestreActual(new Semestre),indiceActual(QModelIndex())
{
    ui->setupUi(this);
    ui->nombreEstudiante->setText(ui->nombreEstudiante->text()+estudianteActual->getNombre());
    estudianteActual->addSemestre(semestreActual);
    /*for(int i=0;i<4;++i)
    {
        semestreActual->addMateria(new Materia(QString("mat%0").arg(i),4));
    }
    semestreActual->getMaterias()[0]->addCalificacion(new Calificacion(QString("Parcial 1"),20));*/
    actualizarModelo();

}

pPrincipal::~pPrincipal()
{
    delete ui;
}

void pPrincipal::on_InsertarC_clicked()
{
    if(!(indiceActual.parent().isValid()) && indiceActual.isValid()){
    QDialog dialogo(this);
    dialogo.setWindowTitle(tr("Ingresar nueva calificacion"));
    QFormLayout form(&dialogo);

    // Add some text above the fields
    form.addRow(new QLabel("Ingresa la informacion de la calificacion.\nSi desconoces tu nota, deja el valor en 0."));

    // Add the lineEdits with their respective labels
    QList<QWidget *> campos;
    for(int i = 0; i < 4; ++i) {
        QWidget *campo=0;
        QString label;
        switch(i)
        {
            case 0:
            {
            QLineEdit * temp;
            temp=new QLineEdit(this);
            temp->setText("");
            //qDebug() << "Entre al caso "<< i << endl;
            campo=temp;
            label=QString("Nombre:");
            break;
            }
            case 1:
            {
            QDoubleSpinBox * temp;
            temp=new QDoubleSpinBox(this);
            temp->setRange(0.0,5.0);
            temp->setDecimals(1);
            temp->setSingleStep(0.5);
            temp->setValue(3.5);
            //qDebug() << "Entre al caso "<< i << endl;
            campo=temp;
            label=QString("Nota:");
            break;
            }
            case 2:
            {
            QSpinBox *temp;
            temp = new QSpinBox(this);
            temp->setRange(0,100);
            temp->setValue(20);
            campo=temp;
            label=QString("Porcentaje:");
            break;
            }
            case 3:
            {
            QComboBox * temp;
            temp = new QComboBox(this);
            QStringList items;
            items  << tr("Facil") << tr("Medio") << tr("Dificil");
            temp->addItems(items);
            temp->setCurrentIndex(1);
            campo=temp;
            label=QString("Dificultad:");
            break;
        }
        }
        form.addRow(label, campo);

        campos << campo;
    }
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialogo);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialogo, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialogo, SLOT(reject()));
    if (dialogo.exec()==QDialog::Accepted)
        {
           QList<QVariant> propiedades;
           propiedades.append(((QLineEdit *)campos[0])->text());
           propiedades.append(((QDoubleSpinBox *)campos[1])->value());
           propiedades.append(((QSpinBox *)campos[2])->value());
           propiedades.append(((QComboBox *)campos[3])->currentIndex());
           if(propiedades.at(0)!="")
           {
            modelo->setData(indiceActual,propiedades,0);
            //actualizarModelo();
           }
        }
    }
}

void pPrincipal::on_columnView_clicked(const QModelIndex &index)
{
    indiceActual=QModelIndex(index);
    //qDebug() << indiceActual.row();
}

void pPrincipal::on_siguienteSemestre_clicked()
{
    QList<Semestre *> semestres=estudianteActual->getSemestres();
    int indice=semestres.indexOf(semestreActual)+1;
    qDebug() << indice;
    if(indice<semestres.size())
    {
        semestreActual=semestres.at(indice);
        ui->Semestre->setText((QString("Semestre %0").arg(indice+1)));
        actualizarModelo();
    }
    else
    {

    }
}

void pPrincipal::on_agregarSemestre_clicked()
{
    QList<Semestre *> semestres = estudianteActual ->getSemestres();
    estudianteActual->addSemestre(new Semestre(semestres.size()+1));
    semestreActual=estudianteActual->getSemestres().last();
    ui->Semestre->setText((QString("Semestre %0").arg(estudianteActual->getSemestres().size())));
    actualizarModelo();
}

void pPrincipal::on_anteriorSemetre_clicked()
{
    QList<Semestre *> semestres=estudianteActual->getSemestres();
    int indice=semestres.indexOf(semestreActual)-1;
    qDebug() << indice;
    if(indice>=0)
    {
        semestreActual=semestres.at(indice);
        ui->Semestre->setText((QString("Semestre %0").arg(indice+1)));
        actualizarModelo();
    }
    else
    {

    }
}
void pPrincipal::actualizarModelo()
{
    modelo=new ModeloSemestre(semestreActual);
    ui->columnView->setModel(modelo);
}


void pPrincipal::on_InsertarM_clicked()
{

    QDialog dialogo(this);
    dialogo.setWindowTitle(tr("Ingresar nueva materia"));
    QFormLayout form(&dialogo);

    // Add some text above the fields
    form.addRow(new QLabel("Ingresa la informacion de la materia.\nSi desconoces tu nota, deja el valor en 0."));

    // Add the lineEdits with their respective labels
    QList<QWidget *> campos;
    for(int i = 0; i < 2; ++i) {
        QWidget *campo=0;
        QString label;
        switch(i)
        {
            case 0:
            {
            QLineEdit * temp;
            temp=new QLineEdit(this);
            temp->setText("");
            //qDebug() << "Entre al caso "<< i << endl;
            campo=temp;
            label=QString("Nombre:");
            break;
            }
            case 1:
            {
            QSpinBox *temp;
            temp = new QSpinBox(this);
            temp->setMinimum(0);
            temp->setValue(2);
            campo=temp;
            label=QString("Creditos:");
            break;
            }
        }
        form.addRow(label, campo);

        campos << campo;
    }
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialogo);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialogo, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialogo, SLOT(reject()));
    if (dialogo.exec()==QDialog::Accepted)
        {
           QList<QVariant> propiedades;
           propiedades.append(((QLineEdit *)campos[0])->text());
           propiedades.append(((QSpinBox *)campos[1])->value());
           if(propiedades.at(0)!="" && propiedades.at(1)!=0)
           {
               semestreActual->addMateria(new Materia(propiedades[0].toString(),propiedades[1].toInt()));
               modelo->setData(QModelIndex(),propiedades,0);
               actualizarModelo();
           }
        }

}

void pPrincipal::on_EstimarPonderadoM_clicked()
{
    if(indiceActual.isValid())
    {
    QMessageBox::StandardButton reply;
    double ponderado;
    if(indiceActual.parent().isValid())
    {
        ponderado=((Calificacion *)indiceActual.internalPointer())->getMateria()->calcPromedioEstimado();
        qDebug()<<((Calificacion *)indiceActual.internalPointer())->getMateria()->getNombre() <<"nombre materia 1";
    }
    else
    {
        ponderado=((Materia *)indiceActual.internalPointer())->calcPromedioEstimado();
        qDebug()<<((Materia *)indiceActual.internalPointer())->getPromedioReal()<< ponderado<<"Nombre materia 2";
    }
    QString texto=QString("El promedio estimado de tu materia es:\n%0").arg(ponderado);
    reply = QMessageBox::information(this, tr("Estimacion del promedio de tu materia"),texto);
    }
}
