#include <GL\glut.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.7, 0.6);
	glRectf(-7.0, -7.0, 7.0, 7.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-4.0, -4.0, 4.0, 4.0);
	glColor3f(0.0, 0.5, 1.0);
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glVertex2f(4.0, 4.0);
	glVertex2f(-7.0, 7.0);
	glVertex2f(-4.0, 4.0);
	glVertex2f(-7.0, -7.0);
	glVertex2f(-4.0, -4.0);
	glVertex2f(7.0, -7.0);
	glVertex2f(4.0, -4.0);
	glVertex2f(7.0, 7.0);
	glVertex2f(4.0, 4.0);
	glEnd();
	glFlush();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc,char **argv)
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