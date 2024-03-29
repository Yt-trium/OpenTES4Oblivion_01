QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenTES4Editor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    TES4Files/tes4filebsa.cpp \
    TES4FilesUI/tes4filebsa_ui.cpp \
    TES4Files/tes4fileesmp.cpp \
    TES4FilesUI/tes4fileesmp_ui.cpp

HEADERS += \
        mainwindow.h \
    TES4Files/tes4filebsa.h \
    TES4Files/tes4files.h \
    TES4Files/tes4filestypes.h \
    TES4FilesUI/tes4filebsa_ui.h \
    TES4FilesUI/tes4files_ui.h \
    TES4Files/tes4filebsastructs.h \
    TES4Files/tes4fileesmp.h \
    TES4FilesUI/tes4fileesmp_ui.h \
    TES4Files/tes4fileesmpstructs.h

FORMS += \
        mainwindow.ui \
    TES4FilesUI/tes4filebsa_ui.ui \
    TES4FilesUI/tes4fileesmp_ui.ui

LIBS += -lz
