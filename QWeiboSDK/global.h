#ifndef QWEIBOSDK_GLOBAL_H
#define QWEIBOSDK_GLOBAL_H

#include <qglobal.h>

#if defined(QWEIBOSDK_LIBRARY)
#  undef QWEIBOSDK_EXPORT
#  define QWEIBOSDK_EXPORT Q_DECL_EXPORT
#else
#  undef QWEIBOSDK_EXPORT
#  define QWEIBOSDK_EXPORT Q_DECL_IMPORT
#endif

static const char *API_HOST = "https://api.weibo.com";
static const char *TOKEN_CHECK_URL = "https://api.weibo.com";// kTokenCheckUrl
#endif // QWEIBOSDK_GLOBAL_H

