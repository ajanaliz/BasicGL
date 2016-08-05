#include <GL\glut.h>
#include <iostream>
#include <cmath>
#define N 100
#define PI 3.14
static float R = 1.0;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	float t = 0, x = 0.0, y = 0.0;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < N;i++)
	{
		glVertex2f(x + R*cos(t), y + R*sin(t));
		t += 2 * PI / N;
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Circle");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}