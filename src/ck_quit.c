/*
Omnispeak: A Commander Keen Reimplementation
Copyright (C) 2012 David Gow <david@ingeniumdigital.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ck_cross.h"

void CK_ShutdownID(void); // TODO: Hack?

void Quit(const char *msg) {
	CK_ShutdownID();
	if (!msg || !(*msg))
	{
		CK_Cross_LogMessage(CK_LOG_MSG_NORMAL, "Thanks for playing Commander Keen!\n");
		exit(0);
	}
	else
	{
		//__asm__("int $3");
		CK_Cross_puts(msg);
		exit(-1);
	}
}
