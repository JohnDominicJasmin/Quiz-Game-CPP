 #include "mainwindoww.h"
#include "ui_mainwindoww.h"
#include <QApplication>
#include <QMessageBox>
#include <QLabel>
#include <QStyle>
#include <QDesktopWidget>
#include <QUrl>
#include <QGuiApplication>
#include "quit.h"
#include "categories.h"


mainwindoww::mainwindoww(QWidget *parent) :QDialog(parent),ui(new Ui::mainwindoww){
  ui->setupUi(this);

  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
  int width = QApplication::desktop()->width();
  int height = QApplication::desktop()->height();
  QDialog::setFixedSize(width,height);
  ui->labelbackground->setFixedSize(width,height);



}


void mainwindoww::makeclickSound(){
SoundForm = new soundSettings(this);
SoundForm->startClickEffects();
}
void mainwindoww::closeWindow(){
  this->close();
}
//////////////////////////////////////////////////////
void mainwindoww::on_pushButton_Quit_clicked(){
Quit *qt = new  Quit(this);
    qt->setModal(true);
    qt->exec();
}

void  mainwindoww::on_pushButton_Start_clicked(){
this->close();
trivia = new TriviaType(this);
trivia->setModal(true);
trivia->exec();
}

void mainwindoww::on_pushButton_Options_clicked(){
SoundForm = new soundSettings(this);
  SoundForm->setModal(true);
  SoundForm->exec();
}

/////////////////////////////////////////////////


mainwindoww::~mainwindoww()
{
  delete ui;
}

///////////////////////////////////
void mainwindoww::on_pushButton_Start_pressed(){
 makeclickSound();
}

void mainwindoww::on_pushButton_Credits_pressed(){
   makeclickSound();
}

void mainwindoww::on_pushButton_Quit_pressed(){
   makeclickSound();
}

void mainwindoww::on_pushButton_Options_pressed(){
  makeclickSound();
SoundForm->loadStateOfCheckboxForMusic();
}



void mainwindoww::on_pushButton_Credits_clicked()
{
    cf = new CreditsForm(this);
    cf->setModal(true);
    cf->exec();
}
