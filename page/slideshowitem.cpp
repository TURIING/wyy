//
// Created by TURIING on 2023/8/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SlideShowItem.h" resolved

#include "slideshowitem.h"


SlideShowItem::SlideShowItem(QGraphicsObject *parent) :QGraphicsObject(parent) {}

SlideShowItem::SlideShowItem(const QPixmap &_pixmap, QGraphicsItem *_parent): QGraphicsObject(_parent), m_pixmap(_pixmap) {

}

SlideShowItem::~SlideShowItem() {}

void SlideShowItem::setPixmap(const QPixmap &_pixmap) {
    this->prepareGeometryChange();
    m_pixmap = _pixmap;
    this->update();
}

QRectF SlideShowItem::boundingRect() const {
    if(m_pixmap.isNull()) return QRectF();

    return QRectF(m_offset, m_pixmap.size() / m_pixmap.devicePixelRatio());
}

void SlideShowItem::setTransformationMode(Qt::TransformationMode _mode) {
    if(_mode == this->m_mode) return;

    this->m_mode = _mode;
    this->update();
}

void SlideShowItem::setOffset(const QPointF &_offset) {
    if(m_offset == _offset) return;

    this->prepareGeometryChange();
    m_offset =_offset;
    this->update();
}

void SlideShowItem::mousePressEvent(QGraphicsSceneMouseEvent *_event) {
    if(_event->button() == Qt::LeftButton) {
        m_pressedScenePoint = _event->pos();
        m_isPressed = true;
    }

    QGraphicsItem::mousePressEvent(_event);
}

void SlideShowItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *_event) {
    if(_event->button() != Qt::LeftButton) return;

    if(m_isPressed && boundingRect().contains(_event->pos()) && boundingRect().contains(m_pressedScenePoint)) {
        m_isPressed = false;
        emit clicked();
        emit clickedId(type());
    }

    QGraphicsItem::mouseReleaseEvent(_event);
}

void SlideShowItem::paint(QPainter *_painter, const QStyleOptionGraphicsItem *_option, QWidget *_widget) {
    Q_UNUSED(_widget);
    Q_UNUSED(_option);

    _painter->setRenderHint(QPainter::SmoothPixmapTransform, (this->m_mode == Qt::SmoothTransformation));
    _painter->drawPixmap(m_offset, getRoundRectPixmap(m_pixmap, 15));
}


