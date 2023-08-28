//
// Created by TURIING on 2023/8/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GalleryWidget.h" resolved

#include "gallerywidget.h"
#include "ui_GalleryWidget.h"


GalleryWidget::GalleryWidget(QWidget *parent) :QWidget(parent), ui(new Ui::GalleryWidget) {
    ui->setupUi(this);

    initUI();
}

GalleryWidget::~GalleryWidget() {
    delete ui;
}

void GalleryWidget::initUI() {
    //this->setFixedSize(1500, 800);
}

void GalleryWidget::adjustSize(int _rowCount) {
    this->setFixedSize(this->width(), _rowCount * 340 + 30);
}

void GalleryWidget::setGalleryItem(const GalleryItemContent &_content) {
    auto [cover, title, view] = _content;
    if(m_currentColumn < 4)
        ui->gridLayout->addWidget(new GalleryItem(cover, title, view), m_currentRow, ++m_currentColumn);
    else {
        m_currentColumn = 0;
        ui->gridLayout->addWidget(new GalleryItem(cover, title, view), ++m_currentRow, m_currentColumn);
    }
    this->adjustSize(m_currentRow + 1);
}

void GalleryWidget::setGalleryItem(std::initializer_list<GalleryItemContent> _list) {
    for(auto &item: _list) this->setGalleryItem(item);
}
