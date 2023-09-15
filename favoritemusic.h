//
// Created by TURIING on 2023/9/5.
//

#ifndef WYY_FAVORITEMUSIC_H
#define WYY_FAVORITEMUSIC_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include "FavoriteMusicDelegate.h"
#include <QScrollBar>
#include <QSortFilterProxyModel>
#include "control/customsearchbox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FavoriteMusic; }
QT_END_NAMESPACE

class SortFilterProxyModel;

class FavoriteMusic : public QWidget {
Q_OBJECT
    struct ItemContent {
        QString song;
        QString singer;
        QString album;
        QString duration;
    };
public:
    explicit FavoriteMusic(QWidget *parent = nullptr);

    ~FavoriteMusic() override;

private:
    Ui::FavoriteMusic *ui;
    CustomSearchBox *m_searchBox = nullptr;

    QStandardItemModel *m_model = nullptr;
    SortFilterProxyModel *m_proxyModel = nullptr;

    void initView();
    void initModel();
    void appendItem(const ItemContent &_content);
    void appendItem(std::initializer_list<ItemContent> _list);
};

class SortFilterProxyModel: public QSortFilterProxyModel {
Q_OBJECT
public:
    explicit SortFilterProxyModel(QSortFilterProxyModel *_parent = nullptr);
protected:
    bool lessThan(const QModelIndex &_source_left, const QModelIndex &_source_right) const override;

    bool filterAcceptsRow(int _source_row, const QModelIndex &_source_parent) const override;

};


#endif //WYY_FAVORITEMUSIC_H
