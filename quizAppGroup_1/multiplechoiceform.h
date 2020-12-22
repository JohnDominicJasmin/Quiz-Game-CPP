#ifndef MULTIPLECHOICEFORM_H
#define MULTIPLECHOICEFORM_H

#include <QDialog>

namespace Ui {
  class MultipleChoiceForm;
}

class MultipleChoiceForm : public QDialog
{
  Q_OBJECT

public:
  explicit MultipleChoiceForm(QWidget *parent = nullptr);
  ~MultipleChoiceForm();

private:
  Ui::MultipleChoiceForm *ui;
};

#endif // MULTIPLECHOICEFORM_H
