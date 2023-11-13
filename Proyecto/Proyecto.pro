TEMPLATE = subdirs

SUBDIRS += \
    libreria \
    main \
    testing

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/libreria/release/ -llibreria
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/libreria/debug/ -llibreria
else:unix: LIBS += -L$$OUT_PWD/libreria/ -llibreria

INCLUDEPATH += $$PWD/libreria
DEPENDPATH += $$PWD/libreria
