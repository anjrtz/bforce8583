/*!	\file	
 ISO8583IssuerGatewayFEApp.cpp: implementation of the CISO8583IssuerGatewayFEApp class.
*/
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

#include "ISO8583IssuerGatewayFE.h"
#include "ISO8583IssuerGatewayFEApp.h"
#include	"ISO8583IssuerGatewayFEServerLink.h"
#include	"ISO8583IssuerGatewayFEProcess.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//!	see CMultiXApp::CMultiXApp
CISO8583IssuerGatewayFEApp::CISO8583IssuerGatewayFEApp(int	Argc,char	*Argv[],std::string	Class)	:
	CMultiXApp(Argc,Argv,ISO8583IssuerGatewayFE_SOFTWARE_VERSION,Class,0)
{
	CreateLogger(ISO8583IssuerGatewayFE_SOFTWARE_VERSION);
}

//!	Destructor
CISO8583IssuerGatewayFEApp::~CISO8583IssuerGatewayFEApp()
{
}
//!	see CMultiXApp::AllocateNewProcess
CMultiXProcess * CISO8583IssuerGatewayFEApp::AllocateNewProcess(TMultiXProcID ProcID)
{
	return	new	CISO8583IssuerGatewayFEProcess(ProcID);
}


//!	see CMultiXApp::OnStartup
void CISO8583IssuerGatewayFEApp::OnStartup()
{
	Logger()->ReportInfo(DebugPrint(0,"Application started\n"));
	CMultiXApp::OnStartup();
}

//!	see CMultiXApp::OnTpmConfiguredLink

void CISO8583IssuerGatewayFEApp::OnTpmConfiguredLink(CMultiXTpmConfiguredLink &Link)
{
	
	if(Link.OpenMode	==	MultiXOpenModeServer)
	{
		CISO8583IssuerGatewayFEServerLink	*pLink	=	new	CISO8583IssuerGatewayFEServerLink(Link.ConfigParams);
		AddLink(pLink);
		if(!pLink->Listen(Link.LocalPort))
		{
			Logger()->ReportError(DebugPrint(0,"Listen Failed on Ip=%s , Port=%s\n",Link.LocalAddress.c_str(),Link.LocalPort.c_str()));
		}	else
		{
			DebugPrint(1,"Started Listenning on Ip=%s , Port=%s\n",pLink->LocalName().c_str(),pLink->LocalPort().c_str());
		}
	}
			CMultiXApp::OnTpmConfiguredLink(Link);
}

bool CISO8583IssuerGatewayFEApp::OnMultiXException(CMultiXException &e)
{
	Logger()->ReportError(
		DebugPrint(0,"Exception occured at file \"%s\" Line %d\nApplication Message=\"%s\"\n\nProgram TERMINATED !!!\n",
								e.m_File.c_str(),
								e.m_Line,
								e.m_Text.c_str()));
	return	false;
}
//!	see	CMultiXApp::OnShutdown
void CISO8583IssuerGatewayFEApp::OnShutdown()
{
	Logger()->ReportInfo(DebugPrint(0,"Application stopped\n"));
}

//!	see	CMultiXApp::OnPrepareForShutdown
void CISO8583IssuerGatewayFEApp::OnPrepareForShutdown(int32_t WaitTime)
{
	//	if we have listeners we close all of them so no new connections will be accepted
	for(CMultiXLink	*Link	=	GetFirstLink();Link;Link=Link->ID().Next())
	{
		if(Link->IsRaw()	&&	Link->OpenMode()	==	MultiXOpenModeServer)
			Link->Close();
	}
	if(WaitTime	<	2000)
		End();
}

//!	see	CMultiXApp::OnProcessRestart
void CISO8583IssuerGatewayFEApp::OnProcessRestart()
{
	//	we are required to end immediately, so we call End()
	End();
}
//!	see	CMultiXApp::OnProcessRestart
void CISO8583IssuerGatewayFEApp::OnProcessSuspend()
{
	//	Add your own code for suspend request
}
//!	see	CMultiXApp::OnProcessRestart
void CISO8583IssuerGatewayFEApp::OnProcessResume()
{
	//	Add your own code for resume request
}



//!	see	CMultiXApp::OnTpmConfigCompleted
void CISO8583IssuerGatewayFEApp::OnTpmConfigCompleted()
{
}

//!	see	CMultiXApp::OnApplicationEvent
void CISO8583IssuerGatewayFEApp::OnApplicationEvent(CMultiXEvent *Event)
{
}

//!	see	CMultiXApp::OnConnectProcessFailed
void CISO8583IssuerGatewayFEApp::OnConnectProcessFailed(TMultiXProcID ProcessID)
{
	Logger()->ReportInfo(DebugPrint(0,"Connect to Process %d Failed !!!\n",ProcessID));
}
