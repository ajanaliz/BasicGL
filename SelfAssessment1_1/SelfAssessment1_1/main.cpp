#include <GL\glut.h>
#include <iostream>


void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.7, -0.1);
	glVertex2f(-0.1, -0.1);
	glVertex2f(-0.1, 0.5);
	glVertex2f(-0.7, 0.5);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.2, -0.3);
	glVertex2f(0.8, -0.3);
	glVertex2f(0.5, 0.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.2, 0.3);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.4, 0.7);
	glVertex2f(0.2, 0.7);
	glVertex2f(0.1, 0.5);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("few shapes");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}