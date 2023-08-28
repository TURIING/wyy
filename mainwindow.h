//
// Created by TURIING on 2023/8/16.
//

#ifndef WYY_MAINWINDOW_H
#define WYY_MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "popupsearch.h"
#include "slideshowwidget.h"
#include "gallerywidget.h"
#include "messagewidget.h"
#include "utility/utility.h"
#include "ranklistwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void setAvator(const QString &_imgPath);

protected:
    void mousePressEvent(QMouseEvent *_event);
    void mouseMoveEvent(QMouseEvent *_event);
private:
    Ui::MainWindow *ui;
    QPoint m_mouseGlobalPos;
    MessageWidget *m_messageWidget = nullptr;


    void initListWidgetLeftMenu();
    void initListWidgetMyMusic();
    void initPersonalRecommand();
    void initRank();
private slots:
    void on_btn_close_clicked();
    void on_btn_maximum_clicked();
    void on_btn_minimum_clicked();
    void on_btn_mailBox_clicked();
};


#endif //WYY_MAINWINDOW_H