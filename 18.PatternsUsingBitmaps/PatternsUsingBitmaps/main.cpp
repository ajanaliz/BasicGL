#include<GL/glut.h>


GLubyte rasters[24] = { 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xff, 0xc0, 0xff, 0xc0 };

void init(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2i(20, 20);
	glBitmap(10, 12, 0.0, 0.0, 12.0, 0.0, rasters);
	glBitmap(10, 12, 0.0, 0.0, 12.0, 0.0, rasters);
	glFlush();
}

void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int x, char **y){
	glutInit(&x, y);
	glutCreateWindow("F pattern -- Ali J");
	init();
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}