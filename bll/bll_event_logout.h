/*
 * bll_event_logout.h
 *
 *  Created on: 2011-12-20
 *      Author: jimm
 */

#ifndef BLL_EVENT_LOGOUT_H_
#define BLL_EVENT_LOGOUT_H_

#include <stdlib.h>
#include <time.h>
#include "common/common_api.h"
#include "def/server_namespace.h"
//#include "def/def_message_body.h"
#include "dal/from_client_message.h"
#include "dal/to_client_message.h"
#include "dal/from_server_message.h"
#include "dal/dal_room.h"
#include "global.h"
#include "main_frame.h"
#include "bll_base.h"


FRAME_ROOMSERVER_NAMESPACE_BEGIN

class CLogoutMessageEvent : public CBllBase
{
public:
	CLogoutMessageEvent()
	{
	}

	virtual ~CLogoutMessageEvent()
	{
	}

	//消息事件
	virtual int32_t OnMessageEvent(MessageHeadSS * pMsgHead, IMsgBody* pMsgBody,
			const uint16_t nOptionLen = 0, const void *pOptionData = NULL);

	//会话事件激活
	virtual int32_t OnSessionEvent(MessageHeadSS * pMsgHead, IMsgBody* pMsgBody,
			CFrameSession* pSession, const uint16_t nOptionLen = 0, const void *pOptionData = NULL);

	int32_t OnSessionTimeOut(CFrameSession *pSession);
};

#define	CREATE_LOGOUTEVENT_INSTANCE		CSingleton<CLogoutMessageEvent>::CreateInstance
#define	GET_LOGOUTEVENT_INSTANCE		CSingleton<CLogoutMessageEvent>::GetInstance
#define	DESTROY_LOGOUTEVENT_INSTANCE	CSingleton<CLogoutMessageEvent>::DestroyInstance

FRAME_ROOMSERVER_NAMESPACE_END

#endif /* BLL_EVENT_LOGOUT_H_ */
