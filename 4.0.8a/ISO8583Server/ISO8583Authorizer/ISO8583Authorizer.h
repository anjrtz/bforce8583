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
#if !defined(ISO8583Authorizer_H_Included)
#define ISO8583Authorizer_H_Included

#pragma once
#include	<MultiXApp.h>
#include	<ISO8583Shared.h>
#include <mysql++.h>
#include	<custom.h>
#include <transaction.h>

#define	ISO8583Authorizer_SOFTWARE_VERSION	"1.00"

enum	TISO8583AuthorizerErrorCodes
{
	ErrLinkDisconnected	=	10000,
	ErrInvalidMsgCode	=	10001,
	ErrUnableToForwardMsg	=	10002,
	ErrMsgForwardTimedout	=	10003
};
// TODO: reference additional headers your program requires here


#endif // !defined(ISO8583Authorizer_H_Included)
