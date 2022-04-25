#!/bin/sh
QT_VERSION=0.3.0
export QT_VERSION
QT_VER=0.3
export QT_VER
QT_VERSION_TAG=030
export QT_VERSION_TAG
QT_INSTALL_DOCS=/home/cc/Qt5.12.11/Docs/Qt-5.12.11
export QT_INSTALL_DOCS
BUILDDIR=/home/cc/Qt5.12.11/ThirdParty/QtXlsxWriter-master/src/xlsx
export BUILDDIR
exec /home/cc/Qt5.12.11/5.12.11/gcc_64/bin/qdoc "$@"
