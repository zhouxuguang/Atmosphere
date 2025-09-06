#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLFunctions_4_1_Core>
#include <QOpenGLWidget>
#include <QOpenGLDebugLogger>
#include <QOpenGLDebugMessage>


class QEvent;
class QKeyEvent;
class QMouseEvent;
class QMoveEvent;
class QWheelEvent;
class DUpdateEvent;

class OpenGLWidgetPrivate;
class OpenGLWidget : public QOpenGLWidget,
        public QOpenGLFunctions_4_1_Core
{
    Q_OBJECT
public:
    OpenGLWidget(UpdateBehavior updateBehavior = NoPartialUpdate,
                 QWidget *parent = nullptr);
    ~OpenGLWidget();

    void printVersionInformation();

protected:

    // OpenGL Protected Methods
    virtual void initializeGL();
    virtual void resizeGL(int width, int height);
    virtual void paintGL();
    QString getFPS()const;

    // Event Methods
    virtual bool event(QEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
    virtual void moveEvent(QMoveEvent *event);
    virtual void updateEvent(DUpdateEvent *event);

public slots:
    void update();
    void frameTimeout(float fps);
    void handleLoggedMessage(const QOpenGLDebugMessage &message);

private:
    OpenGLWidgetPrivate *m_private;
    
    QOpenGLDebugLogger *m_debugLogger = nullptr;
};

#endif // OPENGLWIDGET_H
