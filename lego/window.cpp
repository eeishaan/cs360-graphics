#include "window.h"

void window::draw_window()
{
	glLoadIdentity();
	// GLfloat* prevMatrix = this->prevMatrix;
	// glScalef(0.25,0.25,0.25);
	// setEye();
	//We have the top most point 
	//First we calculate the center of the first brick 
	GLfloat x=point[0]+0.5;
	GLfloat y=point[1]-0.03125;
	GLfloat z=point[2]-0.5;
	GLfloat matrix[16]; 
	

	for(int i=0;i<2;++i) //create 2 
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
		z=z-1;
	}
	GLfloat width = 0.0625;
	GLfloat breadth =2; //new height
	GLfloat height = 1; //width of the window
	GLfloat length= 2; //new length(i.e z axis length)
	
	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	glTranslatef(point[0],point[1]-0.03125-breadth,point[2]);
	glRotatef(90,0,0,1);

	// glTranslatef(0,-breadth,0);
	draw_boundary(width,length,breadth,height,1);

	breadth=1;
	height=0.5;

//THis for lower bezel
	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	glTranslatef(point[0],point[1]-0.03125-1.5,point[2]); //last_breadth-curr-height=1.5
	draw_boundary(width,length,breadth,height,1);
	glLoadMatrixf(prevMatrix);
	// glColorf(1,0,0,1);
//This portion for protuding pane
	breadth=1.5;
	height=-0.25;
	length=1.875;
	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	glTranslatef(point[0]+1,point[1]-0.0625,point[2]-0.0625); 
	glRotatef(-90,0,0,1);
	draw_boundary(width,length,breadth,height,0);
//This portion for circular stick
	length=0.4;//diameter of the circular part
	height=0.2;
	breadth=0.4;
	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	// glTranslatef(0.5,0.03125,0.5);
	glTranslatef(point[0]+1-breadth/2-0.03125,point[1]-2+height/2,point[2]-1); 
	glScalef(breadth,height/0.0625,length);
	glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
	create_small_brick(matrix);
	// draw_boundary(width,length,breadth,height,0);

	glLoadIdentity();
	glLoadMatrixf(prevMatrix);
	glTranslatef(point[0]+1-breadth-0.03125,point[1]-2,point[2]-1); 
	// glRotatef(180,0,1,0);
	create_circular_stick(length/2,height/2);

	glLoadMatrixf(prevMatrix);

}