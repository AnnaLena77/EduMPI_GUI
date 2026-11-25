#ifndef CUSTOMLINEGEOMETRY_H
#define CUSTOMLINEGEOMETRY_H

#include <QtCore/qglobal.h>
#include <QQuick3DGeometry>
#include <QVector3D>

class CustomLineGeometry : public QQuick3DGeometry
{
    Q_OBJECT
    QML_ELEMENT
    // Half the edge length of a rank cube: the arrows end at the surface of the cubes instead
    // of at their centers. 0: the old fixed gap of 2 units from the center.
    Q_PROPERTY(float cubeHalfSize READ cubeHalfSize WRITE setCubeHalfSize NOTIFY cubeHalfSizeChanged)
    // Thick arrows are shifted by this distance in world y (up for a positive value, down for
    // a negative one; in x for an almost vertical arrow). The send arrows get a positive and
    // the receive arrows a negative value, so that both can be seen one above the other from
    // the front. (A shift perpendicular to the arrow would point towards the camera for a
    // horizontal arrow and hide one set of arrows behind the other.)
    Q_PROPERTY(float lateralOffset READ lateralOffset WRITE setLateralOffset NOTIFY lateralOffsetChanged)
    // On top of that, the two directions of the same pair of points get separate lanes: an
    // arrow is shifted by +directionOffset if it goes from the "smaller" to the "larger" point
    // (compared by x, then y, then z) and by -directionOffset if it goes the other way. Without
    // that, two arrows of the same type that go in opposite directions lie on top of each other
    // and each one's shaft runs on through the other one's head.
    Q_PROPERTY(float directionOffset READ directionOffset WRITE setDirectionOffset NOTIFY directionOffsetChanged)

public:
    explicit CustomLineGeometry(QQuick3DObject *parent = nullptr);

    Q_INVOKABLE void addLine(const QVector3D &start, const QVector3D &end);
    // Thick arrow: "width" is the thickness in scene units. Such arrows are drawn as small
    // 3D prisms with a pyramid head, because a GPU line primitive has a fixed width.
    Q_INVOKABLE void addLine(const QVector3D &start, const QVector3D &end, float width);
    Q_INVOKABLE void newFrame();
    Q_INVOKABLE void clearLines();


    float cubeHalfSize() const { return m_cubeHalfSize; }
    void setCubeHalfSize(float v);
    float lateralOffset() const { return m_lateralOffset; }
    void setLateralOffset(float v);
    float directionOffset() const { return m_directionOffset; }
    void setDirectionOffset(float v);

signals:
    void linesUpdated();
    void cubeHalfSizeChanged();
    void lateralOffsetChanged();
    void directionOffsetChanged();

private:
    void rebuildGeometry();
    void rebuildThickGeometry();

    struct Line
    {
        QVector3D start;
        QVector3D end;
        float width = 0.0f; // 0: thin line primitive, > 0: thick arrow
    };

    // distance from a cube center to where the arrow starts or ends, for a given direction
    float gapFor(const QVector3D &direction) const;

    QVector<Line> m_lines;
    float m_cubeHalfSize = 0.0f;
    float m_lateralOffset = 0.0f;
    float m_directionOffset = 0.0f;

};

#endif // CUSTOMLINEGEOMETRY_H
