#ifndef MAINWINDOWW_H
#define MAINWINDOWW_H

#include <QDialog>
#include "soundsettings.h"
#include "creditsform.h"
#include "triviatype.h"
namespace Ui {
  class mainwindoww;
}

class mainwindoww : public QDialog
{
  Q_OBJECT

public:
  explicit mainwindoww(QWidget *parent = nullptr);



  ~mainwindoww();
void makeclickSound();
void closeWindow();


private slots:

  void on_pushButton_Start_clicked();
  void on_pushButton_Start_pressed();


  void on_pushButton_Quit_clicked();
  void on_pushButton_Quit_pressed();


  void on_pushButton_Options_clicked();
  void on_pushButton_Options_pressed();

  void on_pushButton_Credits_pressed();






  void on_pushButton_Credits_clicked();

private:
  Ui::mainwindoww *ui;
soundSettings *SoundForm;
CreditsForm *cf;
TriviaType *trivia;
};

#endif // MAINWINDOWW_H
