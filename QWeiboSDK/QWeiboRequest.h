
#include "global.h"
#include "BaseRequest.h"

namespace QWeiboSDK {

// 2/statuses/public_timeline: 获取最新的公共微博
class QWEIBOSDK_EXPORT StatusesPublicTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesPublicTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/public_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/statuses/friends_timeline: 获取当前登录用户及其所关注用户的最新微博
class QWEIBOSDK_EXPORT StatusesFriendsTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesFriendsTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/friends_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 20)  //单页返回的记录条数，最大不超过100，默认为20。
        ("page", 1)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
        ;
    }
};
// 2/statuses/home_timeline: 获取当前登录用户及其所关注用户的最新微博
class QWEIBOSDK_EXPORT StatusesHomeTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesHomeTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/home_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过100，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
        ;
    }
};
// 2/statuses/friends_timeline/ids: 获取当前登录用户及其所关注用户的最新微博的ID
class QWEIBOSDK_EXPORT StatusesFriendsTimelineIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesFriendsTimelineIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/friends_timeline/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过100，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ;
    }
};
// 2/statuses/user_timeline: 获取用户发布的微博
class QWEIBOSDK_EXPORT StatusesUserTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesUserTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/user_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过100，超过100以100处理，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
        ;
    }
};
// 2/statuses/user_timeline/ids: 获取用户发布的微博的ID
class QWEIBOSDK_EXPORT StatusesUserTimelineIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesUserTimelineIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/user_timeline/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过100，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ;
    }
};
// 2/statuses/timeline_batch: 批量获取指定的一批用户的微博列表
class QWEIBOSDK_EXPORT StatusesTimelineBatch : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesTimelineBatch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/timeline_batch");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uids", "")  //需要查询的用户ID，用半角逗号分隔，一次最多20个。
        ("screen_names", "")  //需要查询的用户昵称，用半角逗号分隔，一次最多20个。
        ("count", 0)  //单页返回的记录条数，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ;
    }
};
// 2/statuses/repost_timeline: 返回一条原创微博的最新转发微博
class QWEIBOSDK_EXPORT StatusesRepostTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesRepostTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/repost_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的微博ID。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过200，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ;
    }
};
// 2/statuses/repost_timeline/ids: 获取一条原创微博的最新转发微博的ID
class QWEIBOSDK_EXPORT StatusesRepostTimelineIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesRepostTimelineIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/repost_timeline/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的微博ID。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过200，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ;
    }
};
// 2/statuses/mentions: 获取@当前用户的最新微博
class QWEIBOSDK_EXPORT StatusesMentions : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesMentions(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/mentions");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过200，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博、2：来自微群，默认为0。
        ("filter_by_type", 0)  //原创筛选类型，0：全部微博、1：原创的微博，默认为0。
        ;
    }
};
// 2/statuses/mentions/ids: 获取@当前用户的最新微博的ID
class QWEIBOSDK_EXPORT StatusesMentionsIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesMentionsIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/mentions/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过200，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博、2：来自微群，默认为0。
        ("filter_by_type", 0)  //原创筛选类型，0：全部微博、1：原创的微博，默认为0。
        ;
    }
};
// 2/statuses/bilateral_timeline: 获取双向关注用户的最新微博
class QWEIBOSDK_EXPORT StatusesBilateralTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesBilateralTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/bilateral_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过100，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
        ;
    }
};
// 2/statuses/show: 根据ID获取单条微博信息
class QWEIBOSDK_EXPORT StatusesShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要获取的微博ID。
        ;
    }
};
// 2/statuses/show_batch: 根据微博ID批量获取微博信息
class QWEIBOSDK_EXPORT StatusesShowBatch : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesShowBatch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/show_batch");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ids", "")  //需要查询的微博ID，用半角逗号分隔，最多不超过50个。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
        ;
    }
};
// 2/statuses/querymid: 通过id获取mid
class QWEIBOSDK_EXPORT StatusesQuerymid : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesQuerymid(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/querymid");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的微博（评论、私信）ID，批量模式下，用半角逗号分隔，最多不超过20个。
        ("type", 0)  //获取类型，1：微博、2：评论、3：私信，默认为1。
        ("is_batch", 0)  //是否使用批量模式，0：否、1：是，默认为0。
        ;
    }
};
// 2/statuses/queryid: 通过mid获取id
class QWEIBOSDK_EXPORT StatusesQueryid : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesQueryid(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/queryid");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("mid", "")  //需要查询的微博（评论、私信）MID，批量模式下，用半角逗号分隔，最多不超过20个。
        ("type", 0)  //获取类型，1：微博、2：评论、3：私信，默认为1。
        ("is_batch", 0)  //是否使用批量模式，0：否、1：是，默认为0。
        ("inbox", 0)  //仅对私信有效，当MID类型为私信时用此参数，0：发件箱、1：收件箱，默认为0 。
        ("isBase62", 0)  //MID是否是base62编码，0：否、1：是，默认为0。
        ;
    }
};
// 2/statuses/count: 批量获取指定微博的转发数评论数
class QWEIBOSDK_EXPORT StatusesCount : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesCount(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/count");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ids", "")  //需要获取数据的微博ID，多个之间用逗号分隔，最多不超过100个。
        ;
    }
};
// 2/statuses/go: 根据ID跳转到单条微博页
class QWEIBOSDK_EXPORT StatusesGo : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesGo(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/go");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要跳转的用户ID。
        ("id", 0)  //需要跳转的微博ID。
        ;
    }
};
// 2/emotions: 获取官方表情
class QWEIBOSDK_EXPORT Emotions : public BaseRequest
{
    Q_OBJECT
public:
    explicit Emotions(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/emotions");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("type", "")  //表情类别，face：普通表情、ani：魔法表情、cartoon：动漫表情，默认为face。
        ("language", "")  //语言类别，cnname：简体、twname：繁体，默认为cnname。
        ;
    }
};
// 2/statuses/repost: 转发一条微博信息
class QWEIBOSDK_EXPORT StatusesRepost : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesRepost(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/repost");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //要转发的微博ID。
        ("status", "")  //添加的转发文本，必须做URLencode，内容不超过140个汉字，不填则默认为“转发微博”。
        ("is_comment", 0)  //是否在转发的同时发表评论，0：否、1：评论给当前微博、2：评论给原微博、3：都评论，默认为0 。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
        ;
    }
};
// 2/statuses/destroy: 删除微博信息
class QWEIBOSDK_EXPORT StatusesDestroy : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesDestroy(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/destroy");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要删除的微博ID。
        ;
    }
};
// 2/statuses/update: 发布一条微博信息
class QWEIBOSDK_EXPORT StatusesUpdate : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesUpdate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/update");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("status", "")  //要发布的微博文本内容，必须做URLencode，内容不超过140个汉字。
        ("visible", 0)  //微博的可见性，0：所有人能看，1：仅自己可见，2：密友可见，3：指定分组可见，默认为0。
        ("list_id", "")  //微博的保护投递指定分组ID，只有当visible参数为3时生效且必选。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬，默认为0.0。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经，默认为0.0。
        ("annotations", "")  //元数据，主要是为了方便第三方应用记录一些适合于自己使用的信息，每条微博可以包含一个或者多个元数据，必须以json字串的形式提交，字串长度不超过512个字符，具体内容可以自定。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
        ;
    }
};
// 2/statuses/upload: 上传图片并发布一条微博
class QWEIBOSDK_EXPORT StatusesUpload : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesUpload(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/upload");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("status", "")  //要发布的微博文本内容，必须做URLencode，内容不超过140个汉字。
        ("visible", 0)  //微博的可见性，0：所有人能看，1：仅自己可见，2：密友可见，3：指定分组可见，默认为0。
        ("list_id", "")  //微博的保护投递指定分组ID，只有当visible参数为3时生效且必选。
        ("pic", 0)  //要上传的图片，仅支持JPEG、GIF、PNG格式，图片大小小于5M。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬，默认为0.0。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经，默认为0.0。
        ("annotations", "")  //元数据，主要是为了方便第三方应用记录一些适合于自己使用的信息，每条微博可以包含一个或者多个元数据，必须以json字串的形式提交，字串长度不超过512个字符，具体内容可以自定。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
        ;
    }
};
// 2/statuses/upload_url_text: 发布一条微博同时指定上传的图片或图片url
class QWEIBOSDK_EXPORT StatusesUploadUrlText : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesUploadUrlText(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/upload_url_text");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("status", "")  //要发布的微博文本内容，必须做URLencode，内容不超过140个汉字。
        ("visible", 0)  //微博的可见性，0：所有人能看，1：仅自己可见，2：密友可见，3：指定分组可见，默认为0。
        ("list_id", "")  //微博的保护投递指定分组ID，只有当visible参数为3时生效且必选。
        ("url", "")  //图片的URL地址，必须以http开头。
        ("pic_id", "")  //已经上传的图片pid，多个时使用英文半角逗号符分隔，最多不超过9个。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬，默认为0.0。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经，默认为0.0。
        ("annotations", "")  //元数据，主要是为了方便第三方应用记录一些适合于自己使用的信息，每条微博可以包含一个或者多个元数据，必须以json字串的形式提交，字串长度不超过512个字符，具体内容可以自定。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
        ;
    }
};
// 2/statuses/filter/create: 屏蔽某条微博
class QWEIBOSDK_EXPORT StatusesFilterCreate : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesFilterCreate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/filter/create");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //微博id。
        ;
    }
};
// 2/statuses/mentions/shield: 屏蔽某个@我的微博及后续由其转发引起的@提及
class QWEIBOSDK_EXPORT StatusesMentionsShield : public BaseRequest
{
    Q_OBJECT
public:
    explicit StatusesMentionsShield(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/statuses/mentions/shield");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要屏蔽的@提到我的微博ID。此ID必须在statuses/mentions列表中。
        ("follow_up", 0)  //是否仅屏蔽当前微博。0：仅屏蔽当前@提到我的微博；1：屏蔽当前@提到我的微博，以及后续对其转发而引起的@提到我的微博。默认1。
        ;
    }
};
// 2/comments/show: 获取某条微博的评论列表
class QWEIBOSDK_EXPORT CommentsShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的微博ID。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ;
    }
};
// 2/comments/by_me: 我发出的评论列表
class QWEIBOSDK_EXPORT CommentsByMe : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsByMe(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/by_me");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博的评论、2：来自微群的评论，默认为0。
        ;
    }
};
// 2/comments/to_me: 我收到的评论列表
class QWEIBOSDK_EXPORT CommentsToMe : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsToMe(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/to_me");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博的评论、2：来自微群的评论，默认为0。
        ;
    }
};
// 2/comments/timeline: 获取用户发送及收到的评论列表
class QWEIBOSDK_EXPORT CommentsTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 50)  //单页返回的记录条数，默认为50。
        ("page", 1)  //返回结果的页码，默认为1。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
        ;
    }
};
// 2/comments/mentions: 获取@到我的评论
class QWEIBOSDK_EXPORT CommentsMentions : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsMentions(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/mentions");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 50)  //单页返回的记录条数，默认为50。
        ("page", 1)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博的评论、2：来自微群的评论，默认为0。
        ;
    }
};
// 2/comments/show_batch: 批量获取评论内容
class QWEIBOSDK_EXPORT CommentsShowBatch : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsShowBatch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/show_batch");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("cids", 0)  //需要查询的批量评论ID，用半角逗号分隔，最大50。
        ;
    }
};
// 2/comments/create: 评论一条微博
class QWEIBOSDK_EXPORT CommentsCreate : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsCreate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/create");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("comment", "")  //评论内容，必须做URLencode，内容不超过140个汉字。
        ("id", 0)  //需要评论的微博ID。
        ("comment_ori", 0)  //当评论转发微博时，是否评论给原微博，0：否、1：是，默认为0。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
        ;
    }
};
// 2/comments/destroy: 删除一条评论
class QWEIBOSDK_EXPORT CommentsDestroy : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsDestroy(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/destroy");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("cid", 0)  //要删除的评论ID，只能删除登录用户自己发布的评论。
        ;
    }
};
// 2/comments/destroy_batch: 批量删除评论
class QWEIBOSDK_EXPORT CommentsDestroyBatch : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsDestroyBatch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/destroy_batch");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("cids", 0)  //需要删除的评论ID，用半角逗号隔开，最多20个。
        ;
    }
};
// 2/comments/reply: 回复一条评论
class QWEIBOSDK_EXPORT CommentsReply : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommentsReply(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/comments/reply");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("cid", 0)  //需要回复的评论ID。
        ("id", 0)  //需要评论的微博ID。
        ("comment", "")  //回复评论内容，必须做URLencode，内容不超过140个汉字。
        ("without_mention", 0)  //回复中是否自动加入“回复@用户名”，0：是、1：否，默认为0。
        ("comment_ori", 0)  //当评论转发微博时，是否评论给原微博，0：否、1：是，默认为0。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
        ;
    }
};
// 2/users/show: 获取用户信息
class QWEIBOSDK_EXPORT UsersShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit UsersShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/users/show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("screen_name", "")  //需要查询的用户昵称。
        ;
    }
};
// 2/users/domain_show: 通过个性域名获取用户信息
class QWEIBOSDK_EXPORT UsersDomainShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit UsersDomainShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/users/domain_show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("domain", "")  //需要查询的个性化域名。
        ;
    }
};
// 2/users/counts: 批量获取用户的粉丝数、关注数、微博数
class QWEIBOSDK_EXPORT UsersCounts : public BaseRequest
{
    Q_OBJECT
public:
    explicit UsersCounts(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/users/counts");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uids", "")  //需要获取数据的用户UID，多个之间用逗号分隔，最多不超过100个。
        ;
    }
};
///////////////////////// ADD begin
//2/friendships/groups/timeline: 获取某一好友分组的微博列表
class QWEIBOSDK_EXPORT FriendshipsGroupsTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsGroupsTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/groups/timeline");
        initiate ();
    }
protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", "")  //需要查询的好友分组ID，建议使用返回值里的idstr，当查询的为私有分组时，则当前登录用户必须为其所有者。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 50)  //单页返回的记录条数，最大不超过200，默认为50。
        ("page", 1)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ;
    }
};


//2/friendships/groups: 获取当前登陆用户好友分组列表
class QWEIBOSDK_EXPORT FriendshipsGroups : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsGroups(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/groups");
        initiate ();
    }
protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ;
    }
};

//2/friendships/groups/destroy: 删除好友分组
class QWEIBOSDK_EXPORT FriendshipsGroupsDestroy : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsGroupsDestroy(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/groups/destroy");
        initiate ();
    }
protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", "")  //要删除的好友分组ID，建议使用返回值里的idstr。
        ;
    }
};

//2/friendships/groups/update: 更新好友分组
class QWEIBOSDK_EXPORT FriendshipsGroupsUpdate : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsGroupsUpdate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/groups/update");
        initiate ();
    }
protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", "")  //需要更新的好友分组ID，建议使用返回值里的idstr，只能更新当前登录用户自己创建的分组。
        ("name", "")  //好友分组更新后的名称，不超过8个汉字，16个半角字符。
        ("description", "")  //好友分组更新后的描述，不超过70个汉字，140个半角字符。
        ("tags", "")  //好友分组更新后的标签，多个之间用逗号分隔，最多不超过10个，每个不超过7个汉字，14个半角字符。
        ;
    }
};

///////////////////////// add end

// 2/friendships/friends: 获取用户的关注列表
class QWEIBOSDK_EXPORT FriendshipsFriends : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFriends(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/friends");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("count", 0)  //单页返回的记录条数，默认为50，最大不超过200。
        ("cursor", 0)  //返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
        ("trim_status", 0)  //返回值中user字段中的status字段开关，0：返回完整status字段、1：status字段仅返回status_id，默认为1。
        ;
    }
};
// 2/friendships/friends/in_common: 获取共同关注人列表
class QWEIBOSDK_EXPORT FriendshipsFriendsInCommon : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFriendsInCommon(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/friends/in_common");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要获取共同关注关系的用户UID。
        ("suid", 0)  //需要获取共同关注关系的用户UID，默认为当前登录用户。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("trim_status", 0)  //返回值中user字段中的status字段开关，0：返回完整status字段、1：status字段仅返回status_id，默认为1。
        ;
    }
};
// 2/friendships/friends/bilateral: 获取双向关注列表
class QWEIBOSDK_EXPORT FriendshipsFriendsBilateral : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFriendsBilateral(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/friends/bilateral");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要获取双向关注列表的用户UID。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序类型，0：按关注时间最近排序，默认为0。
        ;
    }
};
// 2/friendships/friends/bilateral/ids: 获取双向关注UID列表
class QWEIBOSDK_EXPORT FriendshipsFriendsBilateralIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFriendsBilateralIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/friends/bilateral/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要获取双向关注列表的用户UID。
        ("count", 0)  //单页返回的记录条数，默认为50，最大不超过2000。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序类型，0：按关注时间最近排序，默认为0。
        ;
    }
};
// 2/friendships/friends/ids: 获取用户关注对象UID列表
class QWEIBOSDK_EXPORT FriendshipsFriendsIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFriendsIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/friends/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("count", 0)  //单页返回的记录条数，默认为500，最大不超过5000。
        ("cursor", 0)  //返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
        ;
    }
};
// 2/friendships/followers: 获取用户粉丝列表
class QWEIBOSDK_EXPORT FriendshipsFollowers : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFollowers(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/followers");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("count", 0)  //单页返回的记录条数，默认为50，最大不超过200。
        ("cursor", 0)  //返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
        ("trim_status", 0)  //返回值中user字段中的status字段开关，0：返回完整status字段、1：status字段仅返回status_id，默认为1。
        ;
    }
};
// 2/friendships/followers/ids: 获取用户粉丝UID列表
class QWEIBOSDK_EXPORT FriendshipsFollowersIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFollowersIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/followers/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("count", 0)  //单页返回的记录条数，默认为500，最大不超过5000。
        ("cursor", 0)  //返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
        ;
    }
};
// 2/friendships/followers/active: 获取用户优质粉丝列表
class QWEIBOSDK_EXPORT FriendshipsFollowersActive : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFollowersActive(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/followers/active");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("count", 0)  //返回的记录条数，默认为20，最大不超过200。
        ;
    }
};
// 2/friendships/friends_chain/followers: 获取我的关注人中关注了指定用户的人
class QWEIBOSDK_EXPORT FriendshipsFriendsChainFollowers : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsFriendsChainFollowers(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/friends_chain/followers");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //指定的关注目标用户UID。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/friendships/show: 获取两个用户关系的详细情况
class QWEIBOSDK_EXPORT FriendshipsShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("source_id", 0)  //源用户的UID。
        ("source_screen_name", "")  //源用户的微博昵称。
        ("target_id", 0)  //目标用户的UID。
        ("target_screen_name", "")  //目标用户的微博昵称。
        ;
    }
};
// 2/friendships/create: 关注某用户
class QWEIBOSDK_EXPORT FriendshipsCreate : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsCreate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/create");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要关注的用户ID。
        ("screen_name", "")  //需要关注的用户昵称。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
        ;
    }
};
// 2/friendships/destroy: 取消关注某用户
class QWEIBOSDK_EXPORT FriendshipsDestroy : public BaseRequest
{
    Q_OBJECT
public:
    explicit FriendshipsDestroy(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/friendships/destroy");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要取消关注的用户ID。
        ("screen_name", "")  //需要取消关注的用户昵称。
        ;
    }
};
// 2/account/profile/school_list: 获取所有学校列表
class QWEIBOSDK_EXPORT AccountProfileSchoolList : public BaseRequest
{
    Q_OBJECT
public:
    explicit AccountProfileSchoolList(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/account/profile/school_list");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("province", 0)  //省份范围，省份ID。
        ("city", 0)  //城市范围，城市ID。
        ("area", 0)  //区域范围，区ID。
        ("type", 0)  //学校类型，1：大学、2：高中、3：中专技校、4：初中、5：小学，默认为1。
        ("capital", "")  //学校首字母，默认为A。
        ("keyword", "")  //学校名称关键字。
        ("count", 0)  //返回的记录条数，默认为10。
        ;
    }
};
// 2/account/rate_limit_status: 获取当前用户API访问频率限制
class QWEIBOSDK_EXPORT AccountRateLimitStatus : public BaseRequest
{
    Q_OBJECT
public:
    explicit AccountRateLimitStatus(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/account/rate_limit_status");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ;
    }
};
// 2/account/profile/email: 获取用户的联系邮箱
class QWEIBOSDK_EXPORT AccountProfileEmail : public BaseRequest
{
    Q_OBJECT
public:
    explicit AccountProfileEmail(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/account/profile/email");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ;
    }
};
// 2/account/get_uid: OAuth授权之后获取用户UID
class QWEIBOSDK_EXPORT AccountGetUid : public BaseRequest
{
    Q_OBJECT
public:
    explicit AccountGetUid(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/account/get_uid");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ;
    }
};
// 2/favorites: 获取当前用户的收藏列表
class QWEIBOSDK_EXPORT Favorites : public BaseRequest
{
    Q_OBJECT
public:
    explicit Favorites(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/favorites/ids: 获取当前用户的收藏列表的ID
class QWEIBOSDK_EXPORT FavoritesIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/favorites/show: 获取单条收藏信息
class QWEIBOSDK_EXPORT FavoritesShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的收藏ID。
        ;
    }
};
// 2/favorites/by_tags: 获取当前用户某个标签下的收藏列表
class QWEIBOSDK_EXPORT FavoritesByTags : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesByTags(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/by_tags");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tid", 0)  //需要查询的标签ID。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/favorites/tags: 当前登录用户的收藏标签列表
class QWEIBOSDK_EXPORT FavoritesTags : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesTags(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/tags");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //单页返回的记录条数，默认为10。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/favorites/by_tags/ids: 获取当前用户某个标签下的收藏列表的ID
class QWEIBOSDK_EXPORT FavoritesByTagsIds : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesByTagsIds(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/by_tags/ids");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tid", 0)  //需要查询的标签ID。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/favorites/create: 添加收藏
class QWEIBOSDK_EXPORT FavoritesCreate : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesCreate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/create");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //要收藏的微博ID。
        ;
    }
};
// 2/favorites/destroy: 删除收藏
class QWEIBOSDK_EXPORT FavoritesDestroy : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesDestroy(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/destroy");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //要取消收藏的微博ID。
        ;
    }
};
// 2/favorites/destroy_batch: 批量删除收藏
class QWEIBOSDK_EXPORT FavoritesDestroyBatch : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesDestroyBatch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/destroy_batch");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ids", "")  //要取消收藏的收藏ID，用半角逗号分隔，最多不超过10个。
        ;
    }
};
// 2/favorites/tags/update: 更新收藏标签
class QWEIBOSDK_EXPORT FavoritesTagsUpdate : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesTagsUpdate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/tags/update");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要更新的收藏ID。
        ("tags", "")  //需要更新的标签内容，必须做URLencode，用半角逗号分隔，最多不超过2条。
        ;
    }
};
// 2/favorites/tags/update_batch: 更新当前用户所有收藏下的指定标签
class QWEIBOSDK_EXPORT FavoritesTagsUpdateBatch : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesTagsUpdateBatch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/tags/update_batch");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tid", 0)  //需要更新的标签ID。
        ("tag", "")  //需要更新的标签内容，必须做URLencode。
        ;
    }
};
// 2/favorites/tags/destroy_batch: 删除当前用户所有收藏下的指定标签
class QWEIBOSDK_EXPORT FavoritesTagsDestroyBatch : public BaseRequest
{
    Q_OBJECT
public:
    explicit FavoritesTagsDestroyBatch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/favorites/tags/destroy_batch");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tid", 0)  //需要删除的标签ID。
        ;
    }
};
// 2/search/suggestions/users: 搜用户搜索建议
class QWEIBOSDK_EXPORT SearchSuggestionsUsers : public BaseRequest
{
    Q_OBJECT
public:
    explicit SearchSuggestionsUsers(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/search/suggestions/users");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10。
        ;
    }
};
// 2/search/suggestions/schools: 搜学校搜索建议
class QWEIBOSDK_EXPORT SearchSuggestionsSchools : public BaseRequest
{
    Q_OBJECT
public:
    explicit SearchSuggestionsSchools(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/search/suggestions/schools");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10。
        ("type", 0)  //学校类型，0：全部、1：大学、2：高中、3：中专技校、4：初中、5：小学，默认为0。
        ;
    }
};
// 2/search/suggestions/companies: 搜公司搜索建议
class QWEIBOSDK_EXPORT SearchSuggestionsCompanies : public BaseRequest
{
    Q_OBJECT
public:
    explicit SearchSuggestionsCompanies(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/search/suggestions/companies");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10。
        ;
    }
};
// 2/search/suggestions/apps: 搜应用搜索建议
class QWEIBOSDK_EXPORT SearchSuggestionsApps : public BaseRequest
{
    Q_OBJECT
public:
    explicit SearchSuggestionsApps(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/search/suggestions/apps");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10。
        ;
    }
};
// 2/search/suggestions/at_users: @联想搜索
class QWEIBOSDK_EXPORT SearchSuggestionsAtUsers : public BaseRequest
{
    Q_OBJECT
public:
    explicit SearchSuggestionsAtUsers(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/search/suggestions/at_users");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10，粉丝最多1000，关注最多2000。
        ("type", 0)  //联想类型，0：关注、1：粉丝。
        ("range", 0)  //联想范围，0：只联想关注人、1：只联想关注人的备注、2：全部，默认为2。
        ;
    }
};
// 2/search/topics: 搜索某一话题下的微博
class QWEIBOSDK_EXPORT SearchTopics : public BaseRequest
{
    Q_OBJECT
public:
    explicit SearchTopics(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/search/topics");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的话题关键字，必须进行URLencode，utf-8编码。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/remind/unread_count: 获取某个用户的各种消息未读数
class QWEIBOSDK_EXPORT RemindUnreadCount : public BaseRequest
{
    Q_OBJECT
public:
    explicit RemindUnreadCount(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/remind/unread_count");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要获取消息未读数的用户UID，必须是当前登录用户。
        ("callback", "")  //JSONP回调函数，用于前端调用返回JS格式的信息。
        ("unread_message", 0)  //未读数版本。0：原版未读数，1：新版未读数。默认为0。
        ;
    }
};
// 2/remind/set_count: 对当前登录用户某一种消息未读数进行清零
class QWEIBOSDK_EXPORT RemindSetCount : public BaseRequest
{
    Q_OBJECT
public:
    explicit RemindSetCount(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/remind/set_count");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("type", "")  //需要设置未读数计数的消息项，follower：新粉丝数、cmt：新评论数、dm：新私信数、mention_status：新提及我的微博数、mention_cmt：新提及我的评论数、group：微群消息数、notice：新通知数、invite：新邀请数、badge：新勋章数、photo：相册消息数、close_friends_feeds：密友feeds未读数、close_friends_mention_status：密友提及我的微博未读数、close_friends_mention_cmt：密友提及我的评论未读数、close_friends_cmt：密友评论未读数、close_friends_attitude：密友表态未读数、close_friends_common_cmt：密友共同评论未读数、close_friends_invite：密友邀请未读数，一次只能操作一项。
        ;
    }
};
// 2/short_url/shorten: 长链转短链
class QWEIBOSDK_EXPORT ShortUrlShorten : public BaseRequest
{
    Q_OBJECT
public:
    explicit ShortUrlShorten(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/short_url/shorten");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_long", "")  //需要转换的长链接，需要URLencoded，最多不超过20个。
        ;
    }
};
// 2/short_url/expand: 短链转长链
class QWEIBOSDK_EXPORT ShortUrlExpand : public BaseRequest
{
    Q_OBJECT
public:
    explicit ShortUrlExpand(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/short_url/expand");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要还原的短链接，需要URLencoded，最多不超过20个 。
        ;
    }
};
// 2/short_url/share/counts: 获取短链接在微博上的微博分享数
class QWEIBOSDK_EXPORT ShortUrlShareCounts : public BaseRequest
{
    Q_OBJECT
public:
    explicit ShortUrlShareCounts(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/short_url/share/counts");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要取得分享数的短链接，需要URLencoded，最多不超过20个。
        ;
    }
};
// 2/short_url/share/statuses: 获取包含指定单个短链接的最新微博内容
class QWEIBOSDK_EXPORT ShortUrlShareStatuses : public BaseRequest
{
    Q_OBJECT
public:
    explicit ShortUrlShareStatuses(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/short_url/share/statuses");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要取得关联微博内容的短链接，需要URLencoded。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，默认为50，最多不超过200。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/short_url/comment/counts: 获取短链接在微博上的微博评论数
class QWEIBOSDK_EXPORT ShortUrlCommentCounts : public BaseRequest
{
    Q_OBJECT
public:
    explicit ShortUrlCommentCounts(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/short_url/comment/counts");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要取得分享数的短链接，需要URLencoded，最多不超过20个。
        ;
    }
};
// 2/short_url/comment/comments: 获取包含指定单个短链接的最新微博评论
class QWEIBOSDK_EXPORT ShortUrlCommentComments : public BaseRequest
{
    Q_OBJECT
public:
    explicit ShortUrlCommentComments(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/short_url/comment/comments");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要取得关联微博评论内容的短链接，需要URLencoded。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 0)  //单页返回的记录条数，默认为50，最多不超过200。
        ("page", 0)  //返回结果的页码，默认为1。
        ;
    }
};
// 2/common/code_to_location: 通过地址编码获取地址名称
class QWEIBOSDK_EXPORT CommonCodeToLocation : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommonCodeToLocation(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/common/code_to_location");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("codes", "")  //需要查询的地址编码，多个之间用逗号分隔。
        ;
    }
};
// 2/common/get_city: 获取城市列表
class QWEIBOSDK_EXPORT CommonGetCity : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommonGetCity(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/common/get_city");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("province", "")  //省份的省份代码。
        ("capital", "")  //城市的首字母，a-z，可为空代表返回全部，默认为全部。
        ("language", "")  //返回的语言版本，zh-cn：简体中文、zh-tw：繁体中文、english：英文，默认为zh-cn。
        ;
    }
};
// 2/common/get_province: 获取省份列表
class QWEIBOSDK_EXPORT CommonGetProvince : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommonGetProvince(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/common/get_province");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("country", "")  //国家的国家代码。
        ("capital", "")  //省份的首字母，a-z，可为空代表返回全部，默认为全部。
        ("language", "")  //返回的语言版本，zh-cn：简体中文、zh-tw：繁体中文、english：英文，默认为zh-cn。
        ;
    }
};
// 2/common/get_country: 获取国家列表
class QWEIBOSDK_EXPORT CommonGetCountry : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommonGetCountry(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/common/get_country");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("capital", "")  //国家的首字母，a-z，可为空代表返回全部，默认为全部。
        ("language", "")  //返回的语言版本，zh-cn：简体中文、zh-tw：繁体中文、english：英文，默认为zh-cn。
        ;
    }
};
// 2/common/get_timezone: 获取时区配置表
class QWEIBOSDK_EXPORT CommonGetTimezone : public BaseRequest
{
    Q_OBJECT
public:
    explicit CommonGetTimezone(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/common/get_timezone");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("language", "")  //返回的语言版本，zh-cn：简体中文、zh-tw：繁体中文、english：英文，默认为zh-cn。
        ;
    }
};
// 2/place/public_timeline: 获取公共的位置动态
class QWEIBOSDK_EXPORT PlacePublicTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePublicTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/public_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //每次返回的动态数，最大为50，默认为20。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/friends_timeline: 获取用户好友的位置动态
class QWEIBOSDK_EXPORT PlaceFriendsTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceFriendsTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/friends_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大为50，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("type", 0)  //关系过滤，0：仅返回关注的，1：返回好友的，默认为0。
        ;
    }
};
// 2/place/user_timeline: 获取某个用户的位置动态
class QWEIBOSDK_EXPORT PlaceUserTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceUserTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/user_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大为50，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/poi_timeline: 获取某个位置地点的动态
class QWEIBOSDK_EXPORT PlacePoiTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoiTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/poi_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI点ID。
        ("since_id", "")  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", "")  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大为50，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/nearby_timeline: 获取某个位置周边的动态
class QWEIBOSDK_EXPORT PlaceNearbyTimeline : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceNearbyTimeline(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/nearby_timeline");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("lat", 0)  //纬度。有效范围：-90.0到+90.0，+表示北纬。
        ("long", 0)  //经度。有效范围：-180.0到+180.0，+表示东经。
        ("range", 0)  //搜索范围，单位米，默认2000米，最大11132米。
        ("starttime", 0)  //开始时间，Unix时间戳。
        ("endtime", 0)  //结束时间，Unix时间戳。
        ("sort", 0)  //排序方式。默认为0，按时间排序；为1时按与中心点距离进行排序。
        ("count", 0)  //单页返回的记录条数，最大为50，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("offset", 0)  //传入的经纬度是否是纠偏过，0：没纠偏、1：纠偏过，默认为0。
        ;
    }
};
// 2/place/statuses/show: 获取动态的详情
class QWEIBOSDK_EXPORT PlaceStatusesShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceStatusesShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/statuses/show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要获取的动态ID。
        ;
    }
};
// 2/place/users/show: 获取LBS位置服务内的用户信息
class QWEIBOSDK_EXPORT PlaceUsersShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceUsersShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/users/show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/users/checkins: 获取用户签到过的地点列表
class QWEIBOSDK_EXPORT PlaceUsersCheckins : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceUsersCheckins(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/users/checkins");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/users/photos: 获取用户的照片列表
class QWEIBOSDK_EXPORT PlaceUsersPhotos : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceUsersPhotos(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/users/photos");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/users/tips: 获取用户的点评列表
class QWEIBOSDK_EXPORT PlaceUsersTips : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceUsersTips(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/users/tips");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/users/todos: 获取用户的todo列表
class QWEIBOSDK_EXPORT PlaceUsersTodos : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceUsersTodos(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/users/todos");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/pois/show: 获取地点详情
class QWEIBOSDK_EXPORT PlacePoisShow : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisShow(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/show");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI地点ID。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/pois/users: 获取在某个地点签到的人的列表
class QWEIBOSDK_EXPORT PlacePoisUsers : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisUsers(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/users");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI地点ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/pois/tips: 获取地点点评列表
class QWEIBOSDK_EXPORT PlacePoisTips : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisTips(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/tips");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI地点ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序方式，0：按时间、1：按热门，默认为0，目前只支持0。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/pois/photos: 获取地点照片列表
class QWEIBOSDK_EXPORT PlacePoisPhotos : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisPhotos(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/photos");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI地点ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序方式，0：按时间、1：按热门，默认为0，目前只支持0。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ;
    }
};
// 2/place/pois/search: 按省市查询地点
class QWEIBOSDK_EXPORT PlacePoisSearch : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisSearch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/search");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("keyword", "")  //查询的关键词，必须进行URLencode。
        ("city", "")  //城市代码，默认为全国搜索。
        ("category", "")  //查询的分类代码，取值范围见：分类代码对应表。
        ("page", 0)  //返回结果的页码，默认为1。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ;
    }
};
// 2/place/pois/category: 获取地点分类
class QWEIBOSDK_EXPORT PlacePoisCategory : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisCategory(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/category");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("pid", 0)  //父分类ID，默认为0。
        ("flag", 0)  //是否返回全部分类，0：只返回本级下的分类，1：返回全部分类，默认为0。
        ;
    }
};
// 2/place/nearby/pois: 获取附近地点
class QWEIBOSDK_EXPORT PlaceNearbyPois : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceNearbyPois(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/nearby/pois");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经。
        ("range", 0)  //查询范围半径，默认为2000，最大为10000，单位米。
        ("q", "")  //查询的关键词，必须进行URLencode。
        ("category", "")  //查询的分类代码，取值范围见：分类代码对应表。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序方式，0：按权重，1：按距离，3：按签到人数。默认为0。
        ("offset", 0)  //传入的经纬度是否是纠偏过，0：没纠偏、1：纠偏过，默认为0。
        ;
    }
};
// 2/place/nearby/users: 获取附近发位置微博的人
class QWEIBOSDK_EXPORT PlaceNearbyUsers : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceNearbyUsers(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/nearby/users");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经。
        ("range", 0)  //查询范围半径，默认为2000，最大为11132，单位米。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("starttime", 0)  //开始时间，Unix时间戳。
        ("endtime", 0)  //结束时间，Unix时间戳。
        ("sort", 0)  //排序方式，0：按时间、1：按距离，默认为0。
        ("offset", 0)  //传入的经纬度是否是纠偏过，0：没纠偏、1：纠偏过，默认为0。
        ;
    }
};
// 2/place/nearby/photos: 获取附近照片
class QWEIBOSDK_EXPORT PlaceNearbyPhotos : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceNearbyPhotos(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/nearby/photos");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经。
        ("range", 0)  //查询范围半径，默认为500，最大为11132，单位米。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("starttime", 0)  //开始时间，Unix时间戳。
        ("endtime", 0)  //结束时间，Unix时间戳。
        ("sort", 0)  //排序方式，0：按时间、1：按距离，默认为0。
        ("offset", 0)  //传入的经纬度是否是纠偏过，0：没纠偏、1：纠偏过，默认为0。
        ;
    }
};
// 2/place/nearby_users/list: 获取附近的人
class QWEIBOSDK_EXPORT PlaceNearbyUsersList : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceNearbyUsersList(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/nearby_users/list");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("lat", 0)  //动态发生的纬度，有效范围：-90.0到+90.0，+表示北纬，默认为0.0。
        ("long", 0)  //动态发生的经度，有效范围：-180.0到+180.0，+表示东经，默认为0.0。
        ("count", 0)  //单页返回的记录条数，最大为50，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("range", 0)  //查询范围半径，默认为2000，最大为11132。
        ("sort", 0)  //排序方式，0：按时间、1：按距离、2：按社会化关系，默认为2。
        ("filter", 0)  //（暂未启用）用户关系过滤，0：全部、1：只返回陌生人、2：只返回关注人，默认为0。
        ("gender", 0)  //性别过滤，0：全部、1：男、2：女，默认为0。
        ("level", 0)  //用户级别过滤，0：全部、1：普通用户、2：VIP用户、7：达人，默认为0。
        ("startbirth", 0)  //与参数endbirth一起定义过滤年龄段，数值为年龄大小，默认为空。
        ("endbirth", 0)  //与参数startbirth一起定义过滤年龄段，数值为年龄大小，默认为空。
        ("offset", 0)  //传入的经纬度是否是纠偏过，0：没纠偏、1：纠偏过，默认为0。
        ;
    }
};
// 2/place/pois/create: 添加地点
class QWEIBOSDK_EXPORT PlacePoisCreate : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisCreate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/create");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("title", "")  //POI点的名称，不超过30个字符，必须进行URLencode。
        ("address", "")  //POI点的地址，不超过60个字符，必须进行URLencode。
        ("category", 0)  //POI的类型分类代码，取值范围见：分类代码对应表，默认为500。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经。
        ("city", "")  //城市代码。
        ("province", 0)  //省份代码。
        ("country", 0)  //国家代码。
        ("phone", "")  //POI点的电话，不超过14个字符。
        ("postcode", "")  //POI点的邮编。
        ("extra", "")  //其他，必须进行URLencode。
        ;
    }
};
// 2/place/pois/add_checkin: 签到
class QWEIBOSDK_EXPORT PlacePoisAddCheckin : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisAddCheckin(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/add_checkin");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要签到的POI地点ID。
        ("status", "")  //签到时发布的动态内容，必须做URLencode，内容不超过140个汉字。
        ("pic", 0)  //需要上传的图片，仅支持JPEG、GIF、PNG格式，图片大小小于5M。
        ("public", 0)  //是否同步到微博，1：是、0：否，默认为0。
        ;
    }
};
// 2/place/pois/add_photo: 添加照片
class QWEIBOSDK_EXPORT PlacePoisAddPhoto : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisAddPhoto(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/add_photo");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要添加照片的POI地点ID。
        ("status", "")  //签到时发布的动态内容，必须做URLencode，内容不超过140个汉字。
        ("pic", 0)  //需要上传的图片，仅支持JPEG、GIF、PNG格式，图片大小小于5M。
        ("public", 0)  //是否同步到微博，1：是、0：否，默认为0。
        ;
    }
};
// 2/place/pois/add_tip: 添加点评
class QWEIBOSDK_EXPORT PlacePoisAddTip : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisAddTip(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/add_tip");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要点评的POI地点ID。
        ("status", "")  //点评时发布的动态内容，必须做URLencode，内容不超过140个汉字。
        ("public", 0)  //是否同步到微博，1：是、0：否，默认为0。
        ;
    }
};
// 2/place/pois/add_todo: 添加todo
class QWEIBOSDK_EXPORT PlacePoisAddTodo : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlacePoisAddTodo(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/pois/add_todo");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要添加todo的POI地点ID。
        ("status", "")  //添加todo时发布的动态内容，必须做URLencode，内容不超过140个汉字。
        ("public", 0)  //是否同步到微博，1：是、0：否，默认为0。
        ;
    }
};
// 2/place/nearby_users/create: 用户添加自己的位置
class QWEIBOSDK_EXPORT PlaceNearbyUsersCreate : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceNearbyUsersCreate(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/nearby_users/create");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经。
        ;
    }
};
// 2/place/nearby_users/destroy: 用户删除自己的位置
class QWEIBOSDK_EXPORT PlaceNearbyUsersDestroy : public BaseRequest
{
    Q_OBJECT
public:
    explicit PlaceNearbyUsersDestroy(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/place/nearby_users/destroy");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ;
    }
};
// 2/location/base/get_map_image: 生成一张静态的地图图片
class QWEIBOSDK_EXPORT LocationBaseGetMapImage : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationBaseGetMapImage(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/base/get_map_image");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("center_coordinate", "")  //中心点坐标，经度纬度用逗号分隔，与城市代码两者必选其一，中心点坐标优先。
        ("city", "")  //城市代码，与中心点坐标两者必选其一，中心点坐标优先。
        ("coordinates", "")  //地图上标点的坐标串，经度纬度用逗号分隔，多个坐标间用“|”分隔，最多不超过10个。示例：coordinates=120.0358,23.1014|116.0358,38.1014。
        ("names", "")  //地图上标点的名称串，多个名称用逗号分隔，最多不超过10个，数量必须与coordinates参数一致，超出的无效。
        ("offset_x", "")  //x轴偏移方向，东移为正，西移为负，偏移单位为1/4图片宽度，示例：offset_x=1，地图向右移动1/4。
        ("offset_y", "")  //y轴偏移方向，北移为正，南移为负，偏移单位为1/4图片高度，示例：offset_y=1，地图向上移动1/4。
        ("font", "")  //字体格式，参数形式为：”字体,字体风格,字号,字体颜色,背景颜色,是否有背景“，其中是否有背景（0：无，1：有），示例：font=宋体,1,20,0XFF0C0C,0XFFFF00,1，默认值为“宋体,1,20,0XFF0CC0,0XFFFFE0,1”，字号最大不超过72号字，如果coordinates参数不存在则font参数无效。
        ("lines", "")  //在地图中画一条线，参数形式为：“线的颜色,线的宽度,线的拐点坐标”，拐点坐标经度纬度用逗号分隔，多个坐标间用“|”分隔，最多不超过10个，示例：lines=0XFF0000,2,116.32,39.96|116.12,39.96，取值范围为：线的宽度0-50。
        ("polygons", "")  //在地图中画一个多边形，参数形式为：“边框颜色,边框宽度,填充颜色,填充透明度,多边形的拐点坐标”，拐点坐标经度纬度用逗号分隔，多个坐标间用“|”分隔，最多不超过10个，示例：polygons=0XFF0000,1,0XFF0000,50,116.32,39.96|116.12,39.96|116.32,39.86，取值范围：边框宽度0-50，默认为1、填充透明度0（透明）-100（不透明），默认为50。
        ("size", "")  //生成的地图大小，格式为宽×高，最大值为800，默认为240，示例：size=480×360，注意：“x”为小写“x”字母，非“＊”号字符。
        ("format", "")  //生成的地图的图片格式，支持png、jpg等格式，参数全部为小写，默认为png。
        ("zoom", "")  //地图焦距等级，取值范围为1-17，默认为自适应大小。
        ("scale", 0)  //是否显示比例尺，true：是，false：否。
        ("traffic", 0)  //是否需要叠加实际交通地图，true：是，false：否。
        ;
    }
};
// 2/location/geo/ip_to_geo: 根据IP地址返回地理信息坐标
class QWEIBOSDK_EXPORT LocationGeoIpToGeo : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationGeoIpToGeo(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/geo/ip_to_geo");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ip", "")  //需要获取坐标的IP地址，多个IP用逗号分隔，最多不超过10个。
        ;
    }
};
// 2/location/geo/address_to_geo: 根据实际地址返回地理信息坐标
class QWEIBOSDK_EXPORT LocationGeoAddressToGeo : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationGeoAddressToGeo(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/geo/address_to_geo");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("address", "")  //需要获取坐标的实际地址，必须进行URLencode。
        ;
    }
};
// 2/location/geo/geo_to_address: 根据地理信息坐标返回实际地址
class QWEIBOSDK_EXPORT LocationGeoGeoToAddress : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationGeoGeoToAddress(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/geo/geo_to_address");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("coordinate", "")  //需要获取实际地址的坐标，经度纬度用逗号分隔。
        ;
    }
};
// 2/location/geo/gps_to_offset: 根据GPS坐标获取偏移后的坐标
class QWEIBOSDK_EXPORT LocationGeoGpsToOffset : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationGeoGpsToOffset(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/geo/gps_to_offset");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("coordinate", "")  //需要获取偏移坐标的源坐标，经度纬度用逗号分隔。
        ;
    }
};
// 2/location/geo/is_domestic: 判断地理信息坐标是否是国内坐标
class QWEIBOSDK_EXPORT LocationGeoIsDomestic : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationGeoIsDomestic(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/geo/is_domestic");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("coordinates", "")  //需要判断的坐标，格式：经度,纬度,字符标识|经度,纬度,字符标识。其中经度纬度用逗号分隔，字符标识用于返回结果中的返回值标识。“|”分隔多个坐标。一次最多50个坐标。示例：coordinates=120.035847163,23.1014362572,g1|116.035847163,38.1014362572,g2。
        ;
    }
};
// 2/location/pois/search/by_location: 根据关键词按地址位置获取POI点的信息
class QWEIBOSDK_EXPORT LocationPoisSearchByLocation : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationPoisSearchByLocation(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/pois/search/by_location");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode，与category参数必选其一。
        ("category", "")  //查询的分类代码，与q参数必选其一，取值范围见：分类代码对应表。
        ("city", "")  //城市代码，默认为全国搜索。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为20。
        ;
    }
};
// 2/location/pois/search/by_geo: 根据关键词按坐标点范围获取POI点的信息
class QWEIBOSDK_EXPORT LocationPoisSearchByGeo : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationPoisSearchByGeo(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/pois/search/by_geo");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode。
        ("coordinate", "")  //查询的中心点坐标，经度纬度用逗号分隔。例：116.322479,39.980781。
        ("cenname", "")  //中心点名称，如：理想国际大厦。
        ("city", "")  //城市编码:支持编码和名称形式，如0010或者北京，需要进行urlencode编码，默认为全国搜索。
        ("range", "")  //查询范围半径，默认为3000。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为200。
        ("searchtype", "")  // 查询类型:POI分类类型，需要进行urlencode编码，如：住宅小区。
        ("srctype", "")  //数据源类型，POI：基础库，BUS：公交站台。可混合查询。例如公交数据+基础库数据查询，srctype取值为“BUS:1000%2bPOI ”，代表前1000条数据为公交数据，后面为基础库数据。
        ("naviflag", 0)  //航距离排序标识， 默认为0，不按照导航距离排序，如果为1将按照导航距离排序，但性能比直线距离排序差。
        ("sr", 0)  //排序参数， sr为1代表按照距离排序。
        ;
    }
};
// 2/location/pois/search/by_area: 根据关键词按矩形区域获取POI点的信息
class QWEIBOSDK_EXPORT LocationPoisSearchByArea : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationPoisSearchByArea(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/pois/search/by_area");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode，与category参数必选其一。
        ("category", "")  //查询的分类代码，与q参数必选其一，取值范围见：分类代码对应表。
        ("coordinates", "")  //查询的矩形区域坐标，第一个坐标为左上角的点，第二个为右下角，经度纬度用逗号分隔，坐标间用“|”分隔，示例：coordinates=116.37,39.93|116.43,39.91。
        ("city", "")  //城市代码，默认为全国搜索。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为20。
        ;
    }
};
// 2/location/pois/show_batch: 批量获取POI点的信息
class QWEIBOSDK_EXPORT LocationPoisShowBatch : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationPoisShowBatch(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/pois/show_batch");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("srcids", "")  //需要获取POI的来源ID，是由用户通过add接口自己提交的，多个ID用逗号分隔，最多不超过5个。
        ;
    }
};
// 2/location/pois/add: 提交一个新增的POI点信息
class QWEIBOSDK_EXPORT LocationPoisAdd : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationPoisAdd(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/pois/add");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("srcid", 0)  //来源ID，用户自己设置，用于取回自己提交的POI信息，为2-8位的数字。
        ("name", "")  //POI点的名称，不超过30个字符，UTF-8编码。
        ("address", "")  //POI点的地址，不超过60个字符，UTF-8编码。
        ("city_name", "")  //POI点的城市中文名称，不超过30个字符，UTF-8编码。
        ("category", "")  //POI点的类别中文名称，不超过30个字符，UTF-8编码。
        ("longitude", "")  //POI点的经度，2-15个字符，在180到-180之间。
        ("latitude", "")  //POI点的维度，2-15个字符，在90到-90之间。
        ("telephone", "")  //POI点的电话，不超过14个字符。
        ("pic_url", "")  //POI点的图片地址，不超过60个字符。
        ("url", "")  //POI点的网址，不超过60个字符。
        ("tags", "")  //POI点的标签，多个标签之间用逗号分隔，不超过60个字符，UTF-8编码。
        ("description", "")  //POI点的介绍，不超过120个字符，UTF-8编码。
        ("intro", "")  //POI点的其他特色信息，不超过120个字符，可以以JSON字符串方式提交，UTF-8编码。
        ("traffic", "")  //POI点的交通情况描述，不超过120个字符，UTF-8编码。
        ;
    }
};
// 2/location/mobile/get_location: 根据移动基站WIFI等数据获取当前位置信息
class QWEIBOSDK_EXPORT LocationMobileGetLocation : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationMobileGetLocation(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/mobile/get_location");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("json", "")  //特殊的JSON参数形式，使用方法如下，见注意事项。
        ;
    }
};
// 2/location/line/drive_route: 根据起点与终点数据查询自驾车路线信息
class QWEIBOSDK_EXPORT LocationLineDriveRoute : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationLineDriveRoute(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/line/drive_route");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("begin_pid", "")  //查询起点POI的ID，与begin_coordinate参数必选其一，begin_pid优先。
        ("begin_coordinate", "")  //查询起点的坐标，经度纬度用逗号分隔，与begin_pid参数必选其一，begin_pid优先。
        ("end_pid", "")  //查询终点POI的ID，与end_coordinate参数必选其一，end_pid优先。
        ("end_coordinate", "")  //查询终点的坐标，经度纬度用逗号分隔，与end_pid参数必选其一，end_pid优先。
        ("type", 0)  //查询类型，0：速度优先、1：费用优先、2：距离优先，默认值为0。
        ;
    }
};
// 2/location/line/bus_route: 根据起点与终点数据查询公交乘坐路线信息
class QWEIBOSDK_EXPORT LocationLineBusRoute : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationLineBusRoute(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/line/bus_route");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("begin_pid", "")  //查询起点POI的ID，与begin_coordinate参数必选其一，begin_pid优先。
        ("begin_coordinate", "")  //查询起点的坐标，经度纬度用逗号分隔，与begin_pid参数必选其一，begin_pid优先。
        ("end_pid", "")  //查询终点POI的ID，与end_coordinate参数必选其一，end_pid优先。
        ("end_coordinate", "")  //查询终点的坐标，经度纬度用逗号分隔，与end_pid参数必选其一，end_pid优先。
        ("type", 0)  //查询类型，0：最快捷、1：最经济、2：最少换乘、3：最少步行、4：最舒适，默认值为0。
        ;
    }
};
// 2/location/line/bus_line: 根据关键词查询公交线路信息
class QWEIBOSDK_EXPORT LocationLineBusLine : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationLineBusLine(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/line/bus_line");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode。
        ("city", "")  //城市代码，默认为北京搜索。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为50。
        ;
    }
};
// 2/location/line/bus_station: 根据关键词查询公交站点信息
class QWEIBOSDK_EXPORT LocationLineBusStation : public BaseRequest
{
    Q_OBJECT
public:
    explicit LocationLineBusStation(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("2/location/line/bus_station");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode。
        ("city", "")  //城市代码，默认为北京搜索。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为50。
        ;
    }
};

// Oauth2/authorize: 请求用户授权Token
class QWEIBOSDK_EXPORT Oauth2Authorize : public BaseRequest
{
    Q_OBJECT
public:
    explicit Oauth2Authorize(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("Oauth2/authorize");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("client_id", "")  //申请应用时分配的AppKey。
        ("redirect_uri", "")  //授权回调地址，站外应用需与设置的回调地址一致，站内应用需填写canvas page的地址。
        ("scope", "")  //申请scope权限所需参数，可一次申请多个scope权限，用逗号分隔。
        ("state", "")  //用于保持请求和回调的状态，在回调时，会在Query Parameter中回传该参数。开发者可以用这个参数验证请求有效性，也可以记录用户请求授权页前的位置。这个参数可用于防止跨站请求伪造（CSRF）攻击
        ("display", "")  //授权页面的终端类型，取值见下面的说明。
        ("forcelogin", 0)  //是否强制用户重新登录，true：是，false：否。默认false。
        ("language", "")  //授权页语言，缺省为中文简体版，en为英文版。英文版测试中，开发者任何意见可反馈至 @微博API
        ;
    }
};
// OAuth2/access_token: 获取授权过的Access Token
class QWEIBOSDK_EXPORT OAuth2AccessToken : public BaseRequest
{
    Q_OBJECT
public:
    explicit OAuth2AccessToken(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("OAuth2/access_token");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("client_id", "")  //申请应用时分配的AppKey。
        ("client_secret", "")  //申请应用时分配的AppSecret。
        ("grant_type", "")  //请求的类型，填写authorization_code
        ;
    }
};
// Oauth2/get_token_info: 查询用户access_token的授权相关信息
class QWEIBOSDK_EXPORT Oauth2GetTokenInfo : public BaseRequest
{
    Q_OBJECT
public:
    explicit Oauth2GetTokenInfo(QObject *parent = 0)
        : BaseRequest(parent){
        setBaseUrl (QString(TOKEN_CHECK_URL));
        setUrlPath ("oauth2/get_token_info", "");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
        ("access_token", "")  //
        ;
    }
};
} //QWeiboSDK
