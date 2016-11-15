TEMPLATE = lib
TARGET = qmltcpsocketsplugin

CONFIG += qt plugin c++11
CONFIG -= android_install

QT += qml quick

QMAKE_CXXFLAGS -= -O2
QMAKE_CXXFLAGS_RELEASE -= -O2

QMAKE_CXXFLAGS += -O3
QMAKE_CXXFLAGS_RELEASE += -O3

TARGET = $$qtLibraryTarget($$TARGET)
uri = QMLTcpSockets

HEADERS += \
    src/QMLTcpSocketsPlugin.h \
    src/QIntPtr.h \
    src/QTcpServerPub.h \
    src/TcpServer.h \
    src/TcpSocket.h

SOURCES += \
    src/QMLTcpSocketsPlugin.cpp \
    src/QIntPtr.cpp \
    src/QTcpServerPub.cpp \
    src/TcpServer.cpp \
    src/TcpSocket.cpp

OTHER_FILES += qmldir

#Install plugin library, qmldir
qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}