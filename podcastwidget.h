//
// Created by TURIING on 2023/8/29.
//

#ifndef WYY_PODCASTWIDGET_H
#define WYY_PODCASTWIDGET_H

#include <QWidget>
#include "podcastwidgetitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PodcastWidget; }
QT_END_NAMESPACE

class PodcastWidget : public QWidget {
Q_OBJECT
public:
    struct PodcastItemContent {
        QString coverPath;
        QString song;
        QString category;
        QString description;
        QString views;
        QString duration;
    };
public:
    explicit PodcastWidget(QWidget *parent = nullptr);

    ~PodcastWidget() override;

    void appendItem(const PodcastItemContent &_content);
    void appendItem(std::initializer_list<PodcastItemContent> _list);

private:
    Ui::PodcastWidget *ui;

    int m_currentRow = 0;
    int m_currentColumn = -1;

    void adjustSize(int _rowCount);

};


#endif //WYY_PODCASTWIDGET_H
