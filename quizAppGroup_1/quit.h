#ifndef QUIT_H
#define QUIT_H

#include <QDialog>
#include "soundsettings.h"
namespace Ui {
  class Quit;
}

class Quit : public QDialog
{
  Q_OBJECT

public:
  explicit Quit(QWidget *parent = nullptr);
  ~Quit();
 void makeclickSound();
private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_pressed();

  void on_pushButton_2_pressed();

  void on_pushButton_3_pressed();


private:
  Ui::Quit *ui;
soundSettings *makeSound;
};

#endif // QUIT_H
