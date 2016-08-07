#include "Point.h"


float Point::size = 3.0;


vector<Point>points;



void display(){
	vector<Point>::iterator pointit;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	pointit = points.begin();
	while (pointit != points.end()){

		pointit->drawpoint();
		pointit++;
	}
	glFlush();
}

void mouse1(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON&&state == GLUT_DOWN)
		points.push_back(Point(x, height - y));
	if (button == GLUT_RIGHT_BUTTON&&state == GLUT_DOWN)  exit(0);
	glutPostRedisplay();
}
void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);

}
void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, w, 0.0, w, -1.0, 1.0);
	width = w;
	height = h;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(720, 80);
	glutInitWindowSize(500, 500);
	glutCreateWindow("mouse");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
	glutMouseFunc(mouse1);
	glutMainLoop();
	return 0;

}