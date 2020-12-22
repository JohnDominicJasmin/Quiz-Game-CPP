#include "trueorfalse.h"
#include "ui_trueorfalse.h"
#include <QMovie>
#include <mainwindoww.h>
#include "soundsettings.h"
#include "QDesktopWidget"
#include <QStyle>
//Global Variables

int theNumberOfIndex;
int numberOfStreak;
int NumberOfCorrectAnswers;
int numberOflivesLeft  = 3;
int NumberOfWrongAnswers;
int count = 0;
TrueOrFalse::TrueOrFalse(QWidget *parent) :QDialog(parent),ui(new Ui::TrueOrFalse){
  ui->setupUi(this);
  this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
  QDialog::setFixedSize(546,QApplication::desktop()->height());
  QMovie *movie = new QMovie(":/bGrounds/backgrounds/trophy.gif");
  ui->trophy_gif->setMovie(movie);
  movie->start();



hideResultsIfCorrectOrWrong();
displayNextQuestions();
hideFactsDisplay();
displayLivesRemaining();
hideGameOver();

}




void TrueOrFalse::on_pushButton_Continue_clicked()
{
    displayNextQuestions();
    hideResultsIfCorrectOrWrong();
    enableButtons();
    hideFactsDisplay();
}


void TrueOrFalse::on_pushButton_True_clicked(){

if('T' == FromMainFormTo.getAnswers(theNumberOfIndex)){
    ++numberOfStreak;
    ++NumberOfCorrectAnswers;
    showCorrectResults();
    makeCorrectAnswerSounds();

  }else{

    ++NumberOfWrongAnswers;
    --numberOflivesLeft;
    numberOfStreak = 0;
    showWrongResults();
  makeWrongAnswerSounds();
  }
showFactsDisplay();
displayNextTrivia();
disableTheButtons();
displayLivesRemaining();
}



void TrueOrFalse::on_pushButton_False_clicked()
{

  if('F' == FromMainFormTo.getAnswers(theNumberOfIndex)){
      ++numberOfStreak;
      ++NumberOfCorrectAnswers;
      showCorrectResults();
   makeCorrectAnswerSounds();
    }else{
      ++NumberOfWrongAnswers;
      --numberOflivesLeft;
      numberOfStreak = 0;
      showWrongResults();
    makeWrongAnswerSounds();
    }
  ++count;
showFactsDisplay();
displayNextTrivia();
disableTheButtons();
displayLivesRemaining();

}


void TrueOrFalse::on_pushButton_Retry_clicked()
{
     displayNextQuestions();
     hideGameOver();
     setAllToDefault();
   ui->pushButton_Continue->setEnabled(true);
   hideResultsIfCorrectOrWrong();
   enableButtons();
   hideFactsDisplay();
}

void TrueOrFalse::on_pushButton_MainMenu_clicked()
{
    setAllToDefault();
    hideGameOver();
 ui->pushButton_Continue->setEnabled(true);
 showMainMenu();
}

void TrueOrFalse::setAllToDefault(){
  numberOfStreak = 0;
  NumberOfCorrectAnswers = 0;
  numberOflivesLeft  = 3;
  NumberOfWrongAnswers = 0;
}
void TrueOrFalse::on_pushButton_Continue_pressed(){makeClickingSounds();}
void TrueOrFalse::on_pushButton_Retry_pressed(){makeClickingSounds();setAllToDefault();displayLivesRemaining();}
void TrueOrFalse::on_pushButton_MainMenu_pressed(){makeClickingSounds();}










void TrueOrFalse::showResults(){

 QString text[] =  {QString::number(NumberOfCorrectAnswers),QString::number(NumberOfWrongAnswers)};

  ui->label_CorrectAnswer->setText("Correct Answers: "+ text[0]);
    ui->label_WrongAnswers->setText("Wrong Answers: "+ text[1]);
}


void TrueOrFalse::disableTheButtons(){
  ui->pushButton_True->setEnabled(false);
  ui->pushButton_False->setEnabled(false);
}



void TrueOrFalse::enableButtons(){
  ui->pushButton_True->setEnabled(true);
  ui->pushButton_False->setEnabled(true);
}





void TrueOrFalse::displayNextQuestions(){
  srand(time(0));
  theNumberOfIndex = rand()%195;
  ui->plainTextEdit_Questions->setPlainText(FromMainFormTo.getQuestion(theNumberOfIndex));

}

void TrueOrFalse::displayLivesRemaining(){
if(numberOfStreak==5){
    ++numberOflivesLeft;
    numberOfStreak=0;
    if(numberOflivesLeft>3){
        numberOflivesLeft=3;
      }
  }
ui->heart1->setStyleSheet(FromMainFormTo.getLivesPicture());
ui->Heart2->setStyleSheet(FromMainFormTo.getLivesPicture());
ui->Heart3->setStyleSheet(FromMainFormTo.getLivesPicture());
if(numberOflivesLeft==3){
    ui->heart1->setVisible(true);
    ui->Heart2->setVisible(true);
    ui->Heart3->setVisible(true);
  }
if(numberOflivesLeft==2){
    ui->heart1->setVisible(true);
    ui->Heart2->setVisible(true);
    ui->Heart3->setVisible(false);
  }
if(numberOflivesLeft==1){
    ui->heart1->setVisible(true);
    ui->Heart2->setVisible(false);
    ui->Heart3->setVisible(false);
  }
if(numberOflivesLeft==0){

    ui->heart1->setVisible(false);
    ui->Heart2->setVisible(false);
    ui->Heart3->setVisible(false);
   disableTheButtons();
  showGameOver();
  ui->pushButton_Continue->setEnabled(false);
  showResults();
  makeGameOverSounds();
  }



}


void TrueOrFalse::showFactsDisplay(){
  ui->plainTextEdit_Trivia->setVisible(true);
  ui->pushButton_Continue->setVisible(true);
}
void TrueOrFalse::hideFactsDisplay(){
  ui->plainTextEdit_Trivia->setVisible(false);
  ui->pushButton_Continue->setVisible(false);
}
void TrueOrFalse::displayNextTrivia(){
  ui->plainTextEdit_Trivia->setPlainText(FromMainFormTo.getExplanation(theNumberOfIndex));
}

void TrueOrFalse::showCorrectResults(){
  ui->labelIconCorrect->setVisible(true);
  ui->labelResults->setVisible(true);
  ui->labelResults->setText("           CORRECT!");
  ui->labelResults->setStyleSheet("background-color: rgba(0, 255, 0,60);");
  ui->labelIconCorrect->setStyleSheet("background-image:url(:/icons/icons/check.png); background-repeat:no-repeat;");


}
void TrueOrFalse::showWrongResults(){
  ui->labelIconWrong->setVisible(true);
  ui->labelResults->setVisible(true);
  ui->labelResults->setText("            WRONG!");
   ui->labelResults->setStyleSheet("background-color: rgba(247, 0, 0,75);");
   ui->labelIconWrong->setStyleSheet("background-image:url(:/icons/icons/wrong.png);background-repeat:no-repeat;");
}
void TrueOrFalse::hideResultsIfCorrectOrWrong(){
  ui->labelIconCorrect->setVisible(false);
  ui->labelIconWrong->setVisible(false);
  ui->labelResults->setVisible(false);
}
void TrueOrFalse::showGameOver(){
  ui->widget->setVisible(true);
  ui->label_darkeffects->setVisible(true);
}
void TrueOrFalse::hideGameOver(){
  ui->widget->setVisible(false);
  ui->label_darkeffects->setVisible(false);
}


void TrueOrFalse::showMainMenu(){
  this->close();
  mainwindoww *mw = new mainwindoww(this);
  mw->show();
}

void TrueOrFalse::makeClickingSounds(){
 SE.startClickEffects();
}

void TrueOrFalse::makeWrongAnswerSounds(){
  SE.startwrongAnswerEffects();
}
void TrueOrFalse::makeCorrectAnswerSounds(){
  SE.startcorrectAnswerEffects();
}
void TrueOrFalse::makeGameOverSounds(){
 SE.startgameOverEffects();
}










TrueOrFalse::~TrueOrFalse()
{
  delete ui;
}

