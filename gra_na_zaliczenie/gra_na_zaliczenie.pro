TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "D:\Documents\semestr_2\PSiO\laby7\SFML-2.5.1\include"
SOURCES += \
        Bullet.cpp \
        Game.cpp \
        Meteor.cpp \
        Player.cpp \
        Scoreboard.cpp \
        main.cpp
LIBS += -L"D:\Documents\semestr_2\PSiO\laby7\SFML-2.5.1\lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    Bullet.h \
    Game.h \
    Meteor.h \
    Player.h \
    Scoreboard.h \
    const.h
