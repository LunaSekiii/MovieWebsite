#include "movieinput.h"
#include "ui_movieinput.h"
#include <QFileDialog>
#include <QMessageBox>

QString path;
QString rootDir = "D:/mydata", movieDataDir = "D:/mydata/moviedata";

MovieInput::MovieInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MovieInput)
{
    ui->setupUi(this);
}

MovieInput::~MovieInput()
{
    delete ui;
    QDir dir(rootDir);
        if (!dir.exists()) {
            QDir().mkdir(rootDir);
            QDir().mkdir(movieDataDir);
        }
}

void MovieInput::on_ChoiceImg_clicked()
{
    path = QFileDialog::getOpenFileName(this, tr("选择图片"), "/", tr("Image Files(*.webp *.jpg *.png)"));
    QImage *img = new QImage;
    if(!(img->load(path))){
        QMessageBox::information(this, tr("错误"), tr("打开图像失败！"), tr("确定"));//待优化：弹出窗口关闭后可另提示
        ui->LImg->setText(tr("未选择图片"));
        path = QChar::Null;
        delete img;
        return;
    }
    *img = img->scaled(ui->LImg->size(), Qt::KeepAspectRatio);
    ui->LImg->setPixmap(QPixmap::fromImage(*img));
    delete img;
    return;
}


void MovieInput::on_Save_clicked()
{
    QString movieName = ui->lineEdit->text();
    QString movieIntro = ui->textEdit->toPlainText();

    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::information(this, tr("保存失败"), tr("未填写电影名"), tr("确定"));
        return;
    }
    if(ui->textEdit->document()->isEmpty()){
        QMessageBox::information(this, tr("保存失败"), tr("未填写电影介绍"), tr("确定"));
        return;
    }
    if(path == QChar::Null){
        QMessageBox::information(this, tr("保存失败"), tr("未选择图片"), tr("确定"));
        return;
    }

    QDir saveDir(movieDataDir + "/" + movieName);
    if(!saveDir.exists()){
        QDir().mkdir(movieDataDir + "/" + movieName);//创建电影信息文件夹
        QFile file(movieDataDir + "/" + movieName + "/intro.txt");
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        file.write(movieIntro.toUtf8());
        QFile ifile(movieDataDir + "/" + movieName + "/img.txt");
        ifile.open(QIODevice::ReadWrite | QIODevice::Text);
        ifile.write(path.toUtf8());
        ifile.close();
    }

    setAttribute(Qt::WA_DeleteOnClose, true);
    this->close();
}

