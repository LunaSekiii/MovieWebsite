#include "cinema.h"
#include "global.h"

QString cinemaDataDir = "D:/mydata/cinemadata";

Cinema::Cinema(){

}

Cinema::~Cinema(){

}

void Cinema::load(){
    QFile file(cinemaDataDir+"/cinema.json");//打开json文件
    file.open(QIODevice::ReadWrite);
    QByteArray json = file.readAll();
    file.close();//读文件结束
    QJsonDocument doc=doc.fromJson(json);//ByteArray to doc
    QJsonObject obj = doc.object();//doc to obj
    QStringList keys = obj.keys();//QStringList::at(iter);
    if(keys.isEmpty())return;//空值返回
    Cinema* cinema = new Cinema[keys.size()];//初始化
    gCinema = cinema;
    for(int i = 0; i < keys.size(); i++){//遍历影院列表
        QJsonObject item = obj[keys[i]].toObject();//读取每个影院信息
        *cinema[i].name = keys[i];//读取名称
        *cinema[i].address = item["intro"].toString();//读取地址
        cinema[i].img->load(item["img"].toString());//加载图片
    }
    return;
}
