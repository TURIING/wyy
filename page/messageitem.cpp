//
// Created by TURIING on 2023/8/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MessageItem.h" resolved

#include "messageitem.h"
#include "ui_MessageItem.h"


MessageItem::MessageItem(QWidget *parent) :QWidget(parent), ui(new Ui::MessageItem) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("QWidget{ border: 1px; background: transparent; border-radius: 8px;}"
                        "QLabel#label_messager { color: rgb(91, 133, 180); }"
                        "QLabel#label_time { color: rgb(217,217,217); }"
                        "QLabel#label_description { color: rgb(49,49,49); }");
}

MessageItem::~MessageItem() {
    delete ui;
}

MessageItem::MessageItem(const QString &_messager, const QString &_description, const QString &_time, const QString &_iconPath, QWidget *_parent): MessageItem(_parent) {
    ui->label_messager->setText(_messager);

    ui->label_description->setText(_description);

    ui->label_time->setText(_time);

    QImage image(_iconPath);

    // 缩放图片以适应label
    auto width = ui->label_icon->width();
    auto height = ui->label_icon->height();
    image = image.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QPixmap pixmap = QPixmap::fromImage(image);

    ui->label_icon->setPixmap(getRoundRectPixmap(pixmap, width / 2));
}
