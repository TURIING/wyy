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

    initPopupSearch();

    initSinger();
}

MainWindow::~MainWindow() {
    delete ui;
    delete m_popupSearchWidget;
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

    /* 鼠标焦点不在时，则关闭PopupSearch */
    if(m_popupSearchWidget && !m_popupSearchWidget->isHidden()) {
        auto rect = m_popupSearchWidget->geometry();
        if(!rect.contains(_event->pos())) {
            m_popupSearchWidget->hide();
            ui->lineEdit_Search->clearFocus();
        }
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
 * 初始化个性推荐页面
 */
void MainWindow::initPersonalRecommand() {
    /* 推荐歌单 item */
    auto galleryWidget = new GalleryWidget(this);
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

    /* 推荐歌单 label */
    auto label_1 = new QLabel("推荐歌单 >");
    label_1->setCursor(Qt::PointingHandCursor);
    label_1->setFixedWidth(150);
    label_1->setStyleSheet("QLabel { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 28px; font-weight: bold; margin-bottom: 12px; margin-top: 15px; margin-left: 0px;}");

    /* 热门博客 label */
    auto label_2 = new QLabel("热门博客 >");
    label_2->setCursor(Qt::PointingHandCursor);
    label_2->setFixedWidth(150);
    label_2->setStyleSheet("QLabel { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 28px; font-weight: bold; margin-bottom: 8px; margin-top: 30px; }");

    /* 热门播客 item */
    auto podcastWidget = new PodcastWidget(this);
    podcastWidget->appendItem({{":/podcast/Resources/images/podcast/1.png", "爱的回归线(0.8x)", "歌曲翻唱", "慢速降调0.7x/0.8x", "979万", "05:20"},
                               {":/podcast/Resources/images/podcast/2.png", "你离开了我的夏大（音乐会live版）", "歌曲翻唱", "种地吧十个勤天", "40440", "04:53"},
                               {":/podcast/Resources/images/podcast/3.png", "等不到的等待-檀健次", "影视原声", "电视剧 长相思 配乐..", "76万", "04:19"},
                               {":/podcast/Resources/images/podcast/4.png", "钢琴曲独奏《漂洋过海来看你》纯音乐", "乐器演奏", "怀旧钢琴曲", "98539", "02:50"},
                               {":/podcast/Resources/images/podcast/5.png", "兰亭序 (降调)", "动漫", "不问ciaga", "155万", "05:38"},
                               {":/podcast/Resources/images/podcast/6.png", "EA7硬曲日 (抖音热歌）", "3D环绕", "『EA7硬曲』2023..", "47702", "02:22"}});


    auto layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->addWidget(new SlideShowWidget());
    layout->addWidget(label_1);
    layout->addWidget(galleryWidget);
    layout->addWidget(label_2);
    layout->insertSpacing(3, 20);
    layout->addWidget(podcastWidget);

    auto widget = new QWidget();
    widget->setLayout(layout);

    ui->scrollArea_recommend->setWidget(widget);
    ui->scrollArea_recommend->setAlignment(Qt::AlignCenter);
    ui->scrollArea_recommend->setWidgetResizable(false);

    /* 设置滚动条样式 */
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

        /* 阴影 */
        auto shadowEffect = new QGraphicsDropShadowEffect(this);
        shadowEffect->setOffset(0, 1);
        shadowEffect->setColor(Qt::gray);
        shadowEffect->setBlurRadius(10);
        m_messageWidget->setGraphicsEffect(shadowEffect);

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

bool MainWindow::eventFilter(QObject *_watched, QEvent *_event) {
    if(_watched == ui->lineEdit_Search) {
        if(_event->type() == QEvent::MouseButtonPress) {
            auto event = static_cast<QMouseEvent *>(_event);
            if(event->button() == Qt::LeftButton) {
                m_popupSearchWidget->show();
                return true;
            }
        }
    }
    return QObject::eventFilter(_watched, _event);
}

/*
 * 初始化搜索弹出框
 */
void MainWindow::initPopupSearch() {
    if(!m_popupSearchWidget) m_popupSearchWidget = new PopupSearch(this);

    /* 阴影 */
    auto shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0, 1);
    shadowEffect->setColor(Qt::gray);
    shadowEffect->setBlurRadius(10);
    m_popupSearchWidget->setGraphicsEffect(shadowEffect);

    auto pos = ui->lineEdit_Search->pos();
    m_popupSearchWidget->append({{1, "百氚朝海", 27234, ""},
                                 {2, "悬溺", 23125, "这个名字读快了就是喜欢你"},
                                 {3, "理解万岁", 17917, "廖俊涛新歌发行"},
                                 {4, "林俊杰", 16468, "看看行走的CD机又发什么新歌啦"},
                                 {5, "薛之谦", 11859, "老薛一发歌就能掀起狂潮！"},
                                 {6, "武家坡", 10750, ""},
                                 {7, "精卫", 9843, ""},
                                 {8, "坏女孩", 9529, "至我们终将逝去的青春"},
                                 {9, "声音玩具", 9365, "没有人能够比我们更接近对方"},
                                 {10, "张杰", 9089, "与张杰一起，从现在到未来，一直温暖无限！"},
                                 {11, "郑润泽", 5528, ""},
                                 {12, "汪苏泷", 5126, "才华横溢的唱作歌手！"},
                                 {13, "凄美地", 4600, "Tia翻唱郭顶，超有律动～"},
                                 {14, "徐良", 4430, "95后最爱听的原创音乐人之一！"},
                                 {15, "五月天", 4225, "深情最是阿信词怪兽曲"},
                                 {16, "凤凰传奇", 4134, "曾毅的和声起来真是掉一地鸡皮疙瘩。"},
                                 {17, "向云端", 4031, ""},
                                 {18, "陈奕迅", 3908, "年少不听陈奕迅，听懂已不再年少"},
                                 {19, "天若有情", 3853, "当年的电影《天若有情》，现在听着歌都会泪目啊~"}});
    m_popupSearchWidget->setGeometry(pos.x() - 100, pos.y() + 80, ui->lineEdit_Search->width(), ui->lineEdit_Search->height());

    m_popupSearchWidget->hide();
}

/*
 * 初始化歌手页面
 */
void MainWindow::initSinger() {
    ui->scrollArea_singer->setStyleSheet("QScrollArea {background-color:transparent; border: none;}");
    ui->scrollArea_singer->viewport()->setStyleSheet("background-color:transparent;");

    auto languageBox = new CategorySelectBox();
    languageBox->setColumnCount(6);
    languageBox->setCategory("语种：");
    languageBox->appendItem("全部");
    languageBox->appendItem("华语");
    languageBox->appendItem("欧美");
    languageBox->appendItem("日本");
    languageBox->appendItem("韩国");
    languageBox->appendItem("其他");
    languageBox->setDefaultItem(0);
    connect(languageBox, &CategorySelectBox::itemChoosed, [](int _id) {
        qDebug() << "language: " << _id;
    });

    auto categoryBox = new CategorySelectBox();
    categoryBox->setColumnCount(4);
    categoryBox->setCategory("分类：");
    categoryBox->appendItem("全部");
    categoryBox->appendItem("男歌手");
    categoryBox->appendItem("女歌手");
    categoryBox->appendItem("乐队组合");
    categoryBox->setDefaultItem(0);
    connect(categoryBox, &CategorySelectBox::itemChoosed, [](int _id) {
        qDebug() << "category: " << _id;
    });

    auto selectBox = new CategorySelectBox();
    selectBox->setColumnCount(15);
    selectBox->setCategory("筛选：");
    selectBox->appendItem("热门");
    selectBox->appendItem("A");
    selectBox->appendItem("B");
    selectBox->appendItem("C");
    selectBox->appendItem("D");
    selectBox->appendItem("E");
    selectBox->appendItem("F");
    selectBox->appendItem("G");
    selectBox->appendItem("H");
    selectBox->appendItem("I");
    selectBox->appendItem("J");
    selectBox->appendItem("K");
    selectBox->appendItem("L");
    selectBox->appendItem("M");
    selectBox->appendItem("N");
    selectBox->appendItem("O");
    selectBox->appendItem("P");
    selectBox->appendItem("Q");
    selectBox->appendItem("R");
    selectBox->appendItem("S");
    selectBox->appendItem("T");
    selectBox->appendItem("U");
    selectBox->appendItem("V");
    selectBox->appendItem("W");
    selectBox->appendItem("X");
    selectBox->appendItem("Y");
    selectBox->appendItem("Z");
    selectBox->appendItem("#");
    selectBox->setDefaultItem(0);
    connect(selectBox, &CategorySelectBox::itemChoosed, [](int _id) {
        qDebug() << "select: " << _id;
    });

    auto vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    vLayout->setContentsMargins(25, 35, 0, 0);
    vLayout->setSpacing(15);
    vLayout->addWidget(languageBox);
    vLayout->addWidget(categoryBox);
    vLayout->addWidget(selectBox);

    auto widget = new QWidget(this);
    widget->setLayout(vLayout);

    ui->scrollArea_singer->setWidget(widget);
}



