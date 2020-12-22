#include "categories.h"
#include "ui_categories.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QThread>
#include "geographywindow.h"
#include <QStyle>



static bool buttonOfgeographyIsClick,
      buttonOfanimalIsClick,
      buttonOfhistoryIsClick,
      buttonOfSportsIsClick,
      buttonOfHumantiesIsClick,
      buttonOfTechnologyIsClick,
      buttonOfMusicIsClick,
      buttonOfRandomIsClick,
      buttonOfScienceIsClick,
      buttonOfWorldIsClick;


categories::categories(QWidget *parent) : QDialog(parent),ui(new Ui::categories){
  ui->setupUi(this);
  this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
  int width = QApplication::desktop()->width();
  int height = QApplication::desktop()->height();
  QDialog::setFixedSize(width,height);
  ui->lblbackground->setFixedSize(width,height);





}




void categories::on_pushButton_Back_clicked(){this->close(); mw = new mainwindoww(this); mw->show();}


void categories::on_pushButton_Geography_2_clicked(){showMultiplechoiceForm(); buttonOfgeographyIsClick = true; }
void categories::on_pushButton_History_clicked(){showMultiplechoiceForm(); buttonOfhistoryIsClick = true;  }
void categories::on_pushButton_World_clicked(){showMultiplechoiceForm(); buttonOfWorldIsClick = true;  }
void categories::on_pushButton_Animals_clicked(){showMultiplechoiceForm(); buttonOfanimalIsClick = true; }
void categories::on_pushButton_Humanities_clicked(){showMultiplechoiceForm(); buttonOfHumantiesIsClick = true; }
void categories::on_pushButton_Technology_clicked(){showMultiplechoiceForm(); buttonOfTechnologyIsClick = true; }
void categories::on_push_Button_Sports_clicked(){showMultiplechoiceForm(); buttonOfSportsIsClick = true; }
void categories::on_pushButton_Music_clicked(){showMultiplechoiceForm(); buttonOfMusicIsClick = true; }
void categories::on_pushButton_Science_clicked(){showMultiplechoiceForm(); buttonOfScienceIsClick = true;}
void categories::on_push_Button_Random_clicked(){showMultiplechoiceForm();  buttonOfRandomIsClick = true;}



void categories::on_pushButton_Back_pressed(){makeSound.startClickEffects();}
void categories::on_pushButton_Geography_2_pressed(){makeSound.startClickEffects();}
void categories::on_pushButton_History_pressed(){makeSound.startClickEffects();}
void categories::on_pushButton_Animals_pressed(){makeSound.startClickEffects();}
void categories::on_push_Button_Sports_pressed(){ makeSound.startClickEffects();}
void categories::on_pushButton_Humanities_pressed(){ makeSound.startClickEffects();}
void categories::on_pushButton_Technology_pressed(){makeSound.startClickEffects();}
void categories::on_pushButton_World_pressed(){ makeSound.startClickEffects();}
void categories::on_pushButton_Music_pressed(){makeSound.startClickEffects();}
void categories::on_pushButton_Science_pressed(){ makeSound.startClickEffects();}
void categories::on_push_Button_Random_pressed(){  makeSound.startClickEffects();}




QString categories::getQuestion(int indexnumber){
mc = new multiplechoice();
if(buttonOfgeographyIsClick){return mc->getGeographyQuestion(indexnumber);}
if(buttonOfanimalIsClick){return mc->getAnimalsQuestions(indexnumber);}
if(buttonOfhistoryIsClick){return mc->getHistoryQuestions(indexnumber);}
if(buttonOfSportsIsClick){return mc->getSportsQuestion(indexnumber);}
if(buttonOfHumantiesIsClick){return mc->getHumanitiesQuestion(indexnumber);}
if(buttonOfTechnologyIsClick){return mc->getTechnologyQuestions(indexnumber);}
if(buttonOfMusicIsClick){return mc->getMusicQuestion(indexnumber);}
if(buttonOfWorldIsClick){return mc->getWorldQuestions(indexnumber);}
if(buttonOfRandomIsClick){return mc->getRandomQuestions(indexnumber);}
if(buttonOfScienceIsClick){return mc->getScienceQuestions(indexnumber);    }
return NULL;
}








QString categories::getChoices(int column, int row){
mc = new multiplechoice();
if(buttonOfgeographyIsClick){return mc->getGeographyChoices(column,row);}
if(buttonOfanimalIsClick){return mc->getAnimalsChoices(column,row);}
if(buttonOfhistoryIsClick){return mc->getHistoryChoices(column,row);}
if(buttonOfSportsIsClick){return mc->getSportsChoices(column,row);}
if(buttonOfHumantiesIsClick){return mc->getHumanitiesChoices(column,row);}
if(buttonOfTechnologyIsClick){return mc->getTechnologyChoices(column,row);}
if(buttonOfMusicIsClick){return mc->getMusicChoices(column,row);}
if(buttonOfWorldIsClick){return mc->getWorldChoices(column,row);}
if(buttonOfRandomIsClick){return mc->getRandomChoices(column,row);}
if(buttonOfScienceIsClick){return mc->getScienceChoices(column,row);    }
return NULL;
}




char categories::getAnswer(int indexnumber){
  mc = new multiplechoice();
if(buttonOfgeographyIsClick){return mc->getGeographyAnswers(indexnumber);}
if(buttonOfanimalIsClick){return mc->getAnimalsAnswers(indexnumber);}
if(buttonOfhistoryIsClick){return mc->getHistoryAnswers(indexnumber);}
if(buttonOfSportsIsClick){return mc->getSportsAnswer(indexnumber);}
if(buttonOfHumantiesIsClick){return mc->getHumanitiesAnswers(indexnumber);}
if(buttonOfTechnologyIsClick){return mc->getTechnologyAnswers(indexnumber);}
if(buttonOfMusicIsClick){return mc->getMusicAnswer(indexnumber);}
if(buttonOfWorldIsClick){return mc->getWorldAnswers(indexnumber);}
if(buttonOfRandomIsClick){return mc->getRandomAnswers(indexnumber);}
if(buttonOfScienceIsClick){return mc->getScienceAnswers(indexnumber);}
return '\n'; //can't be null
}

void categories::resetButtonState(){
  buttonOfanimalIsClick=false;
  buttonOfgeographyIsClick=false;
  buttonOfhistoryIsClick=false;
  buttonOfSportsIsClick = false;
  buttonOfHumantiesIsClick =false;
  buttonOfTechnologyIsClick = false;
  buttonOfMusicIsClick = false;
  buttonOfWorldIsClick = false;
  buttonOfRandomIsClick = false;
  buttonOfScienceIsClick = false;
}






void categories::showMultiplechoiceForm(){

   this->close();
  GeographyWindow  *gw = new GeographyWindow(this);
  gw->show();

}


categories::~categories()
{
    delete ui;
}













