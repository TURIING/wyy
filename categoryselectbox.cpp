//
// Created by TURIING on 2023/8/30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CategorySelectBox.h" resolved

#include "categoryselectbox.h"
#include "ui_CategorySelectBox.h"


CategorySelectBox::CategorySelectBox(QWidget *parent) :QWidget(parent), ui(new Ui::CategorySelectBox) {
    ui->setupUi(this);

    /* 设置 button group */
    m_btnGroup = new QButtonGroup(this);
    // 连接信号与信号
    void (QButtonGroup::*pSig_1)(int) = &QButtonGroup::buttonClicked;
    void (CategorySelectBox::*pSig_2)(int) = &CategorySelectBox::itemChoosed;
    connect(m_btnGroup, pSig_1, this, pSig_2);

    ui->gridLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    this->setStyleSheet("QLabel#label_category{ color: rgb(133, 133, 133); font-family: '微软雅黑'; font-size: 18px; margin-top: 0px; }");
}

CategorySelectBox::CategorySelectBox(int _columnCount, QWidget *_parent): CategorySelectBox(_parent) {
    this->setColumnCount(_columnCount);
}

CategorySelectBox::~CategorySelectBox() {
    delete ui;
}

/*
 * 设置类别标签
 */
void CategorySelectBox::setCategory(const QString &_text) {
    assert(!_text.isEmpty());

    ui->label_category->setText(_text);
    m_totalWidth += ui->label_category->width() + 25;
}

/*
 * 追加item
 */
void CategorySelectBox::appendItem(const QString &_text) {
    /* 在item前添加分隔符 */
    if(m_itemCount != -1 && (m_itemCount + 1) % m_columnCount != 0) {
        auto frame = new QFrame(this);
        frame->setFrameShape(QFrame::VLine);
        frame->setStyleSheet("QFrame[frameShape='5']{ color: rgb(230, 230, 230); }");
        frame->setFixedSize(2, 20);
        frame->setLineWidth(2);

        ui->gridLayout->addWidget(frame, m_currentRow, ++m_currentColumn);

        m_totalWidth += (22 + 2);
    }

    /* 添加button */
    auto btn = new QPushButton(_text, this);
    btn->setCheckable(true);

    auto size = computeTextSize(btn->font(), _text);
    btn->setFixedSize(size.width() + 32, size.height() + 10);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setStyleSheet("QPushButton{ font-family: '微软雅黑'; font-size: 18px; background: transparent; color: rgb(102, 102, 102); border-radius: 14px; }");

    connect(btn, &QPushButton::toggled, [btn](bool _checked) {
        if(_checked)
            btn->setStyleSheet("QPushButton{ font-family: '微软雅黑'; font-size: 18px; background: rgb(254, 245, 245); color: rgb(240, 105, 105); border-radius: 14px; }"
                               "QPushButton:hover{ background: rgb(253, 238, 238); }");
        else
            btn->setStyleSheet("QPushButton{ font-family: '微软雅黑'; font-size: 18px; background: transparent; color: rgb(102, 102, 102); border-radius: 14px; }"
                               "QPushButton:hover{ color: rgb(51, 51, 51); }");
    });

    if((m_itemCount + 1) % m_columnCount == 0) {
        // 需要换行插入
        m_currentColumn = 0;
        ui->gridLayout->addWidget(btn, ++m_currentRow, m_currentColumn);
    }else {
        // 不需要换行插入
        ui->gridLayout->addWidget(btn, m_currentRow, ++m_currentColumn);
        m_totalWidth += (22 + btn->width());
    }

    m_btnGroup->addButton(btn, ++m_itemCount);


    this->setFixedSize(m_totalWidth + 25, btn->height() * m_currentRow + 15 * (m_currentRow - 1));

}

/**
 * 设置默认选中的item
 * @param _id
 */
void CategorySelectBox::setDefaultItem(int _id) {
    assert(_id >= 0);

    auto btn = static_cast<QPushButton *>(m_btnGroup->button(_id));

    assert(btn != nullptr);

    btn->setChecked(true);
}


