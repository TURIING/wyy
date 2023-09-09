//
// Created by TURIING on 2023/9/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BottomWidget.h" resolved

#include "bottomwidget.h"
#include "ui_BottomWidget.h"


BottomWidget::BottomWidget(QWidget *parent) :QWidget(parent), ui(new Ui::BottomWidget) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("BottomWidget { background: white; border-top: 1px solid rgb(224, 224, 224);}"
                        "QPushButton#btn_songImg{ border-image: url(:/bottom/Resources/bottom/img.png); }"
                        "QLabel#label_song { font-family: '微软雅黑'; font-size: 21px; color: rgb(51, 51, 51); }"
                        "QLabel#label_singer { font-family: '微软雅黑'; font-size: 19px; color: rgb(89, 89, 89); }"

                        "#btn_like { border-image: url(:/bottom/Resources/bottom/like.png);}"

                        "QPushButton#btn_loop { border-image: url(:/bottom/Resources/bottom/loop.png);}"
                        "QPushButton:hover#btn_loop { border-image: url(:/bottom/Resources/bottom/loop_hover.png);}"

                        "QPushButton#btn_prev { border-image: url(:/bottom/Resources/bottom/prev.png);}"
                        "QPushButton:hover#btn_prev { border-image: url(:/bottom/Resources/bottom/prev_hover.png);}"

                        "QPushButton[checked = 'false']#btn_pause_start { border-image: url(:/bottom/Resources/bottom/pause.png);}"
                        "QPushButton[checked = 'false']:hover#btn_pause_start { border-image: url(:/bottom/Resources/bottom/pause_hover.png);}"
                        "QPushButton[checked = 'true']#btn_pause_start { border-image: url(:/bottom/Resources/bottom/start.png);}"
                        "QPushButton[checked = 'true']:hover#btn_pause_start { border-image: url(:/bottom/Resources/bottom/start_hover.png);}"

                        "QPushButton#btn_next { border-image: url(:/bottom/Resources/bottom/next.png);}"
                        "QPushButton:hover#btn_next { border-image: url(:/bottom/Resources/bottom/next_hover.png);}"

                        "QPushButton#btn_lyric { border-image: url(:/bottom/Resources/bottom/lyric.png);}"
                        "QPushButton:hover#btn_lyric { border-image: url(:/bottom/Resources/bottom/lyric_hover.png);}"

                        "#label_duration, #label_duration_total { color: rgb(194, 194, 194);}"

                        "QPushButton#btn_standard { border-image: url(:/bottom/Resources/bottom/standard.png);}"

                        "QPushButton#btn_tone_quality { border-image: url(:/bottom/Resources/bottom/tone_quality.png);}"

                        "QPushButton#btn_volume { border-image: url(:/bottom/Resources/bottom/volume.png);}"
                        "QPushButton:hover#btn_volume { border-image: url(:/bottom/Resources/bottom/volume_hover.png);}"

                        "QPushButton#btn_company { border-image: url(:/bottom/Resources/bottom/company.png);}"

                        "QPushButton#btn_song_list { border-image: url(:/bottom/Resources/bottom/song_list.png);}"
                        "QPushButton:hover#btn_song_list { border-image: url(:/bottom/Resources/bottom/song_list_hover.png);}"

                        "QSlider::groove:horizontal#horizontalSlider { padding: 0px 3px; height: 5px; border: 0px; border-radius: 2px; background: rgb(229, 229, 229); }"
                        "QSlider::handle:horizontal { margin: -3px; width: 10px; height: 10px; background: rgb(236, 65, 65); border-radius: 5px; }"
                        "QSlider::sub-page:horizontal { background: rgb(255, 52, 52);}"
    );

    m_player = new QMediaPlayer;
    m_player->setMedia(QUrl::fromLocalFile("../Resources/1000X.mp3"));


    connect(m_player, &QMediaPlayer::positionChanged, [this](qint64 _position) {
        ui->label_duration->setText(milliSecondToStr(_position));
        ui->horizontalSlider->setSliderPosition(static_cast<int>(_position));
    });

    connect(ui->horizontalSlider, &QSlider::sliderMoved, [this](int _value) {
        m_player->setPosition(static_cast<qint64>(_value));
    });

    connect(m_player, &QMediaPlayer::stateChanged, [this](QMediaPlayer::State _state) {
        if(_state == QMediaPlayer::State::StoppedState) {
            ui->btn_pause_start->setChecked(false);
        }
    });

}

BottomWidget::~BottomWidget() {
    delete ui;
}

void BottomWidget::on_btn_pause_start_toggled(bool _check) {
    ui->btn_pause_start->setChecked(_check);
    ui->btn_pause_start->setStyleSheet("QPushButton[checked = 'false']#btn_pause_start { border-image: url(:/bottom/Resources/bottom/pause.png);}"
                                       "QPushButton[checked = 'false']:hover#btn_pause_start { border-image: url(:/bottom/Resources/bottom/pause_hover.png);}"
                                       "QPushButton[checked = 'true']#btn_pause_start { border-image: url(:/bottom/Resources/bottom/start.png);}"
                                       "QPushButton[checked = 'true']:hover#btn_pause_start { border-image: url(:/bottom/Resources/bottom/start_hover.png);}"
                                       );

    if(_check){
        m_player->play();
        auto duration = m_player->duration();
        ui->label_duration_total->setText(milliSecondToStr(m_player->duration()));
        ui->horizontalSlider->setMaximum(static_cast<int>(duration));
        ui->horizontalSlider->setSingleStep(static_cast<int>(duration) / 200);
    }else{
        m_player->pause();
    }
}




