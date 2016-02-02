import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2

import harbour.sailfish_sinaweibo.sunrain 1.0

ApplicationWindow {
    width: 400
    height: 300
    visible: true
//    Connections {
//        target: loginProvider
//        onPreLoginSuccess: {
//            console.log("===== onPreLoginSuccess");
//            image.source = loginProvider.captchaImgUrl;
//        }
//    }
    HackFriendshipsGroups {
        id: friendshipsGroups
        onRequestAbort: {
            console.log("=== friendshipsGroups onRequestAbort")
        }
        onRequestFailure: { //replyData
            console.log("=== friendshipsGroups onRequestFailure " +replyData);
        }
        onRequestSuccess: {
            console.log("=== friendshipsGroups onRequestSuccess " +replyData);
            infoLabel.text= replyData;
        }
    }

    CookieDataProvider {
        id: loginProvider
        onPreLoginSuccess: {
            console.log("===== onPreLoginSuccess");
            image.source = loginProvider.captchaImgUrl;
        }
        onPreLoginFailure: { //str
            console.log("Try hack login failure on prelogin, error code is [" + str +"].");
        }
        onLoginSuccess: {
            console.log("Hack login success, start try now");
            friendshipsGroups.getRequest();
        }
        onLoginFailure: { //str
            console.log("Try hack login failure [" + str +"], start manual login now");
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
            Label {
                id: infoLabel
                font.pixelSize: 22
                font.italic: true
                color: "steelblue"
            }
        }
        Component.onCompleted: {
            loginProvider.preLogin();
        }
    }

}

