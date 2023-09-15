//
// Created by TURIING on 2023/9/5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FavoriteMusic.h" resolved

#include "favoritemusic.h"
#include "ui_FavoriteMusic.h"


FavoriteMusic::FavoriteMusic(QWidget *parent) :QWidget(parent), ui(new Ui::FavoriteMusic) {
    ui->setupUi(this);
    /* 使滚动区域背景透明 */
    ui->scrollArea->setStyleSheet("QScrollArea {background-color:white; border: none;}");
    ui->scrollArea->viewport()->setStyleSheet("background-color: transparent;");
    /* 设置滚动条样式 */
    auto scrollBar = ui->scrollArea->verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar::vertical{ background: transparent; width: 12px; }"
                             "QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 12px; border-radius: 6px; }"
                             "QScrollBar::up-arrow:vertical{ border: none; }"
                             "QScrollBar::sub-line:vertical{ background: transparent; }"
                             "QScrollBar::add-line:vertical{ background: transparent; }");

    this->setStyleSheet("QWidget#widget_top { background: white; }"
                        "QLabel#label_image { border-image: url(:/favorite/Resources/favorite/image.png); border-radius: 5px; }"
                        "QLabel#label_songList { border: 1px solid rgb(237, 65, 65); border-radius: 4px; color: rgb(237, 65, 65); font-family: '微软雅黑'; font-size: 20px;}"
                        "QLabel#label_title { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 34px; font-weight: bold; }"
                        "QLabel#label_avator { border-image: url(:/images/Resources/images/turiing.png); border-radius: 18px; }"
                        "QLabel#label_user { color: rgb(90, 133, 180); font-family: '微软雅黑'; font-size: 18px; }"
                        "QLabel#label_createTime { color: rgb(102, 102, 102); font-family: '微软雅黑'; font-size: 17px; }"
                        "QWidget#widget_btn { border-radius: 23px; }"
                        "QLabel#label_song, #label_play { color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 20px;}"
                        "QLabel#label_songNum, #label_playNum { color: rgb(145, 145, 145); font-family: '微软雅黑'; font-size: 19px;}"

                        "QTabWidget { border: none; }"
                        "QTabWidget::pane {  background: white; }"
                        "QTabWidget::tab-bar:top { left: 40px; }"
                        "QTabWidget::right-corner { bottom: 10px; left: -120px; }"
                        "QTabBar::tab { height: 40px; width: 110px; font-family: '微软雅黑'; font-size: 21px; margin-bottom: 10px;  }"
                        "QTabBar::tab:!selected { color: rgb(102, 102, 102); }"
                        "QTabBar::tab:selected { font-size: 26px; font-weight: bold; color: rgb(51, 51, 51); border-bottom: none; border-bottom: 4px solid rgb(236, 65, 65); }"
    );

    /* 播放全部 按钮 */
    ui->btn_playAll->setIcon(QIcon(":/favorite/Resources/favorite/play.png"));
    ui->btn_playAll->setIconSize(QSize(28, 20));
    ui->btn_playAll->setStyleSheet("QPushButton { background: rgb(236, 65, 65); border-top-left-radius: 23px; border-bottom-left-radius: 23px; color: white; font-family: '微软雅黑'; font-size: 20px; }"
                                   "QPushButton:hover { background: rgb(205, 50, 50); }");
    /* 添加到播放列表 按钮 */
    ui->btn_addToList->setIcon(QIcon(":/favorite/Resources/favorite/add.png"));
    ui->btn_addToList->setIconSize(QSize(19, 19));
    ui->btn_addToList->setStyleSheet("QPushButton { background: rgb(236, 65, 65); border-top-right-radius: 23px; border-bottom-right-radius: 23px; }"
                                   "QPushButton:hover { background: rgb(205, 50, 50); }");
    /* 收藏 按钮 */
    ui->btn_collect->setIcon(QIcon(":/favorite/Resources/favorite/collect.png"));
    ui->btn_collect->setIconSize(QSize(34, 30));
    ui->btn_collect->setStyleSheet("QPushButton { border: 1px solid rgb(217, 217, 217); background: white; border-radius: 23px; color: rgb(178, 178, 178); font-family: '微软雅黑'; font-size: 20px;}");
    /* 分享 按钮 */
    ui->btn_share->setIcon(QIcon(":/favorite/Resources/favorite/share.png"));
    ui->btn_share->setIconSize(QSize(33, 31));
    ui->btn_share->setStyleSheet("QPushButton { border: 1px solid rgb(217, 217, 217); background: white; border-radius: 23px; color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 20px;}"
                                 "QPushButton:hover { background: rgb(242, 242, 242); }");
    /* 下载全部 按钮 */
    ui->btn_downloadAll->setIcon(QIcon(":/favorite/Resources/favorite/downloadAll.png"));
    ui->btn_downloadAll->setIconSize(QSize(34, 31));
    ui->btn_downloadAll->setStyleSheet("QPushButton { border: 1px solid rgb(217, 217, 217); background: white; border-radius: 23px; color: rgb(51, 51, 51); font-family: '微软雅黑'; font-size: 20px;}"
                                       "QPushButton:hover { background: rgb(242, 242, 242); }");


    m_searchBox = new CustomSearchBox(this);
    ui->tabWidget->setCornerWidget(m_searchBox);
    connect(m_searchBox, &CustomSearchBox::textChanged, [this](const QString &_text) {
        QRegExp regExp(_text);
        m_proxyModel->setFilterRegExp(regExp);
    });

    initModel();
    initView();


}

FavoriteMusic::~FavoriteMusic() {
    delete ui;
}

void FavoriteMusic::initView() {
    ui->tableView->setModel(m_proxyModel);
    ui->tableView->setItemDelegate(new FavoriteMusicDelegate(this));
    ui->tableView->setMouseTracking(true);
    ui->tableView->setSelectionBehavior(QTableView::SelectRows);
    ui->tableView->setSelectionMode(QTableView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setShowGrid(false);
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->resizeSection(0, 80);
    ui->tableView->horizontalHeader()->resizeSection(1, 100);
    ui->tableView->horizontalHeader()->resizeSection(3, 300);
    ui->tableView->horizontalHeader()->resizeSection(4, 300);
    ui->tableView->horizontalHeader()->resizeSection(5, 100);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setHighlightSections(false);
    ui->tableView->verticalHeader()->setDefaultSectionSize(52);
    ui->tableView->setStyleSheet("QTableView { border: none; }"
                                 "QTableView::item { background: white; color: rgb(92, 92, 92);}"
                                 "QTableView::item:!alternate:!selected { background: rgb(250, 250, 250); }"
                                 "QTableView::item:selected { background: rgb(229, 229, 229); }"
                                 "QHeaderView::section { border: none; background: white; color: rgb(136, 136, 136); font-family: '微软雅黑'; font-size: 19px;}"
                                 "QHeaderView::down-arrow { subcontrol-position: center right; image: url(:/favorite/Resources/favorite/desc_sort.png); padding: 30px; }"
                                 "QHeaderView::up-arrow { subcontrol-position: center right; image: url(:/favorite/Resources/favorite/asc_sort.png); padding: 30px; }"
                                 "QTableCornerButton::section { border: none; background: white; }"
    );

    /* 设置滚动条样式 */
    auto scrollBar = ui->tableView->verticalScrollBar();
    scrollBar->setStyleSheet("QScrollBar::vertical{ background: transparent; width: 12px; }"
                             "QScrollBar::handle:vertical{ min-height: 10px; max-height: 20px; background: rgb(224, 224, 224); width: 12px; border-radius: 6px; }"
                             "QScrollBar::up-arrow:vertical{ border: none; }"
                             "QScrollBar::sub-line:vertical{ background: transparent; }"
                             "QScrollBar::add-line:vertical{ background: transparent; }");

    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked, [this](int _index) {
        if(_index == 1) {
            ui->tableView->horizontalHeader()->setSortIndicatorShown(false);
            ui->tableView->setSortingEnabled(false);
            return;
        }

        ui->tableView->setSortingEnabled(true);
        ui->tableView->horizontalHeader()->setSortIndicatorShown(true);

    });
}

void FavoriteMusic::initModel() {
    if(!m_model) m_model = new QStandardItemModel(this);

    m_model->setHorizontalHeaderLabels( {" ", "操作", "标题", "歌手", "专辑", "时间"});

    appendItem({{"星河万里", "Rom邢锐", "星河万里", "03:32"},
                {"One Last Kiss", "宇多田", "One Last Kiss", "04:09"},
                {"水星", "鱼酱", "水星—COVERTOFUBEATS", "04:32"},
                {"致你", "yihuik苡慧", "致你", "04:31"},
                {"妄想感傷代盟", "DECO*27/初音未来", "GHOST", "04:30"},
                {"爱言葉Ⅱ", "DECO*27/初音未来", "DECO*27VOCALOIDCOLLE", "04:34"},
                {"LEVEL5-judgelight", "fripSide", "LEVEL5-judgelight", "04:25"},
                {"琥珀の身体", "HIMEHINA", "琥珀の身体", "04:30"},
                {"Only My Railgun", "fripSide", "Only My Railgun", "04:46"},
                {"孤勇者", "陈奕迅",  "孤勇者", "02:30"},

    });

    if(!m_proxyModel) m_proxyModel = new SortFilterProxyModel();
    m_proxyModel->setSourceModel(m_model);


}

void FavoriteMusic::appendItem(const FavoriteMusic::ItemContent &_content) {
    auto [song, singer, album, duration] = _content;
    auto row = m_model->rowCount();
    for(auto column = 0; column < 6; column++) {
        auto item = new QStandardItem();
        switch (column) {
            case 0: {
                item->setText(QString::number(row + 1));
                break;
            }
            case 1: {
                //item->setData(true, Qt::DisplayRole);
                break;
            };
            case 2: {
                item->setData(song, Qt::DisplayRole);
                break;
            }
            case 3: {
                item->setData(singer, Qt::DisplayRole);
                break;
            }
            case 4: {
                item->setData(album, Qt::DisplayRole);
                break;
            }
            case 5: {
                item->setData(duration, Qt::DisplayRole);
                break;
            }
        }
        m_model->setItem(row, column, item);
    }
}

void FavoriteMusic::appendItem(std::initializer_list<ItemContent> _list) {
    for(auto &item: _list) {
        appendItem(item);
    }
}

SortFilterProxyModel::SortFilterProxyModel(QSortFilterProxyModel *_parent): QSortFilterProxyModel(_parent) {

}

bool SortFilterProxyModel::lessThan(const QModelIndex &_source_left, const QModelIndex &_source_right) const {
    QVariant leftData = sourceModel()->data(_source_left);
    QVariant rightData = sourceModel()->data(_source_right);

    switch (_source_left.column()) {
        case 2:
        case 3:
        case 4:
        case 5: {
            return leftData.toString() < rightData.toString();
        }
        case 0: return leftData.toInt() < rightData.toInt();
    }
    return true;
}

bool SortFilterProxyModel::filterAcceptsRow(int _source_row, const QModelIndex &_source_parent) const {
    auto dataColumn2 = sourceModel()->index(_source_row, 2, _source_parent).data().toString();
    auto dataColumn3 = sourceModel()->index(_source_row, 3, _source_parent).data().toString();
    auto dataColumn4 = sourceModel()->index(_source_row, 4, _source_parent).data().toString();

    if(dataColumn2.contains(this->filterRegExp()))
        return true;
    else if(dataColumn3.contains(this->filterRegExp()))
        return true;
    else if(dataColumn4.contains(this->filterRegExp()))
        return true;
    else
        return false;
}
