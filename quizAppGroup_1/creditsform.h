#ifndef CREDITSFORM_H
#define CREDITSFORM_H

#include <QDialog>
#include "soundsettings.h"
namespace Ui {
  class CreditsForm;
}

class CreditsForm : public QDialog
{
  Q_OBJECT

public:
  explicit CreditsForm(QWidget *parent = nullptr);
  ~CreditsForm();
void makeClickSound();
private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_2_pressed();

  void on_pushButton_pressed();

private:
  Ui::CreditsForm *ui;
  soundSettings *se;
};

#endif // CREDITSFORM_H
