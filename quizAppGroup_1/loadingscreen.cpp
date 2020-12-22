#include "loadingscreen.h"
#include "ui_loadingscreen.h"
#include "mainwindoww.h"
#include <QMovie>
#include <QStyle>
#include <QDesktopWidget>
#include <QPixmap>
loadingScreen::loadingScreen(QWidget *parent) :QDialog(parent),ui(new Ui::loadingScreen){
  ui->setupUi(this);


  QMovie *movie = new QMovie(":/bGrounds/backgrounds/lodi.gif");

     this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
   setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
  ui->labelAnimation->setMovie(movie);
  movie->start();
 QDialog::setFixedSize(800,600);
  time_For_ProgressBar = new QTimer(this);
  connect(time_For_ProgressBar,SIGNAL(timeout()),this,SLOT(ProgressBarValue()));

  time_For_ProgressBar->start(100);

}



int percentage = 0;

void loadingScreen::ProgressBarValue(){
   percentage+=1;
   ui->progressBar->setValue(percentage);
   if(percentage==100){
       this->close();
       mainwindoww *mm = new mainwindoww(this);
       mm->show();
     }

}

loadingScreen::~loadingScreen()
{
  delete ui;
}
