#include <GL\glut.h>
#include <cmath>
#define PI 3.14
#define N 40000

void drawCircle(float x, float y, float r, float z)
{
	float t = 0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(x, y, z);
	for (int i = 0; i < N;i++)
	{
		t = 2 * PI * i / N;
		glVertex3f(x + cos(t)*r, y + sin(t)*r, z);
	}
	glEnd();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 0.0, 0.0);
	drawCircle(50.0, 50.0, 30.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	drawCircle(50.0, 50.0, 20.0, 0.2);
	glColor3f(0.0, 0.0, 1.0);
	drawCircle(50.0, 50.0, 10.0, 0.4);
	glDisable(GL_DEPTH_TEST);
	glFlush();
}


void resize(int w,int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Z-Buffering");
	init();
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}