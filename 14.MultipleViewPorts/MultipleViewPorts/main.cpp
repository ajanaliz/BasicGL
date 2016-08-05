#include <cmath>
#include <iostream>
#include <GL/glut.h>

#define PI 3.14159265

static int width, height;


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width / 2.0, height);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(10.0, 10.0, 0.0);
	glVertex3f(40.0, 10.0, 0.0);
	glVertex3f(40.0, 40.0, 0.0);
	glVertex3f(10.0, 40.0, 0.0);
	glEnd();
	glViewport(width / 2.0, 0, width / 2.0, height);
	glColor3f(0.0, 0.0, 1.0);
	float angle;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 30; ++i)
	{
		angle = 2 * PI * i / 30;
		glVertex2f(50.0 + cos(angle) * 40.0, 50.0 + sin(angle) * 40.0);
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.1, 100.0, 0.0);
	glEnd();
	glLineWidth(1.0);
	glFlush();
}


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}


void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	width = w;
	height = h;
}


void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Double ViewPorts -- Ali J");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	init();
	glutMainLoop();
}