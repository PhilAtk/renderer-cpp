#ifndef PLANE_HPP
#define PLANE_HPP

#include <stdexcept>

#include "vec3.hpp"

class Plane {
public:
	Vec3 _origin;
	Vec3 _normal;

	// Ground plane
	Plane() {
		_origin.SetXYZ(0, 0, 0);
		// ASSUME Y IS UP
		_normal.SetXYZ(0, 1, 0);
	}

	Plane(Vec3 origin, Vec3 direction) {
		_origin = origin;
		_normal = direction;
		_normal.Normalize();
	}

	void SetOrigin(double x, double y, double z) {
		_origin.SetXYZ(x, y, z);
	}

	void SetOrigin(Vec3 v) {
		_origin = v;
	}

	// Returns true if the given vector lies on the same side of the origin that the normal faces
	bool PointAbovePlane(Vec3 v) {
		throw std::logic_error("Not implemented");
	}

	// Returns true if the line drawn between the two given vectors intersects the plane
	// Populates 'out' with the intersection point if it exists
	bool LineIntersectsPlane(Vec3 v1, Vec3 v2, Vec3* out) {
		bool v1Above = PointAbovePlane(v1);
		bool v2Above = PointAbovePlane(v2);

		// FIX: Edgecase of points lying on the plane

		// If the points are on opposite sides of the plane, there's an intersection point
		if (v1Above != v2Above) {
			throw std::logic_error("Not implemented");
		}

		out = nullptr;
		return false;
	}

private:
};

#endif