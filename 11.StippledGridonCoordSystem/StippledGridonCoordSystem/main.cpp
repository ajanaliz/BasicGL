#include<GL/glut.h>
#include<stdio.h>
#include<cmath>
static long font = (long)GLUT_BITMAP_TIMES_ROMAN_24;


void writestring(void *font, char *string){

	char *c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);

}

void grid()
{
	glColor3f(0.0, 0.0, 0.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x00FF);
	glBegin(GL_LINES);
	for (int i = -5; i < 6;i++)
	{
		glVertex2f(5 * i, 25.0);
		glVertex2f(5 * i, -25.0);
	}
	for (int i = -5; i < 6; i++)
	{
		glVertex2f(25.0, 5 * i);
		glVertex2f(-25.0, 5 * i);
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}

void drawaxes(){

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-50.0, 0.0);
	glVertex2f(50.0, 0.0);
	glVertex2f(0.0, -50.0);
	glVertex2f(0.0, 50.0);
	glEnd();
	glRasterPos3f(48, -2.0, 0.0);
	writestring((void *)font, "x");
	glRasterPos3f(1.0, 48.0, 0.0);
	writestring((void *)font, "y");
}
void resize(int w, int h){


	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawaxes();
	grid();
	glFlush();
}


void init(){
	glClearColor(0.8, 0.8, 0.8, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My Awesome Grid -- Ali J");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
}