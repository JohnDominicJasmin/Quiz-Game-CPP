#ifndef GRAMMARTEST_H
#define GRAMMARTEST_H

#include <QDialog>
#include <QTimer>
#include <triviatype.h>
#include "multiplechoice.h"
#include "grammarquiz.h"
#include "soundsettings.h"
namespace Ui {
  class GrammarTest;
}

class GrammarTest : public QDialog
{
  Q_OBJECT

public:
  explicit GrammarTest(QWidget *parent = nullptr);
  ~GrammarTest();

  void playtimer();
  void pausetimer();
  void addScore();
  void checkAnswerIf(char ans);
  void showGreenButtonIfCorrect();
  void disableButtons();
  void enableButtons();
  void setScoreToZero();
  void setAllToDefault();
  void nextSlide(int x,int y,int z);
  void hideContinueButtons();
  void showContinueButtons();
  void closeGameOver();
   void showresults();


   void startclickeffects();
   void startgameOverEffects();
   void startWrongAnswerEffects();
   void startCorrectAnswerEffects();
   void startOutOfTimeEffects();
   void removeNullDisplay();
public slots:
  void secondsTimer();
  void displayLivesLeft();
  void nextQuestions();
  void resetButtonBackgroundToDefault();
   void showGameOver();
private slots:
  void on_pushButton_A_clicked();
  void on_pushButton_B_clicked();
  void on_pushButton_C_clicked();
  void on_pushButton_D_clicked();
  void on_pushButton_Continue_clicked();



  void on_pushButton_Retry_clicked();

  void on_pushButton_MainMenu_pressed();

  void on_pushButton_Retry_pressed();

  void on_pushButton_Continue_pressed();

  void on_pushButton_MainMenu_clicked();

private:
  Ui::GrammarTest *ui;
  QTimer *mytimer,*displayLives,*resetbackgrounds,*nextquestion, *gameOver;
  TriviaType trivia;
  soundSettings SE;
  GrammarQuiz gq;
  multiplechoice mc;
};

#endif // GRAMMARTEST_H
