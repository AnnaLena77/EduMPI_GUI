import QtQuick 2.1
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0

/*DirectionalLight{
    color: "white"
    eulerRotation.x: -90
    brightness: 1
    castsShadow: false
}
DirectionalLight{
    color: "white"
    eulerRotation.x: 90
    brightness: 1
    castsShadow: false
}
DirectionalLight{
    color: "white"
    eulerRotation.z: 90
    brightness: 1
    castsShadow: false
}
DirectionalLight{
    color: "white"
    eulerRotation.z: -90
    brightness: 1
    castsShadow: false
}
DirectionalLight{
    color: "white"
    eulerRotation.y: -90
    brightness: 1
    castsShadow: false
}
DirectionalLight{
    color: "white"
    eulerRotation.y: 90
    brightness: 1
    castsShadow: false
}*/

Entity {
    id: lights

//2 x Directional Lights (steady)
    Entity {
    components: [
        DirectionalLight {
            //worldDirection: Qt.vector3d(5, -3.0, 0.0).normalized();
            color: "white"
            intensity: 1
        }
    ]
}

    Entity {
        components: [
            DirectionalLight {
                worldDirection: Qt.vector3d(-0.3, -0.3, 0.0).normalized();
                color: "#9cdaef"
                intensity: 0.15
            }
        ]
    }
}
