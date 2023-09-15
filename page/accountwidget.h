//
// Created by TURIING on 2023/9/2.
//

#ifndef WYY_ACCOUNTWIDGET_H
#define WYY_ACCOUNTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QSpacerItem>

QT_BEGIN_NAMESPACE
namespace Ui { class AccountWidget; }
QT_END_NAMESPACE

class AccountWidget : public QWidget {
Q_OBJECT

public:
    explicit AccountWidget(QWidget *parent = nullptr);

    ~AccountWidget() override;

private:
    Ui::AccountWidget *ui;

    void initList();

    void append(const QString &_icon, const QString &_text, const QString &_rightIcon);
};


#endif //WYY_ACCOUNTWIDGET_H
