#include "elementary_brick.h"

void elementary_brick::draw_elementary_brick()
{
	glLoadIdentity();
	GLfloat* prevState = this->prevMatrix;
	// glScalef(0.25,0.25,0.25);
	// setEye();
	//We have the top most point 
	//First we calculate the center of the first brick 
	GLfloat x=point[0]+0.5;
	GLfloat y=point[1]-0.03125;
	GLfloat z=point[2]-0.5;
	GLfloat matrix[16]; 
	

	for(int i=0;i<length;++i) //create 2 rows in the same loop
	{
		// x=x+i;
		glLoadIdentity();
 		glLoadMatrixf(prevState);

		glTranslatef(x,y,z); //x,y,z represent the center of the small brick
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_small_brick(matrix);

		glLoadIdentity();
 		glLoadMatrixf(prevState);
		glTranslatef(x,y,z);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_upper_cylinder(matrix);
		
		x=x+1;
		glLoadIdentity();
 		glLoadMatrixf(prevState);
		glTranslatef(x,y,z); //x,y,z represent the center of the small brick
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_small_brick(matrix);
		
		glLoadIdentity();
 		glLoadMatrixf(prevState);
		glTranslatef(x,y,z);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_upper_cylinder(matrix);

		x=x-1;
		z=z-1;
	}

	glLoadIdentity();
	glLoadMatrixf(prevState);
	glTranslatef(point[0],point[1]-0.03125,point[2]);

	GLfloat width = 0.0625;
	GLfloat breadth =2;
	GLfloat height = 2;
	draw_boundary(width,length,breadth,height,0);

	for(int i=0;i<length-1;++i)
	{
		glLoadIdentity();
		glLoadMatrixf(prevState);
		glTranslatef(point[0]+1,point[1]-0.0625,point[2]-1-i);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_lower_cylinder(matrix);
	}
	glLoadMatrixf(prevState);
}