#include "maingui.h"
#include "./ui_maingui.h"

#include <QDebug>
#include <QString>
#include <QStringList>
#include <filesystem>
#include <QList>
#include <deque>

using namespace std;
namespace fs = std::filesystem;

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
    //filesystem libary use string only, we create std::deque list which we need to convert to QString later
    deque<string> listedFiles = {};

    QString qtPath = ui->lineEdit->text();

    filesystem::path sPath = qtPath.toStdString();

    if (!fs::exists(sPath)) {
        return;
    }


    //Creates a list in deque
    for (const auto& entry:filesystem::directory_iterator(sPath)) {
        listedFiles.push_back(entry.path().string());
    }


    //Converts deque to QList
    QList<QString> qtListedFiles;
    for (const auto& file : listedFiles) {
        qtListedFiles.append(QString::fromStdString(file));
    }

    //Shows the ist of files in ui
    ui->listFiles->clear();
    ui->listFiles->addItems(qtListedFiles);

}
