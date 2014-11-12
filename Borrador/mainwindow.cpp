#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),userScreen(new principal)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Crear_clicked()
{
    QTextStream cout(stdout);
    QString filename = QFileDialog::getSaveFileName(this,tr("Selecciona donde guardar tu perfil"),"",tr("All Files (*);;Text Files (*.txt)"));
    cout << filename << endl;
    userScreen->show();
    this->close();
}
void MainWindow::on_Cargar_clicked()
{
    QTextStream cout(stdout);
    QString filename = QFileDialog::getOpenFileName(this,tr("Selecciona tu perfil"),"",tr("All Files (*);;Text Files (*.txt)"));
    cout << filename << endl;
    userScreen->show();
    this->close();
}

