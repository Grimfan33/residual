// Residual - Virtual machine to run LucasArts' 3D adventure games
// Copyright (C) 2003-2005 The ScummVM-Residual Team (www.scummvm.org)
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA

#ifndef DRIVER_TINYGL_H
#define DRIVER_TINYGL_H

#include "bits.h"
#include "vector3d.h"
#include "color.h"
#include "model.h"
#include "colormap.h"
#include "bitmap.h"
#include "driver.h"

#include "tinygl/gl.h"
#include "tinygl/zgl.h"

#include <SDL.h>

#define BITMAP_TEXTURE_SIZE 256

class DriverTinyGL : public Driver {
public:
	DriverTinyGL(int screenW, int screenH, int screenBPP);
	virtual ~DriverTinyGL();

	void setupCamera(float fov, float nclip, float fclip, float roll);
	void positionCamera(Vector3d pos, Vector3d interest);

	void clearScreen(); 
	void flipBuffer();

	void startActorDraw(Vector3d pos, float yaw, float pitch, float roll);
	void finishActorDraw();
	
	void set3DMode();

	void drawHierachyNode(const Model::HierNode *node);
	void drawModelFace(const Model::Face *face, float *vertices, float *vertNormals, float *textureVerts);

	void createMaterial(Material *material, const char *data, const CMap *cmap);
	void selectMaterial(const Material *material);
	void destroyMaterial(Material *material);

	void createBitmap(Bitmap *bitmap);
	void drawBitmap(const Bitmap *bitmap);
	void destroyBitmap(Bitmap *bitmap);

	void drawDepthBitmap(int x, int y, int w, int h, char *data);
	void drawBitmap();

	void drawEmergString(int x, int y, const char *text, const Color &fgColor);
	void loadEmergFont();

	void prepareSmushFrame(int width, int height, byte *bitmap);
	void drawSmushFrame(int offsetX, int offsetY);

private:
	ZBuffer *_zb;
	SDL_Surface *_screen;
	SDL_Surface *_smushSurface;
	SDL_Surface *_zbufferSurface;
	byte *_fullScreenBitmapData;
	byte *_fullScreenZBitmapData;
	int _smushWidth;
	int _smushHeight;
};

#endif