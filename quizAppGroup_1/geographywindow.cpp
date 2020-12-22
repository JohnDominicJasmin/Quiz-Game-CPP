#include "geographywindow.h"
#include "ui_geographywindow.h"
#include <QPalette>
#include <QTimer>
#include "mainwindoww.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QMovie>
#include <QColor>


char user_answers;
 int correctAnswerByUser_Points ;
 int Number_Of_CorrectAnswers;
 int Number_Of_WrongAnswers;
 int livesLeft = 3;
 int streak = 0;
 int SecondsLeft = 21;
  int whatIndexOfQuestionIs;
  int pauseRemaining = 3;


GeographyWindow::GeographyWindow(QWidget *parent) : QDialog(parent), ui(new Ui::GeographyWindow){
   ui->setupUi(this);

setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
int width = QApplication::desktop()->width();
int height = QApplication::desktop()->height();
QDialog::setFixedSize(width,height);
ui->lblbackground->setFixedSize(width,height);
correctAnswerByUser_Points = 0;
QMovie *movie = new QMovie(":/bGrounds/backgrounds/trophy.gif");

ui->widget->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
ui->trophy_gif->setMovie(movie);
movie->start();


timeDelayForNextQuestion = new QTimer(this);
connect(timeDelayForNextQuestion,SIGNAL(timeout()),this,SLOT(nextQuestions()));

 timeDelayForResetbackgroundColors = new QTimer(this);
 connect(timeDelayForResetbackgroundColors,SIGNAL(timeout()),this,SLOT(ResetBackgroundColors()));

timeTodisplayLivesLeft = new  QTimer(this);
connect(timeTodisplayLivesLeft,SIGNAL(timeout()),this,SLOT(displayLivesLeft()));

Seconds_For_Timer = new QTimer(this);
connect(Seconds_For_Timer,SIGNAL(timeout()),this,SLOT(SecondsForCountdown()));



resume_Timer();
nextQuestions();
 displayLivesLeft();
removeNullDisplay();
closeGameOverWindow();
closePlayButton();
}



void GeographyWindow::on_pushButton_A_clicked(){
  checkIfAnswerIs('A');
  if(cate.getAnswer(whatIndexOfQuestionIs) != 'A'){
  ui->pushButton_A->setStyleSheet(mc.getRedButton());
    }
}


void GeographyWindow::on_pushButton_B_clicked(){
  checkIfAnswerIs('B');
if(cate.getAnswer(whatIndexOfQuestionIs) != 'B'){
       ui->pushButton_B->setStyleSheet(mc.getRedButton());
}
}


void GeographyWindow::on_pushButton_C_clicked(){
    checkIfAnswerIs('C');
    if(cate.getAnswer(whatIndexOfQuestionIs) != 'C'){
           ui->pushButton_C->setStyleSheet(mc.getRedButton());
    }
}


void GeographyWindow::on_pushButton_D_clicked(){
  checkIfAnswerIs('D');
  if(cate.getAnswer(whatIndexOfQuestionIs) != 'D'){
         ui->pushButton_D->setStyleSheet(mc.getRedButton());
  }
}


void GeographyWindow::on_pushButton_Retry_clicked()
{
    NextSlideStart(200,200,200);
    closeGameOverWindow();
    setAllToDefault();
    resume_Timer();
    setScoreToZero();
    showPauseButton();
}

void GeographyWindow::on_pushButton_MainMenu_clicked()
{
   showMainmenu();
  setAllToDefault();
  closeGameOverWindow();
    cate.resetButtonState();
}

void GeographyWindow::on_pushButton_Leave_clicked()
{
    QApplication::quit();
}

void GeographyWindow::on_pauseButton_clicked(){

  closePauseButton();
showPlayButton();
pause_Timer();
disableButtons();

}

void GeographyWindow::on_pushButton_Play_clicked()
{
closePlayButton();
showPauseButton();
resume_Timer();
enableButtons();
checkPauseRemaining();
}








void GeographyWindow::checkPauseRemaining(){
    if(pauseRemaining==0){closePauseButton(); }
}


void GeographyWindow::disableButtons(){
  ui->pushButton_A->setEnabled(false);
ui->pushButton_B->setEnabled(false);
 ui->pushButton_C->setEnabled(false);
  ui->pushButton_D->setEnabled(false);
}
void GeographyWindow::enableButtons(){
  ui->pushButton_A->setEnabled(true);
ui->pushButton_B->setEnabled(true);
 ui->pushButton_C->setEnabled(true);
  ui->pushButton_D->setEnabled(true);
}
void GeographyWindow::hideLives(){
  ui->lblLive3->setVisible(false);
ui->lblLive2->setVisible(false);
ui->lblLive1->setVisible(false);
}


void GeographyWindow::ifGameOverThenShowThis(){

  pause_Timer();
   results();
   showGameOverWindow();
    closePauseButton();
    timeDelayForNextQuestion->stop();
     timeDelayForResetbackgroundColors->stop();
     hideLives();

    disableButtons();
}
void GeographyWindow::showMainmenu(){
  this->close();
  mainwindoww *mw = new mainwindoww(this);
  mw->show();
}


void GeographyWindow::nextQuestions(){

  srand(time(0));
  whatIndexOfQuestionIs = rand()%200;

           ui->plainTextEdit_QuestionDisplay->setPlainText(cate.getQuestion(whatIndexOfQuestionIs));
             ui->pushButton_A->setText(cate.getChoices(whatIndexOfQuestionIs,0));
              ui->pushButton_B->setText(cate.getChoices(whatIndexOfQuestionIs,1));
                ui->pushButton_C->setText(cate.getChoices(whatIndexOfQuestionIs,2));
                  ui->pushButton_D->setText(cate.getChoices(whatIndexOfQuestionIs,3));

}


void  GeographyWindow::results(){

      QString displayOverallScore[] = {QString::number(correctAnswerByUser_Points),QString::number(Number_Of_CorrectAnswers),QString::number(Number_Of_WrongAnswers)};
    ui->label_Score->setText("Your Score: "+displayOverallScore[0]);
  ui->label_CorrectAnswer->setText("Correct Answers: "+displayOverallScore[1]);
ui->label_WrongAnswers->setText("Wrong Answers: "+displayOverallScore[2]);
}

void GeographyWindow::SecondsForCountdown(){
    SecondsLeft-=1;
    if(SecondsLeft<=7){
        ui->label_DisplayForTimer->setStyleSheet(mc.getlcdDisplayNumberRedColor());
      }else{
         ui->label_DisplayForTimer->setStyleSheet(mc.getlcdDisplayDefaultColor());
      }

      QString displaySeconds = QString::number(SecondsLeft);
        ui->label_DisplayForTimer->setText(" "+displaySeconds);


        if(SecondsLeft<=9){
             ui->label_DisplayForTimer->setText("  "+displaySeconds);//adds two blank spaces to center text
          }
       if(SecondsLeft==0){
           makeSound.startoutOftimeEffects();
           --livesLeft;
           displayLivesLeft();
           SecondsLeft=21;
           NextSlideStart(700,1000,1000);

         }
}


void GeographyWindow::pause_Timer(){
  Seconds_For_Timer->stop();
 // Seconds_For_Timer->setInterval(Seconds_For_Timer->remainingTime());
}


void GeographyWindow::resume_Timer(){
  Seconds_For_Timer->start(1000);
}


void GeographyWindow::ResetBackgroundColors(){

      enableButtons();
      ui->pushButton_A->setStyleSheet(mc.getDefaultColor_ofButton());
      ui->pushButton_B->setStyleSheet(mc.getDefaultColor_ofButton());
    ui->pushButton_C->setStyleSheet(mc.getDefaultColor_ofButton());
  ui->pushButton_D->setStyleSheet(mc.getDefaultColor_ofButton());


}

void GeographyWindow::NextSlideStart(int timeToDisplayLives,int timeDelayForQuestions,int timedelayForResetBackgrounds){
   timeTodisplayLivesLeft->setSingleShot(true);
  timeTodisplayLivesLeft->start(timeToDisplayLives);

     timeDelayForNextQuestion->setSingleShot(true);
   timeDelayForNextQuestion->start(timeDelayForQuestions);

       timeDelayForResetbackgroundColors->setSingleShot(true);
     timeDelayForResetbackgroundColors->start(timedelayForResetBackgrounds);

}

void GeographyWindow::removeNullDisplay(){
  timeDelayForNextQuestion->setSingleShot(true);
  timeDelayForNextQuestion->start(1);
}


void GeographyWindow::showCorrectAnswer(){
    disableButtons();
   if(cate.getAnswer(whatIndexOfQuestionIs) == 'A'){
    ui->pushButton_A->setStyleSheet(mc.getGreenButton());
     }if(cate.getAnswer(whatIndexOfQuestionIs) == 'B'){
     ui->pushButton_B->setStyleSheet(mc.getGreenButton());
    }if(cate.getAnswer(whatIndexOfQuestionIs) == 'C'){
    ui->pushButton_C->setStyleSheet(mc.getGreenButton());
    }if(cate.getAnswer(whatIndexOfQuestionIs)== 'D'){
    ui->pushButton_D->setStyleSheet(mc.getGreenButton());
    }

}


void GeographyWindow::displayLivesLeft(){

  if(streak==3){
      ++livesLeft;
      streak = 0;
      if(livesLeft>3){
          livesLeft=3;
        }
    }

   ui->lblLive3->setStyleSheet(mc.getLivesLeftPicture());
     ui->lblLive2->setStyleSheet(mc.getLivesLeftPicture());
       ui->lblLive1->setStyleSheet(mc.getLivesLeftPicture());
  if(livesLeft==3){
       ui->lblLive3->setVisible(true);
         ui->lblLive2->setVisible(true);
           ui->lblLive1->setVisible(true);
    }
  if(livesLeft==2){
         ui->lblLive3->setVisible(false);
       ui->lblLive2->setVisible(true);
     ui->lblLive1->setVisible(true);
     }
  if(livesLeft==1){
       ui->lblLive3->setVisible(false);
     ui->lblLive2->setVisible(false);
    ui->lblLive1->setVisible(true);
     }
  if(livesLeft==0){
      makeSound.startgameOverEffects();
     ifGameOverThenShowThis();



     }
}

void GeographyWindow::addScoreAccordingWhatTimeLeft(){
  if(SecondsLeft>=16){
      correctAnswerByUser_Points += 20;
    }else if(SecondsLeft>=10&&SecondsLeft<=15){
      correctAnswerByUser_Points += 15;
    }else if(SecondsLeft<=9&&SecondsLeft>=5){
      correctAnswerByUser_Points += 7;
    }else{
      correctAnswerByUser_Points += 3;
    }

 QString str = QString::number(correctAnswerByUser_Points);
ui->lblScore->setText("SCORE: "+str);
}




void GeographyWindow::setScoreToZero(){
  correctAnswerByUser_Points = 0;
  QString st = QString::number(correctAnswerByUser_Points);
  ui->lblScore->setText("SCORE: "+st);

}

void GeographyWindow::setAllToDefault(){
  Number_Of_CorrectAnswers = 0;
  Number_Of_WrongAnswers = 0;
  livesLeft=3;
  pauseRemaining = 3;
SecondsLeft = 21;

}




void GeographyWindow::closeGameOverWindow(){
  ui->widget->setVisible(false);//
   ui->anotherLabelBackground->setVisible(false);
}


void GeographyWindow::showGameOverWindow(){
  ui->widget->setVisible(true);
    ui->anotherLabelBackground->setVisible(true);
}



void GeographyWindow::closePlayButton(){

  ui->pushButton_Play->setVisible(false);
  ui->anotherLabelBackground->setVisible(false);
  ui->labelpausebackground->setVisible(false);
  ui->pauseText->setVisible(false);
  ui->labelpausebackground->setVisible(false);
  ui->label_PauseRemaining->setVisible(false);
}



void GeographyWindow::closePauseButton(){
  ui->pauseButton->setVisible(false);
}


void GeographyWindow::showPlayButton(){
  --pauseRemaining;
  ui->pushButton_Play->setVisible(true);
  ui->labelpausebackground->setVisible(true);
  ui->anotherLabelBackground->setVisible(true);
  ui->pauseText->setVisible(true);
  ui->labelpausebackground->setVisible(true);
  ui->label_PauseRemaining->setVisible(true);

   QString str = QString::number(pauseRemaining);
  ui->label_PauseRemaining->setText(" Pause Remaining: "+str);
}

void GeographyWindow::showPauseButton(){
  ui->pauseButton->setVisible(true);
}

void GeographyWindow::checkIfAnswerIs(char Answer){


  if(Answer==cate.getAnswer(whatIndexOfQuestionIs)){
       addScoreAccordingWhatTimeLeft();
        ++streak;
       ++Number_Of_CorrectAnswers;
         makeSound.startcorrectAnswerEffects();

  }else{
         --livesLeft;
         streak = 0;
        ++Number_Of_WrongAnswers;
        makeSound.startwrongAnswerEffects();
}
      NextSlideStart(900,1200,1200);//
        SecondsLeft= 21;
        showCorrectAnswer();
}




GeographyWindow::~GeographyWindow()
{
    delete ui;
}







void GeographyWindow::on_pushButton_Play_pressed()
{
    makeSound.startClickEffects();
}

void GeographyWindow::on_pauseButton_pressed()
{
     makeSound.startClickEffects();
}
