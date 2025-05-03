#include "maingui.h"
#include "./ui_maingui.h"

#include <QDebug>
#include <QString>
#include <QStringList>
#include <filesystem>
#include <QList>
#include <QFileDialog>


using namespace std;
namespace fs = std::filesystem;

QList<QString> qtListedFiles;
QStringList qtOrganizedFiles;



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



void mainGui::listFiles() {

    QString qtPath = ui->linePath->text();
    fs::path sPath = qtPath.toStdString();

    if (!fs::exists(sPath)) {
        return;
    }
    //Creates a list in QMM
    for (const auto& entry:filesystem::directory_iterator(sPath)) {
        QString path = QString::fromStdString(entry.path().string());
        qtListedFiles.append(path);
    }

}


void mainGui::on_btnLoadFiles_clicked()
{
    //filesystem libary use string only, we create std::deque list which we need to convert to QString later

    ui->listFiles->clear();
    qtListedFiles.clear();



    listFiles();


    ui->listFiles->addItems(qtListedFiles);
}

void mainGui::on_btnOrganize_clicked()
{

    QString qtTarget = ui->lineTarget->text();
    fs::path sTarget = qtTarget.toStdString();

    for (const QString& file : qtListedFiles) {
        fs::path filePath = file.toStdString();
        fs::path pathFrom = file.toStdString();
        QString fExt = QString::fromStdString(filePath.extension().string());

        if (fs::is_regular_file(filePath)) {
        if (fExt == ".pdf" || fExt == ".docx" || fExt == ".doc" || fExt == ".txt" || fExt == ".pptx"){

            fs::create_directory(sTarget/"Documents");

            fs::copy(pathFrom, sTarget/"Documents" / pathFrom.filename());
        }
        else if (fExt == ".jpg" || fExt == ".jpeg" || fExt == ".webp" || fExt == ".png" || fExt == ".heif") {


            fs::create_directory(sTarget/"Photos");
            fs::copy(pathFrom, sTarget/"Photos" / pathFrom.filename());
        }
        else if (fExt == ".mov" || fExt == ".mp4" || fExt == ".mp2" || fExt == ".avi" || fExt == ".webm" || fExt == ".mkv") {
            fs::create_directory(sTarget/"Movies and Videos");
            fs::copy(pathFrom, sTarget/"Movies and Videos" / pathFrom.filename());
        }
        else {
            fs::create_directory(sTarget/"Other");
            fs::copy(pathFrom, sTarget/"Other" / pathFrom.filename());
        }
        }
    }
}


void mainGui::on_btnPathDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Select Directory");

    if (!dir.isEmpty()) {
        ui->linePath->setText(dir);
    }
}


void mainGui::on_btnTargetDir_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Select Directory");

    if (!dir.isEmpty()) {
        ui->lineTarget->setText(dir);
    }
}

