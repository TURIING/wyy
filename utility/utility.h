//
// Created by TURIING on 2023/8/16.
//

#ifndef WYY_UTILITY_H
#define WYY_UTILITY_H

#include <QString>
#include <QFile>
#include <QApplication>
#include <QTextStream>
#include <QPixmap>
#include <QPainter>

extern QString loadStyle(const QString &_filePath);
extern QPixmap getRoundRectPixmap(QPixmap &_srcPixMap, int _radius);

#endif //WYY_UTILITY_H
