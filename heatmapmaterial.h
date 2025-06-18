#pragma once

#include <QSGMaterial>
#include <QSGMaterialShader>

class HeatmapMaterial : public QSGMaterial
{
public:
    HeatmapMaterial();

    QSGMaterialType *type() const override;
    QSGMaterialShader *createShader(QSGRendererInterface::RenderMode) const override;

private:
    static QSGMaterialType s_type;
};

