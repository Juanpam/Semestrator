#include "pPrincipal.h"
#include "ui_principal.h"
pPrincipal::pPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);
}

pPrincipal::~pPrincipal()
{
    delete ui;
}

void pPrincipal::on_InsertarC_clicked()
{

}
