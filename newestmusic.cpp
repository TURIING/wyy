//
// Created by TURIING on 2023/9/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_NewestMusic.h" resolved

#include "newestmusic.h"
#include "ui_NewestMusic.h"


NewestMusic::NewestMusic(QWidget *parent) :QWidget(parent), ui(new Ui::NewestMusic) {
    ui->setupUi(this);
    //this->setAttribute(Qt::WA_StyledBackground);
    /* 使滚动区域背景透明 */
    ui->scrollArea->setStyleSheet("QScrollArea {background-color:white; border: none;}");
    ui->scrollArea->viewport()->setStyleSheet("background-color: transparent;");
    /* 设置滚动条样式 */
    auto scrollBar = ui->scrollArea->verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar::vertical{ background: transparent; width: 12px; }"
                             "QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 12px; border-radius: 6px; }"
                             "QScrollBar::up-arrow:vertical{ border: none; }"
                             "QScrollBar::sub-line:vertical{ background: transparent; }"
                             "QScrollBar::add-line:vertical{ background: transparent; }");

    this->setStyleSheet("QWidget#widget_pageSwitcher { border: 1px solid rgb(187, 187, 187); border-radius: 22px; }"

                        "QTabWidget { border: none; }"
                        "QTabWidget::pane {  background: white; }"
                        "QTabBar::tab { font-family: '微软雅黑 Light'; font-size: 21px; margin-bottom: 30px; }"
                        "QTabBar::tab:!selected { color: rgb(102, 102, 102); }"
                        "QTabBar::tab:selected { font-weight: bold; color: rgb(51, 51, 51); border-bottom: none; }"

                        "QLabel#label_id { color: rgb(204, 204, 204); font-family: '微软雅黑'; font-size: 18px;}"
                        "QLabel#label_song { color: rgb(89, 89, 89); font-family: '微软雅黑'; font-size: 19px;}"
                        "QLabel#label_singer { color: rgb(102, 102, 102); font-family: '微软雅黑'; font-size: 19px;}"
                        "QLabel#label_album { color: rgb(102, 102, 102); font-family: '微软雅黑'; font-size: 19px;}"
                        "QLabel#label_duration { color: rgb(153, 153, 153); font-family: '微软雅黑'; font-size: 18px;}"
                        );
    initPageSwitcher();
    initListWidget();
}

NewestMusic::~NewestMusic() {
    delete ui;
}

void NewestMusic::initPageSwitcher() {
    auto group = new QButtonGroup(this);
    group->addButton(ui->btn_newMusic, 1);
    group->addButton(ui->btn_newDisk, 2);

    ui->btn_newMusic->setStyleSheet("QPushButton { font-family: '微软雅黑'; font-size: 18px; color: rgb(51, 51, 51);}"
                                    "QPushButton[checked = 'false'] { border: 0px; border-radius: 21px; background: white;  }"
                                    "QPushButton:hover {background: rgb(245, 245, 245); border: 0px; border-radius: 21px; }"
                                    "QPushButton[checked = 'true'] {background: rgb(187, 187, 187); border: 0px; border-radius: 21px; color: white; }");
    ui->btn_newDisk->setStyleSheet("QPushButton { font-family: '微软雅黑'; font-size: 18px; color: rgb(51, 51, 51);}"
                                   "QPushButton[checked = 'false'] { border: 0px; border-radius: 21px; background: white; }"
                                   "QPushButton:hover {background: rgb(245, 245, 245); border: 0px; border-radius: 21px; }"
                                   "QPushButton[checked = 'true'] {background: rgb(187, 187, 187); border: 0px; border-radius: 21px; color: white; }");


}

void NewestMusic::on_btn_newMusic_toggled(bool _checked) {
    ui->btn_newMusic->setStyleSheet("QPushButton { font-family: '微软雅黑'; font-size: 18px; color: rgb(51, 51, 51);}"
                                    "QPushButton[checked = 'false'] { border: 0px; border-radius: 21px; background: white;  }"
                                    "QPushButton:hover {background: rgb(245, 245, 245); border: 0px; border-radius: 21px; }"
                                    "QPushButton[checked = 'true'] {background: rgb(187, 187, 187); border: 0px; border-radius: 21px; color: white; }");
    ui->btn_newDisk->setStyleSheet("QPushButton { font-family: '微软雅黑'; font-size: 18px; color: rgb(51, 51, 51);}"
                                   "QPushButton[checked = 'false'] { border: 0px; border-radius: 21px; background: white; }"
                                   "QPushButton:hover {background: rgb(245, 245, 245); border: 0px; border-radius: 21px; }"
                                   "QPushButton[checked = 'true'] {background: rgb(187, 187, 187); border: 0px; border-radius: 21px; color: white; }");
}

void NewestMusic::initListWidget() {
    m_listWidget = new QListWidget(this);
    m_listWidget->setStyleSheet("QListWidget { background: white; border: none; }"
                                "QListWidget::item { height: 120px; }"
                                "QListWidget::item:hover { background: rgb(242, 242, 243);}"
                                "QListWidget::item:selected { background: rgb(240, 240, 240);}"
                                );
    appendItem({{1, ":/newMusic/Resources/newMusic/1.png", "Special One", "AGA/陈奕迅", "Special One (feat. Eason Chan)", "04:43"},
                {2, ":/newMusic/Resources/newMusic/2.png", "另一个我和你", "Ty.", "另一个我", "03:21"},
                {3, ":/newMusic/Resources/newMusic/3.png", "活力全开", "范世", "活力全开", "03:05"},
                {4, ":/newMusic/Resources/newMusic/4.png", "Angry", "The Rolling Stones", "Angry", "03:46"},
                {5, ":/newMusic/Resources/newMusic/5.png", "NUNA3.0", "郑润泽", "NUNA3.0", "03:43"},
                {6, ":/newMusic/Resources/newMusic/6.png", "亲爱的陌生人", "蔡有绮", "亲爱的陌生人", "04:21"},
                {7, ":/newMusic/Resources/newMusic/7.png", "海赋", "窦唯／朝简", "海赋", "31:08"},
                {8, ":/newMusic/Resources/newMusic/8.png", "Revelation", "周震南", "F.F.F", "03:14"},
                {9, ":/newMusic/Resources/newMusic/9.png", "已有自知之明的人", "sarah salola", "已有自知之明的人", "03:35"},
                {10, ":/newMusic/Resources/newMusic/10.png", "BITE BACK", "王心凌", "BITE BACK", "03:30"},
                {11, ":/newMusic/Resources/newMusic/11.png", "和影子跳舞（feat.毛不易）", "VaVa毛衍七/毛不易", "和影子跳舞（feat.毛不易）", "03:28"},
                {12, ":/newMusic/Resources/newMusic/12.png", "像我们这种女子", "容祖儿", "像我们这种女子", "03:42"},
                {13, ":/newMusic/Resources/newMusic/13.png", "Social Path", "StrayKids/LisA", "Social Path", "03:21"},
                {14, ":/newMusic/Resources/newMusic/14.png", "同心圆", "周深", "同心圆", "03:21"},
                {15, ":/newMusic/Resources/newMusic/15.png", "走到黑", "宝石Gem/大鹏", "走到黑", "03:21"}
                });
    m_listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tabWidget->insertTab(0, m_listWidget, "全部");
    ui->tabWidget->setCurrentIndex(0);
}

void NewestMusic::appendItem(const NewestMusic::ItemContent &_content) {
    auto [id, imgPath, song, singer, album, duration] = _content;
    auto itemWidget = new NewMusicListItem(id, imgPath, song, singer, album, duration, this);
    auto item = new QListWidgetItem(m_listWidget);
    item->setSizeHint(itemWidget->size());
    /* 设置item交替颜色 */
    if(id % 2 == 0) {
        item->setBackground(Qt::white);
    }else {
        item->setBackground(QColor(250, 250, 250));
    }

    m_listWidget->setItemWidget(item, itemWidget);
    m_listWidget->setFixedHeight((m_listWidget->count() - 1) * 120);
}

void NewestMusic::appendItem(std::initializer_list<ItemContent> _list) {
    for(auto &item: _list) {
        appendItem(item);
    }
}
