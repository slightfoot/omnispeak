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

#ifndef ID_CA_H
#define ID_CA_H

#include <stdbool.h>
#include <stdint.h>

#include "id_mm.h"
#include "id_sd.h"
// -- Common --
void CA_Startup(void);
void CA_Shutdown(void);

// -- Audio --
void CA_CacheAudioChunk(int16_t chunk);
void CA_LoadAllSounds(void);

// -- File IO --

char* CAL_AdjustExtension(const char *filename);
bool CA_FarWrite(int handle, uint8_t *source, int length);
bool CA_ReadFile(const char *filename, void *offset);
bool CA_SafeReadFile(const char *filename, void *offset, int bufLength);
bool CA_WriteFile(const char *filename, void *offset, int bufLength);
bool CA_LoadFile(const char *filename, mm_ptr_t *ptr, int *memsize);
int CAL_RLEWCompress (void *src, int expLength, void *dest, uint16_t rletag);


// -- Graphics --

#define CA_MAX_GRAPH_CHUNKS 8192
// The GFXINFOE structure containing info about the EGAGRAPH (see TED5)
typedef struct ca_gfxinfo
{
	uint16_t numTiles8, numTiles8m, numTiles16, numTiles16m, numTiles32, numTiles32m;
	uint16_t offTiles8, offTiles8m, offTiles16, offTiles16m, offTiles32, offTiles32m;
	uint16_t numBitmaps, numMasked, numSprites;
	uint16_t offBitmaps, offMasked, offSprites;
	uint16_t hdrBitmaps, hdrMasked, hdrSprites;
	uint16_t numBinaries, offBinaries;
} ca_gfxinfo;

extern uint8_t ca_levelnum, ca_levelbit;
extern int16_t ca_mapOn;
extern uint8_t ca_graphChunkNeeded[CA_MAX_GRAPH_CHUNKS];
extern ca_gfxinfo ca_gfxInfoE;

extern mm_ptr_t ca_graphChunks[CA_MAX_GRAPH_CHUNKS];

void CA_CacheGrChunk(int chunk);
void CA_ClearMarks(void);
void CA_SetGrPurge(void);
void CA_MarkGrChunk(int chunk);
void CA_LockGrChunk(int chunk);

// The string may be temporarily modified by US_CPrint, hence it's non-const.
void CA_CacheMarks(char *msg);
void CA_UpLevel(void);
void CA_DownLevel(void);

// -- Maps --

#define CA_NUMMAPPLANES 3
#define CA_NUMMAPS 100


typedef struct CA_MapHeader
{
	uint32_t planeOffsets[CA_NUMMAPPLANES];
	uint16_t planeLengths[CA_NUMMAPPLANES];
	uint16_t width, height;
	char name[16];
	char signature[4];
} __attribute__((__packed__)) CA_MapHeader;

extern CA_MapHeader *CA_MapHeaders[CA_NUMMAPS];

extern uint16_t *CA_mapPlanes[CA_NUMMAPPLANES];

extern uint8_t *CA_audio[NUMSNDCHUNKS];

/* Keen: custom cachebox hooks
 * NOTE: The string may be temporarily modified
 * by US_CPrint, so it's non-const.
 */
extern void	(*ca_beginCacheBox)	(char *title, int numcache);
extern void	(*ca_updateCacheBox)	(void);
extern void	(*ca_finishCacheBox)	(void);


void CA_CacheMap(int mapIndex);
uint16_t *CA_TilePtrAtPos(int x, int y, int plane);
uint16_t CA_TileAtPos(int x, int y, int plane);
void CA_SetTileAtPos(int x, int y, int plane, int value);
uint16_t CA_GetMapHeight();
uint16_t CA_GetMapWidth(); 


#endif
