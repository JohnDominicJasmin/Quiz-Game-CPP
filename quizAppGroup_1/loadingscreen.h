#ifndef LOADINGSCREEN_H
#define LOADINGSCREEN_H

#include <QDialog>
#include <QTimer>
namespace Ui {
  class loadingScreen;
}

class loadingScreen : public QDialog
{
  Q_OBJECT

public:
  explicit loadingScreen(QWidget *parent = nullptr);
  ~loadingScreen();
 void progressBarDisplay();
public slots:
  void ProgressBarValue();


private:
  Ui::loadingScreen *ui;
  QTimer *time_For_ProgressBar;
};

#endif // LOADINGSCREEN_H
