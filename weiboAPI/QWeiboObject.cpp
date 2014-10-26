
#include "include/QWeiboObject.h"

namespace QSinaWeiboAPI {

///////////////////////////////
QWeiboStatusObject *QWeiboStatusObject::create(const QString &created_at,
                                               int id, 
                                               const QString &text, 
                                               const QString &source,
                                               const QString &thumbnail_pic, 
                                               const QString &bmiddle_pic,
                                               const QString &original_pic,
                                               int reposts_count, 
                                               int comments_count, 
                                               int attitudes_count, 
                                               int mid, 
                                               QWeiboUserObject *user,
                                               QWeiboStatusObject *retweeted_status,
                                               QObject *parent)
{
    QWeiboStatusObject *obj = new QWeiboStatusObject(parent);
    obj->m_created_at = created_at;
    obj->m_id = id;
    obj->m_text = text;
    obj->m_source = source;
    obj->m_thumbnail_pic = thumbnail_pic;
    obj->m_bmiddle_pic = bmiddle_pic;
    obj->m_original_pic = original_pic;
    obj->m_reposts_count = reposts_count;
    obj->m_comments_count = comments_count;
    obj->m_attitudes_count = attitudes_count;
    obj->m_mid = mid;
    obj->m_user = user;
    obj->m_retweeted_status = retweeted_status;
    return obj;
}

QObject *QWeiboStatusObject::user() const
{
    QObject *o = m_user;
    return o;
}

QObject *QWeiboStatusObject::retweeted_status() const
{
    QObject *o = m_retweeted_status;
    return o;
}


////////////////////

QWeiboUserObject *QWeiboUserObject::create(const QString &id,
                                           const QString &screen_name, 
                                           const QString &name, 
                                           const QString &location,
                                           const QString &description,
                                           const QString &url,
                                           const QString &profile_image_url, 
                                           const QString &domain, 
                                           const QString &gender, 
                                           int followers_count,
                                           int friends_count, 
                                           int statuses_count, 
                                           int favourites_count, 
                                           const QString &created_at, 
                                           bool following, 
                                           bool verified, 
                                           bool follow_me,
                                           const QString &avatar_large, 
                                           int bi_followers_count,
                                           QWeiboStatusObject *status,
                                           QObject *parent)
{
    QWeiboUserObject *obj = new QWeiboUserObject(parent);
    obj->m_id = id;
    obj->m_screen_name = screen_name;
    obj->m_name = name;
    obj->m_location = location;
    obj->m_description = description;
    obj->m_url = url;
    obj->m_profile_image_url = profile_image_url;
    obj->m_domain = domain;
    obj->m_gender = gender;
    obj->m_followers_count = followers_count;
    obj->m_friends_count = friends_count;
    obj->m_statuses_count = statuses_count;
    obj->m_favourites_count = favourites_count;
    obj->m_created_at = created_at;
    obj->m_following = following;
    obj->m_verified = verified;
    obj->m_follow_me = follow_me;
    obj->m_avatar_large = avatar_large;
    obj->m_bi_followers_count = bi_followers_count;
    obj->m_status = status;
    return obj;
}

QObject *QWeiboUserObject::status() const
{
    QObject *o = m_status;
    return o;
}

}
