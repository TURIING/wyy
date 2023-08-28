//
// Created by TURIING on 2023/8/22.
//

#ifndef WYY_GALLERYWIDGET_H
#define WYY_GALLERYWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "galleryitem.h"
#include <QLabel>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class GalleryWidget; }
QT_END_NAMESPACE

class GalleryWidget : public QWidget {
Q_OBJECT
public:
    struct GalleryItemContent {
        QString coverPath;
        QString title;
        int viewCount;
    };
public:
    explicit GalleryWidget(QWidget *parent = nullptr);

    ~GalleryWidget() override;

    void adjustSize(int _rowCount);

    void setGalleryItem(const GalleryItemContent &_content);
    void setGalleryItem(std::initializer_list<GalleryItemContent> _list);

private:
    void initUI();

private:
    Ui::GalleryWidget *ui;
    int m_currentRow = 0;
    int m_currentColumn = -1;
};


#endif //WYY_GALLERYWIDGET_H
