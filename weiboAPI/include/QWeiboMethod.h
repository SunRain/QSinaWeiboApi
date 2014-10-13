#ifndef QWEIBOMETHOD_H
#define QWEIBOMETHOD_H

#include <QObject>

namespace QSinaWeiboAPI {
class QWeiboMethod : public QObject
{
    Q_OBJECT
    Q_ENUMS(WeiboAction)

public:
    explicit QWeiboMethod(QObject *parent = 0) {}

    enum WeiboAction {
        WBOPT_GET_STATUSES_PUBLIC_TIMELINE,//获取最新更新的公共微博消息
        WBOPT_GET_STATUSES_FRIENDS_TIMELINE,//获取当前用户所关注用户的最新微博信息 (别名: statuses/home_timeline)
        WBOPT_GET_STATUSES_HOME_TIMELINE,//获取当前登录用户及其所关注用户的最新微博消息
        WBOPT_GET_STATUSES_USER_TIMELINE,//获取用户发布的微博信息列表
        WBOPT_GET_STATUSES_TIMELINE_BATCH,//批量获得指定的某一批用户的timeline
        WBOPT_GET_STATUSES_REPOST_TIMELINE,//返回一条微博的最新n条转发微博信息
        //WBOPT_GET_STATUSES_REPOST_BYME,//返回用户转发的最新n条微博信息
        WBOPT_GET_STATUSES_MENTIONS,//获取@当前用户的微博列表
        WBOPT_GET_STATUSES_MENTIONS_IDS, //获取@当前用户的最新微博的ID
        WBOPT_GET_STATUSES_SHOW,//根据ID获取单条微博信息
        WBOPT_GET_STATUSES_SHOW_BATCH,//批量获取微博信息
        WBOPT_GET_STATUSES_QUERYMID,//通过id获取mid, type 获取类型，1：微博、2：评论、3：私信，默认为1。
        WBOPT_GET_STATUSES_QUERYID,//通过mid获取id, type 获取类型，1：微博、2：评论、3：私信，默认为1。
        WBOPT_GET_STATUSES_COUNT, //批量获取指定微博的转发数评论数
//        WBOPT_GET_STATUSES_REPOST_DAILY,//按天返回热门转发榜
//        WBOPT_GET_STATUSES_REPOST_WEEKLY,//按周返回热门转发榜
//        WBOPT_GET_STATUSES_HOT_COMMENTS_DAILY,//按天返回热门评论榜
//        WBOPT_GET_STATUSES_HOT_COMMENTS_WEEKLY,//按周返回热门评论榜
        WBOPT_POST_STATUSES_REPOST,//转发一条微博信息, is_comment 是否在转发的同时发表评论，0：否、1：评论给当前微博、2：评论给原微博、3：都评论，默认为0 。
        WBOPT_POST_STATUSES_DESTROY,//删除微博评论信息
        WBOPT_POST_STATUSES_UPDATE,//发布一条微博信息
        WBOPT_POST_STATUSES_UPLOAD,//发布一条微博，上传图片并发布一条微博信息
        WBOPT_POST_STATUSES_UPLOAD_URL_TEXT,//发布一条微博，同时指定上传的图片或图片url

        WBOPT_GET_COMMENTS_SHOW,//获取某条微博的评论列表
        WBOPT_GET_COMMENTS_BY_ME,//我发出的评论列表
        WBOPT_GET_COMMENTS_TO_ME,//我收到的评论列表
        WBOPT_GET_COMMENTS_TIMELINE,//获取当前用户发送及收到的评论列表
        WBOPT_GET_COMMENTS_MENTIONS,//@到我的评论
        WBOPT_GET_COMMENTS_SHOWBATCH,//@批量获取评论内容

        ///below not check
        WBOPT_POST_COMMENTS_CREATE,//评论一条微博
        WBOPT_POST_COMMENTS_DESTROY,//删除一条评论
        WBOPT_POST_COMMENTS_DESTROY_BATCH ,//批量删除评论
        WBOPT_POST_COMMENTS_REPLY,//回复一条评论

        WBOPT_GET_DIRECTMESSAGES,//获取当前用户最新私信列表
        WBOPT_GET_DIRECTMESSAGES_SENT,//获取当前用户发送的最新私信列表
        WBOPT_GET_DIRECTMESSAGES_USER_LIST,//获取私信往来用户列表
        WBOPT_GET_DIRECTMESSAGES_CONVERSATION,//获取与指定用户的往来私信列表
        WBOPT_GET_DIRECTMESSAGES_SHOW_BATCH,//批量获取私信内容
        WBOPT_GET_DIRECTMESSAGES_IS_CAPABLE,//判断是否可以给对方发私信
        WBOPT_POST_DIRECTMESSAGES_NEW,//发送一条私信
        WBOPT_POST_DIRECTMESSAGES_DESTORY,//删除一条私信
        WBOPT_POST_DIRECTMESSAGES_DESTORY_BATCH,//批量删除私信

        WBOPT_GET_USERS_SHOW,//获取用户资料
        WBOPT_GET_USERS_DOMAIN_SHOW,//通过个性域名获取用户信息
        WBOPT_GET_USERS_SHOW_BATCH,//批量获取用户信息

        WBOPT_GET_ACCOUNT_PROFILE_BASIC, //获取用户基本信息
        WBOPT_GET_ACCOUNT_PROFILE_EDUCATION, //获取教育信息
        WBOPT_GET_ACCOUNT_PROFILE_EDUCATION_BATCH, //批量获取教育信息
        WBOPT_GET_ACCOUNT_PROFILE_CAREER, //获取职业信息
        WBOPT_GET_ACCOUNT_PROFILE_CAREER_BATCH, //批量获取职业信息
        WBOPT_GET_ACCOUNT_GET_PRIVACY, //获取隐私设置信息
        WBOPT_GET_ACCOUNT_PROFILE_SCHOOL_LIST, //获取所有学校列表
        WBOPT_GET_ACCOUNT_RATE_LIMIT_STATUS, //获取当前用户API访问频率限制
        WBOPT_GET_ACCOUNT_GET_UID, //OAuth授权之后获取用户UID（作用相当于旧版接口的account/verify_credentials）
        WBOPT_POST_ACCOUNT_PROFILE_BASIC_UPDATE, // 更新用户基本信息
        WBOPT_POST_ACCOUNT_PROFILE_EDU_UPDATE, // 更新用户教育信息
        WBOPT_POST_ACCOUNT_PROFILE_EDU_DESTROY, // 删除用户教育信息
        WBOPT_POST_ACCOUNT_PROFILE_CAR_UPDATE, // 更新用户职业信息
        WBOPT_POST_ACCOUNT_PROFILE_CAR_DESTROY, // 删除用户职业信息
        WBOPT_POST_ACCOUNT_AVATAR_UPLOAD, // 上传头像
        WBOPT_POST_ACCOUNT_UPDATE_PRIVACY, // 更新隐私设置

        WBOPT_GET_FRIENDSHIPS_FRIENDS,//获取用户的关注列表
        WBOPT_GET_FRIENDSHIPS_IN_COMMON,//获取共同关注人列表接口
        WBOPT_GET_FRIENDSHIPS_BILATERAL,//获取双向关注列表
        WBOPT_GET_FRIENDSHIPS_BILATERAL_IDS,//获取双向关注ID列表
        WBOPT_GET_FRIENDSHIPS_FRIENDS_IDS,//获取用户关注对象uid列表
        WBOPT_GET_FRIENDSHIPS_FRIENDS_REMARK_BATCH,//批量获取备注
        WBOPT_GET_FRIENDSHIPS_FRIENDS_FOLLOWERS,//获取用户粉丝列表及每个粉丝的最新一条微博
        WBOPT_GET_FRIENDSHIPS_FRIENDS_FOLLOWERS_IDS,//获取用户粉丝对象uid列表
        WBOPT_GET_FRIENDSHIPS_FRIENDS_FOLLOWERS_ACTIVE,//获取用户优质粉丝列表关系链
        WBOPT_GET_FRIENDSHIPS_CHAIN_FOLLOWERS,//获取我的关注人中关注了指定用户的分组
        WBOPT_GET_FRIENDSHIPS_SHOW,//获取两个用户关系的详细情况
        WBOPT_POST_FRIENDSHIPS_CREATE,//关注某用户
        WBOPT_POST_FRIENDSHIPS_CREATE_BATCH,//批量关注用户
        WBOPT_POST_FRIENDSHIPS_DESTROY,//取消关注某用户
        WBOPT_POST_FRIENDSHIPS_FOLLOWERS_DESTORY,//移除粉丝
        WBOPT_POST_FRIENDSHIPS_REMARK_UPDATE,//更新关注人备注

        WBOPT_GET_FAVORITES,//获取当前登录用户的收藏列表
        WBOPT_GET_FAVORITES_SHOW,//获取单条收藏信息
        WBOPT_GET_FAVORITES_BY_TAGS,//获取当前用户某个标签下的收藏列表
        WBOPT_GET_FAVORITES_TAGS,//当前登录用户的收藏标签列表
        WBOPT_POST_FAVORITES_CREATE,//添加收藏
        WBOPT_POST_FAVORITES_DESTROY,//删除收藏
        WBOPT_POST_FAVORITES_DESTROY_BATCH,//批量删除收藏
        WBOPT_POST_FAVORITES_TAGS_UPDATE,//更新收藏标签
        WBOPT_POST_FAVORITES_TAGS_UPDATE_BATCH,//更新当前用户所有收藏下的指定标签
        WBOPT_POST_FAVORITES_TAGS_DESTROY_BATCH,//删除当前用户所有收藏下的指定标签

        WBOPT_GET_TRENDS,//获取某人话题
        WBOPT_GET_TRENDS_STATUSES,//获取某一话题下的微博
        WBOPT_GET_TRENDS_HOURLY,//返回最近一小时内的热门话题
        WBOPT_GET_TRENDS_DAILY,//返回最近一天内的热门话题
        WBOPT_GET_TRENDS_WEEKLY,//返回最近一周内的热门话题
        WBOPT_POST_TRENDS_FOLLOW,//关注某话题
        WBOPT_POST_TRENDS_DESTROY,//取消关注的某一个话题

        WBOPT_GET_TAGS,//返回指定用户的标签列表
        WBOPT_GET_TAGS_TAGS_BATCH,//批量获取用户标签
        WBOPT_GET_TAGS_SUGGESTIONS,//返回系统推荐的标签列表
        WBOPT_POST_TAGS_CREATE,//添加用户标签
        WBOPT_POST_TAGS_DESTROY,//删除用户标签
        WBOPT_POST_TAGS_DESTROY_BATCH,//批量删除用户标签

        WBOPT_GET_SEARCH_SUGGESTIONS_USERS,//搜用户搜索建议
        WBOPT_GET_SEARCH_SUGGESTIONS_STATUSES,//搜微博搜索建议
        WBOPT_GET_SEARCH_SUGGESTIONS_SCHOOLS,//搜学校搜索建议
        WBOPT_GET_SEARCH_SUGGESTIONS_COMPANIES, //搜公司搜索建议
        WBOPT_GET_SEARCH_SUGGESTIONS_APPS,//搜应用搜索建议
        WBOPT_GET_SEARCH_SUGGESTIONS_AT_USERS, //@联想搜索
        WBOPT_GET_SEARCH_SUGGESTIONS_INTEGRATE,  //综合联想搜索
        WBOPT_GET_SEARCH_STATUSES,//微博搜索
        WBOPT_GET_SEARCH_GEO_STATUSES, //搜索指定范围内的微博
        WBOPT_GET_SEARCH_USERS,//搜索用户

        WBOPT_GET_SUGGESTIONS_FAVORITES_HOT,//热门收藏
        WBOPT_GET_SUGGESTIONS_USERS_HOT,//获取系统推荐用户
        WBOPT_GET_SUGGESTIONS_USERS_MAY_INTERESTED,//获取用户可能感兴趣的人
        WBOPT_POST_SUGGESTIONS_USERS_NOT_INTERESTED,//不感兴趣的人
        WBOPT_GET_SUGGESTIONS_USERS_BY_STATUS,//根据微博内容推荐用户

        WBOPT_GET_SHORT_URL_SHORTEN, //将一个或多个长链接转换成短链接
        WBOPT_GET_SHORT_URL_EXPAND, //将一个或多个短链接还原成原始的长链接
        WBOPT_GET_SHORT_URL_SHARE_COUNTS, //取得一个短链接在微博上的微博分享数（包含原创和转发的微博）
        WBOPT_GET_SHORT_URL_SHARE_STATUSES, //取得包含指定单个短链接的最新微博内容
        WBOPT_GET_SHORT_URL_COMMENT_COUNTS, //取得一个短链接在微博上的微博评论数
        WBOPT_GET_SHORT_URL_COMMENT_COMMENTS, //取得包含指定单个短链接的最新微博评论内容
        WBOPT_GET_SHORT_URL_INFO,

        WBOPT_GET_REMIND_UNREAD_COUNT,//获取某个用户的各种消息未读数
        WBOPT_POST_STATUSES_RESET_COUNT,//设置消息未读数

        // Groups
        WBOPT_GET_GROUPS_JOINED,
        WBOPT_GET_GROUPS_SHOW_BATCH,
        WBOPT_GET_GROUPS_GET_ANNOUNCEMENT,
        WBOPT_GET_GROUPS_ADMIN,
        WBOPT_GET_GROUPS_USERS,
        WBOPT_GET_GROUPS_SUGGESTION_MAY_INTERESTED,
        WBOPT_GET_GROUPS_CHAT_BLOCK,
        WBOPT_GET_GROUPS_CHAT_UNBLOCK,
        WBOPT_GET_GROUPS_CHAT_IS_BLOCKED,
        WBOPT_GET_GROUP_USERS_JOINED_STATUSES
    };
};

}
#endif // QWEIBOMETHOD_H
