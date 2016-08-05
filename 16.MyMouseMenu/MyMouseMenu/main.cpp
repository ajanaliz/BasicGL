#include <iostream>
#include <GL/glut.h>
using namespace std;


static float square_color[3] = { 1.0, 0.0, 0.0 };


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3fv(square_color);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(80.0, 20.0, 0.0);
	glVertex3f(80.0, 80.0, 0.0);
	glVertex3f(20.0, 80.0, 0.0);
	glEnd();
	glFlush();
}


void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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


void top_menu(int id)
{
	if (id == 1) exit(0);
}

void color_menu(int id)
{
	if (id == 2)
	{
		square_color[0] = 1.0; square_color[1] = 0.0; square_color[2] = 0.0;
	}
	if (id == 3)
	{
		square_color[0] = 0.0; square_color[1] = 0.0; square_color[2] = 1.0;
	}
	glutPostRedisplay();
}


void makeMenu(void)
{
	int sub_menu = glutCreateMenu(color_menu);
	glutAddMenuEntry("Red", 2);
	glutAddMenuEntry("Blue", 3);
	glutCreateMenu(top_menu);
	glutAddSubMenu("Color", sub_menu);
	glutAddMenuEntry("Quit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	makeMenu();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("menus.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	setup();
	glutMainLoop();
	return 0;
}
