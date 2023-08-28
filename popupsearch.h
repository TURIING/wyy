//
// Created by TURIING on 2023/8/16.
//

#ifndef WYY_POPUPSEARCH_H
#define WYY_POPUPSEARCH_H

#include <QWidget>
#include <QListWidget>
#include <initializer_list>
#include "popupsearchitem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PopupSearch; }
QT_END_NAMESPACE

class PopupSearch : public QWidget {
    Q_OBJECT
public:
    struct ItemContent {
        int id;
        QString song;
        int hot;
        QString description;
    };
public:
    explicit PopupSearch(QWidget *parent = nullptr);

    ~PopupSearch() override;

    void append(std::initializer_list<ItemContent> _list);
    void append(ItemContent _item);
private:
    Ui::PopupSearch *ui;

};


#endif //WYY_POPUPSEARCH_H
