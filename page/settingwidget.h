//
// Created by TURIING on 2023/9/3.
//

#ifndef WYY_SETTINGWIDGET_H
#define WYY_SETTINGWIDGET_H

#include <QWidget>
#include <QListView>
#include <QScrollBar>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingWidget; }
QT_END_NAMESPACE

class SettingWidget : public QWidget {
Q_OBJECT

public:
    explicit SettingWidget(QWidget *parent = nullptr);

    ~SettingWidget() override;

private:
    Ui::SettingWidget *ui;
};


#endif //WYY_SETTINGWIDGET_H
