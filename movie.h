#include <QApplication>
#include <QLocale>
#include <QFile>
#include <QImage>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#ifndef MOVIE_H
#define MOVIE_H

/**
 * @brief 描述一部电影
 */
class Movie
{
private:
public:
    QString* name = new QString;///电影名
    QString* intro = new QString;///简介
    QImage* img  = new QImage;///图片
    //属性暂时放这，后面改为私有
    Movie();///构造函数
    Movie(const Movie & m);
    ~Movie();
    static void load();///加载电影信息
};

#endif // MOVIE_H
