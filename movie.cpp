#include "movie.h"
#include "global.h"

QString movieDataDir = "D:/mydata/moviedata";

Movie::Movie(){
}

Movie::~Movie(){
}

void Movie:: load(){
    QFile file(movieDataDir+"/movie.json");//打开json文件
    file.open(QIODevice::ReadWrite);
    QByteArray json = file.readAll();
    file.close();//读文件结束
    QJsonDocument doc=doc.fromJson(json);//ByteArray to doc
    QJsonObject obj = doc.object();//doc to obj
    QStringList keys = obj.keys();//QStringList::at(iter);
    if(keys.isEmpty())return;//空值返回
    Movie* movie = new Movie[keys.size()];//初始化
    gMovie = movie;
    for(int i = 0; i < keys.size(); i++){//遍历电影列表
        QJsonObject item = obj[keys[i]].toObject();//读取每个电影信息
        *movie[i].name = keys[i];//读取名称
        *movie[i].intro = item["intro"].toString();//读取简介
        movie[i].img->load(item["img"].toString());//加载图片
    }
}
