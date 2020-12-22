#include "soundsettings.h"
#include "ui_soundsettings.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QUrl>
#include <QMessageBox>
#include <QProcess>
#include <QFile>

bool decision;


soundSettings::soundSettings(QWidget *parent) :QDialog(parent),ui(new Ui::soundSettings){
  ui->setupUi(this);

  this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
 setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);



  SoundForClick = new QMediaPlayer;
   SoundWhenGameOver = new QMediaPlayer;
     SoundWhenCorrectAnswer = new QMediaPlayer;
      SoundWhenOutOfTime = new QMediaPlayer;
       SoundWhenTImerIsLessThan5 = new QMediaPlayer;
        SoundWhenWrongAnswer = new QMediaPlayer;
        BackgroundMusic = new QMediaPlayer;
          QDialog::setFixedSize(402,470);

          SoundForClick->setMedia(QUrl("qrc:/SoundEffects/SoundEffects/clicksound.wav"));
         SoundWhenGameOver->setMedia(QUrl("qrc:/SoundEffects/SoundEffects/congratulation.wav"));
        SoundWhenCorrectAnswer->setMedia(QUrl("qrc:/SoundEffects/SoundEffects/cor.wav"));
       SoundWhenOutOfTime->setMedia(QUrl("qrc:/SoundEffects/SoundEffects/buzzer.wav"));
    SoundWhenWrongAnswer->setMedia(QUrl("qrc:/SoundEffects/SoundEffects/wro.wav"));

    qst = new QSettings;
    qst1 = new QSettings;
decision = false;
loadStateOfCheckboxForMusic();
loadStateofCheckboxForSound();


}

soundSettings::~soundSettings()
{
  delete ui;
}







// CHANGE FILE LOCATION OF THE MUSIC BACKGROUND

QString ThisIsTheFileAddress = "/home/micojasmin";



void soundSettings::playBackgroundMusic(){

   BackgroundMusic->setMedia(QUrl::fromLocalFile( ThisIsTheFileAddress+"/quizAppGroup_1/SoundEffects/bGm.mp3"));
   BackgroundMusic->setVolume(100);
   if(!BackgroundMusic->isAvailable()||QMediaPlayer::EndOfMedia){

       BackgroundMusic->setPosition(0);
     }


  if(ui->checkBoxMusic->isChecked()){
  if(BackgroundMusic->state()==QMediaPlayer::PlayingState){
      BackgroundMusic->setPosition(0);
    }else if(BackgroundMusic->state()== QMediaPlayer::StoppedState){
      BackgroundMusic->play();
    }
    }else{
      BackgroundMusic->stop();
    }
}


void soundSettings::startClickEffects(){
SoundForClick->setVolume(120);
  if (ui->checkboxSound->isChecked()){
      if(SoundForClick->state()==QMediaPlayer::PlayingState){
          SoundForClick->setPosition(0);
        }else if(SoundForClick->state()== QMediaPlayer::StoppedState){
          SoundForClick->play();
        }
  } else{
     SoundForClick->stop();
   }

}


void soundSettings::startgameOverEffects(){

  if (ui->checkboxSound->isChecked()){
      if(SoundWhenGameOver->state()==QMediaPlayer::PlayingState){
          SoundWhenGameOver->setPosition(0);
        }else if(SoundWhenGameOver->state()== QMediaPlayer::StoppedState){
          SoundWhenGameOver->play();
        }
   }
  else{
      SoundWhenGameOver->stop();
    }

}


void soundSettings::startcorrectAnswerEffects(){
SoundWhenCorrectAnswer->setVolume(50);
  if (ui->checkboxSound->isChecked()){
      if(SoundWhenCorrectAnswer->state()==QMediaPlayer::PlayingState){
          SoundWhenCorrectAnswer->setPosition(0);
        }else if(SoundWhenCorrectAnswer->state()== QMediaPlayer::StoppedState){
          SoundWhenCorrectAnswer->play();
        }
   }
  else{
     SoundWhenCorrectAnswer->stop();
    }

}

void soundSettings::startwrongAnswerEffects(){
SoundWhenWrongAnswer->setVolume(50);
  if (ui->checkboxSound->isChecked()){
      if(SoundWhenWrongAnswer->state()==QMediaPlayer::PlayingState){
          SoundWhenWrongAnswer->setPosition(0);
        }else if(SoundWhenWrongAnswer->state()== QMediaPlayer::StoppedState){
          SoundWhenWrongAnswer->play();
        }
   }
  else{
       SoundWhenWrongAnswer->stop();
    }

}


void soundSettings::startoutOftimeEffects(){

  if (ui->checkboxSound->isChecked()){
      if(SoundWhenOutOfTime->state()==QMediaPlayer::PlayingState){
          SoundWhenOutOfTime->setPosition(0);
        }else if(SoundWhenOutOfTime->state()== QMediaPlayer::StoppedState){
          SoundWhenOutOfTime->play();
        }
   }
  else{
      SoundWhenOutOfTime->stop();
     }

}


void soundSettings::saveStateofCheckboxForSound(){ 
  qst->setValue("checkstate",ui->checkboxSound->isChecked()); 
}
void soundSettings::loadStateofCheckboxForSound(){
  ui->checkboxSound->setChecked(qst->value("checkstate").toBool());
}




void soundSettings::saveStateOfCheckBoxForMusic(){
  qst1->setValue("checkstate1",ui->checkBoxMusic->isChecked());
}
void soundSettings::loadStateOfCheckboxForMusic(){
  ui->checkBoxMusic->setChecked(qst1->value("checkstate1").toBool());
}






void soundSettings::on_pushButton_clicked()
{

  QMessageBox::StandardButton response;
  if(decision){

  response = QMessageBox::information(this," ","The game must restart to make changes.",QMessageBox::Ok|QMessageBox::Cancel);
  if(response == QMessageBox::Ok){
      qApp->quit();
     QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
  }if(response == QMessageBox::Cancel){
      this->close();
    }


    }else{
      this->close();
    }
  saveStateOfCheckBoxForMusic();
  saveStateofCheckboxForSound();
}








void soundSettings::on_pushButton_pressed(){
    startClickEffects();
}

void soundSettings::on_checkboxSound_clicked(){
    startClickEffects();
}

void soundSettings::on_checkBoxMusic_clicked(){
 saveStateOfCheckBoxForMusic();
 decision = true;
}










