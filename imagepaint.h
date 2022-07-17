#ifndef IMAGEPAINT_H
#define IMAGEPAINT_H

#include <QtQuick/QQuickPaintedItem>
#include <QColor>

//! 为了基于QPainter API实现自定义的绘制效果，
//! 如果不使用QPainter API，可以继承QQuickItem，
//! 甚至如果连可视化也不需要，QObject以及它的子类都可以作为继承的对象
class ImagePaint : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)
public:
    //! 可视化组件需要把父类设置为QQuickItem
    explicit ImagePaint(QQuickItem *parent = nullptr);

    //! 重载QQuickPaintedItem的paint函数，用于绘制图片
    void paint(QPainter *painter);

    QString source() const;
    void setSource(const QString &source);


    qreal radius() const;
    void setRadius(qreal newRadius);

signals:
    void sourceChanged();

    void radiusChanged();

private:
    QString m_source ;
    qreal m_radius = 2;//!默认自带2个像素的圆角
};

#endif // IMAGEPAINT_H
