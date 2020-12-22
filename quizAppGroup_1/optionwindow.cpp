#include "optionwindow.h"
#include "ui_optionwindow.h"

optionwindow::optionwindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::optionwindow)
{
  ui->setupUi(this);
}

optionwindow::~optionwindow()
{
  delete ui;
}
