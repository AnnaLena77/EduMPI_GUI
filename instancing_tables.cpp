#include "instancing_tables.h"

#include <math.h>
#include <QMatrix4x4>
#include <QRandomGenerator>
#include <QColor>

Instancing_Tables::Instancing_Tables(QQuick3DObject *parent) : QQuick3DInstancing(parent)
{

}

Instancing_Tables::~Instancing_Tables(){

}


QByteArray Instancing_Tables::getInstanceBuffer(int *instanceCount)
{

}
