#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "principal.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_Crear_clicked();

    void on_Cargar_clicked();

private:
    Ui::MainWindow *ui;
    principal * userScreen;

};

#endif // MAINWINDOW_H
