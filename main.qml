import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.0
import MControls 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    Image {
//        id: _image
//        width: 300
//        height: 300
//        anchors.centerIn: parent
//        smooth: true
//        source: "file:///Users/yangqifan1/worker/123.jpg"
//        sourceSize: Qt.size(300,300)
//        antialiasing: true
//    }


//    property int imageRasdius: 10
//    property int imageWidth: 300
//    property int imageHeight: 300

//    Rectangle{
//        id : rect
//        width: 300
//        height: 300
//        anchors.centerIn: parent

//        Image {
//            id: image
//            width: 300
//            height: 300
//            anchors.centerIn: parent
//            smooth: true
//            visible: false
//            anchors.fill: parent
//            source: "file:///Users/yangqifan1/worker/123.jpg"
//            sourceSize: Qt.size(imageWidth,imageHeight)
//            antialiasing: true
//        }
//        Rectangle {
//            id: imageRect
//            color: "#FFFFFF"
//            anchors.fill: parent
//            radius: imageRasdius
//            visible: false
//            antialiasing: true
//            smooth: true
//        }
//        OpacityMask {
//            id: imageOpcityMask
//            anchors.fill: image
//            source: image
//            maskSource: imageRect
//            visible: true
//            antialiasing: true
//        }
//    }

    ImagePaint{
        id:_img
        width: 300
        height: 300
        anchors.centerIn: parent
        source: "/Users/yangqifan1/worker/123.jpg"
        radius: 10
    }

}
