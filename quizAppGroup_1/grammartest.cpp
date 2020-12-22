#include "grammartest.h"
#include "ui_grammartest.h"
#include <QDesktopWidget>
#include "mainwindoww.h"
#include <QStyle>
#include <QMovie>



int timer=21;
int indexOf;
int points;
int correctAnswers;
int wrongAnswers;
int liveleft = 3;
int streakNum = 0;

GrammarTest::GrammarTest(QWidget *parent) :QDialog(parent), ui(new Ui::GrammarTest)
{
  ui->setupUi(this);
  this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
  int height = QApplication::desktop()->height();
  QDialog::setFixedSize(550,height);
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);


  mytimer = new QTimer(this);
  displayLives = new QTimer(this);
  resetbackgrounds = new QTimer(this);
  nextquestion = new QTimer(this);
  gameOver = new QTimer(this);

  connect(mytimer,SIGNAL(timeout()),this,SLOT(secondsTimer()));
  connect(displayLives,SIGNAL(timeout()),this,SLOT(displayLivesLeft()));
  connect(resetbackgrounds,SIGNAL(timeout()),this,SLOT(resetButtonBackgroundToDefault()));
  connect(nextquestion,SIGNAL(timeout()),this,SLOT(nextQuestions()));
  connect(gameOver,SIGNAL(timeout()),this,SLOT(showGameOver()));

  QMovie *movie = new QMovie(":/bGrounds/backgrounds/trophy.gif");
  ui->trophy_gif->setMovie(movie);
  movie->start();
  ui->widget_2->setFixedSize(435,461);

playtimer();
 nextQuestions();
displayLivesLeft();
hideContinueButtons();
closeGameOver();
removeNullDisplay();
}

void GrammarTest::on_pushButton_A_clicked(){
  checkAnswerIf('A');
  if(trivia.getAnswer(indexOf) != 'A'){
      ui->pushButton_A->setStyleSheet(gq.getRedButtonColor());
   }


}

void GrammarTest::on_pushButton_B_clicked()
{
  checkAnswerIf('B');
  if(trivia.getAnswer(indexOf) != 'B'){
      ui->pushButton_B->setStyleSheet(gq.getRedButtonColor());
   }

}

void GrammarTest::on_pushButton_C_clicked()
{
  checkAnswerIf('C');
  if(trivia.getAnswer(indexOf) != 'C'){
      ui->pushButton_C->setStyleSheet(gq.getRedButtonColor());
   }

}

void GrammarTest::on_pushButton_D_clicked()
{
checkAnswerIf('D');
if(trivia.getAnswer(indexOf) != 'D'){
       ui->pushButton_D->setStyleSheet(gq.getRedButtonColor());
}

}

void GrammarTest::on_pushButton_Continue_clicked()
{
timer = 21;
playtimer();
enableButtons();
hideContinueButtons();
nextSlide(400,400,400);
}

void GrammarTest::on_pushButton_Retry_clicked()
{
  timer = 21;
  nextSlide(200,200,200);
  closeGameOver();
    setAllToDefault();
    playtimer();
    disableButtons();
    hideContinueButtons();

}

void GrammarTest::on_pushButton_MainMenu_clicked()
{

   this->close();
  mainwindoww *mw = new mainwindoww(this);
  mw->show();
  setAllToDefault();
closeGameOver();
trivia.resetbuttonstate();

}
void GrammarTest::showGreenButtonIfCorrect(){
  if(trivia.getAnswer(indexOf) == 'A'){
   ui->pushButton_A->setStyleSheet(gq.getGreenButtonColor());
    }if(trivia.getAnswer(indexOf) == 'B'){
    ui->pushButton_B->setStyleSheet(gq.getGreenButtonColor());
   }if(trivia.getAnswer(indexOf) == 'C'){
   ui->pushButton_C->setStyleSheet(gq.getGreenButtonColor());
   }if(trivia.getAnswer(indexOf)== 'D'){
   ui->pushButton_D->setStyleSheet(gq.getGreenButtonColor());
   }
}
void GrammarTest::resetButtonBackgroundToDefault(){
  enableButtons();
ui->pushButton_A->setStyleSheet(gq.getDefaultButtonColor());
    ui->pushButton_B->setStyleSheet(gq.getDefaultButtonColor());
    ui->pushButton_C->setStyleSheet(gq.getDefaultButtonColor());
    ui->pushButton_D->setStyleSheet(gq.getDefaultButtonColor());

}
void GrammarTest::nextQuestions(){
  srand(time(0));
  indexOf = rand()%200;


  ui->plainTextEdit_Question->setPlainText(trivia.getQuestions(indexOf));
    ui->pushButton_A->setText(trivia.getChoices(indexOf,0));
     ui->pushButton_B->setText(trivia.getChoices(indexOf,1));
       ui->pushButton_C->setText(trivia.getChoices(indexOf,2));
         ui->pushButton_D->setText(trivia.getChoices(indexOf,3));

}

void GrammarTest::playtimer(){
  mytimer->start(1000);
}
void GrammarTest::pausetimer(){
  mytimer->stop();
}
void GrammarTest::secondsTimer(){
  timer-=1;

    if(timer<=7){
          ui->label_DisplayForTimer->setStyleSheet(mc.getlcdDisplayNumberRedColor());
      }else{
        ui->label_DisplayForTimer->setStyleSheet(mc.getlcdDisplayDefaultColor());
      }

    QString displaySeconds = QString::number(timer);
      ui->label_DisplayForTimer->setText(" "+displaySeconds);
    if(timer<=9){
        ui->label_DisplayForTimer->setText("  "+displaySeconds);
      }if(timer == 0 ){

         startOutOfTimeEffects();
        displayLives->setSingleShot(true);
        displayLives->start(600);
        --liveleft;
        displayLivesLeft();
        disableButtons();
        showContinueButtons();
        pausetimer();


      }
}
void GrammarTest::addScore(){
  if(timer>=16){
      points += 20;
    }else if(timer>=10&&timer<=15){
      points += 15;
    }else if(timer<=9&&timer>=5){
      points += 7;
    }else{
      points += 3;
    }

 QString str = QString::number(points);
ui->label_ScoreBoard->setText("SCORE: "+str);
}



void GrammarTest::checkAnswerIf(char ans){
  if(trivia.getAnswer(indexOf)==ans){

    addScore();
    ++streakNum;
    ++correctAnswers;
    startCorrectAnswerEffects();
    }else{
      --liveleft;
      streakNum = 0;
      ++wrongAnswers;
      startWrongAnswerEffects();
    }

showGreenButtonIfCorrect();
disableButtons();
pausetimer();
displayLivesLeft();
showContinueButtons();
}




void GrammarTest::hideContinueButtons(){
  ui->pushButton_Continue->setVisible(false);
}
void GrammarTest::showContinueButtons(){
   ui->pushButton_Continue->setVisible(true);
}

void GrammarTest::disableButtons(){
  ui->pushButton_A->setEnabled(false);
    ui->pushButton_B->setEnabled(false);
      ui->pushButton_C->setEnabled(false);
        ui->pushButton_D->setEnabled(false);

}
void GrammarTest::enableButtons(){
  ui->pushButton_A->setEnabled(true);
    ui->pushButton_B->setEnabled(true);
      ui->pushButton_C->setEnabled(true);
        ui->pushButton_D->setEnabled(true);
}

void GrammarTest::displayLivesLeft(){
if(streakNum==5){
    ++liveleft;
    streakNum = 0;
    if(liveleft>3){
        liveleft =3;
      }
  }

ui->lblLive3->setStyleSheet(gq.getLivesBackground());
  ui->lblLive2->setStyleSheet(gq.getLivesBackground());
    ui->lblLive1->setStyleSheet(gq.getLivesBackground());
    switch (liveleft) {
      case 3:
        ui->lblLive1->setVisible(true);
         ui->lblLive2->setVisible(true);
          ui->lblLive3->setVisible(true);
        break;
      case 2:
         ui->lblLive1->setVisible(true);
          ui->lblLive2->setVisible(true);
           ui->lblLive3->setVisible(false);
        break;
      case 1:
         ui->lblLive1->setVisible(true);
          ui->lblLive2->setVisible(false);
           ui->lblLive3->setVisible(false);
        break;
      case 0:
        startgameOverEffects();
        ui->lblLive1->setVisible(false);
         ui->lblLive1->setVisible(false);
          ui->lblLive1->setVisible(false);
            pausetimer();
            hideContinueButtons();
          showresults();
         gameOver->setSingleShot(true);
          gameOver->start(450);

         break;


      }
}
void GrammarTest::setAllToDefault(){
  correctAnswers = 0;
  wrongAnswers = 0;
  liveleft = 3;
  timer = 21;
  setScoreToZero();
}

void GrammarTest::showresults(){
  QString displayOverallScore[] = {QString::number(points),QString::number(correctAnswers),QString::number(wrongAnswers)};
ui->label_Score->setText("YOUR SCORE: "+displayOverallScore[0]);
ui->label_CorrectAnswer->setText("CORRECT ANSWERS: "+displayOverallScore[1]);
ui->label_WrongAnswers->setText("WRONG ANSWERS: "+displayOverallScore[2]);
}
void GrammarTest::showGameOver(){
 ui->widget_2->setVisible(true);
 ui->label_Darkeffects->setVisible(true);
}
void GrammarTest::closeGameOver(){
    ui->widget_2->setVisible(false);
     ui->label_Darkeffects->setVisible(false);
}
void GrammarTest::setScoreToZero(){
  points = 0;
  QString st = QString::number(points);
  ui->label_ScoreBoard->setText("SCORE: "+st);
}
void GrammarTest::nextSlide(int x, int y, int z){
  displayLives->setSingleShot(true);
  displayLives->start(x);

   resetbackgrounds->setSingleShot(true);
   resetbackgrounds->start(y);

   nextquestion->setSingleShot(true);
   nextquestion->start(z);


}
void GrammarTest::startclickeffects(){
  SE.startClickEffects();
}
void GrammarTest::startgameOverEffects(){
  SE.startgameOverEffects();
}
void GrammarTest::startWrongAnswerEffects(){
  SE.startwrongAnswerEffects();
}
void GrammarTest::startCorrectAnswerEffects(){
  SE.startcorrectAnswerEffects();
}
void GrammarTest::startOutOfTimeEffects(){
  SE.startoutOftimeEffects();
}
void GrammarTest::removeNullDisplay(){
  nextquestion->setSingleShot(true);
  nextquestion->start(1);
}
GrammarTest::~GrammarTest()
{
  delete ui;
}






void GrammarTest::on_pushButton_MainMenu_pressed()
{
    startclickeffects();
}

void GrammarTest::on_pushButton_Retry_pressed()
{
    startclickeffects();
}

void GrammarTest::on_pushButton_Continue_pressed()
{
    startclickeffects();
}


