#ifndef VEC3_HPP
#define VEC3_HPP

class Vec3 {
public:
	double _x;
	double _y;
	double _z;

	Vec3() {
		SetXYZ(0, 0, 0);
	}

	Vec3(double x, double y, double z) {
		SetXYZ(x, y, z);
	}

	void SetXYZ(double x, double y, double z) {
		_x = x;
		_y = y;
		_z = z;
	}

	void Normalize() {
		double len = GetMagnitude();

		_x = _x / len;
		_y = _y / len;
		_z = _z / len;
	}

	double GetMagnitude() {
		return 1.0/sqrt(_x*_x + _y*_y + _z*_z);
	}
};

// Returns the result of adding the two given vectors
Vec3 Vec3_add(Vec3 v1, Vec3 v2) {
	return Vec3(v1._x+v2._x, v1._y+v2._y, v1._z+v2._z);
}

// Returns the result of subtracting the second vector from the first
Vec3 Vec3_sub(Vec3 v, Vec3 sub) {
	return Vec3(v._x-sub._x, v._y-sub._y, v._z-sub._z);
}

// Returns the dot product of the two given vectors
double Vec3_dot(Vec3 v1, Vec3 v2) {
	return v1._x*v2._x + v1._y*v2._y + v1._z*v2._z;
}

#endif