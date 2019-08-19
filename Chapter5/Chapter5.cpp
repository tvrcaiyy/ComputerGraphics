// Chapter5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GL\glut.h"

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluOrtho2D(0.0,800,0.0,600);
}

void displayFunc()
{
	/*glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	//glLineWidth(2);
	glBegin(GL_POLYGON);
	glVertex3i(100,500,0);
	glVertex3i(100,100,0);
	glVertex3i(500,100,0);

	glVertex3i(500,100,0);
	glVertex3i(500,500,10);
	glVertex3i(100,500,0);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glPolygonMode(GL_FRONT,GL_LINE);
	glBegin(GL_POLYGON);
	glVertex3i(100,500,0);
	glVertex3i(100,100,0);
	glVertex3i(500,100,0);
	
	glVertex3i(500,100,0);
	glVertex3i(500,500,10);
	glVertex3i(100,500,0);
	glEnd();*/

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0,1.0,0.0);
	//glLineWidth(2);
	glBegin(GL_QUADS);
	glVertex3f(-0.5,0.5,0);
	glVertex3f(-0.5,-0.5,0);
	glVertex3f(0.5,-0.5,0);

	glVertex3f(0.5,-0.5,0);
	glVertex3f(0.5,0.5,-1.0);
	glVertex3f(-0.5,0.5,0);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glPolygonMode(GL_FRONT,GL_LINE);
	glBegin(GL_QUADS);
	glVertex3f(-0.5,0.5,0);
	glVertex3f(-0.5,-0.5,0);
	glVertex3f(0.5,-0.5,0);

	glVertex3f(0.5,-0.5,0);
	glVertex3f(0.5,0.5,-1.0);
	glVertex3f(-0.5,0.5,0);
	glEnd();
	glFlush();
}

void reshapeFunc(int newWidth,int newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0.0,newWidth,0.0,newHeight);
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

