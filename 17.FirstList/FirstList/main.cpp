#include <GL\glut.h>
#include <iostream>
#include <cmath>
static float c1[3] = { 0.0, 0.0, 0.0 };
static float c2[3] = { 0.0, 0.0, 0.0 };
static float c3[3] = { 0.0, 0.0, 0.0 };
#define N 360
float r = 1.0;
int ah;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	float t = 2 * 3.14 / N;
	float angle = 0.0;
	ah = glGenLists(1);
	glNewList(ah, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= N; i++)
	{
		angle = i*t;
		glVertex2f(r*cos(angle), r*sin(angle));
	}
	glEnd();
	glEndList();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3fv(c1);
	glCallList(ah);
	glPopMatrix();
	glPushMatrix();
	glColor3fv(c2);
	glTranslatef(0.0, -2.5, 0.0);
	glCallList(ah);
	glPopMatrix();
	glPushMatrix();
	glColor3fv(c3);
	glTranslatef(0.0, 2.5, 0.0);
	glCallList(ah);
	glPopMatrix();
	glFlush();
}

void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void key1(int key, int x, int y)
{
	if (GLUT_KEY_F1 == key)
	{
		c1[0] = 0.0; c1[1] = 1.0; c1[2] = 0.0;
	}else if (GLUT_KEY_F2 == key)
	{
		c2[0] = 0.0; c2[1] = 0.0; c2[2] = 1.0;
	}
	else if (GLUT_KEY_F3 == key)
	{
		c3[0] = 1.0; c3[1] = 0.0; c3[2] = 0.0;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("working with lists -- Ali J");
	glutDisplayFunc(display);
	init();
	glutReshapeFunc(resize);
	glutSpecialFunc(key1);
	glutMainLoop();
	return 0;
}