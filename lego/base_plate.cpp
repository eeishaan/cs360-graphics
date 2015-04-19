#include "base_plate.h"

void base_plate::draw_base_plate()
{
	glLoadIdentity();

	GLfloat x=point[0]+0.5;
	GLfloat y=point[1]-0.03125;
	GLfloat z=point[2]-0.5;
	GLfloat matrix[16]; 
	

	for(int i=0;i<length;++i) //create multiple rows in the same loop
	{
		for(int j=0;j<length;++j)
		{
			glLoadIdentity();
	 		glLoadMatrixf(prevMatrix);

			glTranslatef(x+j,y,z-i); //x,y,z represent the center of the small brick
			glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
			create_small_brick(matrix);

			glLoadIdentity();
	 		glLoadMatrixf(prevMatrix);
			glTranslatef(x+j,y,z-i);
			glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
			create_upper_cylinder(matrix);
		}
		// x=x+i;
		
	}
	glLoadMatrixf(prevMatrix);

}