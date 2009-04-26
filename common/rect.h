/* Residual - Virtual machine to run LucasArts' 3D adventure games
 *
 * Residual is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $URL$
 * $Id$
 *
 */

#ifndef COMMON_RECT_H
#define COMMON_RECT_H

#include "common/sys.h"
#include "common/util.h"

namespace Common {

/**
 * Simple class for handling both 2D position and size.
 */
struct Point {
	int16 x;	//!< The horizontal part of the point
	int16 y;	//!< The vertical part of the point

	Point() : x(0), y(0) {}
	Point(const Point &p) : x(p.x), y(p.y) {}
	explicit Point(int16 x1, int16 y1) : x(x1), y(y1) {}
	Point & operator=(const Point & p) { x = p.x; y = p.y; return *this; };
	bool operator==(const Point & p) const { return x == p.x && y == p.y; };
	bool operator!=(const Point & p) const { return x != p.x || y != p.y; };

	/**
	 * Return the square of the distance between this point and the point p.
	 *
	 * @param p		the other point
	 * @return the distance between this and p
	 */
	uint sqrDist(const Point & p) const {
		int diffx = ABS(p.x - x);
		if (diffx >= 0x1000)
			return 0xFFFFFF;

		int diffy = ABS(p.y - y);
		if (diffy >= 0x1000)
			return 0xFFFFFF;

		return uint(diffx*diffx + diffy*diffy);
	}
};

/**
 * Simple class for handling a rectangular zone.
 *
 * Note: This implementation is built around the assumption that (top,left) is
 * part of the rectangle, but (bottom,right) is not. This is reflected in
 * various methods, including contains(), intersects() and others.
 *
 * Another very wide spread approach to rectangle classes treats (bottom,right)
 * also as a part of the rectangle.
 *
 * Conceptually, both are sound, but the approach we use saves many intermediate
 * computations (like computing the height in our case is done by doing this:
 *   height = bottom - top;
 * while in the alternate system, it would be
 *   height = bottom - top + 1;
 *
 * When writing code using our Rect class, always keep this principle in mind!
*/
struct Rect {
	int16 top, left;		//!< The point at the top left of the rectangle (part of the rect).
	int16 bottom, right;	//!< The point at the bottom right of the rectangle (not part of the rect).

	Rect() : top(0), left(0), bottom(0), right(0) {}
	Rect(int16 w, int16 h) : top(0), left(0), bottom(h), right(w) {}
	Rect(int16 x1, int16 y1, int16 x2, int16 y2) : top(y1), left(x1), bottom(y2), right(x2) {
		assert(isValidRect());
	}
	int16 width() const { return right - left; }
	int16 height() const { return bottom - top; }

	void setWidth(int16 aWidth) {
		right = left + aWidth;
	}

	void setHeight(int16 aHeight) {
		bottom = top + aHeight;
	}

	/**
	 * Check if given position is inside this rectangle.
	 *
	 * @param x the horizontal position to check
	 * @param y the vertical position to check
	 *
	 * @return true if the given position is inside this rectangle, false otherwise
	 */
	bool contains(int16 x, int16 y) const {
		return (left <= x) && (x < right) && (top <= y) && (y < bottom);
	}

	/**
	 * Check if given point is inside this rectangle.
	 *
	 * @param p the point to check
	 *
	 * @return true if the given point is inside this rectangle, false otherwise
	 */
	bool contains(const Point &p) const {
		return contains(p.x, p.y);
	}

	/**
	 * Check if the given rect is _fully_ contained inside this rectangle.
	 *
	 * @param r The rectangle to check
	 *
	 * @return true if the given rect is inside, false otherwise
	 */
	bool contains(const Rect &r) const {
		return (left < r.left) && (right > r.right) && (top < r.top) && (bottom > r.bottom);
	}

	/**
	 * Check if the given rect is equal to this one.
	 *
	 * @param r The rectangle to check
	 *
	 * @return true if the given rect is equal, false otherwise
	 */
	bool equals(const Rect &r) const {
		return (left == r.left) && (right == r.right) && (top == r.top) && (bottom == r.bottom);
	}

	/**
	 * Check if given rectangle intersects with this rectangle
	 *
	 * @param r the rectangle to check
	 *
	 * @return true if the given rectangle is inside the rectangle, false otherwise
	 */
	bool intersects(const Rect &r) const {
		return (left < r.right) && (r.left < right) && (top < r.bottom) && (r.top < bottom);
	}

	/**
	 * Extend this rectangle so that it contains r
	 *
	 * @param r the rectangle to extend by
	 */
	void extend(const Rect &r) {
		left = MIN(left, r.left);
		right = MAX(right, r.right);
		top = MIN(top, r.top);
		bottom = MAX(bottom, r.bottom);
	}

	/**
	 * Extend this rectangle in all four directions by the given number of pixels
	 *
	 * @param offset the size to grow by
	 */
	void grow(int16 offset) {
		top -= offset;
		left -= offset;
		bottom += offset;
		right += offset;
	}

	void clip(const Rect &r) {
		assert(isValidRect());
		assert(r.isValidRect());

		if (top < r.top) top = r.top;
		else if (top > r.bottom) top = r.bottom;

		if (left < r.left) left = r.left;
		else if (left > r.right) left = r.right;

		if (bottom > r.bottom) bottom = r.bottom;
		else if (bottom < r.top) bottom = r.top;

		if (right > r.right) right = r.right;
		else if (right < r.left) right = r.left;
	}

	void clip(int maxw, int maxh) {
		clip(Rect(0, 0, maxw, maxh));
	}

	bool isEmpty() const {
		return (left >= right || top >= bottom);
	}

	bool isValidRect() const {
		return (left <= right && top <= bottom);
	}

	void moveTo(int16 x, int16 y) {
		bottom += y - top;
		right += x - left;
		top = y;
		left = x;
	}

	void translate(int16 dx, int16 dy) {
		left += dx; right += dx;
		top += dy; bottom += dy;
	}

	void moveTo(const Point &p) {
		moveTo(p.x, p.y);
	}

	void debugPrint(int debuglevel = 0, const char *caption = "Rect:") const {
		debug(debuglevel, "%s %d, %d, %d, %d", caption, left, top, right, bottom);
	}

	/**
	 * Create a rectangle around the given center.
	 */
	static Rect center(int16 cx, int16 cy, int16 w, int16 h) {
		w /= 2;
		h /= 2;
		return Rect(cx - w, cy - h, cx + w, cy + h);
	}
};

}	// End of namespace Common

#endif