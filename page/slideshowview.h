//
// Created by TURIING on 2023/8/19.
//

#ifndef WYY_SLIDESHOWVIEW_H
#define WYY_SLIDESHOWVIEW_H

#include <QGraphicsView>
#include <QResizeEvent>


class SlideShowView : public QGraphicsView {
Q_OBJECT

public:
    explicit SlideShowView(QWidget *parent = nullptr);

    ~SlideShowView() override;

protected:
    void resizeEvent(QResizeEvent *_event) override;
public: signals:
    void sizeChanged(const QSize &);
};


#endif //WYY_SLIDESHOWVIEW_H
