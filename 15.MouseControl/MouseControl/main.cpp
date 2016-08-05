#include<GL/glut.h>

static float c[3] = { 1.0, 0.0, 0.0 };

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3fv(c);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(80.0, 20.0, 0.0);
	glVertex3f(80.0, 80.0, 0.0);
	glVertex3f(20.0, 80.0, 0.0);
	glEnd();
	glFlush();
}
void m(int button, int state, int x, int y)
{
	switch (button){
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			c[0] = 0.0;
			c[1] = 1.0;
			c[2] = 0.0;
		}
		else{
			if (state == GLUT_UP){
				c[0] = 0.0;
				c[1] = 1.0;
				c[2] = 1.0;
			}
		}
		break;
	default:break;
	}
}

void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitWindowPosition(720, 80);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Mouse Control -- Ali J");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(m);
	glutMainLoop();
	return 0;
}
