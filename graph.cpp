#include "stdlib.h" //stdlib has to be inlcuded before glut to ovveride its exit
#include "glut.h"
#include "graphics.h"
#include "graph.h"
#include "time.h"
#include "mouse.h"

#include <cmath>
#include <iostream>
#include <vector>

extern Mouse rat;

Cell::Cell()
{
	left = top = right = bottom = true;
	mVisited = false;
}

//double Cell::getZ(double x,double y) {
//	return zMappingc(rat.getX(), rat.getY());
//}

void Cell::visitCell() {
	this->mVisited = true;
}

bool Cell::isVisited() {
	if (this->mVisited == true) {
		return true;
	}
	return false;
}

void Maze::DrawGrid(int x, int y, int z)
{

		glColor3d(0, 0, 0);
		
		//int chaos = 425;
		//int r = rcolorChaos(x, y, chaos);
		//int g = gcolorChaos(x, y, chaos);
		//int b = bcolorChaos(x, y, chaos);
		//glColor3ub(r, g, b);

		DrawQuadOutline(x, y, z, x, y + 1, z, x + 1, y + 1, z, x + 1, y, z);
			glColor3b(0, 0, 0);

}

void Maze::DrawGridVerticleY(int x, int y, int z)
{

		glColor3d(0, 0, 0);
		
		//int chaos = 425;
		//int r = rcolorChaos(x, y, chaos);
		//int g = gcolorChaos(x, y, chaos);
		//int b = bcolorChaos(x, y, chaos);
		//glColor3ub(r, g, b);

		DrawQuadOutline(x, y, z, x, y + 1, z, x, y + 1, z + 1, x, y, z + 1);
			glColor3b(0, 0, 0);

}

void Maze::DrawGridVerticleX(int x, int y, int z)
{

		glColor3d(0, 0, 0);
		
		//int chaos = 425;
		//int r = rcolorChaos(x, y, chaos);
		//int g = gcolorChaos(x, y, chaos);
		//int b = bcolorChaos(x, y, chaos);
		//glColor3ub(r, g, b);

		DrawQuadOutline(x, y, z, x + 1, y, z, x + 1, y, z + 1, x, y, z + 1);
			glColor3b(0, 0, 0);

}
Maze::Maze() {

}

void Maze::setView(int view) {
	mView = view;
}

double Maze::getZ(double x, double y) {
	double z = zMapping(x, y);
	if (WATERH > z) {
		return WATERH;
	}
	return z;
}


double Maze::zMapping(double x, double y) {
	double z = 0;

	return z;
	
}

void Maze::CurveMapping(double x, double y, double z) {
	int i = 0;
	//time += 1;
	//deaths += i * 1.2;
	glColor3ub(1, 0, 0);
	
	for (int i = 0; i < WIDTH; i++) {

		DrawLinesConnected(x, y, z);
		DrawLinesConnected(x + 1, y + 1, z);
		DrawLinesConnected(x + 1, y + 2, z);
		DrawLinesConnected(x + 1, y + 3, z);
	}
}




void Maze::Draw() {
	for (int i = 0; i < WIDTH; i++){
		for (int j = 0; j < HEIGHT; j++){
				
			/*	if(this->mView == 0 ){
				cells[i][j].Draw2d(i, j);
			}*/
			
			//double z = function of sin/cos product and sums
			//cells[i][j].Draw3d(i, j, z);
			glColor3ub(0,0,0);
			DrawGrid(i, j, 0);

			if (i == WIDTH - 1 || j == HEIGHT - 1) {
				for (int z = 0; z < ZHEIGHT; z++) {
					
					if (i == WIDTH - 1) {
						DrawGridVerticleY(i, j, z);
					}
					else {
						DrawGridVerticleX(i, j, z);
					}

				}
			}
				

		}
	}
	DrawLinesConnected(1, 1, 1);
	
	glColor3ub(0,0,0);
}

int Maze::getView() {
	return mView;
}

int rcolorChaos(int x, int  y, int chaos) {
	int a = x + chaos;
	int b = y + chaos;

	//int a = x + rand();
	//int b = y + rand();
	
	if (x == 0) {
		a = 1;
	}

	if ( y == 0) {
		b = 1;
	}

	return (((a * 32241) + (b * 43882)) % 256);
}


//CSV


