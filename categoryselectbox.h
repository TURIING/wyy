//
// Created by TURIING on 2023/8/30.
//

#ifndef WYY_CATEGORYSELECTBOX_H
#define WYY_CATEGORYSELECTBOX_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QButtonGroup>
#include <QFontMetrics>
#include "utility/utility.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class CategorySelectBox; }
QT_END_NAMESPACE

class CategorySelectBox : public QWidget {
Q_OBJECT

public:
    explicit CategorySelectBox(QWidget *parent = nullptr);

    CategorySelectBox(int _columnCount, QWidget *_parent = nullptr);

    ~CategorySelectBox() override;

    void setCategory(const QString &_text);

    void setColumnCount(int _count) { m_columnCount = _count; }

    void appendItem(const QString &_text);

    void setDefaultItem(int _id);
private:
    Ui::CategorySelectBox *ui;
    QButtonGroup *m_btnGroup;

    int m_columnCount = 0;
    int m_itemCount = -1;
    int m_currentRow = 0;
    int m_currentColumn = -1;
    int m_totalWidth = 0;

signals:
    void itemChoosed(int _id);
};


#endif //WYY_CATEGORYSELECTBOX_H
