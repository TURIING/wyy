//
// Created by TURIING on 2023/8/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SlideShowView.h" resolved

#include "slideshowview.h"


SlideShowView::SlideShowView(QWidget *parent) :QGraphicsView(parent) {}

SlideShowView::~SlideShowView() {}

void SlideShowView::resizeEvent(QResizeEvent *_event) {
    emit sizeChanged(_event->size());

    QGraphicsView::resizeEvent(_event);
}
