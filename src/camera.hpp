#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <stdexcept>

#include "vec3.hpp"
#include "plane.hpp"

class Camera {
public:
	Camera() {
		_loc.SetXYZ(0, 0, 0);
		_dir.SetXYZ(0, 0, 1);		
	}

	// Set the vertical FOV of the camera
	// Horizontal FOV will be set according to aspect ratio
	void SetFOV(double vFOV) {
		_vFOV = vFOV;

		// TODO: Get screen size for aspect ratio

		// Near clip plane
		near.SetOrigin(0, 0, 1);
		near._normal.SetXYZ(0, 0, 1);

		// Sides of the camera frustrum
		top.SetOrigin(0, 0 ,0);
		bottom.SetOrigin(0, 0, 0);
		left.SetOrigin(0, 0, 0);
		right.SetOrigin(0, 0, 0);

		// TODO: Calculate normal vectors of the frustrum sides
		throw std::logic_error("Not implemented");
	}

	void SetLoc(double x, double y, double z) {
		_loc.SetXYZ(x, y, z);
	}

	void PointAt(Vec3 target) {
		_dir = Vec3_sub(target, _loc);
		_dir.Normalize();
	}

	void ClipObject() {
		// TODO: Grab tris of object
		// TODO: Convert tris to Camera Space
		// TODO: Check if tri is within camera frustrum
		// TODO: Clip tris on camera planes if partially within frustrum
			// Generate tris as needed
	}

private:
	// Location in game world
	Vec3 _loc;

	// Where the camera is pointing
	Vec3 _dir;

	// Vertical FOV
	double _vFOV = 90;

	// These are stationary in camera space
	Plane near;
	//Plane far;
	Plane top;
	Plane bottom;
	Plane left;
	Plane right;
};

#endif