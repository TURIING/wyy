//
// Created by TURIING on 2023/8/17.
//
#include "utility.h"

/**
 * 加载全局qss文件
 * @param _filePath
 * @return qss文件内容
 */
QString loadStyle(const QString &_filePath) {
    QFile file(_filePath);

    auto res = file.open(QIODevice::ReadOnly | QIODevice::Text);
    assert(res != false);

    auto ts = new QTextStream(&file);
    auto text = ts->readAll();

    file.close();
    return text;
}

/**
 * 获得圆角的图片
 * @param _srcPixMap 图片
 * @param _radius 圆角值
 * @return
 */
QPixmap getRoundRectPixmap(QPixmap &_srcPixMap, int _radius) {
    //不处理空数据或者错误数据
    if (_srcPixMap.isNull()) {
        return _srcPixMap;
    }

    //获取图片尺寸
    int imageWidth = _srcPixMap.width();
    int imageHeight = _srcPixMap.height();

    //处理大尺寸的图片,保证图片显示区域完整
    QPixmap newPixMap = _srcPixMap.scaled(imageWidth, (imageHeight == 0 ? imageWidth : imageHeight),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPixmap destImage(imageWidth, imageHeight);
    destImage.fill(Qt::transparent);
    QPainter painter(&destImage);
    // 抗锯齿
    painter.setRenderHints(QPainter::Antialiasing, true);
    // 图片平滑处理
    painter.setRenderHints(QPainter::SmoothPixmapTransform, true);
    // 将图片裁剪为圆角
    QPainterPath path;
    QRect rect(0, 0, imageWidth, imageHeight);
    path.addRoundedRect(rect, _radius, _radius);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, imageWidth, imageHeight, newPixMap);
    return destImage;
}

/**
 * 计算字符串所需的尺寸
 * @param _font 字体
 * @param _text 字符串
 * @return
 */
QSize computeTextSize(const QFont &_font, const QString &_text) {
    QFontMetrics fontMetrics(_font);
    auto width = fontMetrics.horizontalAdvance(_text);
    auto height = fontMetrics.height();

    return QSize(width, height);
}