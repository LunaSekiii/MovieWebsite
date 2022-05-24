 #include "mainwindow.h"
#include "ui_mainwindow.h"

#include "movieinput.h"
#include "cinema.h"
#include "global.h"

#include <QImage>
#include <QLabel>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief 打开电影录入会话
 */
void MainWindow::on_AddMovie_clicked()
{
    Movie::load();
    QMessageBox::information(this, tr("qq"),*gMovie[3].name);
    QLabel *label = new QLabel;
    label->setPixmap(QPixmap::fromImage(*gMovie[3].img));
    label->show();
    return;
}

