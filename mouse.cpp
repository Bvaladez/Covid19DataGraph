#include "stdlib.h"
#include "glut.h"
#include "mouse.h"
#include "graph.h"
#include "graphics.h"
#include "time.h"

#include <iostream>


Mouse::Mouse(int start, double width, double height, double radius, double dx, double dy, double x, double y, double rotation) {

	srand(time(0));
	
	mDx = dx;
	mDy = dy;
	mWidth = width;
	mHeight = height;
	mStartPos = start;
	mRadius = radius;
	mRotation = rotation;

	//the mouse should never start above the first row and will always start where the start of the maze is.
	mY = y;
	double centerMargin = .5;
	mX = x + mStartPos + centerMargin;
}

double Mouse::getX() {
	return mX ;
}

double Mouse::getY() {
	return mY;
}

double Mouse::getDX() {
	double degrees = this->getRotation();
	double radians = degrees * 3.145926 / 180.;
	double dx = std::cos(radians);
	return dx;
	//return mDx;
}

double Mouse::getDY() {
	double degrees = this->getRotation();
	double radians = degrees * 3.145926 / 180.;
	double dy = std::sin(radians);
	return dy;
	//return mDy;
}

double Mouse::getRadius() {
	return mRadius;
}

const double Mouse::getRotation() {
	return mRotation;
}

const double Mouse::getSpeed() {
	return mSpeed;
}

void Mouse::setSpeed(double speed) {
	mSpeed = speed;
}

void Mouse::addToRotation(double value) {
	mRotation += value;
}

void Mouse::drawRatInitialPos() {

	extern bool glLeftButtonDown;
	extern bool glRightButtonDown;	
	extern bool glMiddleButtonDown;
	extern Maze gMaze;

	glPushMatrix();
	
	//glTranslated(-1 * (mStartPos + centerMargin) + -1.*this->getX(), -1.*this->getY(), 0);
	//CURRENT
	
	//DrawLine(mX - mDx, mY - mDy, mX + 1, mY +1);
	glTranslated(this->getX(), this->getY(), gMaze.getZ(this->getX(), this->getY()));
	//glTranslated(centerMargin, 0, 0);
	
	//only rotates around the z axis as this is a 2D representation.
	if (glLeftButtonDown) {
		rotateLeft();
	}

	if (glRightButtonDown) {
		rotateRight();
	}

	if (glMiddleButtonDown) {
		scurryForward();
	}
	
	//need to translate to the origin before rotation occurs
	
	//CURRENT
	glRotated(getRotation(), 0, 0, 1);
	
	//glTranslated(-1 * (mStartPos + centerMargin) + -1.*this->getX(), -1.*this->getY(), 0);
	
	glScaled(.3, .3, 1.0);

	glTranslated(0., 0., 0. );

	drawRatShape();
	
	glPopMatrix();

	//if (glLeftButtonDown) {
	//	rotateLeft();
	//}

}



// TODO: add parameters and data members of current point so it is not drawn statically in draw rat
void Mouse::drawRatShape() {

	extern Maze gMaze;

	if (gMaze.getView() == 1)
	{
		return; // drawing yourself in rat view looks bad.
	}
	
	
	DrawTriangle(.7, 0, -.5, .5, -.5, -.5);
}

void Mouse::scurryForward() {

	extern Maze gMaze;

	double degrees = this->getRotation();

	double radians = degrees * 3.145926 / 180.;
	double dx = std::cos(radians);
	double dy = std::sin(radians);
	//double speed = .001;

	//DrawLine(mX - (dx * speed), mY - (dy * speed), mX, mY);
	bool lastMoveLegalFlag = false;

	int i = this->getX();
	int j = this->getY();

	//used for super rat mode
	double speed = .5;
	
		
	this->mX += dx * speed;
	this-> mY += dy * speed;
	lastMoveLegalFlag = true;

	glutPostRedisplay();
}


void Mouse::rotateRight() {

	//deltaRotation is negative so the rat will rotate right not left
	double deltaRotation = -.8;
	addToRotation(deltaRotation);
	glutPostRedisplay();
}


void Mouse::rotateLeft() {
	
	double deltaRotation = .8;
	addToRotation(deltaRotation);
	glutPostRedisplay();
}

