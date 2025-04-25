#include "maingui.h"
#include "./ui_maingui.h"

#include <QString>
#include <QStringList>

mainGui::mainGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainGui)
{
    ui->setupUi(this);
}

mainGui::~mainGui()
{
    delete ui;
}

void mainGui::on_btnLoadFiles_clicked()
{
    QStringList foundFiles = {};
    // numofFiles = foundFiles.size();

    ui->listFiles->addItems(foundFiles);

}
