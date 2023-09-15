//
// Created by TURIING on 2023/9/9.
//

#ifndef WYY_NEWESTMUSIC_H
#define WYY_NEWESTMUSIC_H

#include <QWidget>
#include <QButtonGroup>
#include <QListWidget>
#include "control/newmusiclistitem.h"
#include <QScrollBar>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class NewestMusic; }
QT_END_NAMESPACE

class NewestMusic : public QWidget {
Q_OBJECT
    struct ItemContent {
        int id;
        QString imgPath;
        QString song;
        QString singer;
        QString album;
        QString duration;
    };
public:
    explicit NewestMusic(QWidget *parent = nullptr);

    ~NewestMusic() override;

private:
    Ui::NewestMusic *ui;
    QListWidget *m_listWidget;

    void initPageSwitcher();
    void initListWidget();
    void appendItem(const ItemContent &_content);
    void appendItem(std::initializer_list<ItemContent> _list);
private slots:
    void on_btn_newMusic_toggled(bool _checked);
};


#endif //WYY_NEWESTMUSIC_H
