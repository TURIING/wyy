//
// Created by TURIING on 2023/8/20.
//

#ifndef WYY_SLIDESHOWITEM_H
#define WYY_SLIDESHOWITEM_H

#include <QGraphicsObject>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include "utility/utility.h"

class SlideShowItem : public QGraphicsObject {
Q_OBJECT

public:
    explicit SlideShowItem(QGraphicsObject *parent = nullptr);
    explicit SlideShowItem(const QPixmap &_pixmap, QGraphicsItem *_parent = nullptr);
    ~SlideShowItem() override;

    QPixmap pixmap() const { return m_pixmap; }
    void setPixmap(const QPixmap &_pixmap);

    virtual QRectF boundingRect() const override;

    void setTransformationMode(Qt::TransformationMode _mode);

    QPointF offset() const { return m_offset; }
    void setOffset(const QPointF &_offset);

    virtual int type() const override { return m_type; }
    void setType(int _type) { m_type = _type; }

    int id() const { return m_id; }
    void setId(int _id) { m_id = _id; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *_event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *_event);
    void paint(QPainter *_painter, const QStyleOptionGraphicsItem *_option, QWidget *_widget);

private:
    Qt::TransformationMode m_mode = Qt::SmoothTransformation;
    bool m_isPressed = false;
    int m_type = 0;
    int m_id = 0;
    qreal m_pointPercent = 0.0;
    QPixmap m_pixmap;
    QPointF m_offset;
    QPointF m_pressedScenePoint;                                                // 按压的点

public: signals:
    void clicked();
    void clickedId(int);
};


#endif //WYY_SLIDESHOWITEM_H
