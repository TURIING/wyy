//
// Created by TURIING on 2023/9/3.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SettingWidget.h" resolved

#include "settingwidget.h"
#include "ui_SettingWidget.h"


SettingWidget::SettingWidget(QWidget *parent) :QWidget(parent), ui(new Ui::SettingWidget) {
    ui->setupUi(this);

    /* 设置滚动区域背景颜色以及滚动条样式 */
    ui->scrollArea->setStyleSheet("QScrollArea {background-color:white; border: none;}");
    ui->scrollArea->viewport()->setStyleSheet("background-color:white;");
    auto scrollBar = ui->scrollArea->verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar::vertical{ background: transparent; width: 14px; margin-right: 2px; }"
                             "QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 10px; border-radius: 6px; }"
                             "QScrollBar::up-arrow:vertical{ border: none; }"
                             "QScrollBar::sub-line:vertical{ background: transparent; }"
                             "QScrollBar::add-line:vertical{ background: transparent; }");

    /* 设置组件样式 */
    this->setStyleSheet("#SettingWidget { margin-right: 5px; }"
                        "#label_setting { font-family: '微软雅黑'; font-size: 28px; font-weight: bold; color: rgb(51, 51, 51); }"
                        "#label_bindIcon{ border-image: url(:/setting/Resources/setting/bind.png); }"
                        "#label_bind { color: rgb(51, 51, 51); }"
                        "QLabel:hover#label_bind { color: black; }"
                        "QLabel[role = 'headline'] { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 22px; font-weight: bold;}"
                        "QLabel[role = 'title'] { color: rgb(102, 102, 102); font-family: '微软雅黑'; font-size: 18px; font-weight: bold; }"
                        "QLabel[role = 'comment'] { color: rgb(102, 102, 102); font-family: '微软雅黑'; font-size: 18px; }"
                        "QLabel[role = 'normal'] { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 18px; }"
                        "#label_3 { color: rgb(153, 153, 153); font-family: '微软雅黑'; font-size: 18px; }"

                        "QCheckBox { spacing: 15px; color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 18px; }"
                        "QCheckBox::indicator { width: 24px; height: 24px; }"
                        "QCheckBox::indicator:unchecked { image: url(:/setting/Resources/setting/checkbox_unchecked.png); }"
                        "QCheckBox::indicator:checked { image: url(:/setting/Resources/setting/checkbox_checked.png); }"

                        "QRadioButton { spacing: 15px; color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 18px; }"
                        "QRadioButton::indicator { width: 24px; height: 24px; }"
                        "QRadioButton::indicator:unchecked { image: url(:/setting/Resources/setting/radio_unchecked.png); }"
                        "QRadioButton::indicator:checked { image: url(:/setting/Resources/setting/radio_checked.png); }"

                        "QFrame[frameShape='4']{ color: rgb(240, 240, 240); }");
    ui->btn_modify->setStyleSheet("QPushButton#btn_modify{ border: 1px solid rgb(217, 217, 217); border-radius: 18px; }"
                                  "QPushButton:hover#btn_modify{ background: rgb(242, 242, 242); }");
    ui->btn_findFriend->setStyleSheet("QPushButton#btn_findFriend{ border: 1px solid rgb(217, 217, 217); border-radius: 18px; }"
                                  "QPushButton:hover#btn_findFriend{ background: rgb(242, 242, 242); }");

}

SettingWidget::~SettingWidget() {
    delete ui;
}
