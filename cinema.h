#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDialog>
#include <QLabel>
#include <QFile>
#include <QImage>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#ifndef CINEMA_H
#define CINEMA_H


class Cinema
{
public:
    QString* name = new QString;
    QString* address = new QString;
    QImage* img = new QImage;
    Cinema();
    ~Cinema();
    static void load();
};

#endif // CINEMA_H
