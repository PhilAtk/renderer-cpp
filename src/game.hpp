#ifndef GAME_HPP
#define GAME_HPP

#include <stdio.h>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "camera.hpp"
#include "mesh.hpp"
#include "object3d.hpp"

class Game {
public:
	Game() {
		// Add a cube mesh
		meshes.push_back(new Mesh());

		// Add an object that uses the cube mesh
		objects.push_back(*new Object3D(meshes[0], Vec3(0,0,0), Vec3(0,0,1)));

		cam.SetLoc(-3, 3, -3);
		cam.PointAt(Vec3(0,1,0));
	}

	~Game() {
	}

	void Update() {
		// Update locations of things
	}

private:
	Camera cam;
	std::vector<Mesh*> meshes;
	std::vector<Object3D> objects;
};

#endif