#include "fence.h"

void fence::draw_fence()
{
	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	GLfloat width=0.0625;
	GLfloat breadth=1;
	GLfloat matrix[16];
	point[1]-=width; 
	// glTranslatef(point[0]+length/2,point[1]-width/2,point[2]-breadth/2);
	glTranslatef(point[0]+breadth/2,point[1]-width/2,point[2]-length/2);
	glScalef(breadth,width/0.0625,length);

	glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
	create_small_brick(matrix);

	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	GLfloat height=2;
	// breadth=2;
	glTranslatef(point[0]+breadth/2,point[1]+height/4,point[2]-length/2);
	// glScalef(height,width/0.0625,length-2*width);
	glScalef(height,width/0.0625,length-2*width);
	glRotatef(90,0,0,1);
	// glRotatef(-90,0,1,0);
	create_textured_brick();
	glLoadMatrixf(prevMatrix);

	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	glTranslatef(point[0],point[1]-width,point[2]);

	// width = 0.0625;
	// breadth =2;
	height = 0.5;
	draw_boundary(width,length,breadth,height,0);

	for(int i=0;i<length-1;++i)
	{
		glLoadIdentity();
		glLoadMatrixf(prevMatrix);
		glTranslatef(point[0]+0.5,point[1]-0.0625,point[2]-1-i);
		glScalef(0.75,0.5,0.75);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		create_lower_cylinder(matrix);
	}
	glLoadMatrixf(prevMatrix);

	// GLfloat* prevState = this->prevMatrix;

}
