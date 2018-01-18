#include "stdafx.h"

#include <stdio.h>

#include <GL/glut.h>      // (or others, depending on the system in use)

int point1[] = {10,130};
int point2[] = {30,10};
int point3[] = {80,10};
int point4[] = {60,110};
int point5[] = {100,120};
int point6[] = {105,30};
int point7[] = {190,5};
int point8[] = {180,145};

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
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void lineSegment (void)
{
	glClear (GL_COLOR_BUFFER_BIT);  // Clear display window.

	glLineWidth(5);
	glColor3f (0.0, 0.4, 0.2);      // Set line segment color to green.
	//glBegin (GL_LINES);
	//glBegin(GL_LINE_STRIP);
	//glBegin(GL_LINE_LOOP);
	//glBegin(GL_POLYGON);
	//glBegin(GL_TRIANGLES);
	//glBegin(GL_TRIANGLE_STRIP);
	//glBegin(GL_QUADS);
	glBegin(GL_QUAD_STRIP);
	glVertex2iv (point1);
	glVertex2iv (point2);
	glVertex2iv (point4);
	glVertex2iv (point3);
	glVertex2iv (point5);
	glVertex2iv (point6);
	glVertex2iv (point8);
	glVertex2iv (point7);
	glEnd ( );

	//pointSegment();
	//rectSegment();
	glFlush ( );     // Process all OpenGL routines as quickly as possible.
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                         // Initialize GLUT.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   // Set display mode.
	glutInitWindowPosition (50, 100);   // Set top-left display-window position.
	glutInitWindowSize (400, 300);      // Set display-window width and height.
	glutCreateWindow ("An Example OpenGL Program"); // Create display window.

	init ( );                            // Execute initialization procedure.
	glutDisplayFunc (lineSegment);       // Send graphics to display window.
	glutMainLoop ( );                    // Display everything and wait.
}
