
/******************************************************************************

Coral Tree gpl/track.cc
Copyright (C) 1998 Infinite Monkeys Incorporated

This program is free software; you can redistribute it and/or modify
it under the terms of the Artistic License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
Artistic License for more details.

You should have received a copy of the Artistic License along with
this program (see meta/ART_LICE); if not, write to coral@imonk.com.

******************************************************************************/

#include <gpl/gpl.h>

GPL_DoubleList<GPL_Track> GPL_Track::gplTrack;

GPL_Track::GPL_Track()
{
	gplTrack.AppendNode(this);
}

GPL_Track::~GPL_Track()
{
	if(!gplTrack.RemoveNode(this))
	{
		gplLog("GPL ERROR", "removing object not existant");
	}
}

