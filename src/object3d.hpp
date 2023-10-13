#ifndef OBJECT3D_HPP
#define OBJECT3D_HPP

#include "mesh.hpp"
#include "vec3.hpp"

class Object3D {
public:
	Object3D(Mesh* mesh, Vec3 loc, Vec3 orientation) {
		_mesh = mesh;
		_loc = loc;
		_orientation = orientation;
	}

private:
	Vec3 _loc;

	// Which direction is model space <0, 0, 1> in world space
	Vec3 _orientation;

	Mesh* _mesh;
};

#endif