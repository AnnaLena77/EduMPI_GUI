#include "heatmapmaterial.h"
#include <QMatrix4x4>

class HeatmapShader : public QSGMaterialShader
{
public:
    HeatmapShader() {
        setShaderFileName(VertexStage, QLatin1String(":/shaders/heatmap.vert.qsb"));
        setShaderFileName(FragmentStage, QLatin1String(":/shaders/heatmap.frag.qsb"));
    }

    bool updateUniformData(RenderState &state, QSGMaterial *, QSGMaterial *) override {
        QByteArray *buf = state.uniformData();
        if (state.isMatrixDirty()) {
            const QMatrix4x4 m = state.combinedMatrix();
            memcpy(buf->data(), m.constData(), sizeof(float)*16);
            return true;
        }
        return false;
    }
};

QSGMaterialType HeatmapMaterial::s_type;

HeatmapMaterial::HeatmapMaterial()
{
    setFlag(Blending, true);  // wenn du Transparenz brauchst
}

QSGMaterialType *HeatmapMaterial::type() const
{
    return &s_type;
}

QSGMaterialShader *HeatmapMaterial::createShader(QSGRendererInterface::RenderMode) const
{
    return new HeatmapShader();
}
