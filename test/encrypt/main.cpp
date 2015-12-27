
#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include <openssl/crypto.h>
#include <openssl/rsa.h>
#include <openssl/ossl_typ.h>
#include <openssl/bn.h>

const char *KEY_STR = "EB2A38568661887FA180BDDB5CABD5F21C7BFD59C090CB2D245A87AC253062882729293E5506350508E7F9AA3BB77F4333231490F915F6D63C55FE2F08A49B353F444AD3993CACC02DB784ABBB8E42A9B1BBFFFB38BE18D78E87A0E41B9B8F73A928EE0CCEE1F6739884B9777E4FE9E88A1BBE495927AC4A799B3181D6442443";

const char *tst_servertime = "1451312467";
const char *tst_nonce = "ZSTHCJ";
const char *tst_password = "123456789";
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

//    QByteArray plainData = QString("%1\\t%2\\n%3")
//            .arg (tst_servertime)
//            .arg (tst_nonce)
//            .arg (tst_password)
//            .toUtf8 ();
    QByteArray plainData;
    plainData.append (tst_servertime);
    plainData.append ("\t");
    plainData.append (tst_nonce);
    plainData.append ("\n");
    plainData.append (tst_password);

    qDebug()<<Q_FUNC_INFO<<"plainData "<<plainData;

    BIGNUM *bne = BN_new ();
//    BIGNUM *bnd = BN_new ();
    BIGNUM *bnn = BN_new ();

    unsigned long e = 65537;

    int  ret = BN_set_word(bne, e);
    qDebug()<<Q_FUNC_INFO<<"eret "<<ret;

    ret = BN_hex2bn (&bnn, KEY_STR);
    qDebug()<<Q_FUNC_INFO<<"nret "<<ret<<" bnn length "<<bnn->dmax;

    RSA *rsaObj = RSA_new();
    rsaObj->n = bnn;
    rsaObj->e = bne;
    rsaObj->d = nullptr;

    int flen = RSA_size (rsaObj);
    qDebug()<<Q_FUNC_INFO<<"RSA flen "<<flen;

    unsigned char *to = (unsigned char *)malloc (flen + 1);
    memset (to, 0, flen+1);
    int eret = RSA_public_encrypt (flen/*-11*/,
                                   (unsigned char *)plainData.constData (),
                                   to, rsaObj, RSA_NO_PADDING/*RSA_PKCS1_PADDING*/);

    qDebug()<<Q_FUNC_INFO<<"eret ["<<eret<<"], data ["<<to<<"]";

    QByteArray ba((const char*)to);
    qDebug()<<Q_FUNC_INFO<<"to => hex "<<ba.toHex ();
    qDebug()<<Q_FUNC_INFO<<"to => base64 "<<ba.toBase64 ();
    qDebug()<<Q_FUNC_INFO<<"to => base64 Base64Encoding "<<ba.toBase64 (QByteArray::Base64Encoding);
    qDebug()<<Q_FUNC_INFO<<"to => base64 Base64UrlEncoding "<<ba.toBase64 (QByteArray::Base64UrlEncoding);

    qDebug()<<Q_FUNC_INFO<<"toHex => base64 "<<ba.toHex ().toBase64 ();
    qDebug()<<Q_FUNC_INFO<<"toHex => base64 Base64Encoding "<<ba.toHex ().toBase64 (QByteArray::Base64Encoding);
    qDebug()<<Q_FUNC_INFO<<"toHex => base64 Base64UrlEncoding "<<ba.toHex ().toBase64 (QByteArray::Base64UrlEncoding);


    return app.exec();
}
