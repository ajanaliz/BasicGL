#include <cmath>
#include <GL/glut.h>
#define PI 3.14159265
static int id1, id2;


void display1(void)
{
	glutSetWindow(id1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(10.0, 10.0, 0.0);
	glVertex3f(40.0, 10.0, 0.0);
	glVertex3f(40.0, 40.0, 0.0);
	glVertex3f(10.0, 40.0, 0.0);
	glEnd();
	glFlush();
}


void display2(void)
{
	glutSetWindow(id2);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	float angle;
	int i;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 30; ++i)
	{
		angle = 2 * PI * i / 30;
		glVertex2f(50.0 + cos(angle) * 40.0, 50.0 + sin(angle) * 40.0);
	}
	glEnd();
	glFlush();
}


void init1(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}


void init2(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}


void resize1(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 50.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void resize2(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void key1(unsigned char key, int x, int y)
{
	if (key == 27) exit(0);
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(250, 500);
	glutInitWindowPosition(100, 100);
	id1 = glutCreateWindow(" window 1");
	init1();
	glutDisplayFunc(display1);
	glutReshapeFunc(resize1);
	glutKeyboardFunc(key1);
	glutInitWindowSize(250, 500);
	glutInitWindowPosition(400, 100);
	id2 = glutCreateWindow(" window 2");
	init2();
	glutDisplayFunc(display2);
	glutReshapeFunc(resize2);
	glutKeyboardFunc(key1);
	glutMainLoop();
	return 0;
}