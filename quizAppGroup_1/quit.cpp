#include "quit.h"
#include "ui_quit.h"
#include "QApplication"
#include "optionwindow.h"
#include<QStyle>
#include<QDesktopWidget>
#include <QPixmap>
Quit::Quit(QWidget *parent) :QDialog(parent),ui(new Ui::Quit){
  ui->setupUi(this);
  this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    QDialog::setFixedSize(452,238);

}



void Quit::makeclickSound(){
  makeSound = new soundSettings(this);
  makeSound->startClickEffects();
}

void Quit::on_pushButton_clicked()
{
    QApplication::quit();
}

void Quit::on_pushButton_2_clicked()
{
    this->close();
}

void Quit::on_pushButton_3_clicked()
{
    this->close();
}

void Quit::on_pushButton_pressed()
{
makeclickSound();
}

void Quit::on_pushButton_2_pressed()
{
makeclickSound();
}

void Quit::on_pushButton_3_pressed()
{
makeclickSound();
}




Quit::~Quit()
{
  delete ui;
}





