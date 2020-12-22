#include "optionswindow.h"
#include "ui_optionswindow.h"
#include "QStyle"
#include "QDesktopWidget"
#include "mainwindoww.h"
#include <QUrl>
OptionsWindow::OptionsWindow(QWidget *parent) :QDialog(parent),ui(new Ui::OptionsWindow){
  ui->setupUi(this);
  this->setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,this->size(),qApp->desktop()->availableGeometry()));
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    QDialog::setMinimumSize(340,391);
 QDialog::setMaximumSize(340,391);
loadStateProgressofSound();
  Qst = new QSettings;
}


bool OptionsWindow::musicCheckboxIsChecked(){
  return ui->checkBox_Music->isChecked();
}
bool OptionsWindow::soundCheckboxIsChecked(){
  return ui->checkBox_Sound->isChecked();
}


void OptionsWindow::saveStateProgressofSound(){

  Qst->setValue("checkstate",ui->checkBox_Sound->isChecked());
}


void OptionsWindow::loadStateProgressofSound(){
ui->checkBox_Sound->setChecked(Qst->value("checkstate").toBool());
}


void OptionsWindow::on_pushButton_OKAY_clicked()
{

    saveStateProgressofSound();
    this->close();

}


OptionsWindow::~OptionsWindow()
{
  delete ui;
}


void OptionsWindow::on_pushButton_OKAY_pressed()
{
  mainwindoww mw;
  mw.startClickEffects();

}
