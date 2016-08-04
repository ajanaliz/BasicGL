#include <GL\glut.h>
#include <cmath>



void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	float t, r = 4.0, pi = 3.14;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (t = -10 * pi; t <= 10 * pi;t+=pi/20.0)
	{
		glVertex3f(r*cos(t), r*sin(t), r*t / pi);
	}
	glEnd();
	glFlush();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char**argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3d frustam view spiral");
	glutDisplayFunc(display);
	init();
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0;
}