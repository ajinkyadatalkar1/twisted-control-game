#-------------------------------------------------
#
# Project created by QtCreator 2017-01-28T02:48:44
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = twisted
TEMPLATE = app


SOURCES += main.cpp \
    display.cpp \
    player.cpp \
    enemy.cpp \
    thunder.cpp \
    twisted_control.cpp \
    buttons.cpp \
    font.cpp \
    parallax.cpp \
    game_thread.cpp \
    parallax_thread.cpp

HEADERS  += \
    display.h \
    player.h \
    enemy.h \
    thunder.h \
    twisted_control.h \
    buttons.h \
    font.h \
    common_variables.h \
    parallax.h \
    game_thread.h \
    parallax_thread.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    readme \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

RESOURCES += \
    sounds/sounds.qrc \
    fonts/fonts.qrc \
    android/images.qrc

