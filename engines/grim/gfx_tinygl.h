/* Residual - A 3D game interpreter
 *
 * Residual is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 *
 */

#ifndef GRIM_GFX_TINYGL_H
#define GRIM_GFX_TINYGL_H

#include "engines/grim/gfx_base.h"

#include "graphics/tinygl/zgl.h"

namespace Grim {

class ModelNode;
class Mesh;
class MeshFace;

class GfxTinyGL : public GfxBase {
public:
	GfxTinyGL();
	virtual ~GfxTinyGL();

	byte *setupScreen(int screenW, int screenH, bool fullscreen);

	const char *getVideoDeviceName();

	void setupCamera(float fov, float nclip, float fclip, float roll);
	void positionCamera(Math::Vector3d pos, Math::Vector3d interest);

	void clearScreen();
	void flipBuffer();

	bool isHardwareAccelerated();

	void getBoundingBoxPos(const Mesh *model, int *x1, int *y1, int *x2, int *y2);

	void startActorDraw(Math::Vector3d pos, float scale, const Math::Angle &yaw,
						const Math::Angle &pitch, const Math::Angle &roll);
	void finishActorDraw();
	void setShadow(Shadow *shadow);
	void drawShadowPlanes();
	void setShadowMode();
	void clearShadowMode();
	void setShadowColor(byte r, byte g, byte b);
	void getShadowColor(byte *r, byte *g, byte *b);

	void set3DMode();

	void translateViewpointStart(Math::Vector3d pos, const Math::Angle &pitch,
								 const Math::Angle &yaw, const Math::Angle &roll);
	void translateViewpointFinish();

	void drawHierachyNode(const ModelNode *node, int *x1, int *y1, int *x2, int *y2);
	void drawModelFace(const MeshFace *face, float *vertices, float *vertNormals, float *textureVerts);
	void drawSprite(const Sprite *sprite);

	void enableLights();
	void disableLights();
	void setupLight(Light *light, int lightId);
	void turnOffLight(int lightId);

	void createMaterial(Texture *material, const char *data, const CMap *cmap);
	void selectMaterial(const Texture *material);
	void destroyMaterial(Texture *material);

	void createBitmap(BitmapData *bitmap);
	void drawBitmap(const Bitmap *bitmap);
	void destroyBitmap(BitmapData *bitmap);

	void createFont(Font *font);
	void destroyFont(Font *font);

	void drawTextObject(TextObject *text);
	void createTextObject(TextObject *text);
	void destroyTextObject(TextObject *text);

	void dimScreen();
	void dimRegion(int x, int y, int w, int h, float level);
	void irisAroundRegion(int x1, int y1, int x2, int y2);

	Bitmap *getScreenshot(int w, int h);
	void storeDisplay();
	void copyStoredToDisplay();

	void drawEmergString(int x, int y, const char *text, const Color &fgColor);
	void loadEmergFont();

	void drawRectangle(PrimitiveObject *primitive);
	void drawLine(PrimitiveObject *primitive);
	void drawPolygon(PrimitiveObject *primitive);

	void prepareMovieFrame(Graphics::Surface* frame);
	void drawMovieFrame(int offsetX, int offsetY);
	void releaseMovieFrame();

protected:

private:
	TinyGL::ZBuffer *_zb;
	byte *_screen;
	byte *_smushBitmap;
	int _smushWidth;
	int _smushHeight;
	byte *_storedDisplay;
};

} // end of namespace Grim

#endif
