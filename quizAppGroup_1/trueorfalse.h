#ifndef TRUEORFALSE_H
#define TRUEORFALSE_H
#include "trueorfalsequestions.h"
#include "multiplechoice.h"
#include <QDialog>
#include "soundsettings.h"

namespace Ui {
  class TrueOrFalse;
}

class TrueOrFalse : public QDialog
{
  Q_OBJECT

public:
  explicit TrueOrFalse(QWidget *parent = nullptr);
  ~TrueOrFalse();
  void disableTheButtons();
  void enableButtons();
  void displayNextQuestions();
  void displayLivesRemaining();
  void showFactsDisplay();
  void hideFactsDisplay();
  void displayNextTrivia();
  void hideResultsIfCorrectOrWrong();
  void showCorrectResults();
  void showWrongResults();
  void showGameOver();
  void hideGameOver();
  void setAllToDefault();
  void showMainMenu();
  void showResults();


  void makeClickingSounds();
  void makeWrongAnswerSounds();
  void makeCorrectAnswerSounds();
  void makeGameOverSounds();

private slots:

  void on_pushButton_True_clicked();

  void on_pushButton_False_clicked();

  void on_pushButton_Continue_clicked();

  void on_pushButton_Retry_clicked();

  void on_pushButton_MainMenu_clicked();



  void on_pushButton_Continue_pressed();

  void on_pushButton_Retry_pressed();

  void on_pushButton_MainMenu_pressed();

private:
  Ui::TrueOrFalse *ui;
  trueOrfalseQuestions FromMainFormTo;
  multiplechoice mc;
  soundSettings SE;

};

#endif // TRUEORFALSE_H
