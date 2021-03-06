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

#if defined(WIN32) || defined(__CYGWIN__)
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the GSOAPFORMULTIX_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// GSOAPFORMULTIX_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GSOAPFORMULTIX_EXPORTS
#define GSOAPFORMULTIX_API __declspec(dllexport)
#else
#define GSOAPFORMULTIX_API __declspec(dllimport)
#endif

#endif
