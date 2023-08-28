//
// Created by TURIING on 2023/8/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RankListWidget.h" resolved

#include "ranklistwidget.h"
#include "ui_RankListWidget.h"


RankListWidget::RankListWidget(QWidget *parent) :QWidget(parent), ui(new Ui::RankListWidget) {
    ui->setupUi(this);

    ui->btn_examineAll->setStyleSheet("QPushButton#btn_examineAll { color: rgb(102, 102, 102); border: none; margin-left: 12px;}"
                                      "QPushButton:hover#btn_examineAll { color: rgb(51, 51, 51); }");
}

RankListWidget::~RankListWidget() {
    delete ui;
}

/*
 * 设置飙升排行榜行数据
 */
void RankListWidget::setRankList(const RankItemContent &_content) {
    auto [id, rate, song, singer] = _content;

    auto item = new QListWidgetItem(ui->listRankSurge);
    auto itemWidget = new RankListItem(id, rate, song, singer);


    if(id % 2 != 0) item->setBackground(QColor(249 ,249, 249));
    else item->setBackground(QColor(Qt::white));

    item->setSizeHint(itemWidget->size());

    ui->listRankSurge->insertItem(id - 1, item);
    ui->listRankSurge->setItemWidget(item, itemWidget);
}

void RankListWidget::setRankList(std::initializer_list<RankItemContent> _list) {
    for(auto &item: _list) {
        this->setRankList(item);
    }
}

/*
 * 设置榜单封面
 */
void RankListWidget::setCover(const QString &_imgPath) {
    assert(!_imgPath.isEmpty());

    ui->label_imgSurge->setStyleSheet(QString("border-image: url(%1)").arg(_imgPath));
}
