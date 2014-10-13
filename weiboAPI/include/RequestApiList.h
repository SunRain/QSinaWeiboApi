#ifndef REQUESTAPILIST_H
#define REQUESTAPILIST_H

namespace QSinaWeiboAPI {

//TODO: post and get use different macro
#define REQUEST_API_BEGIN(Class, APIPATH) \
    class QWEIBOAPI_EXPORT Class : public Request \
    { \
    public: \
        Class() {prepare();} \
    protected: \
        void initParameters() { \
            mApiPath = APIPATH; \
            (*this)

#define REQUEST_API_END() \
    ; \
  } \
};

#define REQUEST_API_BEGIN0(Class) \
    class QWEIBOAPI_EXPORT Class : public Request \
    { \
    public: \
        Class(); \
    protected: \
        void initParameters() { \
            (*this)


REQUEST_API_BEGIN0(LoginRequest)
        ("client_id", "sAppKey")
        ("client_secret", "sAppSecret")
        ("grant_type", "password")
        ("username", "mUser")
        ("password", "mPasswd")
REQUEST_API_END()

// 2/statuses/public_timeline: 获取最新的公共微博 
REQUEST_API_BEGIN(statuses_public_timeline, "2/statuses/public_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 20)  //单页返回的记录条数，最大不超过200，默认为20。
REQUEST_API_END()
// 2/statuses/friends_timeline: 获取当前登录用户及其所关注用户的最新微博 
REQUEST_API_BEGIN(statuses_friends_timeline, "2/statuses/friends_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 20)  //单页返回的记录条数，最大不超过100，默认为20。
        ("page", 1)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
REQUEST_API_END()
// 2/statuses/home_timeline: 获取当前登录用户及其所关注用户的最新微博
REQUEST_API_BEGIN(statuses_home_timeline, "2/statuses/home_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 20)  //单页返回的记录条数，最大不超过100，默认为20。
        ("page", 1)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
REQUEST_API_END()
//// 2/statuses/friends_timeline/ids: 获取当前登录用户及其所关注用户的最新微博的ID
//REQUEST_API_BEGIN(statuses_friends_timeline_ids, "2/statuses/friends_timeline/ids")
//REQUEST_API_END()
// 2/statuses/user_timeline: 获取用户发布的微博 
REQUEST_API_BEGIN(statuses_user_timeline, "2/statuses/user_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 20)  //单页返回的记录条数，最大不超过100，超过100以100处理，默认为20。
        ("page", 1)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
REQUEST_API_END()
//// 2/statuses/user_timeline/ids: 获取用户发布的微博的ID
//REQUEST_API_BEGIN(statuses_user_timeline_ids, "2/statuses/user_timeline/ids")
//        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
//        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
//        ("uid", 0)  //需要查询的用户ID。
//        ("screen_name", "")  //需要查询的用户昵称。
//        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
//        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
//        ("count", 20)  //单页返回的记录条数，最大不超过100，默认为20。
//        ("page", 1)  //返回结果的页码，默认为1。
//        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
//        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
//REQUEST_API_END()
// 2/statuses/timeline_batch: 批量获取指定的一批用户的微博列表  
REQUEST_API_BEGIN(statuses_timeline_batch, "2/statuses/timeline_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uids", "")  //需要查询的用户ID，用半角逗号分隔，一次最多20个。
        ("screen_names", "")  //需要查询的用户昵称，用半角逗号分隔，一次最多20个。
        ("count", 20)  //单页返回的记录条数，默认为20。
        ("page", 1)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
REQUEST_API_END()
// 2/statuses/repost_timeline: 返回一条原创微博的最新转发微博 
REQUEST_API_BEGIN(statuses_repost_timeline, "2/statuses/repost_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的微博ID。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 20)  //单页返回的记录条数，最大不超过200，默认为20。
        ("page", 1)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
REQUEST_API_END()
//// 2/statuses/repost_timeline/ids: 获取一条原创微博的最新转发微博的ID
//REQUEST_API_BEGIN(statuses_repost_timeline_ids, "2/statuses/repost_timeline/ids")
//        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
//        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
//        ("id", 0)  //需要查询的微博ID。
//        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
//        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
//        ("count", 0)  //单页返回的记录条数，最大不超过200，默认为20。
//        ("page", 0)  //返回结果的页码，默认为1。
//        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
//REQUEST_API_END()
// 2/statuses/mentions: 获取@当前用户的最新微博 
REQUEST_API_BEGIN(statuses_mentions, "2/statuses/mentions")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 20)  //单页返回的记录条数，最大不超过200，默认为20。
        ("page", 1)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博、2：来自微群，默认为0。
        ("filter_by_type", 0)  //原创筛选类型，0：全部微博、1：原创的微博，默认为0。
REQUEST_API_END()
// 2/statuses/mentions/ids: 获取@当前用户的最新微博的ID  
REQUEST_API_BEGIN(statuses_mentions_ids, "2/statuses/mentions/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过200，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博、2：来自微群，默认为0。
        ("filter_by_type", 0)  //原创筛选类型，0：全部微博、1：原创的微博，默认为0。
REQUEST_API_END()

// 2/statuses/show: 根据ID获取单条微博信息 
REQUEST_API_BEGIN(statuses_show, "2/statuses/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要获取的微博ID。
REQUEST_API_END()
// 2/statuses/show_batch: 根据微博ID批量获取微博信息  
REQUEST_API_BEGIN(statuses_show_batch, "2/statuses/show_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ids", "")  //需要查询的微博ID，用半角逗号分隔，最多不超过50个。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
REQUEST_API_END()
// 2/statuses/querymid: 通过id获取mid 
REQUEST_API_BEGIN(statuses_querymid, "2/statuses/querymid")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的微博（评论、私信）ID，批量模式下，用半角逗号分隔，最多不超过20个。
        ("type", 1)  //获取类型，1：微博、2：评论、3：私信，默认为1。
        ("is_batch", 0)  //是否使用批量模式，0：否、1：是，默认为0。
REQUEST_API_END()
// 2/statuses/queryid: 通过mid获取id 
REQUEST_API_BEGIN(statuses_queryid, "2/statuses/queryid")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("mid", "")  //需要查询的微博（评论、私信）MID，批量模式下，用半角逗号分隔，最多不超过20个。
        ("type", 1)  //获取类型，1：微博、2：评论、3：私信，默认为1。
        ("is_batch", 0)  //是否使用批量模式，0：否、1：是，默认为0。
        ("inbox", 0)  //仅对私信有效，当MID类型为私信时用此参数，0：发件箱、1：收件箱，默认为0 。
        ("isBase62", 0)  //MID是否是base62编码，0：否、1：是，默认为0。
REQUEST_API_END()
// 2/statuses/count: 批量获取指定微博的转发数评论数 
REQUEST_API_BEGIN(statuses_count, "2/statuses/count")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ids", "")  //需要获取数据的微博ID，多个之间用逗号分隔，最多不超过100个。
REQUEST_API_END()

///2/statuses/to_me: 获取当前登录用户关注的人发给其的定向微博
///高级新接口
REQUEST_API_BEGIN(statuses_to_me, "2/statuses/to_me")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("page", 1)  //返回结果的页码，默认为1。
        ("count", 20)  //返回结果的条数数量，最大不超过200，默认为20。
        ("trim_user", 0) //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回uid，默认为0
REQUEST_API_END()
/// 2/statuses/to_me/ids: 获取当前登录用户关注的人发给其的定向微博ID列表
///高级新接口
REQUEST_API_BEGIN(statuses_to_me_ids, "2/statuses/to_me/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("page", 0)  //返回结果的页码，默认为1。
        ("count", 0)  //返回结果的条数数量，最大不超过200，默认为20。
REQUEST_API_END()
// 2/statuses/go: 根据ID跳转到单条微博页 
REQUEST_API_BEGIN(statuses_go, "2/statuses/go")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要跳转的用户ID。
        ("id", 0)  //需要跳转的微博ID。
REQUEST_API_END()
// 2/emotions: 获取官方表情 
REQUEST_API_BEGIN(emotions, "2/emotions")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("type", "face")  //表情类别，face：普通表情、ani：魔法表情、cartoon：动漫表情，默认为face。
        ("language", "cnname")  //语言类别，cnname：简体、twname：繁体，默认为cnname。
REQUEST_API_END()
// 2/statuses/repost: 转发一条微博信息 
REQUEST_API_BEGIN(statuses_repost, "2/statuses/repost")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //要转发的微博ID。
        ("status", "")  //添加的转发文本，必须做URLencode，内容不超过140个汉字，不填则默认为“转发微博”。
        ("is_comment", 0)  //是否在转发的同时发表评论，0：否、1：评论给当前微博、2：评论给原微博、3：都评论，默认为0 。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
REQUEST_API_END()
// 2/statuses/destroy: 删除微博信息 
REQUEST_API_BEGIN(statuses_destroy, "2/statuses/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要删除的微博ID。
REQUEST_API_END()
// 2/statuses/update: 发布一条微博信息  
REQUEST_API_BEGIN(statuses_update, "2/statuses/update")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("status", "")  //要发布的微博文本内容，必须做URLencode，内容不超过140个汉字。
        ("visible", 0)  //微博的可见性，0：所有人能看，1：仅自己可见，2：密友可见，3：指定分组可见，默认为0。
        ("list_id", "")  //微博的保护投递指定分组ID，只有当visible参数为3时生效且必选。
        ("lat", 0.0)  //纬度，有效范围：-90.0到+90.0，+表示北纬，默认为0.0。
        ("long", 0.0)  //经度，有效范围：-180.0到+180.0，+表示东经，默认为0.0。
        ("annotations", "")  //元数据，主要是为了方便第三方应用记录一些适合于自己使用的信息，每条微博可以包含一个或者多个元数据，必须以json字串的形式提交，字串长度不超过512个字符，具体内容可以自定。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
REQUEST_API_END()
// 2/statuses/upload: 上传图片并发布一条微博  
REQUEST_API_BEGIN(statuses_upload, "2/statuses/upload")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("status", "")  //要发布的微博文本内容，必须做URLencode，内容不超过140个汉字。
        ("visible", 0)  //微博的可见性，0：所有人能看，1：仅自己可见，2：密友可见，3：指定分组可见，默认为0。
        ("list_id", "")  //微博的保护投递指定分组ID，只有当visible参数为3时生效且必选。
        ("pic", 0)  //要上传的图片，仅支持JPEG、GIF、PNG格式，图片大小小于5M。
        ("lat", 0.0)  //纬度，有效范围：-90.0到+90.0，+表示北纬，默认为0.0。
        ("long", 0.0)  //经度，有效范围：-180.0到+180.0，+表示东经，默认为0.0。
        ("annotations", "")  //元数据，主要是为了方便第三方应用记录一些适合于自己使用的信息，每条微博可以包含一个或者多个元数据，必须以json字串的形式提交，字串长度不超过512个字符，具体内容可以自定。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
REQUEST_API_END()
// 2/statuses/upload_url_text: 发布一条微博同时指定上传的图片或图片url  
REQUEST_API_BEGIN(statuses_upload_url_text, "2/statuses/upload_url_text")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("status", "")  //要发布的微博文本内容，必须做URLencode，内容不超过140个汉字。
        ("visible", 0)  //微博的可见性，0：所有人能看，1：仅自己可见，2：密友可见，3：指定分组可见，默认为0。
        ("list_id", "")  //微博的保护投递指定分组ID，只有当visible参数为3时生效且必选。
        ("url", "")  //图片的URL地址，必须以http开头。
        ("pic_id", "")  //已经上传的图片pid，多个时使用英文半角逗号符分隔，最多不超过9个。
        ("lat", 0.0)  //纬度，有效范围：-90.0到+90.0，+表示北纬，默认为0.0。
        ("long", 0.0)  //经度，有效范围：-180.0到+180.0，+表示东经，默认为0.0。
        ("annotations", "")  //元数据，主要是为了方便第三方应用记录一些适合于自己使用的信息，每条微博可以包含一个或者多个元数据，必须以json字串的形式提交，字串长度不超过512个字符，具体内容可以自定。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
REQUEST_API_END()
// 2/statuses/filter/create: 屏蔽某条微博  
//REQUEST_API_BEGIN(statuses_filter_create, "2/statuses/filter/create")
//        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
//        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
//        ("id", 0)  //微博id。
//REQUEST_API_END()
// 2/statuses/mentions/shield: 屏蔽某个@我的微博及后续由其转发引起的@提及  
//REQUEST_API_BEGIN(statuses_mentions_shield, "2/statuses/mentions/shield")
//        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
//        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
//        ("id", 0)  //需要屏蔽的@提到我的微博ID。此ID必须在statuses/mentions列表中。
//        ("follow_up", 0)  //是否仅屏蔽当前微博。0：仅屏蔽当前@提到我的微博；1：屏蔽当前@提到我的微博，以及后续对其转发而引起的@提到我的微博。默认1。
//REQUEST_API_END()

//////////////////////////////////////////////////////////////////////////////////////////////////////////

// 2/comments/show: 获取某条微博的评论列表 
REQUEST_API_BEGIN(comments_show, "2/comments/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的微博ID。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 50)  //单页返回的记录条数，默认为50。
        ("page", 1)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
REQUEST_API_END()
// 2/comments/by_me: 我发出的评论列表 
REQUEST_API_BEGIN(comments_by_me, "2/comments/by_me")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 50)  //单页返回的记录条数，默认为50。
        ("page", 1)  //返回结果的页码，默认为1。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博的评论、2：来自微群的评论，默认为0。
REQUEST_API_END()
// 2/comments/to_me: 我收到的评论列表 
REQUEST_API_BEGIN(comments_to_me, "2/comments/to_me")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 50)  //单页返回的记录条数，默认为50。
        ("page", 1)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博的评论、2：来自微群的评论，默认为0。
REQUEST_API_END()
// 2/comments/timeline: 获取用户发送及收到的评论列表 
REQUEST_API_BEGIN(comments_timeline, "2/comments/timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 50)  //单页返回的记录条数，默认为50。
        ("page", 1)  //返回结果的页码，默认为1。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
REQUEST_API_END()
// 2/comments/mentions: 获取@到我的评论 
REQUEST_API_BEGIN(comments_mentions, "2/comments/mentions")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 50)  //单页返回的记录条数，默认为50。
        ("page", 1)  //返回结果的页码，默认为1。
        ("filter_by_author", 0)  //作者筛选类型，0：全部、1：我关注的人、2：陌生人，默认为0。
        ("filter_by_source", 0)  //来源筛选类型，0：全部、1：来自微博的评论、2：来自微群的评论，默认为0。
REQUEST_API_END()
// 2/comments/show_batch: 批量获取评论内容 
REQUEST_API_BEGIN(comments_show_batch, "2/comments/show_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("cids", 0)  //需要查询的批量评论ID，用半角逗号分隔，最大50。
REQUEST_API_END()

///////////////////////////////////////////////////

// 2/comments/create: 评论一条微博 
REQUEST_API_BEGIN(comments_create, "2/comments/create")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("comment", "")  //评论内容，必须做URLencode，内容不超过140个汉字。
        ("id", 0)  //需要评论的微博ID。
        ("comment_ori", 0)  //当评论转发微博时，是否评论给原微博，0：否、1：是，默认为0。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
REQUEST_API_END()
// 2/comments/destroy: 删除一条评论 
REQUEST_API_BEGIN(comments_destroy, "2/comments/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("cid", 0)  //要删除的评论ID，只能删除登录用户自己发布的评论。
REQUEST_API_END()
// 2/comments/destroy_batch: 批量删除评论 
REQUEST_API_BEGIN(comments_destroy_batch, "2/comments/destroy_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("cids", 0)  //需要删除的评论ID，用半角逗号隔开，最多20个。
REQUEST_API_END()
// 2/comments/reply: 回复一条评论 
REQUEST_API_BEGIN(comments_reply, "2/comments/reply")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("cid", 0)  //需要回复的评论ID。
        ("id", 0)  //需要评论的微博ID。
        ("comment", "")  //回复评论内容，必须做URLencode，内容不超过140个汉字。
        ("without_mention", 0)  //回复中是否自动加入“回复@用户名”，0：是、1：否，默认为0。
        ("comment_ori", 0)  //当评论转发微博时，是否评论给原微博，0：否、1：是，默认为0。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
REQUEST_API_END()
// 2/users/show: 获取用户信息  
REQUEST_API_BEGIN(users_show, "2/users/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("screen_name", "")  //需要查询的用户昵称。
REQUEST_API_END()
// 2/users/domain_show: 通过个性域名获取用户信息 
REQUEST_API_BEGIN(users_domain_show, "2/users/domain_show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("domain", "")  //需要查询的个性化域名。
REQUEST_API_END()
// 2/users/counts: 批量获取用户的粉丝数、关注数、微博数 
REQUEST_API_BEGIN(users_counts, "2/users/counts")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uids", "")  //需要获取数据的用户UID，多个之间用逗号分隔，最多不超过100个。
REQUEST_API_END()
// 2/users/get_top_status: 获取用户主页置顶微博  
REQUEST_API_BEGIN(users_get_top_status, "2/users/get_top_status")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
REQUEST_API_END()
// 2/users/set_top_status: 设置用户主页置顶微博  
REQUEST_API_BEGIN(users_set_top_status, "2/users/set_top_status")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要设置为置顶微博的微博ID。
REQUEST_API_END()
// 2/users/cancel_top_status: 取消用户主页置顶微博  
REQUEST_API_BEGIN(users_cancel_top_status, "2/users/cancel_top_status")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要取消设置为置顶微博的微博ID。
REQUEST_API_END()
// 2/friendships/friends: 获取用户的关注列表 
REQUEST_API_BEGIN(friendships_friends, "2/friendships/friends")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("count", 0)  //单页返回的记录条数，默认为50，最大不超过200。
        ("cursor", 0)  //返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
        ("trim_status", 0)  //返回值中user字段中的status字段开关，0：返回完整status字段、1：status字段仅返回status_id，默认为1。
REQUEST_API_END()
// 2/friendships/friends/remark_batch: 批量获取当前登录用户的关注人的备注信息  
REQUEST_API_BEGIN(friendships_friends_remark_batch, "2/friendships/friends/remark_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uids", "")  //需要获取备注的用户UID，用半角逗号分隔，最多不超过50个。
REQUEST_API_END()
// 2/friendships/friends/in_common: 获取共同关注人列表 
REQUEST_API_BEGIN(friendships_friends_in_common, "2/friendships/friends/in_common")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要获取共同关注关系的用户UID。
        ("suid", 0)  //需要获取共同关注关系的用户UID，默认为当前登录用户。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("trim_status", 0)  //返回值中user字段中的status字段开关，0：返回完整status字段、1：status字段仅返回status_id，默认为1。
REQUEST_API_END()
// 2/friendships/friends/bilateral: 获取双向关注列表 
REQUEST_API_BEGIN(friendships_friends_bilateral, "2/friendships/friends/bilateral")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要获取双向关注列表的用户UID。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序类型，0：按关注时间最近排序，默认为0。
REQUEST_API_END()
// 2/friendships/friends/bilateral/ids: 获取双向关注UID列表 
REQUEST_API_BEGIN(friendships_friends_bilateral_ids, "2/friendships/friends/bilateral/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要获取双向关注列表的用户UID。
        ("count", 0)  //单页返回的记录条数，默认为50，最大不超过2000。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序类型，0：按关注时间最近排序，默认为0。
REQUEST_API_END()
// 2/friendships/friends/ids: 获取用户关注对象UID列表 
REQUEST_API_BEGIN(friendships_friends_ids, "2/friendships/friends/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("count", 0)  //单页返回的记录条数，默认为500，最大不超过5000。
        ("cursor", 0)  //返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
REQUEST_API_END()
// 2/friendships/followers: 获取用户粉丝列表 
REQUEST_API_BEGIN(friendships_followers, "2/friendships/followers")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("count", 0)  //单页返回的记录条数，默认为50，最大不超过200。
        ("cursor", 0)  //返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
        ("trim_status", 0)  //返回值中user字段中的status字段开关，0：返回完整status字段、1：status字段仅返回status_id，默认为1。
REQUEST_API_END()
// 2/friendships/followers/ids: 获取用户粉丝UID列表 
REQUEST_API_BEGIN(friendships_followers_ids, "2/friendships/followers/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("screen_name", "")  //需要查询的用户昵称。
        ("count", 0)  //单页返回的记录条数，默认为500，最大不超过5000。
        ("cursor", 0)  //返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
REQUEST_API_END()
// 2/friendships/followers/active: 获取用户优质粉丝列表 
REQUEST_API_BEGIN(friendships_followers_active, "2/friendships/followers/active")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户UID。
        ("count", 0)  //返回的记录条数，默认为20，最大不超过200。
REQUEST_API_END()
// 2/friendships/friends_chain/followers: 获取我的关注人中关注了指定用户的人 
REQUEST_API_BEGIN(friendships_friends_chain_followers, "2/friendships/friends_chain/followers")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //指定的关注目标用户UID。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/friendships/show: 获取两个用户关系的详细情况 
REQUEST_API_BEGIN(friendships_show, "2/friendships/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("source_id", 0)  //源用户的UID。
        ("source_screen_name", "")  //源用户的微博昵称。
        ("target_id", 0)  //目标用户的UID。
        ("target_screen_name", "")  //目标用户的微博昵称。
REQUEST_API_END()
// 2/friendships/create: 关注某用户 
REQUEST_API_BEGIN(friendships_create, "2/friendships/create")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要关注的用户ID。
        ("screen_name", "")  //需要关注的用户昵称。
        ("rip", "")  //开发者上报的操作用户真实IP，形如：211.156.0.1。
REQUEST_API_END()
// 2/friendships/destroy: 取消关注某用户 
REQUEST_API_BEGIN(friendships_destroy, "2/friendships/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要取消关注的用户ID。
        ("screen_name", "")  //需要取消关注的用户昵称。
REQUEST_API_END()
// 2/friendships/followers/destroy: 移除当前登录用户的粉丝  
REQUEST_API_BEGIN(friendships_followers_destroy, "2/friendships/followers/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要移除的粉丝用户的UID。
REQUEST_API_END()
// 2/friendships/remark/update: 更新关注人备注  
REQUEST_API_BEGIN(friendships_remark_update, "2/friendships/remark/update")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要修改备注信息的用户UID。
        ("remark", "")  //备注信息，需要URLencode。
REQUEST_API_END()
// 2/friendships/groups: 获取当前登陆用户好友分组列表  
REQUEST_API_BEGIN(friendships_groups, "2/friendships/groups")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
REQUEST_API_END()
// 2/friendships/groups/timeline: 获取某一好友分组的微博列表  
REQUEST_API_BEGIN(friendships_groups_timeline, "2/friendships/groups/timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //需要查询的好友分组ID，建议使用返回值里的idstr，当查询的为私有分组时，则当前登录用户必须为其所有者。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过200，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
REQUEST_API_END()
// 2/friendships/groups/timeline/ids: 获取某一好友分组的微博ID列表  
REQUEST_API_BEGIN(friendships_groups_timeline_ids, "2/friendships/groups/timeline/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //需要查询的好友分组ID，建议使用返回值里的idstr，当查询的为私有分组时，则当前登录用户必须为其所有者。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，，最大不超过200，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
REQUEST_API_END()
// 2/friendships/groups/members: 获取某一好友分组下的成员列表  
REQUEST_API_BEGIN(friendships_groups_members, "2/friendships/groups/members")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //好友分组ID，建议使用返回值里的idstr。
        ("count", 0)  //单页返回的记录条数，默认为50，最大不超过200。
        ("cursor", 0)  //分页返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
REQUEST_API_END()
// 2/friendships/groups/members/ids: 获取某一好友分组下的成员列表的ID  
REQUEST_API_BEGIN(friendships_groups_members_ids, "2/friendships/groups/members/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //好友分组ID，建议使用返回值里的idstr。
        ("count", 0)  //单页返回的记录条数，默认为50，最大不超过200。
        ("cursor", 0)  //分页返回结果的游标，下一页用返回值里的next_cursor，上一页用previous_cursor，默认为0。
REQUEST_API_END()
// 2/friendships/groups/members/description: 批量取好友分组成员的分组说明  
REQUEST_API_BEGIN(friendships_groups_members_description, "2/friendships/groups/members/description")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uids", "")  //需要查询的好友分组成员用户UID，多个之间用逗号分隔，最多不超过100个。
        ("list_id", 0)  //指定成员所在的好友分组ID，建议使用返回值里的idstr。
REQUEST_API_END()
// 2/friendships/groups/is_member: 判断某个用户是否是指定好友分组内的成员  
REQUEST_API_BEGIN(friendships_groups_is_member, "2/friendships/groups/is_member")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要判断的用户的UID。
        ("list_id", 0)  //指定的当前用户的好友分组ID，建议使用返回值里的idstr。
REQUEST_API_END()
// 2/friendships/groups/listed: 批量获取某些用户在指定用户的好友分组中的收录信息  
REQUEST_API_BEGIN(friendships_groups_listed, "2/friendships/groups/listed")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uids", "")  //需要获取好友分组信息的用户UID列表，多个之间用逗号分隔，每次不超过50个。
REQUEST_API_END()
// 2/friendships/groups/show: 获取某个分组的详细信息  
REQUEST_API_BEGIN(friendships_groups_show, "2/friendships/groups/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //需要查询的好友分组ID，建议使用返回值里的idstr。
REQUEST_API_END()
// 2/friendships/groups/show_batch: 批量获取好友分组的详细信息  
REQUEST_API_BEGIN(friendships_groups_show_batch, "2/friendships/groups/show_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_ids", 0)  //需要查询的好友分组ID，建议使用返回值里的idstr，多个之间用逗号分隔，每次不超过20个。
        ("uids", "")  //参数list_ids所指的好友分组的所有者UID，多个之间用逗号分隔，每次不超过20个，需与list_ids一一对应。
REQUEST_API_END()
// 2/friendships/groups/create: 创建好友分组  
REQUEST_API_BEGIN(friendships_groups_create, "2/friendships/groups/create")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("name", "")  //要创建的好友分组的名称，不超过10个汉字，20个半角字符。
        ("description", "")  //要创建的好友分组的描述，不超过70个汉字，140个半角字符。
        ("tags", "")  //要创建的好友分组的标签，多个之间用逗号分隔，最多不超过10个，每个不超过7个汉字，14个半角字符。
REQUEST_API_END()
// 2/friendships/groups/update: 更新好友分组  
REQUEST_API_BEGIN(friendships_groups_update, "2/friendships/groups/update")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //需要更新的好友分组ID，建议使用返回值里的idstr，只能更新当前登录用户自己创建的分组。
        ("name", "")  //好友分组更新后的名称，不超过8个汉字，16个半角字符。
        ("description", "")  //好友分组更新后的描述，不超过70个汉字，140个半角字符。
        ("tags", "")  //好友分组更新后的标签，多个之间用逗号分隔，最多不超过10个，每个不超过7个汉字，14个半角字符。
REQUEST_API_END()
// 2/friendships/groups/destroy: 删除好友分组  
REQUEST_API_BEGIN(friendships_groups_destroy, "2/friendships/groups/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //要删除的好友分组ID，建议使用返回值里的idstr。
REQUEST_API_END()
// 2/friendships/groups/members/add: 添加关注用户到好友分组  
REQUEST_API_BEGIN(friendships_groups_members_add, "2/friendships/groups/members/add")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要添加的用户的UID。
        ("list_id", 0)  //好友分组ID，建议使用返回值里的idstr。
REQUEST_API_END()
// 2/friendships/groups/members/add_batch: 批量添加用户到好友分组  
REQUEST_API_BEGIN(friendships_groups_members_add_batch, "2/friendships/groups/members/add_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //好友分组ID，建议使用返回值里的idstr。
        ("uids", "")  //需要添加的用户的UID，多个之间用逗号分隔，最多不超过30个。
        ("group_descriptions", "")  //添加成员的分组说明，每个说明最多8个汉字，16个半角字符，多个需先URLencode，然后再用半角逗号分隔，最多不超过30个，且需与uids参数一一对应。
REQUEST_API_END()
// 2/friendships/groups/members/update: 更新好友分组中成员的分组说明  
REQUEST_API_BEGIN(friendships_groups_members_update, "2/friendships/groups/members/update")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_id", 0)  //好友分组ID，建议使用返回值里的idstr。
        ("uid", 0)  //需要更新分组成员说明的用户的UID。
        ("group_description", "")  //需要更新的分组成员说明，每个说明最多8个汉字，16个半角字符，需要URLencode。
REQUEST_API_END()
// 2/friendships/groups/members/destroy: 删除好友分组内的关注用户  
REQUEST_API_BEGIN(friendships_groups_members_destroy, "2/friendships/groups/members/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要删除的用户的UID。
        ("list_id", 0)  //好友分组ID，建议使用返回值里的idstr。
REQUEST_API_END()
// 2/friendships/groups/order: 调整当前登录用户的好友分组顺序  
REQUEST_API_BEGIN(friendships_groups_order, "2/friendships/groups/order")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("list_ids", "")  //调整好顺序后的分组ID列表，以逗号分隔，例：57,38，表示57排第一、38排第二，以此类推。
        ("count", 0)  //好友分组数量，必须与用户所有的分组数一致、与分组ID的list_id个数一致。
REQUEST_API_END()
// 2/account/get_privacy: 获取隐私设置信息 
REQUEST_API_BEGIN(account_get_privacy, "2/account/get_privacy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
REQUEST_API_END()
// 2/account/profile/school_list: 获取所有学校列表 
REQUEST_API_BEGIN(account_profile_school_list, "2/account/profile/school_list")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("province", 0)  //省份范围，省份ID。
        ("city", 0)  //城市范围，城市ID。
        ("area", 0)  //区域范围，区ID。
        ("type", 0)  //学校类型，1：大学、2：高中、3：中专技校、4：初中、5：小学，默认为1。
        ("capital", "")  //学校首字母，默认为A。
        ("keyword", "")  //学校名称关键字。
        ("count", 0)  //返回的记录条数，默认为10。
REQUEST_API_END()
// 2/account/rate_limit_status: 获取当前用户API访问频率限制 
REQUEST_API_BEGIN(account_rate_limit_status, "2/account/rate_limit_status")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
REQUEST_API_END()
// 2/account/profile/email: 获取用户的联系邮箱 
REQUEST_API_BEGIN(account_profile_email, "2/account/profile/email")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
REQUEST_API_END()
// 2/account/get_uid: OAuth授权之后获取用户UID（作用相当于旧版接口的  
REQUEST_API_BEGIN(account_get_uid, "2/account/get_uid")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
REQUEST_API_END()
// 2/account/end_session: 退出登录 
REQUEST_API_BEGIN(account_end_session, "2/account/end_session")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
REQUEST_API_END()
// 2/favorites: 获取当前用户的收藏列表 
REQUEST_API_BEGIN(favorites, "2/favorites")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/favorites/ids: 获取当前用户的收藏列表的ID  
REQUEST_API_BEGIN(favorites_ids, "2/favorites/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/favorites/show: 获取单条收藏信息 
REQUEST_API_BEGIN(favorites_show, "2/favorites/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要查询的收藏ID。
REQUEST_API_END()
// 2/favorites/by_tags: 获取当前用户某个标签下的收藏列表 
REQUEST_API_BEGIN(favorites_by_tags, "2/favorites/by_tags")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tid", 0)  //需要查询的标签ID。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/favorites/tags: 当前登录用户的收藏标签列表 
REQUEST_API_BEGIN(favorites_tags, "2/favorites/tags")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //单页返回的记录条数，默认为10。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/favorites/by_tags/ids: 获取当前用户某个标签下的收藏列表的ID  
REQUEST_API_BEGIN(favorites_by_tags_ids, "2/favorites/by_tags/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tid", 0)  //需要查询的标签ID。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/favorites/create: 添加收藏 
REQUEST_API_BEGIN(favorites_create, "2/favorites/create")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //要收藏的微博ID。
REQUEST_API_END()
// 2/favorites/destroy: 删除收藏 
REQUEST_API_BEGIN(favorites_destroy, "2/favorites/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //要取消收藏的微博ID。
REQUEST_API_END()
// 2/favorites/destroy_batch: 批量删除收藏 
REQUEST_API_BEGIN(favorites_destroy_batch, "2/favorites/destroy_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ids", "")  //要取消收藏的收藏ID，用半角逗号分隔，最多不超过10个。
REQUEST_API_END()
// 2/favorites/tags/update: 更新收藏标签 
REQUEST_API_BEGIN(favorites_tags_update, "2/favorites/tags/update")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要更新的收藏ID。
        ("tags", "")  //需要更新的标签内容，必须做URLencode，用半角逗号分隔，最多不超过2条。
REQUEST_API_END()
// 2/favorites/tags/update_batch: 更新当前用户所有收藏下的指定标签 
REQUEST_API_BEGIN(favorites_tags_update_batch, "2/favorites/tags/update_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tid", 0)  //需要更新的标签ID。
        ("tag", "")  //需要更新的标签内容，必须做URLencode。
REQUEST_API_END()
// 2/favorites/tags/destroy_batch: 删除当前用户所有收藏下的指定标签 
REQUEST_API_BEGIN(favorites_tags_destroy_batch, "2/favorites/tags/destroy_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tid", 0)  //需要删除的标签ID。
REQUEST_API_END()
// 2/trends/hourly: 返回最近一小时内的热门话题 
REQUEST_API_BEGIN(trends_hourly, "2/trends/hourly")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/trends/daily: 返回最近一天内的热门话题 
REQUEST_API_BEGIN(trends_daily, "2/trends/daily")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/trends/weekly: 返回最近一周内的热门话题 
REQUEST_API_BEGIN(trends_weekly, "2/trends/weekly")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/statuses/tags: 获取用户的微博标签列表  
REQUEST_API_BEGIN(statuses_tags, "2/statuses/tags")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //返回结果的条数数量，最大不超过200，默认为20。
REQUEST_API_END()
// 2/statuses/tags/show_batch: 批量获取微博标签  
REQUEST_API_BEGIN(statuses_tags_show_batch, "2/statuses/tags/show_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ids", 0)  //根据指定id返回微博的相应标签信息。一次最多传入50个id，英文逗号分隔。
REQUEST_API_END()
// 2/statuses/tag_timeline/ids: 获取用户某个标签的微博ID列表  
REQUEST_API_BEGIN(statuses_tag_timeline_ids, "2/statuses/tag_timeline/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tag", "")  //要获取的标签。
        ("since_id", 0)  //若指定此参数，则只返回ID比since_id大的微博消息（即比since_id发表时间晚的微博消息），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博消息，默认为0。
        ("count", 0)  //返回结果的条数数量，最大不超过200，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/statuses/tags/create: 创建标签  
REQUEST_API_BEGIN(statuses_tags_create, "2/statuses/tags/create")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tag", "")  //要创建标签名字。长度不可超过7个汉字，14个半角字符，不能包含空格。
REQUEST_API_END()
// 2/statuses/tags/destroy: 删除标签  
REQUEST_API_BEGIN(statuses_tags_destroy, "2/statuses/tags/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tag", "")  //要删除的标签名字。
REQUEST_API_END()
// 2/statuses/tags/update: 更新标签  
REQUEST_API_BEGIN(statuses_tags_update, "2/statuses/tags/update")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("old_tag", "")  //用户微博的旧标签。
        ("new_tag", "")  //用户微博的新标签。长度不可超过7个汉字，14个半角字符，不能包含空格。
REQUEST_API_END()
// 2/statuses/update_tags: 更新某个微博的标签  
REQUEST_API_BEGIN(statuses_update_tags, "2/statuses/update_tags")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //微博ID。
        ("tags", "")  //需要修改成的标签内容.必须URLEncode，UTF-8编码。最多5条，逗号分隔。
REQUEST_API_END()
// 2/tags: 返回指定用户的标签列表 
REQUEST_API_BEGIN(tags, "2/tags")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //要获取的标签列表所属的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/tags/tags_batch: 批量获取用户标签 
REQUEST_API_BEGIN(tags_tags_batch, "2/tags/tags_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uids", "")  //要获取标签的用户ID。最大20，逗号分隔。
REQUEST_API_END()
// 2/tags/suggestions: 返回系统推荐的标签列表 
REQUEST_API_BEGIN(tags_suggestions, "2/tags/suggestions")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //返回记录数，默认10，最大10。
REQUEST_API_END()
// 2/tags/create: 添加用户标签 
REQUEST_API_BEGIN(tags_create, "2/tags/create")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tags", "")  //要创建的一组标签，用半角逗号隔开，每个标签的长度不可超过7个汉字，14个半角字符。
REQUEST_API_END()
// 2/tags/destroy: 删除用户标签 
REQUEST_API_BEGIN(tags_destroy, "2/tags/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("tag_id", 0)  //要删除的标签ID。
REQUEST_API_END()
// 2/tags/destroy_batch: 批量删除用户标签 
REQUEST_API_BEGIN(tags_destroy_batch, "2/tags/destroy_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ids", "")  //要删除的一组标签ID，以半角逗号隔开，一次最多提交10个ID。
REQUEST_API_END()
// 2/register/verify_nickname: 验证昵称是否可用 
REQUEST_API_BEGIN(register_verify_nickname, "2/register/verify_nickname")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("nickname", "")  //需要验证的昵称。4-20个字符，支持中英文、数字、"_"或减号。必须做URLEncode，采用UTF-8编码。
REQUEST_API_END()
// 2/search/suggestions/users: 搜用户搜索建议 
REQUEST_API_BEGIN(search_suggestions_users, "2/search/suggestions/users")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10。
REQUEST_API_END()
// 2/search/suggestions/schools: 搜学校搜索建议 
REQUEST_API_BEGIN(search_suggestions_schools, "2/search/suggestions/schools")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10。
        ("type", 0)  //学校类型，0：全部、1：大学、2：高中、3：中专技校、4：初中、5：小学，默认为0。
REQUEST_API_END()
// 2/search/suggestions/companies: 搜公司搜索建议 
REQUEST_API_BEGIN(search_suggestions_companies, "2/search/suggestions/companies")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10。
REQUEST_API_END()
// 2/search/suggestions/apps: 搜应用搜索建议 
REQUEST_API_BEGIN(search_suggestions_apps, "2/search/suggestions/apps")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10。
REQUEST_API_END()
// 2/search/suggestions/at_users: @联想搜索 
REQUEST_API_BEGIN(search_suggestions_at_users, "2/search/suggestions/at_users")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的关键字，必须做URLencoding。
        ("count", 0)  //返回的记录条数，默认为10，粉丝最多1000，关注最多2000。
        ("type", 0)  //联想类型，0：关注、1：粉丝。
        ("range", 0)  //联想范围，0：只联想关注人、1：只联想关注人的备注、2：全部，默认为2。
REQUEST_API_END()
// 2/search/topics: 搜索某一话题下的微博  
REQUEST_API_BEGIN(search_topics, "2/search/topics")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //搜索的话题关键字，必须进行URLencode，utf-8编码。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/suggestions/users/hot: 获取系统推荐用户 
REQUEST_API_BEGIN(suggestions_users_hot, "2/suggestions/users/hot")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("category", "")  //推荐分类，返回某一类别的推荐用户，默认为default，如果不在以下分类中，返回空列表，default：人气关注、ent：影视名星、music：音乐、sports：体育、fashion：时尚、art：艺术、cartoon：动漫、games：游戏、trip：旅行、food：美食、health：健康、literature：文学、stock：炒股、business：商界、tech：科技、house：房产、auto：汽车、fate：命理、govern：政府、medium：媒体、marketer：营销专家。
REQUEST_API_END()
// 2/suggestions/users/may_interested: 获取用户可能感兴趣的人 
REQUEST_API_BEGIN(suggestions_users_may_interested, "2/suggestions/users/may_interested")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //单页返回的记录条数，默认为10。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/suggestions/users/by_status: 根据微博内容推荐用户 
REQUEST_API_BEGIN(suggestions_users_by_status, "2/suggestions/users/by_status")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("content", "")  //微博正文内容，必须做URLEncode，UTF-8编码 。
        ("num", 0)  //返回结果数目，默认为10。
REQUEST_API_END()
// 2/suggestions/statuses/reorder: 主Feed微博按兴趣推荐排序 
REQUEST_API_BEGIN(suggestions_statuses_reorder, "2/suggestions/statuses/reorder")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("section", 0)  //排序时间段，距现在n秒内的微博参加排序，最长支持24小时。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/suggestions/statuses/reorder/ids: 主Feed微博按兴趣推荐排序的微博ID 
REQUEST_API_BEGIN(suggestions_statuses_reorder_ids, "2/suggestions/statuses/reorder/ids")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("section", 0)  //排序时间段，距现在n秒内的微博参加排序，最长支持24小时。
        ("count", 0)  //单页返回的记录条数，默认为50。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/suggestions/favorites/hot: 热门收藏 
REQUEST_API_BEGIN(suggestions_favorites_hot, "2/suggestions/favorites/hot")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //每页返回结果数，默认20。
        ("page", 0)  //返回页码，默认1。
REQUEST_API_END()
// 2/suggestions/users/not_interested: 不感兴趣的人 
REQUEST_API_BEGIN(suggestions_users_not_interested, "2/suggestions/users/not_interested")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //不感兴趣的用户的UID。
REQUEST_API_END()
// 2/remind/unread_count: 获取某个用户的各种消息未读数  
REQUEST_API_BEGIN(remind_unread_count, "2/remind/unread_count")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要获取消息未读数的用户UID，必须是当前登录用户。
        ("callback", "")  //JSONP回调函数，用于前端调用返回JS格式的信息。
        ("unread_message", 0)  //未读数版本。0：原版未读数，1：新版未读数。默认为0。
REQUEST_API_END()
// 2/remind/set_count: 对当前登录用户某一种消息未读数进行清零  
REQUEST_API_BEGIN(remind_set_count, "2/remind/set_count")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("type", "")  //需要设置未读数计数的消息项，follower：新粉丝数、cmt：新评论数、dm：新私信数、mention_status：新提及我的微博数、mention_cmt：新提及我的评论数、group：微群消息数、notice：新通知数、invite：新邀请数、badge：新勋章数、photo：相册消息数、close_friends_feeds：密友feeds未读数、close_friends_mention_status：密友提及我的微博未读数、close_friends_mention_cmt：密友提及我的评论未读数、close_friends_cmt：密友评论未读数、close_friends_attitude：密友表态未读数、close_friends_common_cmt：密友共同评论未读数、close_friends_invite：密友邀请未读数，一次只能操作一项。
REQUEST_API_END()
// 2/short_url/shorten: 长链转短链  
REQUEST_API_BEGIN(short_url_shorten, "2/short_url/shorten")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_long", "")  //需要转换的长链接，需要URLencoded，最多不超过20个。
REQUEST_API_END()
// 2/short_url/expand: 短链转长链  
REQUEST_API_BEGIN(short_url_expand, "2/short_url/expand")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要还原的短链接，需要URLencoded，最多不超过20个 。
REQUEST_API_END()
// 2/short_url/share/counts: 获取短链接在微博上的微博分享数  
REQUEST_API_BEGIN(short_url_share_counts, "2/short_url/share/counts")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要取得分享数的短链接，需要URLencoded，最多不超过20个。
REQUEST_API_END()
// 2/short_url/share/statuses: 获取包含指定单个短链接的最新微博内容  
REQUEST_API_BEGIN(short_url_share_statuses, "2/short_url/share/statuses")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要取得关联微博内容的短链接，需要URLencoded。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，默认为50，最多不超过200。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/short_url/comment/counts: 获取短链接在微博上的微博评论数  
REQUEST_API_BEGIN(short_url_comment_counts, "2/short_url/comment/counts")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要取得分享数的短链接，需要URLencoded，最多不超过20个。
REQUEST_API_END()
// 2/short_url/comment/comments: 获取包含指定单个短链接的最新微博评论  
REQUEST_API_BEGIN(short_url_comment_comments, "2/short_url/comment/comments")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("url_short", "")  //需要取得关联微博评论内容的短链接，需要URLencoded。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的评论（即比since_id时间晚的评论），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的评论，默认为0。
        ("count", 0)  //单页返回的记录条数，默认为50，最多不超过200。
        ("page", 0)  //返回结果的页码，默认为1。
REQUEST_API_END()
// 2/common/code_to_location: 通过地址编码获取地址名称  
REQUEST_API_BEGIN(common_code_to_location, "2/common/code_to_location")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("codes", "")  //需要查询的地址编码，多个之间用逗号分隔。
REQUEST_API_END()
// 2/common/get_city: 获取城市列表  
REQUEST_API_BEGIN(common_get_city, "2/common/get_city")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("province", "")  //省份的省份代码。
        ("capital", "")  //城市的首字母，a-z，可为空代表返回全部，默认为全部。
        ("language", "")  //返回的语言版本，zh-cn：简体中文、zh-tw：繁体中文、english：英文，默认为zh-cn。
REQUEST_API_END()
// 2/common/get_province: 获取省份列表  
REQUEST_API_BEGIN(common_get_province, "2/common/get_province")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("country", "")  //国家的国家代码。
        ("capital", "")  //省份的首字母，a-z，可为空代表返回全部，默认为全部。
        ("language", "")  //返回的语言版本，zh-cn：简体中文、zh-tw：繁体中文、english：英文，默认为zh-cn。
REQUEST_API_END()
// 2/common/get_country: 获取国家列表  
REQUEST_API_BEGIN(common_get_country, "2/common/get_country")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("capital", "")  //国家的首字母，a-z，可为空代表返回全部，默认为全部。
        ("language", "")  //返回的语言版本，zh-cn：简体中文、zh-tw：繁体中文、english：英文，默认为zh-cn。
REQUEST_API_END()
// 2/common/get_timezone: 获取时区配置表  
REQUEST_API_BEGIN(common_get_timezone, "2/common/get_timezone")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("language", "")  //返回的语言版本，zh-cn：简体中文、zh-tw：繁体中文、english：英文，默认为zh-cn。
REQUEST_API_END()
// 2/place/public_timeline: 获取公共的位置动态  
REQUEST_API_BEGIN(place_public_timeline, "2/place/public_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("count", 0)  //每次返回的动态数，最大为50，默认为20。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/friends_timeline: 获取用户好友的位置动态 
REQUEST_API_BEGIN(place_friends_timeline, "2/place/friends_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大为50，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("type", 0)  //关系过滤，0：仅返回关注的，1：返回好友的，默认为0。
REQUEST_API_END()
// 2/place/user_timeline: 获取某个用户的位置动态 
REQUEST_API_BEGIN(place_user_timeline, "2/place/user_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大为50，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/poi_timeline: 获取某个位置地点的动态 
REQUEST_API_BEGIN(place_poi_timeline, "2/place/poi_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI点ID。
        ("since_id", "")  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", "")  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大为50，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/nearby_timeline: 获取某个位置周边的动态 
REQUEST_API_BEGIN(place_nearby_timeline, "2/place/nearby_timeline")
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
REQUEST_API_END()
// 2/place/statuses/show: 获取动态的详情 
REQUEST_API_BEGIN(place_statuses_show, "2/place/statuses/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("id", 0)  //需要获取的动态ID。
REQUEST_API_END()
// 2/place/users/show: 获取LBS位置服务内的用户信息 
REQUEST_API_BEGIN(place_users_show, "2/place/users/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/users/checkins: 获取用户签到过的地点列表 
REQUEST_API_BEGIN(place_users_checkins, "2/place/users/checkins")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/users/photos: 获取用户的照片列表 
REQUEST_API_BEGIN(place_users_photos, "2/place/users/photos")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/users/tips: 获取用户的点评列表 
REQUEST_API_BEGIN(place_users_tips, "2/place/users/tips")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/users/todos: 获取用户的todo列表  
REQUEST_API_BEGIN(place_users_todos, "2/place/users/todos")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("uid", 0)  //需要查询的用户ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/pois/show: 获取地点详情 
REQUEST_API_BEGIN(place_pois_show, "2/place/pois/show")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI地点ID。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/pois/users: 获取在某个地点签到的人的列表 
REQUEST_API_BEGIN(place_pois_users, "2/place/pois/users")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI地点ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/pois/tips: 获取地点点评列表 
REQUEST_API_BEGIN(place_pois_tips, "2/place/pois/tips")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI地点ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序方式，0：按时间、1：按热门，默认为0，目前只支持0。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/pois/photos: 获取地点照片列表 
REQUEST_API_BEGIN(place_pois_photos, "2/place/pois/photos")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要查询的POI地点ID。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
        ("page", 0)  //返回结果的页码，默认为1。
        ("sort", 0)  //排序方式，0：按时间、1：按热门，默认为0，目前只支持0。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
REQUEST_API_END()
// 2/place/pois/search: 按省市查询地点 
REQUEST_API_BEGIN(place_pois_search, "2/place/pois/search")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("keyword", "")  //查询的关键词，必须进行URLencode。
        ("city", "")  //城市代码，默认为全国搜索。
        ("category", "")  //查询的分类代码，取值范围见：分类代码对应表。
        ("page", 0)  //返回结果的页码，默认为1。
        ("count", 0)  //单页返回的记录条数，默认为20，最大为50。
REQUEST_API_END()
// 2/place/pois/category: 获取地点分类 
REQUEST_API_BEGIN(place_pois_category, "2/place/pois/category")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("pid", 0)  //父分类ID，默认为0。
        ("flag", 0)  //是否返回全部分类，0：只返回本级下的分类，1：返回全部分类，默认为0。
REQUEST_API_END()
// 2/place/nearby/pois: 获取附近地点 
REQUEST_API_BEGIN(place_nearby_pois, "2/place/nearby/pois")
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
REQUEST_API_END()
// 2/place/nearby/users: 获取附近发位置微博的人 
REQUEST_API_BEGIN(place_nearby_users, "2/place/nearby/users")
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
REQUEST_API_END()
// 2/place/nearby/photos: 获取附近照片 
REQUEST_API_BEGIN(place_nearby_photos, "2/place/nearby/photos")
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
REQUEST_API_END()
// 2/place/nearby_users/list: 获取附近的人  
REQUEST_API_BEGIN(place_nearby_users_list, "2/place/nearby_users/list")
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
REQUEST_API_END()
// 2/place/pois/create: 添加地点  
REQUEST_API_BEGIN(place_pois_create, "2/place/pois/create")
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
REQUEST_API_END()
// 2/place/pois/add_checkin: 签到 
REQUEST_API_BEGIN(place_pois_add_checkin, "2/place/pois/add_checkin")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要签到的POI地点ID。
        ("status", "")  //签到时发布的动态内容，必须做URLencode，内容不超过140个汉字。
        ("pic", 0)  //需要上传的图片，仅支持JPEG、GIF、PNG格式，图片大小小于5M。
        ("public", 0)  //是否同步到微博，1：是、0：否，默认为0。
REQUEST_API_END()
// 2/place/pois/add_photo: 添加照片 
REQUEST_API_BEGIN(place_pois_add_photo, "2/place/pois/add_photo")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要添加照片的POI地点ID。
        ("status", "")  //签到时发布的动态内容，必须做URLencode，内容不超过140个汉字。
        ("pic", 0)  //需要上传的图片，仅支持JPEG、GIF、PNG格式，图片大小小于5M。
        ("public", 0)  //是否同步到微博，1：是、0：否，默认为0。
REQUEST_API_END()
// 2/place/pois/add_tip: 添加点评 
REQUEST_API_BEGIN(place_pois_add_tip, "2/place/pois/add_tip")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要点评的POI地点ID。
        ("status", "")  //点评时发布的动态内容，必须做URLencode，内容不超过140个汉字。
        ("public", 0)  //是否同步到微博，1：是、0：否，默认为0。
REQUEST_API_END()
// 2/place/pois/add_todo: 添加todo  
REQUEST_API_BEGIN(place_pois_add_todo, "2/place/pois/add_todo")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("poiid", "")  //需要添加todo的POI地点ID。
        ("status", "")  //添加todo时发布的动态内容，必须做URLencode，内容不超过140个汉字。
        ("public", 0)  //是否同步到微博，1：是、0：否，默认为0。
REQUEST_API_END()
// 2/place/nearby_users/create: 用户添加自己的位置  
REQUEST_API_BEGIN(place_nearby_users_create, "2/place/nearby_users/create")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("lat", 0)  //纬度，有效范围：-90.0到+90.0，+表示北纬。
        ("long", 0)  //经度，有效范围：-180.0到+180.0，+表示东经。
REQUEST_API_END()
// 2/place/nearby_users/destroy: 用户删除自己的位置  
REQUEST_API_BEGIN(place_nearby_users_destroy, "2/place/nearby_users/destroy")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
REQUEST_API_END()
// 2/location/base/get_map_image: 生成一张静态的地图图片 
REQUEST_API_BEGIN(location_base_get_map_image, "2/location/base/get_map_image")
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
REQUEST_API_END()
// 2/location/geo/ip_to_geo: 根据IP地址返回地理信息坐标 
REQUEST_API_BEGIN(location_geo_ip_to_geo, "2/location/geo/ip_to_geo")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("ip", "")  //需要获取坐标的IP地址，多个IP用逗号分隔，最多不超过10个。
REQUEST_API_END()
// 2/location/geo/address_to_geo: 根据实际地址返回地理信息坐标 
REQUEST_API_BEGIN(location_geo_address_to_geo, "2/location/geo/address_to_geo")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("address", "")  //需要获取坐标的实际地址，必须进行URLencode。
REQUEST_API_END()
// 2/location/geo/geo_to_address: 根据地理信息坐标返回实际地址 
REQUEST_API_BEGIN(location_geo_geo_to_address, "2/location/geo/geo_to_address")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("coordinate", "")  //需要获取实际地址的坐标，经度纬度用逗号分隔。
REQUEST_API_END()
// 2/location/geo/gps_to_offset: 根据GPS坐标获取偏移后的坐标 
REQUEST_API_BEGIN(location_geo_gps_to_offset, "2/location/geo/gps_to_offset")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("coordinate", "")  //需要获取偏移坐标的源坐标，经度纬度用逗号分隔。
REQUEST_API_END()
// 2/location/geo/is_domestic: 判断地理信息坐标是否是国内坐标 
REQUEST_API_BEGIN(location_geo_is_domestic, "2/location/geo/is_domestic")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("coordinates", "")  //需要判断的坐标，格式：经度,纬度,字符标识|经度,纬度,字符标识。其中经度纬度用逗号分隔，字符标识用于返回结果中的返回值标识。“|”分隔多个坐标。一次最多50个坐标。示例：coordinates=120.035847163,23.1014362572,g1|116.035847163,38.1014362572,g2。
REQUEST_API_END()
// 2/location/pois/search/by_location: 根据关键词按地址位置获取POI点的信息 
REQUEST_API_BEGIN(location_pois_search_by_location, "2/location/pois/search/by_location")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode，与category参数必选其一。
        ("category", "")  //查询的分类代码，与q参数必选其一，取值范围见：分类代码对应表。
        ("city", "")  //城市代码，默认为全国搜索。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为20。
REQUEST_API_END()
// 2/location/pois/search/by_geo: 根据关键词按坐标点范围获取POI点的信息 
REQUEST_API_BEGIN(location_pois_search_by_geo, "2/location/pois/search/by_geo")
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
REQUEST_API_END()
// 2/location/pois/search/by_area: 根据关键词按矩形区域获取POI点的信息 
REQUEST_API_BEGIN(location_pois_search_by_area, "2/location/pois/search/by_area")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode，与category参数必选其一。
        ("category", "")  //查询的分类代码，与q参数必选其一，取值范围见：分类代码对应表。
        ("coordinates", "")  //查询的矩形区域坐标，第一个坐标为左上角的点，第二个为右下角，经度纬度用逗号分隔，坐标间用“|”分隔，示例：coordinates=116.37,39.93|116.43,39.91。
        ("city", "")  //城市代码，默认为全国搜索。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为20。
REQUEST_API_END()
// 2/location/pois/show_batch: 批量获取POI点的信息 
REQUEST_API_BEGIN(location_pois_show_batch, "2/location/pois/show_batch")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("srcids", "")  //需要获取POI的来源ID，是由用户通过add接口自己提交的，多个ID用逗号分隔，最多不超过5个。
REQUEST_API_END()
// 2/location/pois/add: 提交一个新增的POI点信息 
REQUEST_API_BEGIN(location_pois_add, "2/location/pois/add")
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
REQUEST_API_END()
// 2/location/mobile/get_location: 根据移动基站WIFI等数据获取当前位置信息 
REQUEST_API_BEGIN(location_mobile_get_location, "2/location/mobile/get_location")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("json", "")  //特殊的JSON参数形式，使用方法如下，见注意事项。
REQUEST_API_END()
// 2/location/line/drive_route: 根据起点与终点数据查询自驾车路线信息 
REQUEST_API_BEGIN(location_line_drive_route, "2/location/line/drive_route")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("begin_pid", "")  //查询起点POI的ID，与begin_coordinate参数必选其一，begin_pid优先。
        ("begin_coordinate", "")  //查询起点的坐标，经度纬度用逗号分隔，与begin_pid参数必选其一，begin_pid优先。
        ("end_pid", "")  //查询终点POI的ID，与end_coordinate参数必选其一，end_pid优先。
        ("end_coordinate", "")  //查询终点的坐标，经度纬度用逗号分隔，与end_pid参数必选其一，end_pid优先。
        ("type", 0)  //查询类型，0：速度优先、1：费用优先、2：距离优先，默认值为0。
REQUEST_API_END()
// 2/location/line/bus_route: 根据起点与终点数据查询公交乘坐路线信息 
REQUEST_API_BEGIN(location_line_bus_route, "2/location/line/bus_route")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("begin_pid", "")  //查询起点POI的ID，与begin_coordinate参数必选其一，begin_pid优先。
        ("begin_coordinate", "")  //查询起点的坐标，经度纬度用逗号分隔，与begin_pid参数必选其一，begin_pid优先。
        ("end_pid", "")  //查询终点POI的ID，与end_coordinate参数必选其一，end_pid优先。
        ("end_coordinate", "")  //查询终点的坐标，经度纬度用逗号分隔，与end_pid参数必选其一，end_pid优先。
        ("type", 0)  //查询类型，0：最快捷、1：最经济、2：最少换乘、3：最少步行、4：最舒适，默认值为0。
REQUEST_API_END()
// 2/location/line/bus_line: 根据关键词查询公交线路信息 
REQUEST_API_BEGIN(location_line_bus_line, "2/location/line/bus_line")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode。
        ("city", "")  //城市代码，默认为北京搜索。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为50。
REQUEST_API_END()
// 2/location/line/bus_station: 根据关键词查询公交站点信息 
REQUEST_API_BEGIN(location_line_bus_station, "2/location/line/bus_station")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("q", "")  //查询的关键词，必须进行URLencode。
        ("city", "")  //城市代码，默认为北京搜索。
        ("page", 0)  //返回结果的页码，默认为1，最大为40。
        ("count", 0)  //单页返回的记录条数，默认为10，最大为50。
REQUEST_API_END()
// Location/citycode: 城市代码对应表 
REQUEST_API_BEGIN(Location_citycode, "Location/citycode")
REQUEST_API_END()
// Location/citycode_bus: 公交城市代码表 
REQUEST_API_BEGIN(Location_citycode_bus, "Location/citycode_bus")
REQUEST_API_END()
// Location/error2: 地理位置信息接口错误代码及解释
REQUEST_API_BEGIN(Location_error2, "Location/error2")
REQUEST_API_END()
// Oauth2/authorize: 请求用户授权Token 
REQUEST_API_BEGIN(Oauth2_authorize, "Oauth2/authorize")
        ("client_id", "")  //申请应用时分配的AppKey。
        ("redirect_uri", "")  //授权回调地址，站外应用需与设置的回调地址一致，站内应用需填写canvas page的地址。
        ("scope", "")  //申请scope权限所需参数，可一次申请多个scope权限，用逗号分隔。
        ("state", "")  //用于保持请求和回调的状态，在回调时，会在Query Parameter中回传该参数。开发者可以用这个参数验证请求有效性，也可以记录用户请求授权页前的位置。这个参数可用于防止跨站请求伪造（CSRF）攻击
        ("display", "")  //授权页面的终端类型，取值见下面的说明。
        ("forcelogin", 0)  //是否强制用户重新登录，true：是，false：否。默认false。
        ("language", "")  //授权页语言，缺省为中文简体版，en为英文版。英文版测试中，开发者任何意见可反馈至 @微博API
REQUEST_API_END()
// OAuth2/access_token: 获取授权过的Access Token 
REQUEST_API_BEGIN(OAuth2_access_token, "OAuth2/access_token")
        ("client_id", "")  //申请应用时分配的AppKey。
        ("client_secret", "")  //申请应用时分配的AppSecret。
        ("grant_type", "")  //请求的类型，填写authorization_code
REQUEST_API_END()
// Oauth2/get_token_info: 查询用户access_token的授权相关信息  
REQUEST_API_BEGIN(Oauth2_get_token_info, "Oauth2/get_token_info")
        ("uid", "")  //
        ("appkey", "" )  //
        ("scope", "")  //
        ("create_at", "")  //
        ("expire_in", "")  //
REQUEST_API_END()

// Oauth2/revokeoauth2: 授权回收接口，帮助开发者主动取消用户的授权  
REQUEST_API_BEGIN(Oauth2_revokeoauth2, "Oauth2/revokeoauth2")
REQUEST_API_END()






// 2/statuses/bilateral_timeline: 获取双向关注用户的最新微博
REQUEST_API_BEGIN(statuses_bilateral_timeline, "2/statuses/bilateral_timeline")
        ("source", "")  //采用OAuth授权方式不需要此参数，其他授权方式为必填参数，数值为应用的AppKey。
        ("access_token", "")  //采用OAuth授权方式为必填参数，其他授权方式不需要此参数，OAuth授权后获得。
        ("since_id", 0)  //若指定此参数，则返回ID比since_id大的微博（即比since_id时间晚的微博），默认为0。
        ("max_id", 0)  //若指定此参数，则返回ID小于或等于max_id的微博，默认为0。
        ("count", 0)  //单页返回的记录条数，最大不超过100，默认为20。
        ("page", 0)  //返回结果的页码，默认为1。
        ("base_app", 0)  //是否只获取当前应用的数据。0为否（所有数据），1为是（仅当前应用），默认为0。
        ("feature", 0)  //过滤类型ID，0：全部、1：原创、2：图片、3：视频、4：音乐，默认为0。
        ("trim_user", 0)  //返回值中user字段开关，0：返回完整user字段、1：user字段仅返回user_id，默认为0。
REQUEST_API_END()
}

#endif
