//
// Created by TURIING on 2023/9/5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FavoriteMusic.h" resolved

#include "favoritemusic.h"
#include "ui_FavoriteMusic.h"


FavoriteMusic::FavoriteMusic(QWidget *parent) :QWidget(parent), ui(new Ui::FavoriteMusic) {
    ui->setupUi(this);

    initModel();
    initView();


}

FavoriteMusic::~FavoriteMusic() {
    delete ui;
}

void FavoriteMusic::initView() {
    ui->tableView->setModel(m_model);
    ui->tableView->setItemDelegate(new FavoriteMusicDelegate(this));
    ui->tableView->setMouseTracking(true);
    ui->tableView->setSelectionBehavior(QTableView::SelectRows);
    ui->tableView->setSelectionMode(QTableView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setShowGrid(false);
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setDefaultSectionSize(52);
    ui->tableView->setStyleSheet("QTableView::item { background: white; }"
                                 "QTableView::item:!alternate:!selected { background: rgb(250, 250, 250); }"
                                 "QTableView::item:selected { background: rgb(229, 229, 229);}"
                                 "QHeaderView::section { border: none; background: white; }"
                                 "QTableCornerButton::section { border: none; background: white; }"

    );
}

void FavoriteMusic::initModel() {
    if(!m_model) m_model = new QStandardItemModel(this);

    m_model->setHorizontalHeaderLabels( {" ", "操作", "标题", "歌手", "专辑", "时间"});

    for(auto row = 0; row < 6; row++) {
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
                    item->setData("星河万里", Qt::DisplayRole);
                    break;
                }
                case 3: {
                    item->setData("Rom邢锐", Qt::DisplayRole);
                    break;
                }
                case 4: {
                    item->setData("星河万里", Qt::DisplayRole);
                    break;
                }
                case 5: {
                    item->setData("03:32", Qt::DisplayRole);
                    break;
                }
            }
            m_model->setItem(row, column, item);
        }
    }
}
