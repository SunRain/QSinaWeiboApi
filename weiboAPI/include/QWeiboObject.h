#ifndef QWEIBOOBJECT_H
#define QWEIBOOBJECT_H

#include <QObject>
#include <QSharedPointer>

namespace QSinaWeiboAPI {
///
/// \brief The QWeiboStatusObject class
///
class QWeiboUserObject;
class QWeiboStatusObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString created_at READ created_at CONSTANT)
    Q_PROPERTY(QString text READ text CONSTANT)
    Q_PROPERTY(QString source READ source CONSTANT)
    Q_PROPERTY(QString thumbnail_pic READ thumbnail_pic CONSTANT)
    Q_PROPERTY(QString bmiddle_pic READ bmiddle_pic CONSTANT)
    Q_PROPERTY(QString original_pic READ original_pic CONSTANT)
    Q_PROPERTY(int reposts_count READ reposts_count CONSTANT)
    Q_PROPERTY(int comments_count READ comments_count CONSTANT)
    Q_PROPERTY(int attitudes_count READ attitudes_count CONSTANT) 
    Q_PROPERTY(int mid READ mid CONSTANT)
    Q_PROPERTY(QObject user READ user CONSTANT)
    Q_PROPERTY(QObject retweeted_status READ retweeted_status CONSTANT)
    
public:
    explicit QWeiboStatusObject(QObject *parent =0) :QObject(parent) {}
    
    ///
    /// \brief create 创建时间
    /// \param created_at 创建时间
    /// \param id  微博ID
    /// \param text 微博信息内容
    /// \param source  微博来源
    /// \param thumbnail_pic  缩略图，没有时不返回此字段
    /// \param bmiddle_pic 中型图片，没有时不返回此字段
    /// \param original_pic 原始图片，没有时不返回此字段
    /// \param reposts_count 转发数
    /// \param comments_count 评论数
    /// \param attitudes_count "赞"数
    /// \param mid 微博MID
    /// \param user  作者信息
    /// \param retweeted_status 转发的博文，内容为status，如果不是转发，则没有此字段
    /// \return 
    ///
    static QWeiboStatusObject *create(
            const QString &created_at, ///< 创建时间
            int id, ///< 微博ID
            const QString &text, ///<微博信息内容
            const QString &source, ///< 微博来源
            const QString &thumbnail_pic, ///< 缩略图，没有时不返回此字段
            const QString &bmiddle_pic, ///<中型图片，没有时不返回此字段
            const QString &original_pic, ///<原始图片，没有时不返回此字段
            int reposts_count, ///<转发数
            int comments_count, ///<评论数
            int attitudes_count, ///"赞"数
            int mid, ///<微博MID
            QWeiboUserObject *user = 0, ///< 作者信息
            QWeiboStatusObject *retweeted_status = 0, ///<转发的博文，内容为status，如果不是转发，则没有此字段
            QObject *parent = 0);
    
    QString created_at() const                  {return m_created_at;}
    QString text() const                        {return m_text;}
    QString source() const                      {return m_source;}
    QString thumbnail_pic() const               {return m_thumbnail_pic;}
    QString bmiddle_pic() const                 {return m_bmiddle_pic;}
    QString original_pic() const                {return m_original_pic;}
    int reposts_count() const                   {return m_reposts_count;}
    int comments_count() const                  {return m_comments_count;}
    int attitudes_count() const                 {return m_attitudes_count;}
    int mid() const                             {return m_mid;}
    QObject* user() const;                      
    QObject* retweeted_status() const;           

private:
    QString m_created_at; ///< 创建时间
    int m_id; ///< 微博ID
    QString m_text; ///<微博信息内容
    QString m_source; ///< 微博来源
//    bool favorited; ///< 是否已收藏
//    QString in_reply_to_status_id; ///< 回复ID //（暂未支持）
//    QString in_reply_to_user_id; ///< 回复人UID //（暂未支持）
//    QString in_reply_to_screen_name; ///< 回复人昵称 //（暂未支持）
    QString m_thumbnail_pic; ///< 缩略图，没有时不返回此字段
    QString m_bmiddle_pic; ///<中型图片，没有时不返回此字段
    QString m_original_pic; ///<原始图片，没有时不返回此字段
    int m_reposts_count; ///<转发数
    int m_comments_count; ///<评论数
    int m_attitudes_count; ///"赞"数
    int m_mid; ///<微博MID
//    QString annotations; ///<元数据，没有时不返回此字段

    ///TODO geo location
//    ParsingGeoPtr geo; ///<地理信息，保存经纬度，没有时不返回此字段
    QWeiboUserObject *m_user; ///< 作者信息
    QWeiboStatusObject *m_retweeted_status; ///<转发的博文，内容为status，如果不是转发，则没有此字段
};

////
/// \brief The QWeiboUserObject class
///
class QWeiboUserObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id CONSTANT)
    Q_PROPERTY(QString screen_name READ screen_name CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString location READ location CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString url READ url CONSTANT)
    Q_PROPERTY(QString profile_image_url READ profile_image_url CONSTANT)
    Q_PROPERTY(QString domain READ domain CONSTANT)
    Q_PROPERTY(QString gender READ gender CONSTANT)
    Q_PROPERTY(int followers_count READ followers_count CONSTANT)
    Q_PROPERTY(int friends_count READ friends_count CONSTANT)
    Q_PROPERTY(int statuses_count READ statuses_count CONSTANT)
    Q_PROPERTY(int favourites_count READ favourites_count CONSTANT)
    Q_PROPERTY(QString created_at READ created_at CONSTANT)
    Q_PROPERTY(bool following READ following CONSTANT)
    Q_PROPERTY(bool verified READ verified CONSTANT)
    Q_PROPERTY(bool follow_me READ follow_me CONSTANT)
    Q_PROPERTY(QString avatar_large READ avatar_large CONSTANT)
    Q_PROPERTY(int bi_followers_count READ bi_followers_count CONSTANT)
    Q_PROPERTY(QObject status READ status CONSTANT)
public:
    explicit  QWeiboUserObject(QObject *parent =0) :QObject(parent) {}
    
    ///
    /// \brief create
    /// \param id 用户UID
    /// \param screen_name  微博昵称
    /// \param name  友好显示名称，如Bill Gates,名称中间的空格正常显示(此特性暂不支持)
    /// \param location 地址
    /// \param description  个人描述
    /// \param url  用户博客地址
    /// \param profile_image_url  自定义图像
    /// \param domain  用户个性化URL
    /// \param gender  性别,m--男，f--女,n--未知
    /// \param followers_count  粉丝数
    /// \param friends_count  关注数
    /// \param statuses_count  微博数
    /// \param favourites_count  收藏数
    /// \param created_at  创建时间
    /// \param following  是否已关注  暂未支持
    /// \param verified  加V标示，是否微博认证用户
    /// \param follow_me 此用户是否关注我
    /// \param avatar_large 大头像地址
    /// \param bi_followers_count 互粉数
    /// \param status 用户最新一条微博
    /// \return 
    ///
    static QWeiboUserObject *create(
            const QString &id,///<用户UID
            const QString &screen_name,///< 微博昵称
            const QString &name,///< 友好显示名称，如Bill Gates,名称中间的空格正常显示(此特性暂不支持)
            const QString &location,///<地址
            const QString &description,///< 个人描述
            const QString &url,///< 用户博客地址
            const QString &profile_image_url,///< 自定义图像
            const QString &domain,///< 用户个性化URL
            const QString &gender,///< 性别,m--男，f--女,n--未知
            int followers_count,///< 粉丝数
            int friends_count,///< 关注数
            int statuses_count,///< 微博数
            int favourites_count,///< 收藏数
            const QString &created_at,///< 创建时间
            bool following,///< 是否已关注  暂未支持
            bool verified,///< 加V标示，是否微博认证用户
            bool follow_me,///<此用户是否关注我
            const QString &avatar_large,///<大头像地址
            int bi_followers_count,///<互粉数
            QWeiboStatusObject *status = 0,///<用户最新一条微博
            QObject *parent = 0);
    
    QString id() const                  {return m_id;}
    QString screen_name() const         {return m_screen_name;}
    QString name() const                {return m_name;}
    QString location() const            {return m_location;}
    QString description() const         {return m_description;}
    QString url() const                 {return m_url;}
    QString profile_image_url() const   {return m_profile_image_url;}
    QString domain() const              {return m_domain;}
    QString gender() const              {return m_gender;}
    int followers_count() const         {return m_followers_count;}
    int friends_count() const           {return m_friends_count;}
    int statuses_count() const          {return m_statuses_count;}
    int favourites_count() const        {return m_favourites_count;}
    QString created_at() const          {return m_created_at;}
    bool following() const              {return m_following;}
    bool verified() const               {return m_verified;}
    bool follow_me() const              {return m_follow_me;}
    QString avatar_large() const        {return m_avatar_large;}
    int bi_followers_count() const      {return m_bi_followers_count;}
    QObject *status() const;

private:
    QString m_id;///<用户UID
    QString m_screen_name;///< 微博昵称
    QString m_name;///< 友好显示名称，如Bill Gates,名称中间的空格正常显示(此特性暂不支持)
    QString m_location;///<地址
    QString m_description;///< 个人描述
    QString m_url;///< 用户博客地址
    QString m_profile_image_url;///< 自定义图像
    QString m_domain;///< 用户个性化URL
    QString m_gender;///< 性别,m--男，f--女,n--未知
    int m_followers_count;///< 粉丝数
    int m_friends_count;///< 关注数
    int m_statuses_count;///< 微博数
    int m_favourites_count;///< 收藏数
    QString m_created_at;///< 创建时间
    bool m_following;///< 是否已关注  暂未支持
    bool m_verified;///< 加V标示，是否微博认证用户
    bool m_follow_me;///<此用户是否关注我
    QString m_avatar_large;///<大头像地址
    int m_bi_followers_count;///<互粉数
    QWeiboStatusObject *m_status;///<用户最新一条微博
};

}

#endif // QWEIBOOBJECT_H
