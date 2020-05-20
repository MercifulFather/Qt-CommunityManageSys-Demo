QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AttendPage/attendancepart.cpp \
    AttendPage/attendpage.cpp \
    AttendPage/requestpart.cpp \
    AttendPage/reviewpart.cpp \
    AttendPage/signpart.cpp \
    CarPage/adddialog.cpp \
    CarPage/applypart.cpp \
    CarPage/carmanagepart.cpp \
    CarPage/carpage.cpp \
    CarPage/myparkingpart.cpp \
    CarPage/rentpart.cpp \
    CustomWidget/flatui.cpp \
    CustomWidget/iconhelper.cpp \
    EstatePage/estatepage.cpp \
    OwnerPage/ownerpage.cpp \
    PayPage/paypage.cpp \
    PayPage/paypart.cpp \
    PayPage/pricepart.cpp \
    PayPage/querypart.cpp \
    PersonnelPage/staffmanagepart.cpp \
    RepairPage/contentdialog.cpp \
    RepairPage/processdialog.cpp \
    RepairPage/queryrepairpart.cpp \
    RepairPage/repairpage.cpp \
    RepairPage/reportpart.cpp \
    loginpage.cpp \
    main.cpp \
    mainframe.cpp \
    mainwindow.cpp \
    CustomWidget/navbutton.cpp \
    PersonnelPage/personnelpage.cpp \
    registerpage.cpp \
    SettingsPage/settingspage.cpp

HEADERS += \
    AttendPage/attendancepart.h \
    AttendPage/attendpage.h \
    AttendPage/requestpart.h \
    AttendPage/reviewpart.h \
    AttendPage/signpart.h \
    CarPage/adddialog.h \
    CarPage/applypart.h \
    CarPage/carmanagepart.h \
    CarPage/carpage.h \
    CarPage/myparkingpart.h \
    CarPage/rentpart.h \
    CustomWidget/navbutton.h \
    EstatePage/estatepage.h \
    OwnerPage/ownerpage.h \
    PayPage/paypage.h \
    PayPage/paypart.h \
    PayPage/pricepart.h \
    PayPage/querypart.h \
    PersonnelPage/staffmanagepart.h \
    RepairPage/contentdialog.h \
    RepairPage/processdialog.h \
    RepairPage/queryrepairpart.h \
    RepairPage/repairpage.h \
    RepairPage/reportpart.h \
    common.h \
    CustomWidget/flatui.h \
    CustomWidget/iconhelper.h \
    loginpage.h \
    mainframe.h \
    mainwindow.h \
    PersonnelPage/personnelpage.h \
    registerpage.h \
    SettingsPage/settingspage.h

FORMS += \
    AttendPage/attendancepart.ui \
    AttendPage/attendpage.ui \
    AttendPage/requestpart.ui \
    AttendPage/reviewpart.ui \
    AttendPage/signpart.ui \
    CarPage/adddialog.ui \
    CarPage/applypart.ui \
    CarPage/carmanagepart.ui \
    CarPage/carpage.ui \
    CarPage/myparkingpart.ui \
    CarPage/rentpart.ui \
    EstatePage/estatepage.ui \
    OwnerPage/ownerpage.ui \
    PayPage/paypage.ui \
    PayPage/paypart.ui \
    PayPage/pricepart.ui \
    PayPage/querypart.ui \
    PersonnelPage/staffmanagepart.ui \
    RepairPage/contentdialog.ui \
    RepairPage/processdialog.ui \
    RepairPage/queryrepairpart.ui \
    RepairPage/repairpage.ui \
    RepairPage/reportpart.ui \
    loginpage.ui \
    mainframe.ui \
    mainwindow.ui \
    PersonnelPage/personnelpage.ui \
    registerpage.ui \
    SettingsPage/settingspage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    main.qrc

DISTFILES +=
