#include <iostream>
#include <GL\glut.h>
#include <cmath>



void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display()
{
	float r = 1.0;
	glClear(GL_COLOR_BUFFER_BIT);
	int n = 360;
	float dTheta = 2 * 3.14 / n;
	float angle = 0.0;
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i <= n; i++)
	{
		angle = i*dTheta;
		glVertex2f(r*cos(angle), r*sin(angle));
	}
	glEnd();
	glFlush();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("2Squares");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0;
}