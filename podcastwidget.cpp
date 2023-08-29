//
// Created by TURIING on 2023/8/29.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PodcastWidget.h" resolved

#include "podcastwidget.h"
#include "ui_PodcastWidget.h"


PodcastWidget::PodcastWidget(QWidget *parent) :QWidget(parent), ui(new Ui::PodcastWidget) {
    ui->setupUi(this);
}

PodcastWidget::~PodcastWidget() {
    delete ui;
}

/*
 * 添加一个item
 */
void PodcastWidget::appendItem(const PodcastWidget::PodcastItemContent &_content) {
    auto [cover, song, category, description, views, duration] = _content;

    auto item = new PodcastWidgetItem(cover, song, description, category, views, duration, this);

    if(m_currentColumn < 1)
        ui->gridLayout->addWidget(item, m_currentRow, ++m_currentColumn);
    else {
        m_currentColumn = 0;
        ui->gridLayout->addWidget(item, ++m_currentRow, m_currentColumn);
    }
    this->adjustSize(m_currentRow + 1);
}

void PodcastWidget::adjustSize(int _rowCount) {
    this->setFixedSize(this->width(), _rowCount * 124 + 40);
}

/*
 * 添加多个item
 */
void PodcastWidget::appendItem(std::initializer_list<PodcastItemContent> _list) {
    for(auto &item: _list) this->appendItem(item);
}
