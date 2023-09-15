//
// Created by TURIING on 2023/9/15.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CustomSearchBox.h" resolved

#include "customsearchbox.h"
#include "ui_CustomSearchBox.h"


CustomSearchBox::CustomSearchBox(QWidget *parent) :QWidget(parent), ui(new Ui::CustomSearchBox) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("#CustomSearchBox { background: rgb(247, 247, 247); border-radius: 17px; }"
                        "QLineEdit { background: rgb(247, 247, 247); border: none;  }"
                        "QLabel { border-image: url(:/favorite/Resources/favorite/search.png); }");

    connect(ui->lineEdit, &QLineEdit::textChanged, this, [this](const QString &_text) {
        if(_text.isEmpty()) {
            ui->label_icon->setStyleSheet("QLabel { border-image: url(:/favorite/Resources/favorite/search.png); }");
        }else {
            ui->label_icon->setStyleSheet("QLabel { border-image: url(:/favorite/Resources/favorite/deleteAll.png); }");
        }

        emit textChanged(_text);
    });
}

CustomSearchBox::~CustomSearchBox() {
    delete ui;
}
