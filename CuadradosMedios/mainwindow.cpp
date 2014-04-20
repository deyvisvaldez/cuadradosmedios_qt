#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int semilla=0, cantidad=0;
    int semilla_cuadrada=0;
    semilla=ui->lineEdit->text().toInt();
    cantidad=ui->lineEdit_2->text().toInt();

    for( int i = 0; i < cantidad; i++ )
    {
      semilla_cuadrada=semilla*semilla;
      QString nsemillacuadrada, D4, pseudo, nueva;
      nsemillacuadrada= QString::number(semilla_cuadrada);
      int tamanio = nsemillacuadrada.length();

      if(tamanio % 2 == 0)
      {
          for( int j= tamanio; j > 4 ; j = j - 2)
          {
              pseudo=nsemillacuadrada.remove(0,1);
              D4 = pseudo.remove(j-2,1);
              nsemillacuadrada=D4;
          }
      }
      else
      {
          nueva=nsemillacuadrada.prepend("0");
          int ntamanio = nueva.length();
          for( int j= ntamanio; j > 4;j = j-2)
          {
              pseudo=nueva.remove(0,1);
              D4=pseudo.remove(j-2,1);
              nueva=D4;
          }
          nsemillacuadrada=nueva;
      }

      ui->listWidget->addItem(QString::number(semilla_cuadrada));
      ui->listWidget_2->addItem(nsemillacuadrada);
      semilla= nsemillacuadrada.toInt();
      ui->listWidget_3->addItem("0."+nsemillacuadrada);
      //ui->listWidget_3->addItem(QString::number("0."+semilla));

      /*QString semilla_ = QString::number(semilla);
      int digito= semilla_.length();

      if(digito == 4)
          ui->listWidget_3->addItem("0."+nsemillacuadrada);
      else
          ui->listWidget_3->addItem("0."+nsemillacuadrada);
*/
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
}
