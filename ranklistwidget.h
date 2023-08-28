//
// Created by TURIING on 2023/8/28.
//

#ifndef WYY_RANKLISTWIDGET_H
#define WYY_RANKLISTWIDGET_H

#include <QWidget>
#include "ranklistitem.h"


QT_BEGIN_NAMESPACE
namespace Ui { class RankListWidget; }
QT_END_NAMESPACE

class RankListWidget : public QWidget {
Q_OBJECT
public:
    struct RankItemContent {
        int id;
        QString surgeRate;
        QString song;
        QString singer;
    };
public:
    explicit RankListWidget(QWidget *parent = nullptr);

    ~RankListWidget() override;

    void setRankList(const RankItemContent &_content);
    void setRankList(std::initializer_list<RankItemContent> _list);

    void setCover(const QString &_imgPath);

private:
    Ui::RankListWidget *ui;
};


#endif //WYY_RANKLISTWIDGET_H
