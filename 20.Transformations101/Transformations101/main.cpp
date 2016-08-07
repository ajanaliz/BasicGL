#include <cmath>
#include <iostream>
#include<stdio.h>
#include <GL/glut.h>

#define PI 3.14159265

using namespace std;

static int n = 0;
static long font = (long)GLUT_BITMAP_TIMES_ROMAN_24;


void writeBitmapString(void *font, char *string)
{
	char *c;

	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

void floatToString(char * destStr, int p, float v)
{
	sprintf(destStr, "%f", v);

}



void drawWorldAxes(void)
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-300.0, 0.0);
	glVertex2f(300.0, 0.0);
	glVertex2f(0.0, -300.0);
	glVertex2f(0.0, 300.0);
	glEnd();
}


void writeFixedMessages(void)
{
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(190.0, 90.0, 0.0);
	writeBitmapString((void*)font, "draw ");
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos3f(190.0, 110.0, 0.0);
	writeBitmapString((void*)font, "translate");
	glRasterPos3f(190, 130.0, 0.0);
	writeBitmapString((void*)font, "rotate");
	glRasterPos3f(190, 150.0, 0.0);
	writeBitmapString((void*)font, "scale");
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	writeFixedMessages();
	drawWorldAxes();

	glColor3f(0.0, 0.0, 0.0);

	switch (n)
	{
	case 0:
		goto step0;
		break;
	case 1:
		goto step1;
		break;
	case 2:
		goto step2;
		break;
	case 3:
		goto step3;
		break;
	case 4:
		goto step4;
		break;

	default:
		break;
	}
step4:
	glPushMatrix();
	glLoadIdentity();
	glRasterPos3f(190.0, 150.0, 0.0);
	writeBitmapString((void*)font, "scale!");
	glPopMatrix();
	glLoadIdentity();
	glScalef(-0.5, 1.0, 1.0);
	glRecti(50, 100, 150, 150);
step3:
	glPushMatrix();
	glLoadIdentity();
	glRasterPos3f(190.0, 130.0, 0.0);
	writeBitmapString((void*)font, "rotate!");
	glPopMatrix();
	glLoadIdentity();
	glRotatef(90, 0.0, 0.0, 1.0);
	glRecti(50, 100, 150, 150);
step2:
	glPushMatrix();
	glLoadIdentity();
	glRasterPos3f(190.0, 110.0, 0.0);
	writeBitmapString((void*)font, "translate!");
	glPopMatrix();
	glLoadIdentity();
	glTranslatef(-200.0, -50.0, 0.0);
	glRecti(50, 100, 150, 150);
step1:
	glLoadIdentity();
	glRasterPos3f(190.0, 90.0, 0.0);
	writeBitmapString((void*)font, "draw! ");
	glLoadIdentity();
	glRecti(50, 100, 150, 150);
step0:
	glFlush();
}


void init(void)
{
	glClearColor(0.8, 0.8, 0.8, 1.0);
}


void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-300.0, 300.0, -300.0, 300.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void key1(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
		break;
	default:
		break;
	}
}


void key2(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		if (n < 4) n++; else n = 0;
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (n > 0) n--; else n = 4;
	}
	glutPostRedisplay();
}




int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("relativePlacement.cpp");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(key1);
	glutSpecialFunc(key2);
	init();
	glutMainLoop();
}