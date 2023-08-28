//
// Created by TURIING on 2023/8/16.
//

#ifndef WYY_POPUPSEARCHITEM_H
#define WYY_POPUPSEARCHITEM_H

#include <QWidget>
#include "utility/utility.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PopupSearchItem; }
QT_END_NAMESPACE

class PopupSearchItem : public QWidget {
Q_OBJECT
private:
    Ui::PopupSearchItem *ui;
public:
    explicit PopupSearchItem(QWidget *parent = nullptr);

    ~PopupSearchItem() override;

    void setIdColorHighlight(bool _bo = false);
    void setId(int _id);
    void setSong(const QString &_text);
    void setHot(int _num);
    void setDescription(const QString &_text);


};


#endif //WYY_POPUPSEARCHITEM_H
