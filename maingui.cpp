#include "maingui.h"
#include "./ui_maingui.h"

#include <QDebug>
#include <QString>
#include <QStringList>
#include <filesystem>
#include <QList>
#include <QMultiMap>

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

    QMultiMap<QString, QString> qtListedFiles;
    QMultiMap<QString, QString> qtOrganizedFiles;

void mainGui::on_btnLoadFiles_clicked()
{
    //filesystem libary use string only, we create std::deque list which we need to convert to QString later


    QString qtPath = ui->lineEdit->text();

    filesystem::path sPath = qtPath.toStdString();

    if (!fs::exists(sPath)) {
        return;
    }


    //Creates a list in deque
    for (const auto& entry:filesystem::directory_iterator(sPath)) {
        QString filePath = QString::fromStdString(entry.path().string());
        qtListedFiles.insert(//expansion, //path);
    }


    //Converts deque to QList

   /* for (const auto& file : qtListedFiles) {
        qtListedFiles.append(QString::fromStdString(file));
    }

    //Shows the ist of files in ui
    ui->listFiles->clear();
    ui->listFiles->addItems(qtOrganizedFiles);
*/
}

void mainGui::on_btnOrganize_clicked()
{
    for (const auto& file : qtListedFiles) {
        return;
    }
}

