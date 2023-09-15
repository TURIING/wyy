//
// Created by TURIING on 2023/8/25.
//

#ifndef WYY_MESSAGEITEM_H
#define WYY_MESSAGEITEM_H

#include <QWidget>
#include "utility/utility.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MessageItem; }
QT_END_NAMESPACE

class MessageItem : public QWidget {
Q_OBJECT

public:
    explicit MessageItem(QWidget *parent = nullptr);
    MessageItem(const QString &_messager, const QString &_description, const QString &_time, const QString &_iconPath, QWidget *_parent = nullptr);

    ~MessageItem() override;



private:
    Ui::MessageItem *ui;
};


#endif //WYY_MESSAGEITEM_H
