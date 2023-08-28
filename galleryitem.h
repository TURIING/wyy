//
// Created by TURIING on 2023/8/22.
//

#ifndef WYY_GALLERYITEM_H
#define WYY_GALLERYITEM_H

#include <QWidget>
#include <QImage>
#include "ui_GalleryItem.h"
#include "utility/utility.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GalleryItem; }
QT_END_NAMESPACE

class GalleryItem : public QWidget {
Q_OBJECT

public:
    GalleryItem(const QString &_filePath, const QString &_title, int _viewCount, QWidget *parent = nullptr): QWidget(parent), ui(new Ui::GalleryItem) {
        ui->setupUi(this);

        m_image = new QImage(_filePath);
        m_title = _title;
        m_viewCount = _viewCount;

        auto pixmap = QPixmap::fromImage(*m_image);
        ui->label_image->setPixmap(getRoundRectPixmap(pixmap, 10));

        ui->label_title->setText(m_title);

    }

    ~GalleryItem() override{
        delete m_image;
        delete ui;
    }

private:
    Ui::GalleryItem *ui;

    QImage *m_image;
    QString m_title;
    int m_viewCount = 0;
};





#endif //WYY_GALLERYITEM_H
