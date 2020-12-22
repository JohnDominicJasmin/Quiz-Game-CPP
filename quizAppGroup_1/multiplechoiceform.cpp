#include "multiplechoiceform.h"
#include "ui_multiplechoiceform.h"

MultipleChoiceForm::MultipleChoiceForm(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MultipleChoiceForm)
{
  ui->setupUi(this);
}

MultipleChoiceForm::~MultipleChoiceForm()
{
  delete ui;
}
