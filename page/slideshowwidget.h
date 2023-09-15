//
// Created by TURIING on 2023/8/19.
//

#ifndef WYY_SLIDESHOWWIDGET_H
#define WYY_SLIDESHOWWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QButtonGroup>
#include "slideshowbutton.h"
#include "slideshowitem.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>

constexpr qreal P1 = 0.01;
constexpr qreal P2 = 0.45;
constexpr qreal P3 = 1.05;
constexpr qreal P4 = P2;
constexpr qreal P5 = P2;
constexpr qreal P6 = P2;
constexpr qreal P7 = P2;
constexpr qreal P8 = P2;
constexpr qreal P9 = P2;
constexpr qreal P10 = P2;

constexpr QSize RAW_VIEW_SIZE(800, 300);
constexpr qreal SCALE_VIEW_PIXMAP = 1/1;                                    // View与图片比例
constexpr qreal SCALE_BIG_SMALL = 1/1;                                      // //图片大小比例

constexpr int DURATION_MS = 500;                                            // 移动一次图元经过时间,毫秒，不得低于帧数
constexpr int FPS = 60;                                                     // 帧数
QT_BEGIN_NAMESPACE
namespace Ui { class SlideShowWidget; }
QT_END_NAMESPACE

class SlideShowWidget : public QWidget {
Q_OBJECT
    const QSize BIG_SIZE = RAW_VIEW_SIZE / SCALE_VIEW_PIXMAP;
public:
    enum Rules: int {
        RuleA = 1,
        RuleB = -1,
        RuleC = 2,
        RuleD = -2,
    };

public:
    explicit SlideShowWidget(QWidget *parent = nullptr);

    ~SlideShowWidget() override;

    int getRightN(int _num);

    void rollItem(int _rollDir, unsigned _rollCount);
private:
    void initButtonGroup();
    void initList();
    void initView();
    void setTimer();
private:
    Ui::SlideShowWidget *ui;
    QButtonGroup *m_btnGroup = new QButtonGroup(this);

    QTimer *m_timer = new QTimer(this);
    QTimer * m_newTimer;
    QGraphicsScene *m_scene = new QGraphicsScene(this);
    int m_index = 0;
    Rules m_currentRule = RuleA;                                            // 当前执行的类型操作
    unsigned m_rollCount = 0;                                               // 滚动次数
    bool m_btnMoveEnable = true;

    QList<qreal> m_posList;                                                 // 各个图片的位置信息
    QList<qreal> m_zValueList;                                              // 各个显示优先级列表
    QList<qreal> m_pixmapScaleList;                                         // 各个图片位置信息伸缩因子列表
    QList<QPixmap> m_pixmapList;                                            // 各个图片列表
    QList<SlideShowItem *> m_itemList;
    QList<QPointF> m_point;

    QLineF m_midLine;                                                       // 中等线，确定图片位置
    QMap<int, SlideShowItem *> m_map;                                       // 按钮id与图片资源的映射
    int m_startNum = 0;
public slots:
    void onTimeOut();
    void onItemRollClicked(int _type);

private slots:
    void onRollLeft();
    void onRollRight();
};


#endif //WYY_SLIDESHOWWIDGET_H
