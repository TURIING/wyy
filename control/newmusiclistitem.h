//
// Created by TURIING on 2023/9/9.
//

#ifndef WYY_NEWMUSICLISTITEM_H
#define WYY_NEWMUSICLISTITEM_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class NewMusicListItem; }
QT_END_NAMESPACE

class NewMusicListItem : public QWidget {
Q_OBJECT

public:
    explicit NewMusicListItem(QWidget *parent = nullptr);
    NewMusicListItem(int _id, const QString &_imgPath, const QString &_song, const QString &_singer, const QString &_album, const QString &_duration, QWidget *_parent = nullptr);

    ~NewMusicListItem() override;

private:
    Ui::NewMusicListItem *ui;
};


#endif //WYY_NEWMUSICLISTITEM_H
