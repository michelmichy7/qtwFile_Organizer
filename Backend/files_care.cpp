#include "files_care.h"

#include <QDebug>
#include <QStringList>



Files_Care::Files_Care(QObject *parent)
    : QObject{parent}
{}

QStringList Files_Care::getfoundFiles() const {
    return foundFiles;
}
/*
void Files_Care:::setfoundFiles(const QStringList &Files_Care) {
    foundFiles = files;
}


void manageFiles() {
    qDebug() << foundFiles;
}*/
