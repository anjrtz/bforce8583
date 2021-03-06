/*

MultiX Network Applications Development Toolkit.
Copyright (C) 2007, Moshe Shitrit, Mitug Distributed Systems Ltd., All Rights Reserved.

This file is part of MultiX.

MultiX is free software; you can redistribute it and/or modify it under the terms of the 
GNU General Public License as published by the Free Software Foundation; 
either version 2 of the License, or (at your option) any later version. 

MultiX is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program;
if not, write to the 
Free Software Foundation, Inc., 
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
--------------------------------------------------------------------------------
Author contact information: 
msr@mitug.co.il
--------------------------------------------------------------------------------

*/
#pragma once
#include "ISO8583TestClientLink.h"

class CISO8583TestClientClientLink :
	public CISO8583TestClientLink,
	public	CMultiXAlertableObject
{
public:
	enum	TTimersCodes
	{
		ConnectRetriesTimer	=	1
	};

	CISO8583TestClientClientLink(TTpmConfigParams	&Params);
	~CISO8583TestClientClientLink(void);
	inline	int32_t	&MaxConnectRetries(){return	m_MaxConnectRetries;}	//!<	used by the application, MultiX does not manage it.
	inline	int32_t	&ConnectRetriesDelay(){return	m_ConnectRetriesDelay;}	//!<	used by the application, MultiX does not manage it.
	CMultiXTimer * SetTimer(int TimerCode, uint32_t Timeout);
	void CancelConnectTimer();

protected:
	bool OnConnectFailed(int IoError);
	void OnLinkConnected(void);
	bool	OnLinkClosed(void);
	void OnTimer(CMultiXTimer *pTimer);



protected:
	int32_t	m_MaxConnectRetries;
	int32_t	m_ConnectRetriesDelay;
	int	m_ConnectRetries;
	CMultiXTimer	*m_pConnectTimer;	//!< used for setting timeouts on send operations
};
