#pragma once
#include<GL/glut.h>
#include<vector>
#include<cstdlib>


using namespace std;
static int width, height;
class Point {
public:
	Point(int x, int y);
	~Point();
	void drawpoint();
private:
	int x, y;
	static float size;
};

