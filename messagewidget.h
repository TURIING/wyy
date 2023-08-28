//
// Created by TURIING on 2023/8/24.
//

#ifndef WYY_MESSAGEWIDGET_H
#define WYY_MESSAGEWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include "messageitem.h"
#include <QListWidgetItem>
#include <QScrollBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MessageWidget; }
QT_END_NAMESPACE

class MessageWidget : public QWidget {
Q_OBJECT
public:
    struct Message {
        QString messager;
        QString description;
        QString time;
        QString iconPath;
    };

public:
    explicit MessageWidget(QWidget *parent = nullptr);

    ~MessageWidget() override;

    void setMessage(const Message &_message);
    void setMessage(std::initializer_list<Message> _messageList);
private:
    void initBtnGroup();
    void initMessageList();
private:
    Ui::MessageWidget *ui;
};


#endif //WYY_MESSAGEWIDGET_H
