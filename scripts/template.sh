OUT_FILE=weiboapi.h  #cat >> &1 is wrong, why?

begin_api() {
	[ $# -eq 0 ] && return 1
	API=$1
	URL=$2
#echo "REQUEST_API_BEGIN($API, \"$URL\")"
cat <<EOF
class QWEIBOSDK_EXPORT ${API} : public BaseRequest
{
    Q_OBJECT
public:
    explicit ${API}(QObject *parent = 0)
        : BaseRequest(parent){
        setUrlPath ("$URL");
        initiate ();
    }

protected:
    void initParameters () {
        (*this)
EOF
}

end_api() {
API=$1

cat <<EOF
        ;
    }
};
EOF
}

BEGIN_PARAMETER="        (\""
END_PARAMETER=\)
PARAMETER_VALUE_SEP="\","
BEGIN_COMMENT="//"
END_COMMEND=

