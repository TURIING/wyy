//
// Created by TURIING on 2023/9/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AccountWidget.h" resolved

#include "accountwidget.h"
#include "ui_AccountWidget.h"


AccountWidget::AccountWidget(QWidget *parent) :QWidget(parent), ui(new Ui::AccountWidget) {
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("#AccountWidget{ background: white; border-radius: 10px; }"
                        "QListWidget{ border: none; }"
                        "QListWidget::item { height: 60px; padding-left: 15px; }"
                        "QListWidget::item:hover { background: rgb(242, 242, 243); }"
                        "QListWidget::item:selected { background: rgb(242, 242, 243); }"
                        "#label_dynamicsNum, #label_attentionNum, #label_fansNum { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 26px; font-weight: bold; }"
                        "#label_dynamics, #label_attention, #label_fans {font-family: '微软雅黑'; color: rgb(102, 102, 102); }"
                        "#btn_signIn { border-radius: 24px; border: 1px solid rgb(217, 217, 217); font-family: '微软雅黑'; font-size: 20px; color: rgb(51, 51, 51); }"
                        "QPushButton:hover#btn_signIn { background: rgb(242, 242, 242); }");

    ui->btn_signIn->setIcon(QIcon(":/icon/Resources/signIn.png"));
    ui->btn_signIn->setIconSize(QSize(32, 25));

    initList();
}

AccountWidget::~AccountWidget() {
    delete ui;
}

void AccountWidget::initList() {
    this->append(":/account/Resources/account/1.png", "会员中心", ":/account/Resources/account/10.png");
    this->append(":/account/Resources/account/2.png", "等级", ":/account/Resources/account/9.png");
    this->append(":/account/Resources/account/3.png", "商城", "");
    this->append(":/account/Resources/account/4.png", "个人信息设置", "");
    this->append(":/account/Resources/account/5.png", "绑定社交账号", ":/account/Resources/account/8.png");
    this->append(":/account/Resources/account/6.png", "我的客服", "");
    this->append(":/account/Resources/account/7.png", "退出登录", "");
}

/*
 * 往ListWidget添加item
 */
void AccountWidget::append(const QString &_icon, const QString &_text, const QString &_rightIcon) {
    auto hLayout = new QHBoxLayout();
    hLayout->setSpacing(0);

    /* 左侧图标 */
    auto label_icon = new QLabel(this);
    label_icon->setPixmap(QPixmap(_icon));
    hLayout->addWidget(label_icon, 0, Qt::AlignLeft);
    hLayout->insertSpacing(1, 8);

    /* text */
    auto label_text = new QLabel(this);
    label_text->setText(_text);
    label_text->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    label_text->setStyleSheet("QLabel { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 20px; }");
    hLayout->addWidget(label_text, 1, Qt::AlignLeft);

    /* 右侧图标 */
    if (!_rightIcon.isEmpty()) {
        auto label_rightIcon = new QLabel(this);
        label_rightIcon->setPixmap(QPixmap(_rightIcon));
        hLayout->addWidget(label_rightIcon, 0, Qt::AlignRight);
    }

    /* 向右箭头 */
    auto label_rightArrow = new QLabel(this);
    label_rightArrow->setPixmap(QPixmap(":/account/Resources/account/right.png"));
    hLayout->addWidget(label_rightArrow, 0, Qt::AlignRight);


    auto itemWidget = new QWidget(this);
    itemWidget->setLayout(hLayout);

    ui->listWidget->setItemWidget(new QListWidgetItem(ui->listWidget), itemWidget);
}
