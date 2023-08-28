//
// Created by TURIING on 2023/8/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SlideShowWidget.h" resolved

#include "slideshowwidget.h"
#include "ui_SlideShowWidget.h"


SlideShowWidget::SlideShowWidget(QWidget *parent) :QWidget(parent), ui(new Ui::SlideShowWidget) {
    ui->setupUi(this);

    this->setAttribute(Qt::WA_StyledBackground);
    this->setFixedSize(1500, 380);

    this->initButtonGroup();

    this->initList();

    this->initView();

    this->setTimer();

    m_newTimer = new QTimer(this);
    m_newTimer->setInterval(5000);
    connect(m_newTimer, &QTimer::timeout, [this]{ onRollRight(); });
    m_newTimer->start();

}

SlideShowWidget::~SlideShowWidget() {
    delete ui;
}

void SlideShowWidget::initButtonGroup() {
    m_btnGroup->addButton(ui->btnPic0, 0);
    m_btnGroup->addButton(ui->btnPic1, 1);
    m_btnGroup->addButton(ui->btnPic2, 2);
    m_btnGroup->addButton(ui->btnPic3, 3);
    m_btnGroup->addButton(ui->btnPic4, 4);
    m_btnGroup->addButton(ui->btnPic5, 5);
    m_btnGroup->addButton(ui->btnPic6, 6);
    m_btnGroup->addButton(ui->btnPic7, 7);
    m_btnGroup->addButton(ui->btnPic8, 8);
    m_btnGroup->addButton(ui->btnPic9, 9);

    m_btnGroup->setExclusive(true);

    m_btnGroup->button(1)->setChecked(true);
    for(auto i = 0; i < 10; i++)
        static_cast<SlideShowButton*>(m_btnGroup->button(i))->setId(i);

}

/**
 * 初始化m_posList、m_zValueList、m_pixmapScaleList
 */
void SlideShowWidget::initList() {
    m_posList << P1 << P2 << P3 << P4 << P5 << P6 << P7 << P8 << P9 << P10;
    m_zValueList << 1 << 2 << 1  << 0  << 0  << 0  << 0  << 0  << 0 << 0;
    m_pixmapScaleList << 0.8<< 1 << 0.8 << 0.8 << 0.8 << 0.8 << 0.8 << 0.8 << 0.8 << 0.8;
}

void SlideShowWidget::initView() {
    ui->graphicsView->setStyleSheet("background: transparent; padding: 0px; border: 0px;");
    ui->graphicsView->setScene(m_scene);
    m_scene->setSceneRect(0, 0, RAW_VIEW_SIZE.width(), RAW_VIEW_SIZE.height());
    m_midLine.setPoints(QPointF(0, 0), QPointF(RAW_VIEW_SIZE.width(), 0));

    for(auto i = 1; i <= 10; i++)
        m_pixmapList.append(QPixmap(QString(":/images/Resources/images/%1.png").arg(i)));

    for(auto i = 0; i < 10; i++) {
        m_itemList.append(new SlideShowItem(m_pixmapList[i].scaled(BIG_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        m_itemList[i]->setScale(m_pixmapScaleList[i]);
        m_itemList[i]->setType(i);
        m_itemList[i]->setId(i);
        m_itemList[i]->setOffset(QPointF(0, 0));
    }

    for(auto i = 0; i < 10; i++) {
        m_scene->addItem(m_itemList[i]);
        m_itemList[i]->setPos(m_midLine.pointAt(m_posList[i]));
        m_itemList[i]->setZValue(m_zValueList[i]);
        m_itemList[i]->setTransformationMode(Qt::SmoothTransformation);

        if(i != 1) m_itemList[i]->setPos(m_itemList[i]->x(), RAW_VIEW_SIZE.height() / 10);

        m_point.append(m_itemList[i]->pos());
    }

    for(auto i = 0; i < 10; i++)
        m_map.insert((static_cast<SlideShowButton *>(m_btnGroup->button(i)))->id(), m_itemList[i]);
}

void SlideShowWidget::setTimer() {
    // 利用持续时间和帧数计算出定时时间,持续时间/（帧数*持续时间），这里乘1000是转为秒
    m_timer->setInterval(DURATION_MS / (FPS * DURATION_MS / 1000));
    connect(m_timer, &QTimer::timeout, this, &SlideShowWidget::onTimeOut);

    for(auto i = 0; i < 10; i++) {
        connect(m_itemList[i], &SlideShowItem::clickedId, this, &SlideShowWidget::onItemRollClicked);
        void (SlideShowButton:: *func)(int) = &SlideShowButton::entered;
        connect(static_cast<SlideShowButton *>(m_btnGroup->button(i)), func, [this](int _id) {
            auto *p = m_map.value(_id);
            m_btnMoveEnable = false;
            onItemRollClicked(p->type());
        });
    }
}

void SlideShowWidget::onTimeOut() {
    QVector<QGraphicsItemAnimation *> item(10);
    for(auto i = 0; i < 10; i++) item[i] = new QGraphicsItemAnimation();

    auto timeLine = new QTimeLine(200);
    timeLine->setLoopCount(1);
    int first = getRightN(m_startNum - 1);
    for(auto i = 0; i < 10; i++) {
        m_itemList[i] = m_map.value(first % 10);
        first++;
        m_itemList[i]->setScale(m_pixmapScaleList[i]);
        m_itemList[i]->setZValue(m_zValueList[i]);
        m_itemList[i]->setTransformationMode(Qt::SmoothTransformation);

        item[i]->setItem(m_itemList[i]);
        item[i]->setTimeLine(timeLine);
        item[i]->setPosAt(1, m_point[i]);

        m_itemList[i]->setPos(m_point[i]);
    }

    timeLine->start();
    m_scene->invalidate();
    m_timer->stop();
}

/*
 * 获取准确的位置
 */
int SlideShowWidget::getRightN(int _num) {
    if(_num == -1) return 9;
    if(_num == 10) return 0;
}

void SlideShowWidget::onItemRollClicked(int _type) {
    if(m_timer->isActive()) return;

    rollItem(_type, 0);
}

void SlideShowWidget::rollItem(int _rollDir, unsigned int _rollCount) {
    _rollCount = 0;
    if(m_timer->isActive()) return;

    int nBegin = _rollDir;
    m_startNum = getRightN(nBegin);
    m_timer->start();
}

void SlideShowWidget::onRollLeft() {
    int id = m_btnGroup->checkedId();
    if(id - 1 < 0) id = 9;
    else id -= 1;

    m_btnGroup->button(id)->setChecked(true);
    rollItem(id, 0);
}

void SlideShowWidget::onRollRight() {
    int id = m_btnGroup->checkedId();
    id = (id + 1) % 10;
    m_btnGroup->button(id)->setChecked(true);
    rollItem(id, 0);
}
