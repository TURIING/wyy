//
// Created by TURIING on 2023/8/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RankListItem.h" resolved

#include "ranklistitem.h"
#include "ui_RankListItem.h"


RankListItem::RankListItem(QWidget *parent) :QWidget(parent), ui(new Ui::RankListItem) {
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QLabel#label_id { color: rgb(255, 61, 61); background: transparent; }"
                        "QLabel#label_song { color: rgb(54, 54, 54); background: transparent; }"
                        "QLabel#label_singer { color: rgb(152, 152, 152); background: transparent; }"
                        "QLabel#label_surgeRate { color:rgb(152,152,152);background:transparent; }");
                        //"QWidget#RankListItem { background: rgb(249, 249, 249); border-radius: 8px; }"
                        //"QWidget:hover#RankListItem { background: transparent; }");
}

RankListItem::~RankListItem() {
    delete ui;
}

void RankListItem::setId(int _id) {
    assert(_id >= 1);
    ui->label_id->setText(QString::number(_id));

    if(_id <= 3) ui->label_id->setStyleSheet("#label_id { color: rgb(255,61, 61); background: transparent; }");
    else ui->label_id->setStyleSheet("#label_id { color: rgb(222,222,222); background: transparent; }");
}

void RankListItem::setSurgeRate(const QString &_text) {
    ui->label_surgeRate->setText(_text);
}

void RankListItem::setSong(const QString &_name) {
    ui->label_song->setText(_name);
}

void RankListItem::setSinger(const QString &_name) {
    ui->label_singer->setText(_name);
}

RankListItem::RankListItem(int _id, const QString &_rate, const QString &_song, const QString &_singer, QWidget *_parent): RankListItem(_parent) {
    setId(_id);
    setSong(_song);
    setSinger(_singer);
    setSurgeRate(_rate);
}
