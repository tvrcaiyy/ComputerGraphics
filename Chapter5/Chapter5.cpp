// Chapter5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GL\glut.h"

void init()
{
	glClearColor(0.0,0.0,1.0,1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,800,0.0,600);
}

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0,0.0,0.0);
	glLineWidth(2);
	glBegin(GL_LINE);
	glVertex2i(100,100);
	glVertex2i(500,500);
	glEnd();
	glFlush();
}

void reshapeFunc(int newWidth,int newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,newWidth,0.0,newHeight);
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Chapter 5 Test!");

	init();

	glutDisplayFunc(displayFunc);
	//glutReshapeFunc(reshapeFunc);

	glutMainLoop();
	return 0;
}

