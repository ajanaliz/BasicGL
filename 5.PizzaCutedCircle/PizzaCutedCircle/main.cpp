#include<GL/glut.h>
#include<cmath>
void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int n = 360;
	float dTheta = 2 * 3.1415926 / n;
	float angle = 0.0;
	float r = 1.0;
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 1, 0);
	glVertex2f(0.0, 0.0);
	for (int i = n/4; i <= n; i++)
	{
		angle = i*dTheta;
		glVertex2f(r*cos(angle), r*sin(angle));
	}
	glEnd();
	glFlush();
}


int main(int argc, char**argv){
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("example1");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}