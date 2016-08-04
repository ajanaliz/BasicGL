#include <GL\glut.h>
#include <iostream>
#include <cmath>
#define N 360
#define PI 3.14
static float R = 0.7;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	float d = 2 * 3.14 / N;
	float angle = 0.0;
	glLineWidth(10);
	glBegin(GL_LINE_STRIP);
	for (int i = 180; i <= 270;i++)
	{
		glColor3f(0.0, 0.6, 0.6);
		angle = i*d;
		glVertex2f(cos(angle)*R + 0.5, sin(angle)*R + 0.5);
		glVertex2f(cos(angle)*R + 0.7, sin(angle)*R + 0.7);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(cos(270 * d)*R + 0.5, sin(270 * d)*R + 0.5);
	glVertex2f(cos(270 * d)*R + 0.7, sin(270 * d)*R + 0.7);
	glVertex2f(0.7, -0.25);
	glVertex2f(0.5, -0.45);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(cos(180 * d)*R + 0.5, sin(180 * d)*R + 0.5);
	glVertex2f(cos(180 * d)*R + 0.7, sin(180 * d)*R + 0.7);
	glVertex2f(0., -0.25);
	glVertex2f(-0.2, -0.45);
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