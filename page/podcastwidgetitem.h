//
// Created by TURIING on 2023/8/29.
//

#ifndef WYY_PODCASTWIDGETITEM_H
#define WYY_PODCASTWIDGETITEM_H

#include <QWidget>
#include <QPixmap>
#include "utility/utility.h"
#include <QDebug>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class PodcastWidgetItem; }
QT_END_NAMESPACE

class PodcastWidgetItem : public QWidget {
Q_OBJECT

public:
    explicit PodcastWidgetItem(QWidget *parent = nullptr);
    PodcastWidgetItem(const QString &_coverPath, const QString &_song, const QString &_description, const QString &_category, const QString &_views, const QString &_duration, QWidget *_parent = nullptr);

    ~PodcastWidgetItem() override;

    void setCover(const QString &_filePath);

    void setSong(const QString &_song);

    void setDescription(const QString &_description);

    void setCategory(const QString &_category);

    void setViews(const QString &_views);

    void setDuration(const QString &_duration);

protected:
    void enterEvent(QEvent *_event);
    void leaveEvent(QEvent *_event);
    void paintEvent(QPaintEvent *_event);

private:
    Ui::PodcastWidgetItem *ui;
    QImage *m_image;
    bool m_isEnter = false;
};


#endif //WYY_PODCASTWIDGETITEM_H
