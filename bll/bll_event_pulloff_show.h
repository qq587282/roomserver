/*
 *  bll_event_pulloff_show.h
 *
 *  To do：
 *  Created on: 	2012-2-7
 *  Author: 		luocj
 */

#ifndef BLL_EVENT_PULLOFF_SHOW_H_
#define BLL_EVENT_PULLOFF_SHOW_H_

#include <stdlib.h>
#include <time.h>
#include "common/common_api.h"
#include "def/server_namespace.h"
#include "global.h"
#include "main_frame.h"
#include "bll_base.h"
#include "dal/from_client_message.h"
#include "dal/to_server_message.h"
#include "../dal/to_client_message.h"
#include "ctl/server_datacenter.h"

FRAME_ROOMSERVER_NAMESPACE_BEGIN

class CPullOffShowEvent:public CBllBase
{
public:
	CPullOffShowEvent()
	{
	}

	virtual ~CPullOffShowEvent()
	{
	}

	//消息事件
	virtual int32_t OnMessageEvent(MessageHeadSS * pMsgHead, IMsgBody* pMsgBody,const uint16_t nOptionLen = 0, const void *pOptionData = NULL);

	//会话事件激活
	virtual int32_t OnSessionEvent(MessageHeadSS * pMsgHead, IMsgBody* pMsgBody, CFrameSession* pSession, const uint16_t nOptionLen = 0, const void *pOptionData = NULL);

	int32_t OnSessionTimeOut(CFrameSession *pSession);
private:
	int32_t OnEventPullOffShow(MessageHeadSS *pMsgHead, IMsgBody* pMsgBody,const uint16_t nOptionLen = 0, const void *pOptionData = NULL);
	int32_t SendNotifyToUser(RoomID nRoomID,RoleID nSrcRoleID,RoleID nDestRoleID,const uint16_t nOptionLen = 0, const void *pOptionData = NULL);
	int32_t SendResponseToUser(MessageHeadSS *pMsgHead,PullResult nPullResult,const uint16_t nOptionLen = 0, const void *pOptionData = NULL);
	int32_t SendNotifyToMediaServer(MessageHeadSS *pMsgHead,RoleID nPullOffRoleID,int32_t nDestTelMediaID,int32_t nDestCncMediaID);
};

#define	CREATE_PULLOFFSHOWEVENT_INSTANCE			CSingleton<CPullOffShowEvent>::CreateInstance
#define	GET_PULLOFFSHOWEVENT_INSTANCE				CSingleton<CPullOffShowEvent>::GetInstance
#define	DESTROY_PULLOFFSHOWEVENT_INSTANCE			CSingleton<CPullOffShowEvent>::DestroyInstance

FRAME_ROOMSERVER_NAMESPACE_END

#endif /* BLL_EVENT_PULLOFF_SHOW_H_ */
