#include "sloping_brick.h"

void sloping_brick::draw_sloping_brick()
{
	GLfloat x=point[0]+0.5;
	GLfloat y=point[1]-0.03125;
	GLfloat z=point[2]-0.5;
	GLfloat matrix[16]; 
	for(int i=0;i<length;++i) //only 1 row in the same loop
	{
		// x=x+i;
		glLoadIdentity();
 		glLoadMatrixf(prevMatrix);

		glTranslatef(x,y,z); //x,y,z represent the center of the small brick
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_small_brick(matrix);

		glLoadIdentity();
 		glLoadMatrixf(prevMatrix);
		glTranslatef(x,y,z);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_upper_cylinder(matrix);
			
		// x=x-1;
		z=z-1;
	}
	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	glTranslatef(point[0],point[1]-0.03125,point[2]);

	GLfloat width = 0.0625;
	GLfloat breadth =1;
	GLfloat height = 2;
	/*if(type==1)
	{
		draw_boundary(width,length,breadth,height,4);
		 

		glLoadIdentity();
		glLoadMatrixf(prevMatrix);

		glTranslatef(point[0]+1,point[1],point[2]-length);
		glRotatef(0,0,1,0);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_slope(matrix,1);
	}
	else if(type==2)
	{*/
		draw_boundary(width,length,breadth,height,3);
		x=point[0]+1;
		z=point[2];

		// for(int i=0;i<length;++i)
		// {		
			glLoadIdentity();
			glLoadMatrixf(prevMatrix);

			glTranslatef(x,point[1],z);
			glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
			create_slope(matrix,length);
			// z=z-1;
		// }
	// }

	for(int i=0;i<length-1;++i)
	{
		glLoadIdentity();
		glLoadMatrixf(prevMatrix);
		glTranslatef(point[0]+1,point[1]-0.0625,point[2]-1-i);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_sloping_cylinder(matrix);
	}
	glLoadMatrixf(prevMatrix);
}