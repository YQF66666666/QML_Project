#include "imagepaint.h"
#include <QPainter>
#include <QDebug>
#include <QRect>

ImagePaint::ImagePaint(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_source = QString();
    //! QQuickPaintedItem::Image QPainter使用光栅绘制引擎将绘画成 QImage。之后需要将图像的内容上传到图形内存，如果项目很大，则此操作可能会变慢。此呈现器目标允许高质量的抗锯齿和快速调整项目大小。
    //! QQuickPaintedItem::FramebufferObject QPainter 使用 openGL 引擎将图层绘制到 QOpenGLFramebufferObject 中。绘画速度可能更快，因为不需要纹理上传，但抗锯齿质量不如使用图像好。在某些情况下，此呈现器目标允许更快的呈现速度，但如果经常调整项的大小，则应避免使用它。
    //! QQuickPaintedItem::InvertedYFramebufferObject 与上面的 FramebufferObject 完全相同，除了绘画完成后，在渲染之前，绘制的图像将围绕 x 轴翻转，以便最上面的像素现在位于底部。由于这是使用 OpenGL 纹理坐标完成的，因此与使用QPainter变换相比，实现此效果的方法要快得多。
    setRenderTarget(QQuickPaintedItem::Image);
    //! 打开抗锯齿
    setAntialiasing(true);
}

QString ImagePaint::source() const
{
    return m_source;
}

void ImagePaint::setSource(const QString &source)
{
    m_source = source;
    emit sourceChanged();
}

void ImagePaint::paint(QPainter *painter)
{
    QPixmap pixmap(m_source);
    QRect rect(0,0,static_cast<int>(width()),static_cast<int>(height()));
    QPainterPath path;

    painter->setPen(QColor(208,208,208));
    painter->setBrush(Qt::white);
    painter->setRenderHint(QPainter::Antialiasing);
    path.addRoundedRect(rect, m_radius, m_radius);
    painter->setClipPath(path);

    painter->drawEllipse(rect);
    //SmoothTransformation平滑处理。
    pixmap = pixmap.scaled(QSize(width() , height()), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter->drawPixmap(QRect(0, 0, static_cast<int>(width()), static_cast<int>(height())), pixmap);

    painter->restore();
}


qreal ImagePaint::radius() const
{
    return m_radius;
}

void ImagePaint::setRadius(qreal newRadius)
{
    if (qFuzzyCompare(m_radius, newRadius))
        return;
    m_radius = newRadius;
    emit radiusChanged();
}
