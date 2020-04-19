#pragma once
#include "graphics.h"

const int Resolution = 100;
const int WIDTH = Resolution;
const int HEIGHT = Resolution;
const int ZHEIGHT = Resolution;
const int WATERH = -2;


struct Cell
{
	Cell();
	//double getZ( double x, double y);

	//void Draw2d(double x, double y);
	//void Draw2d(int x, int y);
	//void Draw3d(int x, int y, int z);
	bool left, top, right, bottom;
	
	//double zMappingc(double x, double y);
	//double zMappingc(int x, int y);

	void visitCell();
	bool isVisited();

private:
	bool mVisited;
};

class Maze
{
public:
	Maze();

	void DrawWater(int width, int height);
	void setView(int view);
	int getView();
	void CurveMapping(double x, double y, double z);
	double zMapping(double x, double y);
	double getZ(double x, double y);
	void DrawGrid(int x, int y, int z);
	void DrawGridVerticleY(int x, int y, int z);
	void DrawGridVerticleX(int x, int y, int z);


	void Draw();

private:
	Cell cells[WIDTH][HEIGHT];
	int mStartPoint;
	int mEndPoint;
//  0 perspective, 1 rat		
	int mView = 0;
	bool mSuperRat = false;
	
};

