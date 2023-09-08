//
// Created by TURIING on 2023/9/5.
//

#ifndef WYY_FAVORITEMUSICDELEGATE_H
#define WYY_FAVORITEMUSICDELEGATE_H

#include <QStyledItemDelegate>
#include <QPushButton>
#include <QPainter>
#include <QPushButton>
#include <QStyleOptionButton>
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>

class FavoriteMusicDelegate: public QStyledItemDelegate {
private:
    QPushButton *m_btnLike = nullptr;
    QPushButton *m_btnDownload = nullptr;
    int m_btnCount = 2;
    QSize m_btnSize = QSize(22, 22);
    int m_spacing = 10;
    int m_stateType = -1;
    QPoint m_mousePoint;
public:
    explicit FavoriteMusicDelegate(QObject *_parent = nullptr): QStyledItemDelegate(_parent) {
        m_btnLike = new QPushButton();
        m_btnLike->setStyleSheet("QPushButton { border-image: url(:/favorite/Resources/favorite/like.png);}"
                                 "QPushButton:hover { border-image: url(:/favorite/Resources/favorite/like_hover.png);}");


        m_btnDownload = new QPushButton();
        m_btnDownload->setStyleSheet("QPushButton { border-image: url(:/favorite/Resources/favorite/download.png);}"
                                     "QPushButton:hover { border-image: url(:/favorite/Resources/favorite/download_hover.png);}");
    }


    virtual QWidget *createEditor(QWidget *_parent, const QStyleOptionViewItem &_option, const QModelIndex &_index) const override {
        switch (_index.column()) {
            case 1: {
                auto editor = new QPushButton("click", _parent);
                //editor->setStyleSheet("border-image: url(:/favorite/Resources/favorite/like.png)");
                return editor;
            }
            default:
                break;
        }
        return QStyledItemDelegate::createEditor(_parent, _option, _index);
    }

    virtual void setEditorData(QWidget *_editor, const QModelIndex &_index) const override {

    }

    virtual void setModelData(QWidget *_editor, QAbstractItemModel *_model, const QModelIndex &_index) const override {

    }

    virtual void updateEditorGeometry(QWidget *_editor, const QStyleOptionViewItem &_option, const QModelIndex &_index) const override {
        _editor->setGeometry(_option.rect);
    }


    virtual void paint(QPainter *_painter, const QStyleOptionViewItem &_option, const QModelIndex &_index) const override {

        //QStyleOptionViewItem viewOption(_option);
        //initStyleOption(&viewOption, _index);
        //if (_option.state.testFlag(QStyle::State_HasFocus))
        //    viewOption.state = viewOption.state ^ QStyle::State_HasFocus;

        if(_index.column() == 1) {
            /* 绘制背景颜色 */
            QStyleOptionViewItem itemStyle = _option;
            itemStyle.displayAlignment = Qt::AlignCenter;
            static QPixmap bg(itemStyle.rect.size());
            // 设置选中行背景颜色
            if(_option.state & QStyle::State_Selected) {
                bg.fill(QColor(229, 229, 229));
                QApplication::style()->drawItemPixmap(_painter, itemStyle.rect, Qt::AlignCenter, bg);
            // 设置交替行背景颜色
            } else if((_option.state | QStyle::State_Selected) && ((_index.row()+1) % 2 != 0)) {
                bg.fill(QColor(250, 250, 250));
                QApplication::style()->drawItemPixmap(_painter, itemStyle.rect, Qt::AlignCenter, bg);
            // 设置非交替行背景颜色
            } else if((_option.state | QStyle::State_Selected) && ((_index.row()+1) % 2 == 0)) {
                bg.fill(Qt::white);
                QApplication::style()->drawItemPixmap(_painter, itemStyle.rect, Qt::AlignCenter, bg);
            }

            /* 绘制按钮 */
            int half = (_option.rect.width() - m_btnSize.width() * m_btnCount - m_spacing * (m_btnCount - 1)) / 2;
            int top = (_option.rect.height() - m_btnSize.height()) / 2;

            for(auto i = 0; i < m_btnCount; i++) {
                auto x = _option.rect.left() + half + m_btnSize.width() * i + m_spacing * i;
                auto y = _option.rect.top() + top;
                QStyleOptionButton button;
                button.rect = QRect(x, y, m_btnSize.width(), m_btnSize.height());

                button.state |= QStyle::State_Enabled;
                if(button.rect.contains(m_mousePoint)) {
                    if(m_stateType == 0)
                        button.state |= QStyle::State_MouseOver;
                    else if(m_stateType == 1)
                        button.state |= QStyle::State_Sunken;
                }

                QWidget *widget = (i == 0) ? m_btnLike : m_btnDownload;
                widget->style()->drawControl(QStyle::CE_PushButton, &button, _painter, widget);
            }
        }
        else
            QStyledItemDelegate::paint(_painter, _option, _index);
    }


    virtual bool editorEvent(QEvent *_event, QAbstractItemModel *_model, const QStyleOptionViewItem &_option, const QModelIndex &_index) override {
        if(_index.column() != 1) return false;

        auto event = static_cast<QMouseEvent *>(_event);
        m_mousePoint = event->pos();

        int half = (_option.rect.width() - m_btnSize.width() * m_btnCount - m_spacing * (m_btnCount - 1)) / 2;
        int top = (_option.rect.height() - m_btnSize.height()) / 2;

        bool bRepaint = false;
        QApplication::restoreOverrideCursor();

        for(auto i = 0; i < m_btnCount; i++) {
            auto x = _option.rect.left() + half + m_btnSize.width() * i + m_spacing * i;
            auto y = _option.rect.top() + top;
            QStyleOptionButton button;
            button.rect = QRect(x, y, m_btnSize.width(), m_btnSize.height());

            if(!button.rect.contains(m_mousePoint)) continue;

            bRepaint = true;

            switch (event->type()) {
                case QMouseEvent::MouseMove: {
                    QApplication::setOverrideCursor(Qt::PointingHandCursor);
                    m_stateType = 0;
                    break;
                }
                case QMouseEvent::MouseButtonPress: {
                    m_stateType = 1;
                    qDebug() << "like clicked";
                    break;
                }

            }
        }
        return bRepaint;
    }


};
#endif //WYY_FAVORITEMUSICDELEGATE_H
