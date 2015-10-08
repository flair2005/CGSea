//---------------------------------------------------------------------------
//
// Jun Burden 2015
//
//----------------------------------------------------------------------------

#pragma once

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "comp308.hpp"
#include "geometry.hpp"
#include "marchingCubes.hpp"

//boundary values for Marching Cubes
#define MINX -10.0
#define MAXX 10.0
#define MINY -10.0
#define MAXY 10.0
#define MINZ -10.0
#define MAXZ 10.0

class Terrain {
private:
	Geometry *g_geometry = nullptr;

	//minimal value and number of cells on each axis: passed into Marching Cubes
	float minValue = 0.0;
	int nX = 20;
	int nY = 20;
	int nZ = 20;
	//data points passed to Marching Cubes
	comp308::vec4 * mcPoints;
	//data returned by Marching Cubes
	TRIANGLE * Triangles;
	int numOfTriangles;

	float calculateDensity(vec4);

public:
	Terrain();
	Terrain(std::string);

	void renderTerrain();
};