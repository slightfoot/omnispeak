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

#ifndef ID_RF_H
#define ID_RF_H

#include <stdint.h>
#include <stdbool.h>

// Sprite Draw object
typedef struct RF_SpriteDrawEntry
{
	int chunk;
	int zLayer;
	int x, y;
	int sx, sy;
	int sw, sh;
	bool maskOnly;
	struct RF_SpriteDrawEntry **prevNextPtr;		// Pointer to the previous entry's 'next' pointer.
	struct RF_SpriteDrawEntry *next;
} RF_SpriteDrawEntry;

// Width/Height of the screen buffers in-game.
#define RF_BUFFER_WIDTH_TILES 21
#define RF_BUFFER_HEIGHT_TILES 14

#define RF_BUFFER_WIDTH_PIXELS (RF_BUFFER_WIDTH_TILES << 4)
#define RF_BUFFER_HEIGHT_PIXELS (RF_BUFFER_HEIGHT_TILES << 4)

#define RF_BUFFER_WIDTH_UNITS (RF_BUFFER_WIDTH_TILES << 8)
#define RF_BUFFER_HEIGHT_UNITS (RF_BUFFER_HEIGHT_TILES << 8)

// Width/Height of the visible screen in tiles.
#define RF_SCREEN_WIDTH_TILES 20
#define RF_SCREEN_HEIGHT_TILES 13


extern int rf_scrollXUnit, rf_scrollYUnit;
extern int rf_scrollXMinUnit;
extern int rf_scrollYMinUnit;
extern int rf_scrollXMaxUnit;
extern int rf_scrollYMaxUnit;

extern void (*rf_drawFunc) (void);

void RF_SetScrollBlock(int tileX, int tileY, bool vertical);
void RF_MarkTileGraphics();
void RF_SetDrawFunc(void (*func) (void));
void RF_Startup();
void RF_NewMap(void);
void RF_RenderTile16(int x, int y, int tile);
void RF_RenderTile16m(int x, int y, int tile);
void RF_ReplaceTileBlock(int srcx, int srcy, int destx, int desty, int width, int height);
void RF_ReplaceTiles(uint16_t *tilePtr, int plane, int dstX, int dstY, int width, int height);
void RF_Reposition(int scrollXunit, int scrollYunit);
void RF_SmoothScroll(int scrollXdelta, int scrollYdelta);
void RF_RemoveSpriteDraw(RF_SpriteDrawEntry **drawEntry);
void RF_AddSpriteDraw(RF_SpriteDrawEntry **drawEntry, int unitX, int unitY, int chunk, bool allWhite, int zLayer);
void RF_Refresh();

#endif //ID_RF_H
