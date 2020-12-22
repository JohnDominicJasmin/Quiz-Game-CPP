#include "multiplechoices.h"
#include "ui_multiplechoices.h"

Multiplechoices::Multiplechoices(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Multiplechoices)
{
  ui->setupUi(this);
}

Multiplechoices::~Multiplechoices()
{
  delete ui;
}
