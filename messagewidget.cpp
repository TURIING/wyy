//
// Created by TURIING on 2023/8/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MessageWidget.h" resolved

#include "messagewidget.h"
#include "ui_MessageWidget.h"


MessageWidget::MessageWidget(QWidget *parent) :QWidget(parent), ui(new Ui::MessageWidget) {
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("QWidget#MessageWidget{border:0px; background:white; border-radius:1px;}"
                        "QLabel#label_read{ color:rgb(80,125,175); }");
    initBtnGroup();
    initMessageList();

    this->setMessage({{"云音乐VIP", "黑胶时光机：您的本周(1.9-1.15)听歌数据已生成，快去查看吧！", "2022年1月16日", ":/message/Resources/images/message/1.png"},
                      {"云音乐小秘书", "恭喜你获得1个月网易云音乐黑胶VIP", "2022年1月06日", ":/message/Resources/images/message/2.png"},
                      {"云音乐福利", "你升级啦：恭喜你到达8级，快去看看有哪些新的特权吧！", "2021年10月14日", ":/message/Resources/images/message/3.png"},
                      {"音乐挑战小助手", "你私藏的宝藏歌曲《这就是爱吗》登上了2021-08-02期赏音猎人应援榜", "2022年1月16日", ":/message/Resources/images/message/4.png"},
                      {"社区小助手", "活动：恭喜你获得了一次抽奖机会，100%中奖噢 ~ 10年黑胶会员", "2022年1月16日", ":/message/Resources/images/message/5.png"},
                      {"网易云音乐", "活动：薅羊毛的快乐，你想象不到！邀请新用户使用一起听", "2022年1月16日", ":/message/Resources/images/message/6.png"},
                      {"曲库小学妹", "若看不到更新快清理缓存召唤一下吧！如有上传歌词翻译", "2020年11月20日", ":/message/Resources/images/message/1.png"},
                      {"云音乐游戏酱", "热门活动：想和异界少女一起开学吗？二次元专区营业啦！", "2020年09月02日", ":/message/Resources/images/message/2.png"},
                      {"云村大喇叭", "活动：疫情过后，你最想和谁一起拥抱春天？ 在这段特殊的时间里", "2020年02月22日", ":/message/Resources/images/message/3.png"},
                      {"音乐人来了", "直播：中午好，你喜欢的音乐人要不要买菜即将到访！", "2020年02月22日", ":/message/Resources/images/message/4.png"},
                      {"云音乐VIP", "黑胶时光机：您的本周(1.9-1.15)听歌数据已生成，快去查看吧！", "2022年1月16日", ":/message/Resources/images/message/5.png"},
                      {"云音乐VIP", "黑胶时光机：您的本周(1.9-1.15)听歌数据已生成，快去查看吧！", "2022年1月16日", ":/message/Resources/images/message/6.png"},
                      });
}

MessageWidget::~MessageWidget() {
    delete ui;
}

void MessageWidget::initBtnGroup() {
    ui->btnGroupWidget->setGeometry(10, 60, 342, 30);
    ui->btnGroupWidget->setStyleSheet("QWidget#btnGroupWidget { background: rgb(255,255,255); border: 1px solid rgb(187, 187, 187); border-radius: 19px; }");

    /* 私信按钮 */
    ui->btn_chat->setGeometry(0, 1, 85, 28);
    ui->btn_chat->move(1, 1);
    ui->btn_chat->setCheckable(true);
    ui->btn_chat->setStyleSheet("QPushButton{ color: rgb(55, 55, 55); border: 0px; background: rgb(255, 255, 255); border-radius: 19px; font-size: 20px;}"
                                "QPushButton:hover{ border: 0px; background: rgb(244, 244, 244); border-radius: 19px; }"
                                "QPushButton:checked{ color: rgb(255, 255, 255); border: 0px; background: rgb(187, 187, 187); border-radius: 19px; }");

    /* 评论按钮 */
    ui->btn_comment->setGeometry(0, 1, 85, 28);
    ui->btn_comment->move(86, 1);
    ui->btn_comment->setCheckable(true);
    ui->btn_comment->setStyleSheet("QPushButton{ color: rgb(55, 55, 55); border: 0px; background: rgb(255, 255, 255); border-radius: 19px; font-size: 20px; }"
                                "QPushButton:hover{ border: 0px; background: rgb(244, 244, 244); border-radius: 19px; }"
                                "QPushButton:checked{ color: rgb(255, 255, 255); border: 0px; background: rgb(187, 187, 187); border-radius: 19px; }");

    /* @我按钮 */
    ui->btn_atMe->setGeometry(0, 1, 85, 28);
    ui->btn_atMe->move(171, 1);
    ui->btn_atMe->setCheckable(true);
    ui->btn_atMe->setStyleSheet("QPushButton{ color: rgb(55, 55, 55); border: 0px; background: rgb(255, 255, 255); border-radius: 19px; font-size: 20px; }"
                                "QPushButton:hover{ border: 0px; background: rgb(244, 244, 244); border-radius: 19px; }"
                                "QPushButton:checked{ color: rgb(255, 255, 255); border: 0px; background: rgb(187, 187, 187); border-radius: 19px; }");

    /* 通知按钮 */
    ui->btn_inform->setGeometry(0, 1, 85, 28);
    ui->btn_inform->move(256, 1);
    ui->btn_inform->setCheckable(true);
    ui->btn_inform->setStyleSheet("QPushButton{ color: rgb(55, 55, 55); border: 0px; background: rgb(255, 255, 255); border-radius: 19px; font-size: 20px; }"
                                "QPushButton:hover{ border: 0px; background: rgb(244, 244, 244); border-radius: 19px; }"
                                "QPushButton:checked{ color: rgb(255, 255, 255); border: 0px; background: rgb(187, 187, 187); border-radius: 19px; }");

    auto btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->btn_chat, 0);
    btnGroup->addButton(ui->btn_comment, 1);
    btnGroup->addButton(ui->btn_atMe, 2);
    btnGroup->addButton(ui->btn_inform, 3);
    btnGroup->setExclusive(true);
    btnGroup->button(0)->setChecked(true);
}

void MessageWidget::setMessage(const Message &_message) {
    auto item = new QListWidgetItem(ui->chatListWidget);

    auto [messager, description, time, iconPath] = _message;
    auto messageItem = new MessageItem(messager, description, time, iconPath);

    ui->chatListWidget->setItemWidget(item, messageItem);
}

void MessageWidget::setMessage(std::initializer_list<Message> _messageList) {
    for(auto &message: _messageList) {
        this->setMessage(message);
    }
}

void MessageWidget::initMessageList() {
    ui->chatListWidget->setStyleSheet("QListWidget{ border: 1px; background: white; border-radius: 5px; }"
                                      "QListWidget::Item{ background: white; height: 88px; padding-right: 12px; }"
                                      "QListWidget::Item:hover { background: rgb(246, 246, 247); }");
    auto scrollBar = ui->chatListWidget->verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar::vertical{ background: transparent; width: 10px; }"
                             "QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 10px; border-radius: 5px; }"
                             "QScrollBar::up-arrow:vertical{ border: none; }"
                             "QScrollBar::sub-line:vertical{ background: transparent; }"
                             "QScrollBar::add-line:vertical{ background: transparent; }");

}
