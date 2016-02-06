(function(win, doc){
	var ENTRY = 'mweibo';
	var PRELOGIN = '//login.sina.com.cn/sso/prelogin.php?checkpin=1&entry=' + ENTRY;
	var LOGIN = '//passport.weibo.cn/sso/login';
	var VERIFY_IMAGE = '//passport.weibo.cn/captcha/image';
	var STAT_URL = '//passport.weibo.cn/stat/s';
	var STAT_ONEKEY_CLICK = 1;
	var STAT_ONEKEY_FAIL  = 2;
	var STAT_ACT_ONEKEY_APP_CONFIRM	     = 1;
	var STAT_ACT_ONEKEY_WEBVIEW_OPEN     = 2;
	var STAT_ACT_ONEKEY_WEBVIEW_CONFIRM  = 3;
	var ERROR_COUNT = 0;
	var ERROR_COUNT_Mobile = 0;
	
	function parseJSON(str){
		if(typeof(str) === 'object') {
			return str;
		} else {
			if(window.JSON){
				return JSON.parse(str);
			} else {
				return eval('(' + str + ')');
			}
		}
	}
	
	function encodeFormData(data){
		var pairs = [], regexp = /%20/g;

		var value;
		for(var key in data){
			value = data[key].toString();

			// encodeURIComponent encodes spaces as %20 instead of "+"
			pairs.push(win.encodeURIComponent(key).replace(regexp, '+') +
				'=' + win.encodeURIComponent(value).replace(regexp, '+'));
		}

		return pairs.join('&');
	}
	
	function $(id){
		return doc.getElementById(id);
	}
	var LOGIN_SUCCESS_ADDRESS = $('loginSuccessAddress').value;
	
	
	function hasClass(elem, cls){
		var reg = new RegExp('(^|\\s)' + cls + '($|\\s)');
		return reg.test(elem.className);
	}

	function removeClass(elem, cls){
		var reg = new RegExp('(^|\\s)' + cls + '($|\\s)', 'g');
		elem.className = elem.className.replace(reg, ' ');
	}

	function addClass(elem, cls){
		if(!hasClass(elem, cls)){
			elem.className += ' ' + cls;
		}
	}

	var addEvent = doc.addEventListener ?
		function(elem, type, fn){
			elem.addEventListener(type, fn, false);
		} : function(elem, type, fn){
			elem.attachEvent('on' + type, fn);
		};
	function bind(fn, context){
		return function(){
			fn.call(context);
		};
	}
	function utf8_to_b64(str){
		return win.btoa(win.encodeURIComponent(trim(str)));
	}
	function trim(str){
		return (!str) ? '' : str.toString().replace(/^\s+|\s+$/g, '');
	}
	function objLength(obj) {
		var cnt = 0;
		if (typeof obj != "object") return 0;
		for (var k in obj) {
			if (obj.hasOwnProperty(k)) cnt++;
		}
		return cnt;
	}

	function compareVersion(baseVer,version){
		var baseVer_arr=[],
			version_arr =[];
		if(version){
			baseVer_arr = baseVer.split('.');
			version_arr = version.split('.');
			if(version_arr.length == 0){
				version_arr.push(version.parseInt()||0);
			}
			if(baseVer_arr.length == 0){
				baseVer_arr.push(baseVer.parseInt()||0);
			}

			for (var i = 0; i < 3; i++) {
				if(!version_arr[i]){
					version_arr[i] = 0;
				}
				if(!baseVer_arr[i]){
					baseVer_arr[i] = 0;
				}
				version_arr[i] = parseInt(version_arr[i]);
				baseVer_arr[i] = parseInt(baseVer_arr[i]);

				if(version_arr[i] == baseVer_arr[i]){
					if(i == 2){
						return true;
					}
					continue;
				}
				else if(version_arr[i] > baseVer_arr[i]){
					return true;
				}
				else{
					return false;
				}
			}
			
		}

		return false;
	}
	
	function Login(){
		this.init();
	};


	
	Login.prototype = {
		mode: 0,
		countDown : 60,
		intervalCount : 0,
		lastLogin: $('lastLogin'),
		loginName: $('loginName'),
		loginPassword: $('loginPassword'),
		loginNamePassword: $('loginNamePassword'),
		dVerifyCode: $('dVerifyCodeWrapper'),
		weidunCode: $('loginDVCode'),
		needWeidun: false,
		verifyCodeWrapper: $('verifyCodeWrapper'),
		verifyImage: $('verifyCodeImage'),
		verifyCode: $('loginVCode'),
		changeVerifyCode :$('changeVerifyCode'),
		needVerifyCode: false,
		errorMsg: $('errorMsg'),
		errorDialogMsg : $('errorDialogMsg'),
		errorDialog : $('errorDialog'),
		loginNamePanel : $('loginNamePanel'),
		jumpName: $('loginName'),
		errorDialogBtnF: $('errorDialogBtnF'),
		errorDialogBtnT: $('errorDialogBtnT'),
		errorBtn : $('errorBtn'),
	//	countDownButton :  $('mVerifyBtn'), 
		mobileLogin:$('mobileLogin'),
		passwordLogin:$('passwordLogin'),
		forgetPassword : $('forgetPassword'),
		register :	$('register'),
		loginAction : $('loginAction'),
		weiboLogin : $('weiboLogin'),
		loginWrapper : $('loginWrapper'),
		accountWrapper : $('accountWrapper'),
		uctext : $('uctext'),
		weibotext : $('weibotext'),
		logByAppAuth : $('logByAppAuth'),
		ucORweiboLogin : $('ucORweiboLogin'),
		changeLogin : $('changeLogin'),
		errorDialogPanel : $('errorDialogPanel'),
		oldUserName : $('oldUserName'),
		avatarWrapper : $('avatarWrapper'),
		loginnameclear : $('loginnameclear'),
		ucname : $('ucname'),
		ucavatar : $('ucavatar'),
		loginRF : $('loginRF'),
		postform : $('postform'),
		loginfrom : $('loginfrom'),
		clientId : $('client_id'),
		redirectUri : $('redirect_uri'),
		display : $('display'),
		offcialMobile : $('offcialMobile'),
		action : $('action'),
		quickAuth : $('quick_auth'),
		countDownKey : true,
		disabled : false,
		appsetInterval : null,
		featurecode : $('featurecode'),
		loginRFCAL : $('loginRFCAL'),
		//支付免登录流程 红包飞新增
		hff:$('hff'),//1表示是红包飞项目，0表示不是红包飞项目
		hfp:$('hfp'),//表示本次是因为用户点了免登页的其他账号登录才到用户名字密码页的

		
		init: function(){
			var that = this;
			that.adaptByUA();
			that.bindEvent();
			that.ucYORN();
		},
		ucYORN:function(){
			var that = this; 
			var loginRFValue = that.loginRF.value;
			if(window.ucweb&&window.ucweb.startRequest&&loginRFValue!=1){
				var ucCode = window.ucweb.startRequest('shell.comments.getToken', ['weibo','noauth']);
				var url = 'http://passport.weibo.cn/sso/uclogin';//php请求接口
				if(ucCode&&trim(ucCode.length>8)){
					ajax({
						url:'https://passport.weibo.cn/signin/ajuclogin',
						data:{
							token : ucCode
							},
						type : 'get',
						onsuccess : function(ret){
							var result = parseJSON(ret);
							if(result.retcode == 20000000){
								that.ucname.innerHTML = result.data.nick;
								that.ucavatar.src = result.data.avatar;
								that.loginWrapper.style.display = 'none';
								that.accountWrapper.style.display = 'block';
								that.uctext.style.display = 'block';
								that.weibotext.style.display = 'none';
								that.ucORweiboLogin.onclick = function(){
									ajax({
										url: 'https://passport.weibo.cn/sso/uclogin',
										type: 'post',
										data: {
											token : ucCode,
											entry : 'mweibo',
											r:LOGIN_SUCCESS_ADDRESS
										},
										onsuccess: function(ret){
											var result = parseJSON(ret);
											if(result.retcode == 20000000){
												that.addCookie(result.data,true);
											} 
										}
									});					
								};
							}else{
								that.weiboAppYORN();
							};
						}
					});
				}else{
					that.weiboAppYORN();
					return;
				}
			}else{
				that.weiboAppYORN();
			}
		},
		adaptByUA: function(){
			var ua = navigator.userAgent.toLowerCase();
			if(ua.indexOf('android 4.4.4')){
				this.loginWrapper.style.minHeight = 'initial';
			}
		},
		bindEvent: function(){
			var that = this;
			addEvent($('loginAction'), 'click', bind(this.doLogin, this));
			addEvent(this.loginName, 'blur', bind(this.checkVerify, this));
			addEvent(this.loginName, 'focus', bind(this.onInput, this));
			addEvent(this.loginPassword, 'focus', bind(this.onInput, this));
			addEvent(this.verifyImage, 'click', bind(this.getVerifyImage, this));
			addEvent(this.changeVerifyCode, 'click', bind(this.getVerifyImage, this));
			addEvent(this.changeLogin, 'click', function() {
				that.accountWrapper.style.display = 'none';
				that.loginWrapper.style.display = 'block';
			});
			addEvent(this.weidunCode, 'focus', function() {
				that.weidunCode.type = "tel";
			});
			addEvent(this.weidunCode, 'blur', function() {
				that.weidunCode.type = "text";
			});
			addEvent(this.errorDialogBtnF, 'click', function() {
				that.errorDialog.style.display = "none";
			});
			addEvent(win, 'resize', function(){
				that.setErrorDialogPanelPosition();
			});
			addEvent(that.errorDialogBtnT,'click',function(){
				var opt = {},formdata={},formstr='';
				opt.type = 'get';
				opt.url = 'https://passport.weibo.cn/signin/ajsu';
				opt.data = {};
				opt.data.entry = 'mweibo';
				var inputs = that.postform.getElementsByTagName('input');
				for(var i = 0 ;i<inputs.length;i++){
					formdata[inputs[i].id] = inputs[i].value;
				}
				formstr = encodeFormData(formdata);
				var loginRFValue = that.loginRF.value;
				if(that.mode == 0 ){
					opt.data.su = utf8_to_b64(trim(that.loginName.value));
				}
				opt.onsuccess = function(ret){
					var result = parseJSON(ret);
					if(result.retcode == 20000000){
						var href =	'https://passport.weibo.cn/signin/loginsms?code='+result.data.code+'&entry='+fEntry+'&r='+LOGIN_SUCCESS_ADDRESS+'&rf='+loginRFValue+'&'+formstr;
						if (that.featurecode.value || that.featurecode.value.trim().length !== 0) {
							href = href + "&featurecode=" + that.featurecode.value;
						}
						win.location.href = href;
					}
				}
				ajax(opt);
			});
			addEvent(that.loginnameclear,'click',function(){
				that.mode = 0;
				that.loginName.value = '';
				that.loginPassword.value = '';
				that.verifyCode.value = '';
				that.weidunCode.value = '';
				that.avatarWrapper.innerHTML='';
				that.verifyCodeWrapper.style.display = 'none';
				that.dVerifyCode.style.display = 'none';
				that.onInput();
				that.loginnameclear.className = "input-clear hid";
			});
		},
		weiboAppYORN : function(){
			var that = this;
			var loginRFValue = that.loginRF.value;
			var timeout = window.setTimeout(function(){
				that.loginWrapper.style.display = 'block';
				that.accountWrapper.style.display = 'none';
			}, 1000);

			if(that.logByAppAuth){

				var deviceType = that.logByAppAuth.getAttribute('weibo-data-os-name');
				var appScheme =	 that.logByAppAuth.getAttribute('weibo-data-onekey-param');
				var logByAppAuth_new = function(){
					that.logByAppAuth.onclick = that.ucORweiboLogin.onclick = function(){
						if(appScheme){
							that.openClient(appScheme);
						}
					};
				};

				if(deviceType && deviceType == 'ios'){
					// ios: 新方法
					logByAppAuth_new();
				}
				else{
					//android: 根据版本号判断
					jsonp({
						url: 'http://127.0.0.1:9527/query?appid=com.sina.weibo',
						onsuccess: function(ret){
							var result = parseJSON(ret);
							if(result){
								that.logByAppAuth.onclick = that.ucORweiboLogin.onclick = function(){
									var baseVer = '5.3.0';
									var curVer = result.versionName ||'0';
									var isUpperVer = compareVersion(baseVer,curVer);
									if(isUpperVer){
										// Android5.3.0以上：新方法
										if(appScheme){
											that.openClient(appScheme);
										}
									}
									else{
										// Android低版本 旧方法
										ajax({
											url: "https://passport.weibo.cn/sso/ajgetappt?entry=abc",
											type: 'get',
											onsuccess: function(ret){
												var result = parseJSON(ret);
												if(result.retcode == 20000000){
													that.openClient("sinaweibo://browser?url=https%3A%2F%2Fpassport.weibo.cn%2Fwapclient%2Fconfirm%3Ff%3Dw%26token%3D"+result.data.token, STAT_ACT_ONEKEY_WEBVIEW_CONFIRM);
													that.appsetInterval = window.setInterval(function(){that.appLogin(result.data.token)}, 3000);
												}else{
													win.location.href = "https://passport.weibo.cn/wapclient/error?info=1";
												}
											}
										});
									}
								}
							}
						},
						ontimeout : function(){
							logByAppAuth_new();
						},
						onerror : function(){
							logByAppAuth_new();
						}
					});
				}
			}	
		},
		
		openClient:function(scheme, action){
			if (typeof action == 'undefined') {
				if (scheme.indexOf("sinaweibo://weblogin") === 0) {
					action = STAT_ACT_ONEKEY_APP_CONFIRM;
				}
				if (scheme.indexOf("sinaweibo://browser")  === 0) {
					action = STAT_ACT_ONEKEY_WEBVIEW_OPEN;
				}
			}
			ajax({
				url: STAT_URL + '?' + 'entry=' + ENTRY + '&tag=apponekey&act=' + action + '&stat=' + STAT_ONEKEY_CLICK,
				type: 'get'
			});
						
			var that=this;
			var type = this.detectBrowser();
			if(type == "open"){
				var w = window.open(scheme, "_blank");
				setTimeout(function() {
						w.close();
				}, 0);
			}
			else{
				var $iframe = document.createElement('iframe');
				$iframe.src = scheme;
				$iframe.style.display = 'none';
				document.body.appendChild($iframe);
			}
			
			var startTime = Date.now();
			var _TIME_OUT = 3000;
			var timer = setTimeout(function() {
				var endTime = Date.now();
				//如果装了app并跳到客户端后，endTime - startTime 一定> timeout + 200
				if (!startTime || endTime - startTime < _TIME_OUT + 200) {
					that.logByAppAuth.innerHTML = '<span style="color:red;">呼起失败</span>';
					that.showTips('登录失败，请使用其它方式登录');
					ajax({
						url: STAT_URL + '?' + 'entry=' + ENTRY + '&tag=apponekey&act=' + action + '&stat=' + STAT_ONEKEY_FAIL,
						type: 'get'
					});
				}
			}, _TIME_OUT);

			window.onblur = function() {
				if(type != "open"){
					clearTimeout(timer);
				}  
			}
		},

		detectBrowser : function() {
			var b = navigator.userAgent;
			var type;

			if (/android/i.test(b)) {
				if (b.match(/MQQBrowser|UCBrowser|360Browser|Firefox|baidubrowse|SogouMobileBrowser|LieBaoFast|XiaoMi\/MiuiBrowser|opr/i)) {
					type = "iframe";
				} else if(b.match(/Chrome/i) && window.chrome){
					type = "open";
				}else{
					type = "iframe";
				}
			} else {
				if(b.match(/360Browser|QHBrowser|MQQBrowser/i)) {
					type = "open";
				}
				else{
					type = "iframe";
				}
			}
			return type;
		},
		showTips : function(msg,CW,CH,notClear){
			var h = 100,
				w = 100,
				t,
				l,
				pop = document.createElement("div"),
				scrollT =  document.documentElement.scrollTop || document.body.scrollTop;

			if($('J-showTip')){
				return;
			}
			document.body.appendChild(pop);
			pop.id = "J-showTip";


			CH = CH || window.innerHeight || document.documentElement.clientHeight;
			CW = CW || window.innerWidth || document.documentElement.clientWidth;
			l = parseInt((CW-w)/2);
			t = scrollT+parseInt((CH-h)/2);

			pop.style.cssText="width: 80px;height: 60px;position: absolute;text-align: center;border-radius: 8px;font-weight: bold;font-size: 12px;color: rgb(255, 255, 255);-webkit-transition: opacity 0.4s ease-out;transition: opacity 0.4s ease-out;background: rgba(0, 0, 0, 0.6);padding: 20px 10px;top:"+t+"px;left:"+l+"px;";
			pop.innerHTML = msg;

			if(!notClear){
				setTimeout(function(){
					pop.style.opacity = 0;
				},4000);
				setTimeout(function(){
					document.body.removeChild(pop);
				},5000);
			}			
			return pop;
		},
		doNeedVerifyCode: function(){
			this.needVerifyCode = true;
			this.verifyCodeWrapper.style.display = 'block';
			this.getVerifyImage();
		},
		doNeedWeidun: function(){
			this.needWeidun = true;
			this.dVerifyCode.style.display = 'block';
		},
		doNeedMobile : function(url){
			this.needWeidun = false;
			this.needVerifyCode = false;
			this.needMobile = true;
			this.verifyCodeWrapper.style.display = 'none';
			this.dVerifyCode.style.display = 'none';
			this.errorDialogBtnT.innerHTML = '验证码登录';
			this.errorDialogMsg.innerHTML = '您的账号是通过快速注册方式获得的，需通过验证码登陆方式登陆微博';
			this.errorDialog.style.display = 'block';
			this.setErrorDialogPanelPosition();
		},
		doLogin: function(){
			if(this.disabled){
				return;
			}
			var that = this;
			var fromValue = that.loginfrom.value;
			var loginRFValue = trim(that.loginRF.value);
			var loginRFCALValue = trim(that.loginRFCAL.value);

			if(that.validate()){
				var data;
				that.changeDisabled(true);
				if(that.mode == 0){
					data = {
						username: trim(that.loginName.value),
						password: trim(that.loginPassword.value),
						savestate: 1
					};
				} else {
					data = {
						password: trim(that.loginPassword.value),
						savestate: 1
					};
				}
				if(that.needWeidun){
					data.vsn = trim(that.weidunCode.value);
				//	that.weidunCode.value = '';
				}
				if(that.needVerifyCode){
					data.pincode = trim(that.verifyCode.value);
					data.pcid = that.verifyImage.getAttribute('data-pcid');
				}
				
				
				
				if(that.oldUserName.vaule != that.loginName.value){
					ERROR_COUNT = 0;
					ERROR_COUNT_Mobile = 0;
				}
				
				that.oldUserName.vaule = that.loginName.value;
				
				
				data.ec = ERROR_COUNT;

				
				data.pagerefer = document.referrer;

				data.entry = fEntry;
                data.wentry = fWentry;

				loginRFValue ? data.rf = trim(loginRFValue) : null;
				loginRFCALValue ? data.rfcal = trim(loginRFCALValue) : null;
				
				data.loginfrom = fromValue;
				data.client_id = fClientid;
				data.code = fCode;
				data.qq = fQq;
				
				if (that.featurecode.value || that.featurecode.value.trim().length !== 0) {
					data.featurecode = that.featurecode.value;
				}
				//支付免登录流程 红包飞新增
				data.hff = that.hff.value;
				data.hfp = that.hfp.value;

				//登录wifi
				if(typeof Zepto != "undefined"){
					Zepto.ajax({
						url: LOGIN,
						type: 'post',
						data: data,
						success: function(ret){
							var result = parseJSON(ret);
							if(result.retcode == 20000000){
								that.addCookie(result.data);
							} else {
								that.dealLoginFail(result);
							}
						}
					});
				}else{
					ajax({
						url: LOGIN,
						type: 'post',
						data: data,
						onsuccess: function(ret){
							var result = parseJSON(ret);
							if(result.retcode == 20000000){
								that.addCookie(result.data);
							} else {
								that.dealLoginFail(result);
							}
						}
					});
				}
			}
		},
		callClientApp : function(options){
			var conf = {
				//客户端APP呼起协议地址
				protocol : '',
				//客户端下载地址或者中间页地址
				url : '',
				//开始时间
				startTime : Date.now(),
				//呼起超时等待时间
				waiting : 800,
				//呼起操作限制时间
				callLimit : 50,
				//需要跳转到下载地址时
				onRedirect : function(){}
			};

			for(var attr in options){
				if(conf.hasOwnProperty(attr)){
					conf[attr] = options[attr];
				}
			}
			var ua = navigator.userAgent.toLowerCase();
			var platform = navigator.platform.toLowerCase();
			var version, m;

			var numberify = function(s) {
			    var c = 0;
			    try{
			        var arr = s.split(/[_\.]/);
			        var main = arr.shift();
			        c = parseFloat(main + '.' + arr.join(''), 10);
			    }catch(e){}
			    return c;
			};
			if( (m = ua.match(/\((ipad|iphone|ipod|itouch).*os\s([\d_\.]+)/)) && m[2]){
			    version = numberify(m[2]);
			}
			var wId;
			var isChrome = /(chrome|crios)\/([\d.]*)/.test(ua);
			if(isChrome) {
				// chrome下iframe无法唤起Android客户端，这里使用window.open
				// 另一个方案参考 https://developers.google.com/chrome/mobile/docs/intents
				var w = window.open(conf.protocol);
				wId = setInterval(function(){
					if(typeof w === 'object'){
						clearInterval(wId);
						w.close();
					}
				}, 10);
			}else if(version && version >=9){
				window.location = conf.protocol;
			}else {
				// 创建iframe
				var iframe = document.createElement('iframe');
				iframe.style.display = 'none';
				iframe.src = conf.protocol;
				document.body.appendChild(iframe);
			}

			setTimeout(function(){
				if(!isChrome){
					document.body.removeChild(iframe);
				}else{
					clearInterval(wId);
				}
				
				//ios下，跳转到APP，页面JS会被阻止执行。
				//因此如果超时时间大大超过了预期时间范围，可断定APP已被打开。
				if(Date.now() - conf.startTime < conf.waiting + conf.callLimit){
					// 在一定时间内无法唤起客户端，跳转下载地址或到中间页
					window.location = conf.url;

					if(typeof conf.onRedirect === 'function'){
						conf.onRedirect();
					}
				}
			}, conf.waiting);
		},
		saveHandler : function(){
			var that = this;
			var html = '该账号已开启安全设备，<a href="javascript:;" id="openApp">请点此使用微博客户端登录</a>';
			that.errorMsg.innerHTML = html;
			that.errorMsg.style.display = 'block';
			addEvent($('openApp'),'touchend',function(){
				that.callClientApp({
					startTime: Date.now(),
					waiting: 800,
					callLimit: 50,
					protocol : 'sinaweibo://splash',
					url : 'http://weibo.cn/qr/download'
				});
			});
		},
		changeDisabled : function(control){
			this.disabled = control;
		},
		errorDialogBtnHidden : function(){
			this.errorDialogBtnMsg.innerHTML = '';
			this.errorDialogBtn.style.display = 'none';
		},
		newRegister:function(){
			var href = this.register.href;
			this.errorDialogBtnHidden();
			win.location.href = href;		
		},
		dealLoginFail: function(result){
			//分成两种显示方式，一种是在顶导显示一种是用弹层显示
			var that = this;
			var loginRFValue = that.loginRF.value;
			if(result.retcode == 50011009 || result.retcode == 50011011 || result.retcode == 50011002 || result.retcode == 50011008 || result.retcode == 50011010 || result.retcode == 50011012){
				//当rf为1的时候只提示错误
				if(result.retcode == 50011002&&loginRFValue!=1) {
					if(ERROR_COUNT >= 2) {
						var errorData = parseJSON(result.data);
						if(errorData.er == 1) {
							that.errorDialogBtnT.innerHTML = '确定';
							addEvent(that.errorDialogBtnT,'click',function(){
								win.location.href = 'http://m.weibo.cn/forgotpwd/index';
							});
							that.errorDialogMsg.innerHTML = '登录失败，是否找回密码？';
							that.errorDialog.style.display = 'block';
							that.setErrorDialogPanelPosition();
						}
					}else if (result.data.im === 1){//只有绑定手机的用户才在两次错误的时候出现使用手机验证码登录的流程
						
						if(ERROR_COUNT_Mobile ===1){
					
							that.errorDialogBtnT.innerHTML = '验证码登录';
							that.errorDialogMsg.innerHTML = '帐号或密码错误，你也可以选择短信验证码方式登录微博。';
							that.errorDialog.style.display = 'block';
							that.setErrorDialogPanelPosition();
						
						}else{
							that.errorMsg.innerHTML = result.msg;
							that.errorMsg.style.display = 'block';
						}
						ERROR_COUNT++;
						ERROR_COUNT_Mobile++;
					} else{
						ERROR_COUNT++;
						ERROR_COUNT_Mobile = 0;
						that.errorMsg.innerHTML = result.msg;
						that.errorMsg.style.display = 'block';
					}
					if(that.needVerifyCode){
						that.getVerifyImage();
					}
				}else{
					that.errorMsg.innerHTML = result.msg;
					that.errorMsg.style.display = 'block';
				}
				
			}else if(result.retcode == 50030000){
				that.saveHandler();
			}else{
				that.errorMsg.innerHTML = result.msg;
				
				that.errorMsg.style.display = 'block';
				
				if(result.retcode == 50011003 || result.retcode == 50011004){
					that.needWeidun = true;
					that.dVerifyCode.style.display = 'block';
				} else if(result.retcode == 50011005 || result.retcode == 50011006){
					that.needVerifyCode = true;
					that.verifyCodeWrapper.style.display = 'block';		
					that.getVerifyImage();
				}			
			}
			that.weidunCode.value = '';
			that.changeDisabled(false);
		},
		addCookie: function(obj,uc){
			var that = this;
			
			setTimeout(function(){
				uc ? that.goToNextPageUC(obj) : that.goToNextPage(obj);
			},5000);
			var crossdomainlist = obj.crossdomainlist;
			var counter = objLength(crossdomainlist);
			if (counter == 0) {
				that.goToNextPage(obj);
			}
			for(var d in crossdomainlist) {
				if (!crossdomainlist.hasOwnProperty(d)) continue;
				jsonp({
					url: crossdomainlist[d] + '&savestate=1',
					onsuccess: function(){
						counter--;
						if (counter <= 0) {
							uc ? that.goToNextPageUC(obj) : that.goToNextPage(obj);
						}
					}
				});
			}
		},
		goToNextPage: function(obj){
			var that = this; 
			if(obj['toauth']!=1){
				var href =	obj['loginresulturl'] ? obj['loginresulturl'] + '&savestate=1&url=' + LOGIN_SUCCESS_ADDRESS : win.decodeURIComponent(LOGIN_SUCCESS_ADDRESS);
				win.location.href = href;
			}else{
				if(obj['ticket']){
					var ipt = document.createElement('input');
					that.postform.appendChild(ipt);
					ipt.id = 'ticket';
					ipt.name = 'ticket';
					ipt.type = 'hidden';
					ipt.value = obj['ticket'];
				}
				that.postform.submit();
			}
		},
		goToNextPageUC: function(obj){
			var that = this; 
			if(obj['toauth']!=1){
				var href = obj['loginresulturl'] ? obj['loginresulturl'] : win.decodeURIComponent(LOGIN_SUCCESS_ADDRESS);
				win.location.href = href;
			}else{
				if(obj['ticket']){
					var ipt = document.createElement('input');
					that.postform.appendChild(ipt);
					ipt.id = 'ticket';
					ipt.name = 'ticket';
					ipt.type = 'hidden';
					ipt.value = obj['ticket'];
				}
				that.postform.submit();
			}
		},
		validate: function(){
			var username = trim(this.loginName.value);
			var password = trim(this.loginPassword.value);
			var that = this;
			if(this.mode == 0){
				if(username.length == 0){
					this.errorMsg.innerHTML = '用户名不能为空';			
					this.errorMsg.style.display = 'block';
					return false;
				} else if(password.length == 0&&!this.needMobile){
					this.errorMsg.innerHTML = '密码不能为空';				
					this.errorMsg.style.display = 'block';
					return false;
				}
			} else {
				if(password.length == 0&&!this.needMobile){				
					this.errorMsg.innerHTML = '密码不能为空';
					this.errorMsg.style.display = 'block';
					return false;
				}
			}
			if(this.needWeidun && trim(this.weidunCode.value).length == 0){
				this.errorMsg.innerHTML = '请输入微盾动态码';		
				this.errorMsg.style.display = 'block';
				return false;
			} else if(this.needVerifyCode && trim(this.verifyCode.value).length == 0){
				this.errorMsg.innerHTML = '请输入验证码';		
				this.errorMsg.style.display = 'block';
				return false;
			}

			return true;
		},
		checkVerify: function(){
			var that = this;
			var oldUserName =that.oldUserName.value,username = trim(that.loginName.value);
			if(that.mode != 0&&oldUserName === username){
				return true;
			}else{
				//增加对于手机验证码登陆情况的判断，，增加一个超链，增加一个点击事件
				if(that.mode != 0){
					that.mode = 0;
					that.avatarWrapper.innerHTML='';
				}
				jsonp({
					url: PRELOGIN + '&su=' + utf8_to_b64(username),
					onsuccess: function(ret){
						if(ret.retcode === 0){
							if(ret.nopwd === 1&&ret.lm==1){
								that.verifyCodeWrapper.style.display = 'none';
								that.dVerifyCode.style.display = 'none';
								that.errorDialogBtnT.innerHTML = '验证码登录';
								that.errorDialogMsg.innerHTML = '您的账号是通过快速注册方式获得的，需通过验证码登陆方式登陆微博';
								that.errorDialog.style.display = 'block';
								that.setErrorDialogPanelPosition();
							}else{
								switch(ret.showpin){//此处不要忘记隐藏需要手机验证码登陆时要隐藏的东西
									case 1:
									that.dVerifyCode.style.display = 'none';
									that.verifyCodeWrapper.style.display = 'block';
									that.errorMsg.style.display = 'none';
									that.getVerifyImage();
									that.needVerifyCode = true;
									that.needMobile = false;
									that.needWeidun = false;
									break;
									case 2:
									that.dVerifyCode.style.display = 'block';
									that.verifyCodeWrapper.style.display = 'none';
									that.errorMsg.style.display = 'none';
									that.needWeidun = true;
									that.needMobile = false;
									that.needVerifyCode = false;
									break;
									default:
									that.verifyCodeWrapper.style.display = 'none';
									that.dVerifyCode.style.display = 'none';
									that.errorMsg.style.display = 'none';
									that.needVerifyCode = false;
									that.needWeidun = false;
									that.needMobile = false;
									break;
								}
							}
						}
					}
				});
			}
		},
		onInput: function(){
			this.errorMsg.innerHTML = '';
			this.errorMsg.style.display = 'none';
		},
		getVerifyImage: function(){
			var that = this;
			ajax({
				url: VERIFY_IMAGE,
				type: 'get',
				onsuccess: function(ret){
					var result = parseJSON(ret);
					if(result.retcode == 20000000){
						that.verifyImage.src = result.data.image;
						that.verifyImage.setAttribute('data-pcid', result.data.pcid);
					}
				}
			});
		},
		appLogin : function(token){
			var that = this;
			if(that.intervalCount >= 200){
				win.clearInterval(that.appsetInterval);
				that.intervalCount = 0;
				return;
			};
			that.intervalCount++;
			ajax({
				url: 'https://passport.weibo.cn/wapclient/check?token='+token+'&r='+LOGIN_SUCCESS_ADDRESS,
				type: 'get',
				onsuccess: function(ret){
					var json = parseJSON(ret);
					if(json.retcode == 20000000){
						window.location.href = json.data;
					}
				}
			})
		},
		setErrorDialogPanelPosition : function(){
			var that = this;
			that.setPosition(that.errorDialogPanel,'center');
		},
		setPosition : function(dom,position){
			var top,left,width = dom.offsetWidth,height = dom.offsetHeight,
				winWidth = doc.body.clientWidth,winHeight = doc.body.clientHeight,
				dd = doc.documentElement,db = doc.body,
				limitTop = top = Math.max(window.pageYOffset || 0, dd.scrollTop, db.scrollTop),
				limitLeft = left = Math.max(window.pageXOffset || 0, dd.scrollLeft, db.scrollLeft);
			if(position === 'center'){
				top +=(winHeight - height) / 2;
				left += (winWidth - width) / 2;
				if(top < limitTop) top = limitTop;
				if(left < limitLeft) left = limitLeft;
			}
			dom.style.top = top + 'px';
			dom.style.left = left + 'px';
		}
	};
	
	win.loginApp = new Login();
	
	addEvent(document, 'keydown', function(e){
		e = e || window.event;
		if(e.keyCode == 13){
			loginApp.doLogin();
		}
	});
	var url = window.location.href;
	//if(url.indexOf('openlock=1') > -1){
	//	win.loginApp.saveHandler();
	//}
})(window, document); 
