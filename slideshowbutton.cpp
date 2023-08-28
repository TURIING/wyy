//
// Created by TURIING on 2023/8/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SlideShowButton.h" resolved

#include "slideshowbutton.h"


SlideShowButton::SlideShowButton(QWidget *parent) :QAbstractButton(parent){
    this->setCheckable(true);
    this->setFixedSize(8, 8);
}

SlideShowButton::~SlideShowButton() {}

void SlideShowButton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRectF drawRect = this->rect();

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::gray);
    painter.setPen(pen);

    QPainterPath drawPath;
    drawPath.addRoundedRect(drawRect, 4, 4);
    painter.setClipPath(drawPath);

    if(this->isChecked())
        painter.fillRect(drawRect, QColor(236, 65, 65));
    else
        painter.fillRect(drawRect, QColor(128, 128, 128, 128));
}

void SlideShowButton::enterEvent(QEvent *_event) {
    if(!isChecked()) setChecked(true);
    emit entered(m_id);

    QAbstractButton::enterEvent(_event);
}


