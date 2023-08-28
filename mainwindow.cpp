//
// Created by TURIING on 2023/8/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->scrollArea_recommend->setStyleSheet("QScrollArea {background-color:transparent; border: none;}");
    ui->scrollArea_recommend->viewport()->setStyleSheet("background-color:transparent;");
    /* window */
    this->setWindowIcon(QIcon(":/icon/Resources/icon.png"));                // 设置程序icon
    this->setWindowFlag(Qt::FramelessWindowHint);                           // 窗口无边框

    /* lineEdit_Search */
    ui->lineEdit_Search->installEventFilter(this);
    ui->lineEdit_Search->setMouseTracking(true);                            // 使鼠标接收到鼠标move事件

    /* PopupSearch */
    auto popupSearch = new PopupSearch(this);
    popupSearch->installEventFilter(this);
    popupSearch->setMouseTracking(true);
    popupSearch->hide();

    this->initListWidgetLeftMenu();
    this->initListWidgetMyMusic();
    this->initPersonalRecommand();

    /* btn_avator */
    this->setAvator(":/images/Resources/images/turiing.png");

    initRank();

}

MainWindow::~MainWindow() {
    delete ui;
}

/**
 * 初始化左侧菜单样式及内容
 */
void MainWindow::initListWidgetLeftMenu() {
    ui->listWidget_LeftMenu->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);        // 取消垂直滚动条
    ui->listWidget_LeftMenu->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);      // 取消水平滚动条
    ui->listWidget_LeftMenu->setCurrentRow(0);
}

/**
 * 初始化左侧 我的音乐 菜单
 */
void MainWindow::initListWidgetMyMusic() {
    auto item_like = ui->listWidget_MyMusic->item(0);
    item_like->setIcon(QIcon(":/icon/Resources/like.png"));

    auto item_download = ui->listWidget_MyMusic->item(1);
    item_download->setIcon(QIcon(":/icon/Resources/download.png"));

    auto item_recently = ui->listWidget_MyMusic->item(2);
    item_recently->setIcon(QIcon(":/icon/Resources/recently.png"));
}

void MainWindow::mousePressEvent(QMouseEvent *_event) {
    /* 处理窗口移动事件 */
    int topWidgetHeight = ui->widget_top->height();
    if(_event->y() < topWidgetHeight)
        m_mouseGlobalPos = _event->globalPos();

    /* 鼠标焦点不在时，则关闭MessageWidget */
    if(m_messageWidget && !m_messageWidget->isHidden()) {
        auto rect = m_messageWidget->geometry();
        if(!rect.contains(_event->pos())) m_messageWidget->hide();
    }

    QWidget::mousePressEvent(_event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *_event) {
    int topWidgetHeight = ui->widget_top->height();
    if(_event->y() < topWidgetHeight) {
        int dx = _event->globalX() - m_mouseGlobalPos.x();
        int dy = _event->globalY() - m_mouseGlobalPos.y();
        m_mouseGlobalPos = _event->globalPos();
        this->move(x() + dx, y() + dy);
    }

    QWidget::mouseMoveEvent(_event);
}

/*
 * 初始化轮播图
 */
void MainWindow::initPersonalRecommand() {
    auto galleryWidget = new GalleryWidget;
    galleryWidget->setGalleryItem({{":/gallery/Resources/images/gallery/1.png", "每日歌曲推荐", 143},
                                   {":/gallery/Resources/images/gallery/2.png", "今天从《像你》开始听起|私人雷达", 143},
                                   {":/gallery/Resources/images/gallery/3.png", "萝莉女王Reol精选歌单", 143},
                                   {":/gallery/Resources/images/gallery/4.png", "动漫/神曲音乐集", 143},
                                   {":/gallery/Resources/images/gallery/5.png", "《二刺猿》日漫神曲大盘点根本停不下来", 143},
                                   {":/gallery/Resources/images/gallery/6.png", "日系私人订制 最懂你的日系 推荐每日更新35首", 143},
                                   {":/gallery/Resources/images/gallery/7.png", "东方评论5000以上歌曲", 143},
                                   {":/gallery/Resources/images/gallery/8.png", "乐符『东方缝纫机』", 143},
                                   {":/gallery/Resources/images/gallery/9.png", "[日漫二次元]那些无法跳过的op ed", 143},
                                   {":/gallery/Resources/images/gallery/10.png", "【绘画/肝图食用】适合画画时听的BGM", 143}});

    auto label_1 = new QLabel("推荐歌单 >");
    label_1->setCursor(Qt::PointingHandCursor);
    label_1->setFixedWidth(150);
    label_1->setStyleSheet("QLabel { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 28px; font-weight: bold; margin-bottom: 8px; margin-top: 15px;}");

    auto layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->addWidget(new SlideShowWidget());
    layout->addWidget(label_1);
    layout->addWidget(galleryWidget);

    auto widget = new QWidget();
    widget->setLayout(layout);

    ui->scrollArea_recommend->setWidget(widget);
    ui->scrollArea_recommend->setAlignment(Qt::AlignCenter);
    ui->scrollArea_recommend->setWidgetResizable(false);
    auto scrollBar = ui->scrollArea_recommend->verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar::vertical{ background: transparent; width: 10px; }"
                             "QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 10px; border-radius: 5px; }"
                             "QScrollBar::up-arrow:vertical{ border: none; }"
                             "QScrollBar::sub-line:vertical{ background: transparent; }"
                             "QScrollBar::add-line:vertical{ background: transparent; }");
}

/**
 * 设置头像
 * @param _imgPath
 */
void MainWindow::setAvator(const QString &_imgPath) {
    //QImage image(_imgPath);
    //image = image.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //
    //QPixmap pixmap = QPixmap::fromImage(image);
    //ui->btn_avator->setIcon(QIcon(pixmap));
    ui->btn_avator->setStyleSheet(QString("QPushButton{border-image: url(%1); border-radius: 25px; }").arg(_imgPath));
}

void MainWindow::on_btn_close_clicked() {
    this->close();
}

void MainWindow::on_btn_minimum_clicked() {
    this->showMinimized();
}

void MainWindow::on_btn_maximum_clicked() {
    // 最大化处理函数
}

void MainWindow::on_btn_mailBox_clicked() {
    if(!m_messageWidget) {
        m_messageWidget = new MessageWidget(this);
        m_messageWidget->setMouseTracking(true);
        auto mousePos = ui->btn_mailBox->pos();
        m_messageWidget->setGeometry(mousePos.x() - 233, mousePos.y() + 60, m_messageWidget->width(), m_messageWidget->height());
    }

    if(m_messageWidget->isHidden()) m_messageWidget->show();
    else m_messageWidget->hide();
}

/*
 * 初始化排行榜页面
 */
void MainWindow::initRank() {
    /* 页面滚动条 */
    ui->scrollArea_rank->setStyleSheet("QScrollArea {background-color:transparent; border: none;}");
    ui->scrollArea_rank->viewport()->setStyleSheet("background-color:transparent;");
    auto scrollBar = ui->scrollArea_rank->verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar::vertical{ background: transparent; width: 10px; }"
                             "QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 10px; border-radius: 5px; }"
                             "QScrollBar::up-arrow:vertical{ border: none; }"
                             "QScrollBar::sub-line:vertical{ background: transparent; }"
                             "QScrollBar::add-line:vertical{ background: transparent; }");
    /* 官方榜 */
    auto label_1 = new QLabel("官方榜");
    label_1->setStyleSheet("QLabel { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 28px; font-weight: bold; margin-left: 6px; margin-top: 15px;}");

    /* 飙升榜 */
    auto surgeRankWidget = new RankListWidget;
    surgeRankWidget->setRankList({{1, "270%", "坏女孩", "徐良/小凌"},
                            {2, "187%", "嘴脸", "Bo Peep"},
                            {3, "179%", "吞吐", "八仙饭店"},
                            {4, "173%", "我想念", "汪苏泷"},
                            {5, "141%", "Angel's Song", "苏照钦"}});
    surgeRankWidget->setCover(":/rank/Resources/rank/surge.png");

    /* 新歌榜 */
    auto newRankWidget = new RankListWidget;
    newRankWidget->setRankList({{1, "-", "河流", "川川"},
                                  {2, "157%", "KunupBiraymu（要我习惯吗）", "Nureli Turgun"},
                                  {3, "174%", "乘着风", "李宇春"},
                                  {4, "156%", "插叙人生（Montage）", "Y.Z.H/李晨曦Chrisulous"},
                                  {5, "165%", "有些(lofi Type Beat)", "Zy"}});
    newRankWidget->setCover(":/rank/Resources/rank/new.png");

    /* 原创榜 */
    auto originalRankWidget = new RankListWidget;
    originalRankWidget->setRankList({{1, "178%", "麻烦删掉狮子座", "裘德"},
                                {2, "159%", "危险关系", "XMASwu(吴鹭）"},
                                {3, "123%", "忽视距离（我想要看到你的微笑", "黑松"},
                                {4, "168%", "本能", "RAiNBOW计划/林力尧"},
                                {5, "114%", "when I", "Lu1"}});
    originalRankWidget->setCover(":/rank/Resources/rank/original.png");

    /* 热歌榜 */
    auto hotRankWidget = new RankListWidget;
    hotRankWidget->setRankList({{1, "128%", "悬溺", "葛东琪"},
                                {2, "195%", "凄美地", "郭顶"},
                                {3, "156%", "予你", "队长"},
                                {4, "125%", "向云端", "小霞/海洋Bo"},
                                {5, "145%", "精卫", "30年前，50年后"}});
    hotRankWidget->setCover(":/rank/Resources/rank/hot.png");

    /* 全球榜 */
    auto label_2 = new QLabel("全球榜");
    label_2->setStyleSheet("QLabel { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 28px; font-weight: bold; margin-top: 15px;}");

    /* 全球榜item*/
    auto galleryWidget = new GalleryWidget;
    galleryWidget->setGalleryItem({{":/rank/Resources/rank/1.png", "云音乐说唱榜", 143},
                                   {":/rank/Resources/rank/2.png", "云音乐古典榜", 143},
                                   {":/rank/Resources/rank/3.png", "云音乐电音", 143},
                                   {":/rank/Resources/rank/4.png", "黑胶VIP爱听榜", 143},
                                   {":/rank/Resources/rank/5.png", "云音乐ACG榜", 143},
                                   {":/rank/Resources/rank/6.png", "云音乐韩语榜", 143},
                                   {":/rank/Resources/rank/7.png", "云音乐国电榜", 143},
                                   {":/rank/Resources/rank/8.png", "UK排行榜周榜", 143},
                                   {":/rank/Resources/rank/9.png", "美国Billboard榜", 143},
                                   {":/rank/Resources/rank/10.png", "Beatport全球电子舞曲榜", 143},
                                   {":/rank/Resources/rank/11.png", "KTV唛榜", 143},
                                   {":/rank/Resources/rank/12.png", "日本Oricon榜", 143},
                                   {":/rank/Resources/rank/13.png", "云音乐欧美热歌榜", 143},
                                   {":/rank/Resources/rank/14.png", "云音乐欧美新歌榜", 143},
                                   {":/rank/Resources/rank/15.png", "法国 NRJ Vos Hits 周榜", 143},
                                   {":/rank/Resources/rank/16.png", "云音乐ACG动画榜", 143},
                                   {":/rank/Resources/rank/17.png", "云音乐ACG游戏榜", 143},
                                   {":/rank/Resources/rank/18.png", "云音乐ACG VOCALOID榜", 143},
                                   {":/rank/Resources/rank/19.png", "云音乐日语榜", 143},
                                   {":/rank/Resources/rank/20.png", "云音乐摇滚榜", 143}});

    auto vLayout = new QVBoxLayout;
    vLayout->setSpacing(45);

    vLayout->addWidget(label_1);
    vLayout->insertSpacing(1, -20);
    vLayout->addWidget(surgeRankWidget);
    vLayout->addWidget(newRankWidget);
    vLayout->addWidget(originalRankWidget);
    vLayout->addWidget(hotRankWidget);
    vLayout->addWidget(label_2);
    vLayout->insertSpacing(7, -25);
    vLayout->addWidget(galleryWidget);

    auto widget = new QWidget;
    widget->setLayout(vLayout);

    ui->scrollArea_rank->setWidget(widget);
}



