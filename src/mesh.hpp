#ifndef MESH_HPP
#define MESH_HPP

#include <stdlib.h>
#include <vector>

#include "vec3.hpp"

class Tri {
public:
	Vec3 verts[3];

	Tri(Vec3 v1, Vec3 v2, Vec3 v3) {
		this->verts[0] = v1;
		this->verts[1] = v2;
		this->verts[2] = v3;
	}	
};

// Container for Tris
// Origin is assumed (0, 0, 0)
class Mesh {
public:
	int num_verts;
	int num_tris;

	std::vector<Vec3> verts;
	std::vector<Tri> tris;

	// TODO: Create from mdl/obj file

	Mesh(double cube_length=10) {
		this->num_verts = 8;
		this->num_tris = 12;

		// Cube Verticies
		for (int i=0; i<=1; i++) {
			for (int j=0; j<=1; j++) {
				for (int k=0; k<=1; k++) {
					verts.push_back(*new Vec3(i*cube_length, j*cube_length, k*cube_length));
				}
			}
		}

		// Cube Triangles, 2 per face
		// TODO: Confirm these are correct by rendering
		tris.push_back(*new Tri(verts[0], verts[1], verts[3]));
		tris.push_back(*new Tri(verts[0], verts[3], verts[2]));
		tris.push_back(*new Tri(verts[1], verts[5], verts[7]));
		tris.push_back(*new Tri(verts[1], verts[7], verts[3]));
		tris.push_back(*new Tri(verts[5], verts[4], verts[6]));
		tris.push_back(*new Tri(verts[5], verts[6], verts[7]));
		tris.push_back(*new Tri(verts[4], verts[0], verts[2]));
		tris.push_back(*new Tri(verts[4], verts[2], verts[6]));
		tris.push_back(*new Tri(verts[2], verts[3], verts[7]));
		tris.push_back(*new Tri(verts[2], verts[7], verts[6]));
		tris.push_back(*new Tri(verts[4], verts[0], verts[1]));
	}
};

#endif