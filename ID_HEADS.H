/* Catacomb Abyss Source Code
 * Copyright (C) 1993-2014 Flat Rock Software
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

// ID_GLOB.H


#include <ALLOC.H>
#include <CTYPE.H>
#include <DOS.H>
#include <ERRNO.H>
#include <FCNTL.H>
#include <IO.H>
#include <MEM.H>
#include <PROCESS.H>
#include <STDIO.H>
#include <STDLIB.H>
#include <STRING.H>
#include <SYS\STAT.H>

#define __ID_GLOB__

//--------------------------------------------------------------------------

#define	EXT	"ABS"

extern	char far introscn;

#include "GFXE_ABS.H"
#include "AUDIOABS.H"
#include "MAPSABS.H"

//--------------------------------------------------------------------------

//
// DEFINES THE TILE ATTRIBUTE CHECKING CONVENTION (macros).
//
// DEFINE CUSTOM BIT-FLAG NAMES...
//


#define tf_SOLID							0x01
#define tf_SPECIAL						0x02
#define tf_EMBEDDED_KEY_COLOR			0x04

#define TILE_FLAGS(tile)   (tinf[FLAGS+(tile)])

#define GATE_KEY_COLOR(tile)		((unsigned char)(TILE_FLAGS(tile)>>4))

#define CAT3D

#define	TEXTGR	0
#define	CGAGR	1
#define	EGAGR	2
#define	VGAGR	3

#define  EGA320GR	10					// MDM (GAMERS EDGE)
#define  EGA640GR	11					// MDM (GAMERS EDGE)

#define GRMODE	EGAGR

#if GRMODE == EGAGR
#define GREXT	"EGA"
#endif
#if GRMODE == CGAGR
#define GREXT	"CGA"
#endif

//#define PROFILE

//
//	ID Engine
//	Types.h - Generic types, #defines, etc.
//	v1.0d1
//

#ifndef	__TYPES__
#define	__TYPES__

typedef	enum	{false,true}	boolean;
typedef	unsigned	char		byte;
typedef	unsigned	int			word;
typedef	unsigned	long		longword;
typedef	byte *					Ptr;

typedef	struct
		{
			int	x,y;
		} Point;
typedef	struct
		{
			Point	ul,lr;
		} Rect;

#define	nil	((void *)0)

#endif

#include "ID_MM.H"
#include "ID_CA.H"
#include "ID_VW.H"
#include "ID_IN.H"
#include "ID_SD.H"
#include "ID_US.H"


void	Quit (char *error, ...);		// defined in user program

//
// replacing refresh manager with custom routines
//

#define	PORTTILESWIDE		21      // all drawing takes place inside a
#define	PORTTILESHIGH		14		// non displayed port of this size

#define UPDATEWIDE			(PORTTILESWIDE+1)
#define UPDATEHIGH			PORTTILESHIGH

#define	MAXTICS				6
#define DEMOTICS			3

#define	UPDATETERMINATE	0x0301

extern	unsigned	mapwidth,mapheight,tics,realtics;
extern	boolean		compatability;

extern	byte		*updateptr;
extern	unsigned	uwidthtable[UPDATEHIGH];
extern	unsigned	blockstarts[UPDATEWIDE*UPDATEHIGH];
