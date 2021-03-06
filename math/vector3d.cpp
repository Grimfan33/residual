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
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 *
 * $URL$
 * $Id$
 */

#include "common/streamdebug.h"

#include "math/vector3d.h"

namespace Math {

Vector3d::Matrix() :
	MatrixType<3, 1>() {
	x() = 0;
	y() = 0;
	z() = 0;
}

Vector3d::Matrix(float lx, float ly, float lz) :
	MatrixType<3, 1>() {
	x() = lx;
	y() = ly;
	z() = lz;
}

Vector3d::Matrix(const MatrixBase<3, 1> &vec) :
	MatrixType<3, 1>(vec) {
}

void Vector3d::set(float lx, float ly, float lz) {
	x() = lx; y() = ly; z() = lz;
}

// Get the angle a vector is around the unit circle
// (ignores z-component)
Angle Vector3d::unitCircleAngle() const {
	return Angle::arcTangent2(y(), x());
}

}
