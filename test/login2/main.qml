import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 1.2

import harbour.sailfish_sinaweibo.sunrain 1.0

ApplicationWindow {
    width: 600
    height: 300
    visible: true
    WrapperFriendshipsGroups {
        id: wrapperFriendshipsGroups
        onRequestAbort: {
            etLabel.text = "=== wrapperFriendshipsGroups onRequestAbort";
        }
        onRequestFailure: { //replyData
            retLabel.text = "=== wrapperFriendshipsGroups onRequestFailure " +replyData
        }
        onRequestSuccess: {
            retLabel.text = replyData;
        }
    }

    CookieDataProvider {
        id: loginProvider
        onPreLoginSuccess: {
            console.log("===== onPreLoginSuccess");
            image.source = loginProvider.captchaImgUrl;
        }
        onPreLoginFailure: { //str
            retLabel.text = "Try hack login failure on prelogin, error code is [" + str +"].";
        }
        onLoginSuccess: {
            retLabel.text = "Hack login success";
        }
        onLoginFailure: { //str
            retLabel.text = "Try hack login failure [" + str +"]";
        }
    }

    Component.onCompleted: {
        loginProvider.preLogin();
    }

    Flickable {
        id: loginFlickable
        width: parent.width *0.3
        anchors {
            top: parent.top
            left: parent.left
            bottom: btnFlickable.top
        }
        contentHeight: column.height

        Column {
            id: column
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
//            Label {
//                id: infoLabel
//                font.pixelSize: 22
//                font.italic: true
//                color: "steelblue"
//            }
            CheckBox {
                id: hackLoginCheck
                checked: tokenProvider.useHackLogin
                text: "use hacklogin"
                onCheckedChanged: {
                    console.log("=== onCheckedChanged " +hackLoginCheck.checked);
                    tokenProvider.useHackLogin = hackLoginCheck.checked;
                }
            }
        }
    }
    Flickable {
        id: flickable
        anchors {
            top: parent.top
            left: loginFlickable.right
            right: parent.right
            bottom: btnFlickable.top
        }
        contentHeight: retLabel.height
        Label {
            id: retLabel
            font.pixelSize: 16
//            font.italic: true
            color: "steelblue"
            width: parent.width
            wrapMode: Text.WrapAnywhere
        }
    }
    Flickable {
        id: btnFlickable
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        height: btnRow.height
        contentWidth: btnRow.width
        Row {
            id: btnRow
            Button {
                text: "groups"
                onClicked: {
                    wrapperFriendshipsGroups.getRequest();
                }
            }
        }
    }

}

