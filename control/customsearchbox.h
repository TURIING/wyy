//
// Created by TURIING on 2023/9/15.
//

#ifndef WYY_CUSTOMSEARCHBOX_H
#define WYY_CUSTOMSEARCHBOX_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CustomSearchBox; }
QT_END_NAMESPACE

class CustomSearchBox : public QWidget {
Q_OBJECT

public:
    explicit CustomSearchBox(QWidget *parent = nullptr);

    ~CustomSearchBox() override;

private:
    Ui::CustomSearchBox *ui;

signals:
    void textChanged(const QString &text);
};


#endif //WYY_CUSTOMSEARCHBOX_H
