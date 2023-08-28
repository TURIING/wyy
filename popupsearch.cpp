//
// Created by TURIING on 2023/8/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PopupSearch.h" resolved

#include "popupsearch.h"
#include "ui_PopupSearch.h"


PopupSearch::PopupSearch(QWidget *parent) :QWidget(parent), ui(new Ui::PopupSearch) {
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);                           // 无边框
    this->setAttribute(Qt::WA_StyledBackground);                            // 启用样式表
    this->setStyleSheet(loadStyle("../Resources/qss/popup_search.qss"));

    this->append({{1, "消愁", 12345, "消愁的描述"}, {2, "海底", 23456, "海底的描述"}});
}

PopupSearch::~PopupSearch() {
    delete ui;
}

/**
 * 追加多个Item
 * @param _list
 */
void PopupSearch::append(std::initializer_list<ItemContent> _list) {
    for(auto &item: _list) append(item);
}

/**
 * 追加item
 * @param _item
 */
inline void PopupSearch::append(PopupSearch::ItemContent _item) {
    auto itemWidget = new PopupSearchItem();
    itemWidget->setId(_item.id);
    itemWidget->setSong(_item.song);
    itemWidget->setHot(_item.hot);
    itemWidget->setDescription(_item.description);
    if(_item.id <= 3) itemWidget->setIdColorHighlight(false);

    ui->listWidget->setItemWidget(new QListWidgetItem(ui->listWidget), itemWidget);
}
