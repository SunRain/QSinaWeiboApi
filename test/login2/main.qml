import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2

ApplicationWindow {
    width: 400
    height: 300
    visible: true
    Connections {
        target: loginProvider
        onPreLoginSuccess: {
            console.log("===== onPreLoginSuccess");
            image.source = loginProvider.captchaImgUrl;
        }
    }

    Item {
        anchors.fill: parent
        Column {
            width: parent.width
            TextField {
                id: userName
                placeholderText: "userName"
            }
            TextField {
                id: password
                placeholderText: "password"
            }
            Image {
                id: image
            }
            TextField {
                id: input
            }
            Button {
                text: "login"
                onClicked: {
                    loginProvider.captcha = input.text;
                    loginProvider.userName = userName.text;
                    loginProvider.passWord = password.text;
                    loginProvider.login();
                }
            }
        }
        Component.onCompleted: {
            loginProvider.preLogin();
        }
    }

}

