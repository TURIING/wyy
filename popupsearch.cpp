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

    /* 设置滚动条的样式 */
    auto scrollBar = ui->listWidget->verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar::vertical{ background: transparent; width: 10px; }"
                             "QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 10px; border-radius: 5px; }"
                             "QScrollBar::up-arrow:vertical{ border: none; }"
                             "QScrollBar::sub-line:vertical{ background: transparent; }"
                             "QScrollBar::add-line:vertical{ background: transparent; }");
}

PopupSearch::~PopupSearch() {
    delete ui;
}

/**
 * 追加多个Item
 * @param _list
 */
void PopupSearch::append(std::initializer_list<SearchItemContent> _list) {
    for(auto &item: _list) append(item);
}

/**
 * 追加item
 * @param _item
 */
inline void PopupSearch::append(PopupSearch::SearchItemContent _item) {
    auto itemWidget = new PopupSearchItem();
    itemWidget->setId(_item.id);
    itemWidget->setSong(_item.song);
    itemWidget->setHot(_item.hot);
    itemWidget->setDescription(_item.description);
    if(_item.id <= 3) itemWidget->setIdColorHighlight(true);
    else itemWidget->setIdColorHighlight(false);

    ui->listWidget->setItemWidget(new QListWidgetItem(ui->listWidget), itemWidget);
}
