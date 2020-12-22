QT       += core gui multimedia



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categories.cpp \
    creditsform.cpp \
    geographywindow.cpp \
    grammarquiz.cpp \
    grammartest.cpp \
    loadingscreen.cpp \
    main.cpp \
    mainwindoww.cpp \
    multiplechoice.cpp \
    quit.cpp \
    soundsettings.cpp \
    triviatype.cpp \
    trueorfalse.cpp \
    trueorfalsequestions.cpp

HEADERS += \
    categories.h \
    creditsform.h \
    geographywindow.h \
    grammarquiz.h \
    grammartest.h \
    loadingscreen.h \
    mainwindoww.h \
    multiplechoice.h \
    quit.h \
    soundsettings.h \
    triviatype.h \
    trueorfalse.h \
    trueorfalsequestions.h

FORMS += \
    categories.ui \
    creditsform.ui \
    geographywindow.ui \
    grammartest.ui \
    loadingscreen.ui \
    mainwindoww.ui \
    quit.ui \
    soundsettings.ui \
    triviatype.ui \
    trueorfalse.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    OurProjectCpp.pro

DISTFILES += \
    OurProjectCpp.pro.user \
    SoundEffects/456161__bwg2020__correct.wav \
    SoundEffects/Read.txt \
    SoundEffects/applause3.wav \
    SoundEffects/buzzer.mp3 \
    SoundEffects/buzzer.wav \
    SoundEffects/click.mp3 \
    SoundEffects/clicksound.wav \
    SoundEffects/coin_roll.wav \
    SoundEffects/congratulation.mp3 \
    SoundEffects/congratulation.wav \
    SoundEffects/cor.mp3 \
    SoundEffects/cor.wav \
    SoundEffects/music.mp3 \
    SoundEffects/music1.mp3 \
    SoundEffects/wro.mp3 \
    SoundEffects/wro.wav \
    backgrounds/122358600_352027169194017_7030235920439217828_n.png \
    backgrounds/122459144_399529254404600_8820718102731057412_n.png \
    backgrounds/abs.jpg \
    backgrounds/asdf.gif \
    backgrounds/bber.jpg \
    backgrounds/bluu.svg \
    backgrounds/cgrts.png \
    backgrounds/darkUiBackground.jpg \
    backgrounds/ere.gif \
    backgrounds/erere.jpg \
    backgrounds/ff.jpg \
    backgrounds/gameover.gif \
    backgrounds/geographyBackground.jpg \
    backgrounds/ggez.jpg \
    backgrounds/grad.jpg \
    backgrounds/h1.png \
    backgrounds/h2.png \
    backgrounds/history.jpg \
    backgrounds/loading3.gif \
    backgrounds/lodi.gif \
    backgrounds/lods.gif \
    backgrounds/quiz_1.jpg \
    backgrounds/references.png \
    backgrounds/science.jpg \
    backgrounds/sdasd.jpg \
    backgrounds/setting.jpg \
    backgrounds/settings.jpg \
    backgrounds/ss.jpg \
    backgrounds/trophy.gif \
    backgrounds/wwe\.gif \
    backgrounds/www.gif \
    icons/atom.png \
    icons/checklist.png \
    icons/cogwheel.png \
    icons/cpu.png \
    icons/disc.png \
    icons/earth.png \
    icons/exit.png \
    icons/flag.png \
    icons/human.png \
    icons/lion.png \
    icons/parchment.png \
    icons/pause.png \
    icons/pause_w .png \
    icons/play_b.png \
    icons/remove.png \
    icons/shuffle.png \
    icons/sport.png

RESOURCES += \
    myRes.qrc
