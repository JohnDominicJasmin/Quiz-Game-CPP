#include "triviatype.h"
#include "ui_triviatype.h"
#include "categories.h"
#include "mainwindoww.h"
#include "soundsettings.h"
#include "fillinttheblanks.h"
#include "grammartest.h"


static bool FillIntTheBlanksBttnIsClicked,BonusQuizIsClicked;

TriviaType::TriviaType(QWidget *parent) :QDialog(parent),ui(new Ui::TriviaType){
    ui->setupUi(this);
     setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
     QDialog::setFixedSize(470,643);
}



void TriviaType::on_MultipleChoice_clicked()
{
   this->close();
categories *mc = new categories(this);
mc->show();
}

void TriviaType::on_trueOrFalse_clicked()
{
  this->close();
    True_Or_False_Form =new TrueOrFalse(this);
   True_Or_False_Form->show();
}

void TriviaType::on_pushButton_clicked()
{
    this->close();
  mainwindoww *mw = new mainwindoww(this);
  mw->show();
}

void TriviaType::on_FillInTheBlanks_clicked()
{
  this->close();
GrammarTest *gt = new GrammarTest(this);
gt->show();
FillIntTheBlanksBttnIsClicked = true;

}
void TriviaType::on_bonusQuiz_clicked()
{
  this->close();
 GrammarTest *gt = new GrammarTest(this);
gt->show();
BonusQuizIsClicked = true;
}









void TriviaType::resetbuttonstate(){
  BonusQuizIsClicked = false;
  FillIntTheBlanksBttnIsClicked = false;
}


QString TriviaType::getQuestions(int index){
  gq = new GrammarQuiz();
  if(FillIntTheBlanksBttnIsClicked){return gq->getQuestion(index);}
  if(BonusQuizIsClicked){return gq->getQuestionBonusQuiz(index);}
  return NULL;
}

QString TriviaType::getChoices(int col, int row){
  gq= new GrammarQuiz();
  if(FillIntTheBlanksBttnIsClicked){return gq->getChoices(col,row);}
      if(BonusQuizIsClicked){return gq->getChoicesBonusQuiz(col,row);}
      return NULL;
}
char TriviaType::getAnswer(int index){
  gq=new GrammarQuiz();
  if(FillIntTheBlanksBttnIsClicked){return gq->getAnswers(index);}
    if(BonusQuizIsClicked){return gq->getAnswerBonusQuiz(index);}
    return '\n';
}












void TriviaType::on_trueOrFalse_pressed()
{
   makeClickingSounds();
}

void TriviaType::on_MultipleChoice_pressed()
{
    makeClickingSounds();
}

void TriviaType::on_pushButton_pressed()
{
    makeClickingSounds();
}
void TriviaType::on_FillInTheBlanks_pressed()
{
     makeClickingSounds();
}

void TriviaType::on_bonusQuiz_pressed()
{
     makeClickingSounds();
}
void TriviaType::makeClickingSounds(){
  soundSettings *ss = new soundSettings(this);
  ss->startClickEffects();
}
TriviaType::~TriviaType()
{
    delete ui;
}









