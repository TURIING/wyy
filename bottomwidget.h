//
// Created by TURIING on 2023/9/8.
//

#ifndef WYY_BOTTOMWIDGET_H
#define WYY_BOTTOMWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMediaPlayer>
#include <QObject>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui { class BottomWidget; }
QT_END_NAMESPACE

class BottomWidget : public QWidget {
Q_OBJECT

public:
    explicit BottomWidget(QWidget *parent = nullptr);

    ~BottomWidget() override;


private:
    Ui::BottomWidget *ui;
    QMediaPlayer *m_player;


    /*
     * 微秒转文本
     */
    static QString milliSecondToStr(qint64 _duration) {
        auto duration = static_cast<int>(_duration);
        int secs = duration / 1000;
        int res_min = secs / 60;
        int res_sec = secs % 60;
        return QString::asprintf("%02d:%02d", res_min, res_sec);
    }

private slots:
    void on_btn_pause_start_toggled(bool _check);
};


#endif //WYY_BOTTOMWIDGET_H
