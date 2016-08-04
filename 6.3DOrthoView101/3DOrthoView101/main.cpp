#include <GL\glut.h>



void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
}


void draw()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(80.0, 20.0, 0.0);
	glVertex3f(80.0, 80.0, 0.0);
	glVertex3f(20.0, 80.0, 0.0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(40.0, 40.0, 0.0);
	glVertex3f(60.0, 40.0, 0.0);
	glVertex3f(60.0, 60.0, 0.0);
	glVertex3f(40.0, 60.0, 0.0);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glFlush();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0,100.0,0.0,100.0,-1.0,1.0);
	//glOrtho(20.0, 80.0, 20.0, 80.0, -1.0, 1.0);
	glOrtho(0.0, 200.0, 0.0, 200.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char**argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3d view");
	glutDisplayFunc(display);
	init();
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0;
}