#include "slope.h"

void create_slope(GLfloat* matrix, GLint breadth)
{
	
	/*GLfloat coordinates[][3]={
								{}
							};*/

	GLfloat height = 2.03125;
	GLfloat length = 1;
	GLfloat width = 0.0625;

	glLoadIdentity();
	glLoadMatrixf(matrix);

	glBegin(GL_POLYGON);//left
		glNormal3f(0,0,1);

		glVertex3f(0,0,0);
		glVertex3f(0,-height,0);
		glVertex3f(length,-height,0);
		glVertex3f(length,width-height,0);
	glEnd();

	glBegin(GL_POLYGON);//left inner
		glNormal3f(0,0,-1);

		glVertex3f(-width,0,-width);
		glVertex3f(0,0,-width);
		glVertex3f(length,width-height,-width);
		glVertex3f(length,-height,-width);
		// glVertex3f(0,-height,-width);
		glVertex3f(-width,-height,-width);
	glEnd();
	glBegin(GL_POLYGON);//left bottom
		glNormal3f(0,-1,0);
		glVertex3f(-width,-height,-width);
		// glVertex3f(0,-height,-width);
		glVertex3f(length,-height,-width);
		glVertex3f(length,-height,0);
		glVertex3f(0,-height,0);
	glEnd();
	glBegin(GL_POLYGON);//right
		glNormal3f(0,0,-1);

		glVertex3f(0,0,-breadth);
		glVertex3f(0,-height,-breadth);
		glVertex3f(length,-height,-breadth);
		glVertex3f(length,width-height,-breadth);
	glEnd();

	glBegin(GL_POLYGON);//right inner
		glNormal3f(0,0,1);

		glVertex3f(-width,0,-breadth+width);
		glVertex3f(0,0,-breadth+width);
		glVertex3f(length,width-height,-breadth+width);
		glVertex3f(length,-height,-breadth+width);
		glVertex3f(-width,-height,-breadth+width);
	glEnd();

	glBegin(GL_POLYGON);//right bottom
		glNormal3f(0,-1,0);
		glVertex3f(-width,-height,-breadth+width);
		glVertex3f(length,-height,-breadth+width);
		glVertex3f(length,-height,-breadth);
		glVertex3f(0,-height,-breadth);
	glEnd();
	// int texture_id= load_bmp("slope_texture.bmp",1);
	float theta = 63.43494882;//tan((height- width)/length);
	glBegin(GL_POLYGON);//top
		// glNormal3f(Cos(theta),Sin(theta),0);
		glNormal3f(0.447213595,0.89442719,0);
		glTexCoord2f(0,0);
		glVertex3f(0,0,0);
		glTexCoord2f(1,0);
		glVertex3f(0,0,-breadth);
		glTexCoord2f(1,1);
		glVertex3f(length,width-height,-breadth);
		glTexCoord2f(0,1);
		glVertex3f(length,width-height,0);
		// glVertex3f(length,-height,0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glBegin(GL_POLYGON); //front
		glNormal3f(0,0,1);
		glVertex3f(length,width-height,-breadth);
		glVertex3f(length,width-height,0);
		glVertex3f(length,-height,0);
		glVertex3f(length,-height,-breadth);		
	glEnd();

}