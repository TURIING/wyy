//
// Created by TURIING on 2023/8/27.
//

#ifndef WYY_RANKLISTITEM_H
#define WYY_RANKLISTITEM_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class RankListItem; }
QT_END_NAMESPACE

class RankListItem : public QWidget {
Q_OBJECT

public:
    explicit RankListItem(QWidget *parent = nullptr);
    RankListItem(int _id, const QString &_rate, const QString &_song, const QString &_singer, QWidget *_parent = nullptr);

    ~RankListItem() override;

    void setId(int _id);

    void setSurgeRate(const QString &_text);

    void setSong(const QString &_name);

    void setSinger(const QString &_name);

private:
    Ui::RankListItem *ui;
};


#endif //WYY_RANKLISTITEM_H
