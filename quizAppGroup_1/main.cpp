
#include "loadingscreen.h"
#include "soundsettings.h"
#include <QApplication>

#include <QThread>
int main(int argc, char *argv[]){

    QApplication a(argc, argv);
  loadingScreen ls;
  soundSettings *ss = new soundSettings();
  ss->playBackgroundMusic();

  ls.show();

    return a.exec();
}
