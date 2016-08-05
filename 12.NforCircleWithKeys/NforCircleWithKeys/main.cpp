#include<GL/glut.h>
#include<stdio.h>
#include<cmath>
static long font = (long)GLUT_BITMAP_TIMES_ROMAN_24;
int n = 10;
float x = 0.0, y = 0.0;
float r = 1.0;
float t;
char s[10];
void writestring(void *font, char *string){
	char *c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}
void floattostring(char *c, int p, float v){
	sprintf(c, "%f", v);
	c[p] = '\0';
}
void drawaxes(){
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-2.0, 0.0);
	glVertex2f(2.0, 0.0);
	glVertex2f(0.0, -2.0);
	glVertex2f(0.0, 2.0);
	glEnd();

}
void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void writemessage(){
	glColor3f(1.0, 1.0, 1.0);
	floattostring(s, 4, (float)n);
	glRasterPos3f(-1.5, 0.90, 0.0);
	writestring((void *)font, "n=");
	writestring((void *)font, s);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	drawaxes();
	writemessage();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++){
		glVertex2f(x + r*cos(t), y + r*sin(t));
		t += 2 * 3.14 / n;
	}
	glEnd();
	glFlush();
}


void init(){
	glClearColor(0.8, 0.8, 0.8, 1.0);
}
void key1(unsigned char key, int x, int y){
	switch (key){
	case 27:
		exit(0);
		break;
	default:break;
	}
}
void key2(int key, int x, int y){
	if (key == GLUT_KEY_UP)
		n++;
	if (key == GLUT_KEY_DOWN)
		if (n > 0)n--;


	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My Custom Circle - Ali J");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(key1);
	glutSpecialFunc(key2);
	init();
	glutMainLoop();
}