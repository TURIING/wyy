//
// Created by TURIING on 2023/9/3.
//

#ifndef WYY_CUSTOMCOMBOBOX_H
#define WYY_CUSTOMCOMBOBOX_H

#include <QComboBox>
#include <QListView>

class CustomComboBox: public QComboBox{
public:
    explicit CustomComboBox(QWidget *_parent = nullptr): QComboBox(_parent) {
        this->setView(new QListView());
        this->setMaxVisibleItems(9);
        this->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);

        this->setStyleSheet("QComboBox { border: 1px solid rgb(224, 224, 224); border-radius: 5px; padding-left: 15px; font-family: '微软雅黑'; font-size: 18px; color: rgb(51, 51, 51); }"
                            "QComboBox::drop-down { width: 20px; height: 17px; subcontrol-origin: padding; border-top-right-radius: 5px; margin-top: 7px; margin-right: 7px; }"
                            "QComboBox::down-arrow { image: url(:/setting/Resources/setting/comboBox_down_arrow.png); }"
                            "QComboBox QAbstractItemView { border: 1px solid rgb(224, 224, 224); border-radius: 5px; padding-bottom: 2px; padding-top: 2px; }"
                            "QComboBox QAbstractItemView::item { padding-left: 13px; min-height: 35px; background: white; color: rgb(102, 102, 102); }"
                            "QComboBox QAbstractItemView::item:selected { background: rgb(250, 250, 250); color: rgb(51, 51, 51); }"
                            "QComboBox QAbstractItemView::item:hover { background: rgb(245, 245, 245); color: rgb(51, 51, 51); }"
                            "QComboBox QScrollBar::vertical { width: 10px; border-radius: 5px; background: transparent; }"
                            "QComboBox QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 10px; border-radius: 5px; }"
                            "QComboBox QScrollBar::up-arrow:vertical{ border: none; }"
                            "QComboBox QScrollBar::sub-line:vertical{ background: transparent; }"
                            "QComboBox QScrollBar::add-line:vertical{ background: transparent; }");
    }
};


#endif //WYY_CUSTOMCOMBOBOX_H
