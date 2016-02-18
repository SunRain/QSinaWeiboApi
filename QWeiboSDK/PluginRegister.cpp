#include "PluginRegister.h"

#include <QtQml>

#include "QWeiboRequest.h"
#include "ImageUploader.h"
#ifdef WITH_HACKLOGIN
#include "HackLogin/CookieDataProvider.h"
#include "HackLogin/HackFriendshipsGroups.h"
#include "HackLogin/HackUsersInfo.h"
#endif

#ifdef WITH_SDK_WRAPPER
#include "Wrapper/FriendshipsGroupsWrapper.h"
#endif

namespace QWeiboSDK {

void registerPlugins(const char *url)
{
//    qmlRegisterType<MyType>("harbour.sailfish_sinaweibo.sunrain", 1, 0, "MyType");

    qmlRegisterType<QWeiboSDK::AccountGetUid>(url, 1, 0, "AccountGetUid");
    qmlRegisterType<QWeiboSDK::AccountProfileEmail>(url, 1, 0, "AccountProfileEmail");
//    qmlRegisterType<QWeiboSDK::AccountProfileSoolList>(url, 1, 0, "AccountProfileSoolList");
    qmlRegisterType<QWeiboSDK::AccountRateLimitStatus>(url, 1, 0, "AccountRateLimitStatus");
    qmlRegisterType<QWeiboSDK::CommentsByMe>(url, 1, 0, "CommentsByMe");
    qmlRegisterType<QWeiboSDK::CommentsCreate>(url, 1, 0, "CommentsCreate");
//    qmlRegisterType<QWeiboSDK::CommentsDestroyBat>(url, 1, 0, "CommentsDestroyBat");
    qmlRegisterType<QWeiboSDK::CommentsDestroy>(url, 1, 0, "CommentsDestroy");
    qmlRegisterType<QWeiboSDK::CommentsMentions>(url, 1, 0, "CommentsMentions");
    qmlRegisterType<QWeiboSDK::CommentsReply>(url, 1, 0, "CommentsReply");
//    qmlRegisterType<QWeiboSDK::CommentsowBat>(url, 1, 0, "CommentsowBat");
//    qmlRegisterType<QWeiboSDK::Commentsow>(url, 1, 0, "Commentsow");
    qmlRegisterType<QWeiboSDK::CommentsTimeline>(url, 1, 0, "CommentsTimeline");
    qmlRegisterType<QWeiboSDK::CommentsToMe>(url, 1, 0, "CommentsToMe");
    qmlRegisterType<QWeiboSDK::CommonCodeToLocation>(url, 1, 0, "CommonCodeToLocation");
    qmlRegisterType<QWeiboSDK::CommonGetCity>(url, 1, 0, "CommonGetCity");
    qmlRegisterType<QWeiboSDK::CommonGetCountry>(url, 1, 0, "CommonGetCountry");
    qmlRegisterType<QWeiboSDK::CommonGetProvince>(url, 1, 0, "CommonGetProvince");
    qmlRegisterType<QWeiboSDK::CommonGetTimezone>(url, 1, 0, "CommonGetTimezone");
    qmlRegisterType<QWeiboSDK::Emotions>(url, 1, 0, "Emotions");
    qmlRegisterType<QWeiboSDK::FavoritesByTags>(url, 1, 0, "FavoritesByTags");
    qmlRegisterType<QWeiboSDK::FavoritesByTagsIds>(url, 1, 0, "FavoritesByTagsIds");
    qmlRegisterType<QWeiboSDK::FavoritesCreate>(url, 1, 0, "FavoritesCreate");
//    qmlRegisterType<QWeiboSDK::FavoritesDestroyBat>(url, 1, 0, "FavoritesDestroyBat");
    qmlRegisterType<QWeiboSDK::FavoritesDestroy>(url, 1, 0, "FavoritesDestroy");
    qmlRegisterType<QWeiboSDK::Favorites>(url, 1, 0, "Favorites");
//    qmlRegisterType<QWeiboSDK::FavoritesIds>(url, 1, 0, "FavoritesIds");
//    qmlRegisterType<QWeiboSDK::Favoritesow>(url, 1, 0, "Favoritesow");
//    qmlRegisterType<QWeiboSDK::FavoritesTagsDestroyBat>(url, 1, 0, "FavoritesTagsDestroyBat");
    qmlRegisterType<QWeiboSDK::FavoritesTags>(url, 1, 0, "FavoritesTags");
//    qmlRegisterType<QWeiboSDK::FavoritesTagsUpdateBat>(url, 1, 0, "FavoritesTagsUpdateBat");
    qmlRegisterType<QWeiboSDK::FavoritesTagsUpdate>(url, 1, 0, "FavoritesTagsUpdate");
//    qmlRegisterType<QWeiboSDK::FriendipsCreate>(url, 1, 0, "FriendipsCreate");
//    qmlRegisterType<QWeiboSDK::FriendipsDestroy>(url, 1, 0, "FriendipsDestroy");
//    qmlRegisterType<QWeiboSDK::FriendipsFollowersActive>(url, 1, 0, "FriendipsFollowersActive");
//    qmlRegisterType<QWeiboSDK::FriendipsFollowers>(url, 1, 0, "FriendipsFollowers");
//    qmlRegisterType<QWeiboSDK::FriendipsFollowersIds>(url, 1, 0, "FriendipsFollowersIds");
//    qmlRegisterType<QWeiboSDK::FriendipsFriendsBilateral>(url, 1, 0, "FriendipsFriendsBilateral");
//    qmlRegisterType<QWeiboSDK::FriendipsFriendsBilateralIds>(url, 1, 0, "FriendipsFriendsBilateralIds");
//    qmlRegisterType<QWeiboSDK::FriendipsFriendsainFollowers>(url, 1, 0, "FriendipsFriendsainFollowers");
//    qmlRegisterType<QWeiboSDK::FriendipsFriends>(url, 1, 0, "FriendipsFriends");
//    qmlRegisterType<QWeiboSDK::FriendipsFriendsIds>(url, 1, 0, "FriendipsFriendsIds");
//    qmlRegisterType<QWeiboSDK::FriendipsFriendsInCommon>(url, 1, 0, "FriendipsFriendsInCommon");
//    qmlRegisterType<QWeiboSDK::Friendipsow>(url, 1, 0, "Friendipsow");
    qmlRegisterType<QWeiboSDK::LocationBaseGetMapImage>(url, 1, 0, "LocationBaseGetMapImage");
//    qmlRegisterType<QWeiboSDK::LocationCategory>(url, 1, 0, "LocationCategory");
//    qmlRegisterType<QWeiboSDK::LocationCitycodeBus>(url, 1, 0, "LocationCitycodeBus");
//    qmlRegisterType<QWeiboSDK::LocationCitycode>(url, 1, 0, "LocationCitycode");
//    qmlRegisterType<QWeiboSDK::LocationError2>(url, 1, 0, "LocationError2");
    qmlRegisterType<QWeiboSDK::LocationGeoAddressToGeo>(url, 1, 0, "LocationGeoAddressToGeo");
    qmlRegisterType<QWeiboSDK::LocationGeoGeoToAddress>(url, 1, 0, "LocationGeoGeoToAddress");
    qmlRegisterType<QWeiboSDK::LocationGeoGpsToOffset>(url, 1, 0, "LocationGeoGpsToOffset");
    qmlRegisterType<QWeiboSDK::LocationGeoIpToGeo>(url, 1, 0, "LocationGeoIpToGeo");
    qmlRegisterType<QWeiboSDK::LocationGeoIsDomestic>(url, 1, 0, "LocationGeoIsDomestic");
    qmlRegisterType<QWeiboSDK::LocationLineBusLine>(url, 1, 0, "LocationLineBusLine");
    qmlRegisterType<QWeiboSDK::LocationLineBusRoute>(url, 1, 0, "LocationLineBusRoute");
    qmlRegisterType<QWeiboSDK::LocationLineBusStation>(url, 1, 0, "LocationLineBusStation");
    qmlRegisterType<QWeiboSDK::LocationLineDriveRoute>(url, 1, 0, "LocationLineDriveRoute");
    qmlRegisterType<QWeiboSDK::LocationMobileGetLocation>(url, 1, 0, "LocationMobileGetLocation");
    qmlRegisterType<QWeiboSDK::LocationPoisAdd>(url, 1, 0, "LocationPoisAdd");
//    qmlRegisterType<QWeiboSDK::LocationPoisSearByArea>(url, 1, 0, "LocationPoisSearByArea");
//    qmlRegisterType<QWeiboSDK::LocationPoisSearByGeo>(url, 1, 0, "LocationPoisSearByGeo");
//    qmlRegisterType<QWeiboSDK::LocationPoisSearByLocation>(url, 1, 0, "LocationPoisSearByLocation");
//    qmlRegisterType<QWeiboSDK::LocationPoisowBat>(url, 1, 0, "LocationPoisowBat");
//    qmlRegisterType<QWeiboSDK::OAu2AccessToken>(url, 1, 0, "OAu2AccessToken");
//    qmlRegisterType<QWeiboSDK::Oau2Auorize>(url, 1, 0, "Oau2Auorize");
//    qmlRegisterType<QWeiboSDK::Oau2GetOau2Token（尚未撰写）>(url, 1, 0, "Oau2GetOau2Token（尚未撰写）");
//    qmlRegisterType<QWeiboSDK::Oau2GetTokenInfo>(url, 1, 0, "Oau2GetTokenInfo");
//    qmlRegisterType<QWeiboSDK::Oau2Revokeoau2>(url, 1, 0, "Oau2Revokeoau2");
    qmlRegisterType<QWeiboSDK::PlaceFriendsTimeline>(url, 1, 0, "PlaceFriendsTimeline");
//    qmlRegisterType<QWeiboSDK::PlaceNearbyotos>(url, 1, 0, "PlaceNearbyotos");
    qmlRegisterType<QWeiboSDK::PlaceNearbyPois>(url, 1, 0, "PlaceNearbyPois");
    qmlRegisterType<QWeiboSDK::PlaceNearbyTimeline>(url, 1, 0, "PlaceNearbyTimeline");
    qmlRegisterType<QWeiboSDK::PlaceNearbyUsersCreate>(url, 1, 0, "PlaceNearbyUsersCreate");
    qmlRegisterType<QWeiboSDK::PlaceNearbyUsersDestroy>(url, 1, 0, "PlaceNearbyUsersDestroy");
    qmlRegisterType<QWeiboSDK::PlaceNearbyUsers>(url, 1, 0, "PlaceNearbyUsers");
    qmlRegisterType<QWeiboSDK::PlaceNearbyUsersList>(url, 1, 0, "PlaceNearbyUsersList");
//    qmlRegisterType<QWeiboSDK::PlacePoisAddeckin>(url, 1, 0, "PlacePoisAddeckin");
//    qmlRegisterType<QWeiboSDK::PlacePoisAddoto>(url, 1, 0, "PlacePoisAddoto");
    qmlRegisterType<QWeiboSDK::PlacePoisAddTip>(url, 1, 0, "PlacePoisAddTip");
    qmlRegisterType<QWeiboSDK::PlacePoisAddTodo>(url, 1, 0, "PlacePoisAddTodo");
    qmlRegisterType<QWeiboSDK::PlacePoisCategory>(url, 1, 0, "PlacePoisCategory");
    qmlRegisterType<QWeiboSDK::PlacePoisCreate>(url, 1, 0, "PlacePoisCreate");
//    qmlRegisterType<QWeiboSDK::PlacePoisotos>(url, 1, 0, "PlacePoisotos");
//    qmlRegisterType<QWeiboSDK::PlacePoisSear>(url, 1, 0, "PlacePoisSear");
//    qmlRegisterType<QWeiboSDK::PlacePoisow>(url, 1, 0, "PlacePoisow");
    qmlRegisterType<QWeiboSDK::PlacePoisTips>(url, 1, 0, "PlacePoisTips");
    qmlRegisterType<QWeiboSDK::PlacePoisUsers>(url, 1, 0, "PlacePoisUsers");
    qmlRegisterType<QWeiboSDK::PlacePoiTimeline>(url, 1, 0, "PlacePoiTimeline");
    qmlRegisterType<QWeiboSDK::PlacePublicTimeline>(url, 1, 0, "PlacePublicTimeline");
//    qmlRegisterType<QWeiboSDK::PlaceStatusesow>(url, 1, 0, "PlaceStatusesow");
//    qmlRegisterType<QWeiboSDK::PlaceUserseckins>(url, 1, 0, "PlaceUserseckins");
//    qmlRegisterType<QWeiboSDK::PlaceUsersotos>(url, 1, 0, "PlaceUsersotos");
//    qmlRegisterType<QWeiboSDK::PlaceUsersow>(url, 1, 0, "PlaceUsersow");
    qmlRegisterType<QWeiboSDK::PlaceUsersTips>(url, 1, 0, "PlaceUsersTips");
    qmlRegisterType<QWeiboSDK::PlaceUsersTodos>(url, 1, 0, "PlaceUsersTodos");
    qmlRegisterType<QWeiboSDK::PlaceUserTimeline>(url, 1, 0, "PlaceUserTimeline");
    qmlRegisterType<QWeiboSDK::RemindSetCount>(url, 1, 0, "RemindSetCount");
    qmlRegisterType<QWeiboSDK::RemindUnreadCount>(url, 1, 0, "RemindUnreadCount");
//    qmlRegisterType<QWeiboSDK::SearSuggestionsApps>(url, 1, 0, "SearSuggestionsApps");
//    qmlRegisterType<QWeiboSDK::SearSuggestionsAtUsers>(url, 1, 0, "SearSuggestionsAtUsers");
//    qmlRegisterType<QWeiboSDK::SearSuggestionsCompanies>(url, 1, 0, "SearSuggestionsCompanies");
//    qmlRegisterType<QWeiboSDK::SearSuggestionsSools>(url, 1, 0, "SearSuggestionsSools");
//    qmlRegisterType<QWeiboSDK::SearSuggestionsUsers>(url, 1, 0, "SearSuggestionsUsers");
//    qmlRegisterType<QWeiboSDK::SearTopics>(url, 1, 0, "SearTopics");
//    qmlRegisterType<QWeiboSDK::ortUrlCommentComments>(url, 1, 0, "ortUrlCommentComments");
//    qmlRegisterType<QWeiboSDK::ortUrlCommentCounts>(url, 1, 0, "ortUrlCommentCounts");
//    qmlRegisterType<QWeiboSDK::ortUrlExpand>(url, 1, 0, "ortUrlExpand");
//    qmlRegisterType<QWeiboSDK::ortUrlareCounts>(url, 1, 0, "ortUrlareCounts");
//    qmlRegisterType<QWeiboSDK::ortUrlareStatuses>(url, 1, 0, "ortUrlareStatuses");
//    qmlRegisterType<QWeiboSDK::ortUrlorten>(url, 1, 0, "ortUrlorten");
    qmlRegisterType<QWeiboSDK::StatusesBilateralTimeline>(url, 1, 0, "StatusesBilateralTimeline");
    qmlRegisterType<QWeiboSDK::StatusesCount>(url, 1, 0, "StatusesCount");
    qmlRegisterType<QWeiboSDK::StatusesDestroy>(url, 1, 0, "StatusesDestroy");
    qmlRegisterType<QWeiboSDK::StatusesFilterCreate>(url, 1, 0, "StatusesFilterCreate");
    qmlRegisterType<QWeiboSDK::StatusesFriendsTimeline>(url, 1, 0, "StatusesFriendsTimeline");
    qmlRegisterType<QWeiboSDK::StatusesFriendsTimelineIds>(url, 1, 0, "StatusesFriendsTimelineIds");
    qmlRegisterType<QWeiboSDK::StatusesGo>(url, 1, 0, "StatusesGo");
    qmlRegisterType<QWeiboSDK::StatusesHomeTimeline>(url, 1, 0, "StatusesHomeTimeline");
    qmlRegisterType<QWeiboSDK::StatusesMentions>(url, 1, 0, "StatusesMentions");
    qmlRegisterType<QWeiboSDK::StatusesMentionsIds>(url, 1, 0, "StatusesMentionsIds");
//    qmlRegisterType<QWeiboSDK::StatusesMentionsield>(url, 1, 0, "StatusesMentionsield");
    qmlRegisterType<QWeiboSDK::StatusesPublicTimeline>(url, 1, 0, "StatusesPublicTimeline");
    qmlRegisterType<QWeiboSDK::StatusesQueryid>(url, 1, 0, "StatusesQueryid");
    qmlRegisterType<QWeiboSDK::StatusesQuerymid>(url, 1, 0, "StatusesQuerymid");
    qmlRegisterType<QWeiboSDK::StatusesRepost>(url, 1, 0, "StatusesRepost");
    qmlRegisterType<QWeiboSDK::StatusesRepostTimeline>(url, 1, 0, "StatusesRepostTimeline");
    qmlRegisterType<QWeiboSDK::StatusesRepostTimelineIds>(url, 1, 0, "StatusesRepostTimelineIds");
//    qmlRegisterType<QWeiboSDK::StatusesowBat>(url, 1, 0, "StatusesowBat");
//    qmlRegisterType<QWeiboSDK::Statusesow>(url, 1, 0, "Statusesow");
//    qmlRegisterType<QWeiboSDK::StatusesTimelineBat>(url, 1, 0, "StatusesTimelineBat");
    qmlRegisterType<QWeiboSDK::StatusesUpdate>(url, 1, 0, "StatusesUpdate");
    qmlRegisterType<QWeiboSDK::StatusesUpload>(url, 1, 0, "StatusesUpload");
    qmlRegisterType<QWeiboSDK::StatusesUploadUrlText>(url, 1, 0, "StatusesUploadUrlText");
    qmlRegisterType<QWeiboSDK::StatusesUserTimeline>(url, 1, 0, "StatusesUserTimeline");
    qmlRegisterType<QWeiboSDK::StatusesUserTimelineIds>(url, 1, 0, "StatusesUserTimelineIds");
    qmlRegisterType<QWeiboSDK::UsersCounts>(url, 1, 0, "UsersCounts");
//    qmlRegisterType<QWeiboSDK::UsersDomainow>(url, 1, 0, "UsersDomainow");
    qmlRegisterType<QWeiboSDK::UsersShow>(url, 1, 0, "UsersShow");
//    qmlRegisterType<QWeiboSDK::发送消息>(url, 1, 0, "发送消息");
//    qmlRegisterType<QWeiboSDK::接收消息>(url, 1, 0, "接收消息");
//    qmlRegisterType<QWeiboSDK::生成带参数的二维码>(url, 1, 0, "生成带参数的二维码");

    qmlRegisterType<QWeiboSDK::FriendshipsGroupsTimeline>(url, 1, 0, "FriendshipsGroupsTimeline");
    qmlRegisterType<QWeiboSDK::FriendshipsGroups>(url, 1, 0, "FriendshipsGroups");
    qmlRegisterType<QWeiboSDK::FriendshipsGroupsDestroy>(url, 1, 0, "FriendshipsGroupsDestroy");
    qmlRegisterType<QWeiboSDK::FriendshipsGroupsUpdate>(url, 1, 0, "FriendshipsGroupsUpdate");
    qmlRegisterType<QWeiboSDK::SearchSuggestionsAtUsers>(url, 1, 0, "SearchSuggestionsAtUsers");
    qmlRegisterType<QWeiboSDK::CommentsShow>(url, 1, 0, "CommentsShow");
    qmlRegisterType<QWeiboSDK::FriendshipsFriends>(url, 1, 0, "FriendshipsFriends");
    qmlRegisterType<QWeiboSDK::FriendshipsFollowers>(url, 1, 0, "FriendshipsFollowers");
    qmlRegisterType<QWeiboSDK::FriendshipsFriendsBilateral>(url, 1, 0, "FriendshipsFriendsBilateral");

    qmlRegisterType<QWeiboSDK::ImageUploader>(url, 1, 0, "ImageUploader");
    qmlRegisterType<QWeiboSDK::FriendshipsCreate>(url, 1, 0, "FriendshipsCreate");
    qmlRegisterType<QWeiboSDK::FriendshipsDestroy>(url, 1, 0, "FriendshipsDestroy");

#ifdef WITH_HACKLOGIN
    qmlRegisterType<QWeiboSDK::HackLogin::CookieDataProvider>(url, 1, 0, "CookieDataProvider");
    qmlRegisterType<QWeiboSDK::HackLogin::HackFriendshipsGroups>(url, 1, 0, "HackFriendshipsGroups");
    qmlRegisterType<QWeiboSDK::HackLogin::HackFriendshipsGroupsTimeline>(url, 1, 0, "HackFriendshipsGroupsTimeline");
    qmlRegisterType<QWeiboSDK::HackLogin::HackFriendshipsGroupsCreate>(url, 1, 0, "HackFriendshipsGroupsCreate");
    qmlRegisterType<QWeiboSDK::HackLogin::HackFriendshipsGroupsDestroy>(url, 1, 0, "HackFriendshipsGroupsDestroy");
    qmlRegisterType<QWeiboSDK::HackLogin::HackUsersInfo>(url, 1, 0, "HackUsersInfo");

#endif

#ifdef WITH_SDK_WRAPPER
    qmlRegisterType<QWeiboSDK::Wrapper::WrapperFriendshipsGroups>(url, 1, 0, "WrapperFriendshipsGroups");
    qmlRegisterType<QWeiboSDK::Wrapper::WrapperFriendshipsGroupsTimeline>(url, 1, 0, "WrapperFriendshipsGroupsTimeline");
    qmlRegisterType<QWeiboSDK::Wrapper::WrapperFriendshipsGroupsDestroy>(url, 1, 0, "WrapperFriendshipsGroupsDestroy");
    qmlRegisterType<QWeiboSDK::Wrapper::WrapperFriendshipsGroupsCreate>(url, 1, 0, "WrapperFriendshipsGroupsCreate");

#endif

}

}
