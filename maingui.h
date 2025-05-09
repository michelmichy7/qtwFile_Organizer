#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class mainGui;
}
QT_END_NAMESPACE

class mainGui : public QMainWindow
{
    Q_OBJECT

public:
    mainGui(QWidget *parent = nullptr);
    ~mainGui();


private slots:
    void on_btnLoadFiles_clicked();
    void listFiles();
    void on_btnOrganize_clicked();

    void on_btnPathDir_clicked();

    void on_btnTargetDir_clicked();

private:
    Ui::mainGui *ui;
};
#endif // MAINGUI_H
