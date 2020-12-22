#ifndef SOUNDSETTINGS_H
#define SOUNDSETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QMediaPlayer>

namespace Ui {
  class soundSettings;
}

class soundSettings : public QDialog
{
  Q_OBJECT

public:
  explicit soundSettings(QWidget *parent = nullptr);
  ~soundSettings();


  void startClickEffects();
  void startgameOverEffects();
  void startcorrectAnswerEffects();
  void startwrongAnswerEffects();
  void startoutOftimeEffects();
  void playBackgroundMusic();

  void saveStateofCheckboxForSound();
  void loadStateofCheckboxForSound();
  void saveStateOfCheckBoxForMusic();
  void loadStateOfCheckboxForMusic();


private slots:
  void on_pushButton_clicked();

  void on_pushButton_pressed();

  void on_checkboxSound_clicked();





  void on_checkBoxMusic_clicked();

private:
  Ui::soundSettings *ui;
  QMediaPlayer *SoundForClick,
  *SoundWhenGameOver,
  *SoundWhenCorrectAnswer,
  *SoundWhenTImerIsLessThan5,
   *SoundWhenOutOfTime,
  *BackgroundMusic,
  *SoundWhenWrongAnswer;
  QSettings *qst;
  QSettings *qst1;

};

#endif // SOUNDSETTINGS_H
