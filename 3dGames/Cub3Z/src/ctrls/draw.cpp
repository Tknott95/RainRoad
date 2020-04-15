#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "../headers/draw.h"

//Draw a cube at the origin
void Draw_Cuboid(float width,float height,float depth){
		// points of a cube
	static GLfloat points[][3]={	{1.0f,1.0f,1.0f},
									{1.0f,1.0f,0.0f},
									{0.0f,1.0f,0.0f},
									{0.0f,1.0f,1.0f},
									{1.0f,0.0f,1.0f},
									{1.0f,0.0f,0.0f},
									{0.0f,0.0f,0.0f},
									{0.0f,0.0f,1.0f}};

		//GLfloat normal[3];
		glPushMatrix();	
		glScalef(width,height,depth);
		glTranslatef(-0.5,-0.5,-0.5);
		glBegin(GL_QUADS);
		//top 
		
		//NormalVector(points[0],points[1],points[2],normal);
		//glNormal3fv(normal);
		glColor3d(1.0,1.0,1.0);
		glVertex3fv(points[0]); glVertex3fv(points[1]); glVertex3fv(points[2]); glVertex3fv(points[3]);
		
		//front
		//NormalVector(points[0],points[3],points[7],normal);
		//glNormal3fv(normal);
		glColor3d(1.0,0.0,1.0);
		glVertex3fv(points[0]); glVertex3fv(points[3]); glVertex3fv(points[7]); glVertex3fv(points[4]);

		//back
		//NormalVector(points[1],points[5],points[6],normal);
		//glNormal3fv(normal);
		glColor3d(1.0,1.0,0.0);
		glVertex3fv(points[1]); glVertex3fv(points[5]); glVertex3fv(points[6]); glVertex3fv(points[2]);

		//left
		//NormalVector(points[3],points[2],points[6],normal);
		//glNormal3fv(normal);
		glColor3d(0.0,1.0,0.0);
		glVertex3fv(points[3]); glVertex3fv(points[2]); glVertex3fv(points[6]); glVertex3fv(points[7]);

		//right
		//NormalVector(points[1],points[0],points[4],normal);
		//glNormal3fv(normal);
		glColor3d(0.0,0.0,1.0);
		glVertex3fv(points[1]); glVertex3fv(points[0]); glVertex3fv(points[4]); glVertex3fv(points[5]);

		//bottom
		//NormalVector(points[4],points[7],points[6],normal);
		//glNormal3fv(normal);
		glColor3d(1.0,0.0,0.0);
		glVertex3fv(points[4]); glVertex3fv(points[7]); glVertex3fv(points[6]); glVertex3fv(points[5]);

	glEnd();
	glPopMatrix();
}
