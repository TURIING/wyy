//
// Created by TURIING on 2023/9/5.
//

#ifndef WYY_FAVORITEMUSIC_H
#define WYY_FAVORITEMUSIC_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "FavoriteMusicDelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FavoriteMusic; }
QT_END_NAMESPACE

class FavoriteMusic : public QWidget {
Q_OBJECT

public:
    explicit FavoriteMusic(QWidget *parent = nullptr);

    ~FavoriteMusic() override;

private:
    Ui::FavoriteMusic *ui;

    QStandardItemModel *m_model = nullptr;

    void initView();
    void initModel();
    //void appendItem()
};


#endif //WYY_FAVORITEMUSIC_H
