#ifndef CUSTOMLINEGEOMETRY_H
#define CUSTOMLINEGEOMETRY_H

#include <QtCore/qglobal.h>
#include <QQuick3DGeometry>
#include <QVector3D>

class CustomLineGeometry : public QQuick3DGeometry
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit CustomLineGeometry(QQuick3DObject *parent = nullptr);

    Q_INVOKABLE void addLine(const QVector3D &start, const QVector3D &end);
    Q_INVOKABLE void newFrame();
    Q_INVOKABLE void clearLines();


signals:
    void linesUpdated();

private:
    void rebuildGeometry();

    struct Line
    {
        QVector3D start;
        QVector3D end;
    };

    QVector<Line> m_lines;

};

#endif // CUSTOMLINEGEOMETRY_H
