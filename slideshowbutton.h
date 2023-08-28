//
// Created by TURIING on 2023/8/19.
//

#ifndef WYY_SLIDESHOWBUTTON_H
#define WYY_SLIDESHOWBUTTON_H

#include <QAbstractButton>
#include <QPainter>


class SlideShowButton : public QAbstractButton {
Q_OBJECT

public:
    explicit SlideShowButton(QWidget *parent = nullptr);

    ~SlideShowButton() override;

    int id() const { return m_id; }
    void setId(int _id) { m_id = _id; }
protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void enterEvent(QEvent *_event);
private:
    bool m_isSelected = false;
    int m_id = 0;

public: signals:
    void entered();
    void entered(int);
};


#endif //WYY_SLIDESHOWBUTTON_H
