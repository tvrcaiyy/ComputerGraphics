#include "stdafx.h"

#include <stdio.h>

#include <GL/glut.h>      // (or others, depending on the system in use)
//test
// GLint points[8][3] = {{0,0,0},{0,1,0},{1,0,0},{1,1,0},
// 					{0,0,1},{0,1,1},{1,0,1},{1,1,1}};

GLfloat points[8][3] = {{-0.5,-0.5,-0.5},{-0.5,0.5,-0.5},{0.5,-0.5,-0.5},{0.5,0.5,-0.5},
					{-0.5,-0.5,0.5},{-0.5,0.5,0.5},{0.5,-0.5,0.5},{0.5,0.5,0.5}};

GLubyte vertexIndex[] = {6,2,3,7,5,1,0,4,4,0,2,6,7,3,1,5,4,6,7,5,1,3,2,0};

GLubyte bitShape [20] = {
	0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00,
	0xff, 0x80, 0x7f, 0x00, 0x3e, 0x00, 0x1c, 0x00, 0x08, 0x00};

GLubyte rasters[24] = {  
	0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,  
	0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,  
	0xff, 0xc0, 0xff, 0xc0};  

GLubyte label[] = {'t','h','e',' ','q','u','i','c','k',' ','b','r','o','w','n',' ','f','o','x',
	' ','j','u','m','p',' ','o','v','e','r',' ','t','h','e',' ','l','a','z','y',' ','d','o','g','!'};

GLenum errorCheck()
{
	GLenum code;
	const GLubyte* str;

	code = glGetError();
	if(code != GL_NO_ERROR)
	{
		str = gluErrorString(code);
		fprintf(stderr, "OpenGL error: %s\n",str);
	}
	return code;
}

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.

	glMatrixMode (GL_PROJECTION);       // Set projection parameters.
	glLoadIdentity();
	gluOrtho2D (0.0, 800.0, 0.0, 600.0);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
}

void quad(GLint n1,GLint n2,GLint n3,GLint n4)
{
	glBegin(GL_QUADS);
		glVertex3fv(points[n1]);
		glVertex3fv(points[n2]);
		glVertex3fv(points[n3]);
		glVertex3fv(points[n4]);
	glEnd();
}

void cube()
{
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.

	glColor3f (0.0, 0.4, 0.2);      // Set line segment color to green.

	/*quad(6,2,3,7);
	quad(5,1,0,4);
	quad(4,0,2,6);
	quad(7,3,1,5);
	quad(4,6,7,5);
	quad(1,3,2,0);*/

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,points);
	glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,vertexIndex);

	glFlush();
}

void bit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glRasterPos2i (10, 10);
	glBitmap (9, 10, 5.0, 5.0, 20.0, 15.0, bitShape);
	
	
	glRasterPos2i (20, 20);//确定当前光栅位置，x,y,z,w指定了当前光栅位置的坐标  
	glBitmap (10, 12, 5.0, 5.0, 11.0, 0.0, rasters);  
	glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);  
	glBitmap (10, 12, 0.0, 0.0, 11.0, 0.0, rasters);  
	//绘制由bitmap指定的位图，bitmap是一个指向位图图像的指针，位图的原点是当前光栅位置，如果当前光栅位置无效，则这个函数不会绘制任何东西。  
	//width和height表示位图的宽度和高度，xorig和yorig定义了位图的原点，他是根据当期光栅位置确定的，右上为正。  
	//xmove和ymove表示位图光栅化之后光栅坐标的x增加值和y增加值  


	/*GLint month, k;
	for (k = 0; k < 12; k++)
		glRecti (20 + k*50, 165, 40 + k*50, dataValue [k]);

	glColor3f (0.0, 0.0, 0.0);           //  Set text color to black.
	GLint xRaster = 20;                   //  Display chart labels.
	GLint yRaster = 100;
	for (month = 0; month < 12; month++) {
		glRasterPos2i (xRaster, yRaster);
		for (k = 3*month; k < 3*month + 3; k++)
			glutBitmapCharacter (GLUT_BITMAP_HELVETICA_12, 
			label [h]);
		xRaster += 50;
	}*/
	for(int i = 0;i < 43;i++)
	{
		glRasterPos2i(20 + i * 10,300);
		//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,label[i]);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,label[i]);
	}

	glFlush(); 
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (50, 100);   // Set top-left display-window position.
	glutInitWindowSize (800, 600);      // Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.

	init ( );                            // Execute initialization procedure.
	//glutDisplayFunc (cube);       // Send graphics to display window.
	glutDisplayFunc(bit);
	glutMainLoop ( );                    // Display everything and wait.
}
