#ifndef GEOGRAPHYWINDOW_H
#define GEOGRAPHYWINDOW_H

#include <QDialog>
#include <QTimer>
#include "multiplechoice.h"
#include "categories.h"
#include "soundsettings.h"



namespace Ui {
class GeographyWindow;
}
class GeographyWindow : public QDialog{
    Q_OBJECT

public:
  explicit GeographyWindow(QWidget *parent = nullptr);

void results(); // to be use
    void showCorrectAnswer();
    void addScoreAccordingWhatTimeLeft();
    void ifGameOverThenShowThis();
    void removeAnsweredQuestion();
    void NextSlideStart(int x,int y,int z);
    void pause_Timer();
    void resume_Timer();
    void checkPauseRemaining();
    void setScoreToZero();
    void setAllToDefault();
    void showMainmenu();
    void resetTheChosenTopic();
    void removeNullDisplay();
    void checkIfAnswerIs(char answer);
    void showGameOverWindow();
    void closeGameOverWindow();
    void closePlayButton();
    void closePauseButton();
    void showPauseButton();
    void showPlayButton();
    void disableButtons();
    void enableButtons();
    void hideLives();
~GeographyWindow();

private slots:
    void on_pushButton_A_clicked();
    void on_pushButton_B_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_D_clicked();



    void on_pushButton_Retry_clicked();

    void on_pushButton_MainMenu_clicked();

    void on_pushButton_Leave_clicked();

    void on_pauseButton_clicked();

    void on_pushButton_Play_clicked();

    void on_pushButton_Play_pressed();

    void on_pauseButton_pressed();

public slots:
      void displayLivesLeft();
      void ResetBackgroundColors();
      void nextQuestions();
      void SecondsForCountdown();


private:
    Ui::GeographyWindow *ui;

    QTimer *timeTodisplayLivesLeft, *timeDelayForResetbackgroundColors,*timeDelayForNextQuestion,*Seconds_For_Timer;
    categories cate;
    multiplechoice mc;
    soundSettings makeSound;

};


#endif // GEOGRAPHYWINDOW_H
