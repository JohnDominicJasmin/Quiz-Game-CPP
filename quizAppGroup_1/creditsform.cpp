#include "creditsform.h"
#include "ui_creditsform.h"

CreditsForm::CreditsForm(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CreditsForm)
{

  ui->setupUi(this);
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
  ui->tabWidget->setTabText(0,"Credits");
  ui->tabWidget->setTabText(1,"Rules");
  this->setFixedSize(450,650);
}

CreditsForm::~CreditsForm()
{
  delete ui;
}

void CreditsForm::on_pushButton_clicked()
{
this->close();
}

void CreditsForm::on_pushButton_2_clicked()
{
    this->close();
}

void CreditsForm::on_pushButton_2_pressed()
{
    makeClickSound();
}

void CreditsForm::on_pushButton_pressed()
{
    makeClickSound();
}
void CreditsForm::makeClickSound(){
  se = new soundSettings(this);
  se->startClickEffects();
}
