//
// Created by TURIING on 2023/8/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PopupSearchItem.h" resolved

#include "popupsearchitem.h"
#include "ui_PopupSearchItem.h"


PopupSearchItem::PopupSearchItem(QWidget *parent) :QWidget(parent), ui(new Ui::PopupSearchItem) {
    ui->setupUi(this);

    this->setStyleSheet(loadStyle("../Resources/qss/popup_search_item.qss"));
}

PopupSearchItem::~PopupSearchItem() {
    delete ui;
}

/**
 * 设置列表id的前景色(前3名为false， 其余为true)
 * @param _bo
 */
void PopupSearchItem::setIdColorHighlight(bool _bo) {
    if(_bo) {
        ui->label_id->setStyleSheet("QLabel{ color:rgb(255, 58, 58); font-size: 24px; }");
        ui->label_song->setStyleSheet("QLabel#label_song { font-weight: bold; color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 18px; }");
    }
    else
        ui->label_id->setStyleSheet("QLabel{ color:rgb(194, 194, 194); font-size: 24px; }");
}

/**
 * 设置item id
 * @param _id
 */
void PopupSearchItem::setId(int _id) {
    ui->label_id->setText(QString::number(_id));
}

/**
 * 设置歌曲名称
 * @param _text
 */
void PopupSearchItem::setSong(const QString &_text) {
    ui->label_song->setText(_text);
}

/**
 * 设置热度
 * @param _num
 */
void PopupSearchItem::setHot(int _num) {
    ui->label_hot->setText(QString::number(_num));
}

/**
 * 设置歌曲描述
 * @param _text
 */
void PopupSearchItem::setDescription(const QString &_text) {
    if(_text.isEmpty()) {
        ui->label_description->hide();
        return;
    }
    ui->label_description->setText(_text);
}
