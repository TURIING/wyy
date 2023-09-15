//
// Created by TURIING on 2023/8/29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PodcastWidgetItem.h" resolved

#include "podcastwidgetitem.h"
#include "ui_PodcastWidgetItem.h"


PodcastWidgetItem::PodcastWidgetItem(QWidget *parent) :QWidget(parent), ui(new Ui::PodcastWidgetItem) {
    ui->setupUi(this);
}

PodcastWidgetItem::PodcastWidgetItem(const QString &_coverPath, const QString &_song, const QString &_description,
                                     const QString &_category, const QString &_views, const QString &_duration,
                                     QWidget *_parent): PodcastWidgetItem(_parent) {
    this->setCover(_coverPath);
    this->setSong(_song);
    this->setCategory(_category);
    this->setDuration(_duration);
    this->setDescription(_description);
    this->setViews(_views);

    this->setMouseTracking(true);

    this->setStyleSheet("QLabel#label_song{ color: rgb(47, 47, 47); font-family: '微软雅黑'; font-size: 20px; }"
                        "QLabel#label_category{ color: rgb(181, 181, 181); border: 1px solid rgb(217, 217, 217); font-family: '微软雅黑'; font-size: 18px; }"
                        "QLabel#label_description{ color: rgb(181, 181, 181); font-family: '微软雅黑'; font-size: 18px; margin-right: 20px; }"
                        "QLabel#label_viewsIcon{ border-image: url(:/podcast/Resources/images/podcast/views.png); }"
                        "QLabel#label_views{ color: rgb(181, 181, 181); font-family: '微软雅黑'; font-size: 16px; margin-right: 20px; margin-left: 3px; }"
                        "QLabel#label_durationIcon{ border-image: url(:/podcast/Resources/images/podcast/duration.png); }"
                        "QLabel#label_duration{ color: rgb(181, 181, 181); font-family: '微软雅黑'; font-size: 16px; margin-left: 5px; }");

}

PodcastWidgetItem::~PodcastWidgetItem() {
    delete ui;
}

/*
 * 设置封面
 */
void PodcastWidgetItem::setCover(const QString &_filePath) {
    assert(!_filePath.isEmpty());

    m_image = new QImage(_filePath);
    auto pixmap = QPixmap::fromImage(*m_image);
    ui->label_cover->setPixmap(getRoundRectPixmap(pixmap, 5));
}

/*
 * 设置歌曲
 */
void PodcastWidgetItem::setSong(const QString &_song) {
    assert(!_song.isEmpty());
    ui->label_song->setText(_song);
}

/*
 * 设置描述
 */
void PodcastWidgetItem::setDescription(const QString &_description) {
    assert(!_description.isEmpty());
    ui->label_description->setText(_description);
}

/*
 * 设置类别
 */
void PodcastWidgetItem::setCategory(const QString &_category) {
    assert(!_category.isEmpty());
    ui->label_category->setText(_category);
}

/*
 * 设置播放量
 */
void PodcastWidgetItem::setViews(const QString &_views) {
    assert(!_views.isEmpty());
    ui->label_views->setText(_views);
}

/*
 * 设置时长
 */
void PodcastWidgetItem::setDuration(const QString &_duration) {
    assert(!_duration.isEmpty());
    ui->label_duration->setText(_duration);
}

void PodcastWidgetItem::enterEvent(QEvent *_event) {
    m_isEnter = true;
    this->update();
    QWidget::enterEvent(_event);
}

void PodcastWidgetItem::leaveEvent(QEvent *_event) {
    m_isEnter = false;
    this->update();
    QWidget::leaveEvent(_event);
}

void PodcastWidgetItem::paintEvent(QPaintEvent *_event) {
    if(m_isEnter) {
        QPainter painter(this);
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(235, 235, 235));
        painter.drawRoundedRect(this->rect(), 5, 5);
    }

    QWidget::paintEvent(_event);
}




