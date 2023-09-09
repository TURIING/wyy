//
// Created by TURIING on 2023/9/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_NewMusicListItem.h" resolved

#include "newmusiclistitem.h"
#include "ui_NewMusicListItem.h"


NewMusicListItem::NewMusicListItem(QWidget *parent) :QWidget(parent), ui(new Ui::NewMusicListItem) {
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_StyledBackground);
    //this->setStyleSheet("QLabel{ background: black; }");
}

NewMusicListItem::~NewMusicListItem() {
    delete ui;
}

NewMusicListItem::NewMusicListItem(int _id, const QString &_imgPath, const QString &_song, const QString &_singer, const QString &_album, const QString &_duration, QWidget *_parent): NewMusicListItem(_parent) {
    ui->label_id->setText(QString::asprintf("%02d", _id));
    ui->label_image->setStyleSheet(QString("border-image: url(%1); ").arg(_imgPath));
    ui->label_song->setText(_song);
    ui->label_singer->setText(_singer);
    ui->label_album->setText(_album);
    ui->label_duration->setText(_duration);
}
