#include "small_brick.h"

void create_small_brick(GLfloat* matrix)
{
	// int x =load_bmp_1d("color.bmp");
	
	/*if(x!=100)
	{
		printf("Something bad happened in load_bmp_1d\n");
		return;
	}*/
	// GLfloat pos[3],pos_orig[3];
	// glGetLightfv(GL_LIGHT0,GL_POSITION,pos);
	//memcpy (pos_orig, pos, 3*sizeof(GLfloat));;
	// //memcpy(pos_orig,pos,3*sizeof(GLfloat));//	pos_orig=pos;
	// printf("Position of light is %lf,%lf,%lf\n",pos[0],pos[1],pos[2]);
	// normalize(pos);
	GLfloat normal[6][3]={
				{1,0,0},
				{0,1,0},
				{0,0,1},
				{-1,0,0},
				{0,-1,0},
				{0,0,-1}
	};
	glLoadIdentity();
 	glLoadMatrixf(matrix);
	 	// glColor3f( 0.4, 0.5, 0.2 );     
	//BAck

	glBegin(GL_POLYGON);
	// GLfloat coordinate[3]={0,0,-0.5};
	//light_vector_generator(coordinate,pos);
	//glTexCoord1f(maxNdotL(normal[5], pos));
	glNormal3fv(normal[5]);
 	glVertex3f(  0.5, -0.03125, -0.5 );  
	glVertex3f(  0.5,  0.03125, -0.5 );  
	glVertex3f( -0.5,  0.03125, -0.5 );  
	glVertex3f( -0.5, -0.03125, -0.5 );  
	glEnd();
	//memcpy (pos, pos_orig, 3*sizeof(GLfloat));;
	//FRONT
	glBegin(GL_POLYGON);
	// glColor3f(   0.2,  0.3, 0.9 );
	// coordinate[2]=0.5;
	//light_vector_generator(coordinate,pos);
	//glTexCoord1f(maxNdotL(normal[2], pos));
	glNormal3fv(normal[2]);
	glVertex3f(  0.5, -0.03125, 0.5 );
	glVertex3f(  0.5,  0.03125, 0.5 );
	glVertex3f( -0.5,  0.03125, 0.5 );
	glVertex3f( -0.5, -0.03125, 0.5 );
	glEnd();
	//memcpy (pos, pos_orig, 3*sizeof(GLfloat));;

	//RIGHT
	glBegin(GL_POLYGON);
	// glColor3f(  1.0,  0.0,  1.0 );
	// coordinate[2]=0;coordinate[0]=0.5;
	//light_vector_generator(coordinate,pos);
	//glTexCoord1f(maxNdotL(normal[0], pos));
	glNormal3fv(normal[0]);
	glVertex3f( 0.5, -0.03125, -0.5 );
	glVertex3f( 0.5,  0.03125, -0.5 );
	glVertex3f( 0.5,  0.03125,  0.5 );
	glVertex3f( 0.5, -0.03125,  0.5 );
	glEnd();
	//memcpy (pos, pos_orig, 3*sizeof(GLfloat));;
	//LEFT
	glBegin(GL_POLYGON);
	// glColor3f(   0.0,  1.0,  0.0 );
	// coordinate[0]=-0.5;
	//light_vector_generator(coordinate,pos);
	//glTexCoord1f(maxNdotL(normal[3], pos));
	glNormal3fv(normal[3]);
	glVertex3f( -0.5, -0.03125,  0.5 );
	glVertex3f( -0.5,  0.03125,  0.5 );
	glVertex3f( -0.5,  0.03125, -0.5 );
	glVertex3f( -0.5, -0.03125, -0.5 );
	glEnd();

	//memcpy (pos, pos_orig, 3*sizeof(GLfloat));;
	//TOP
	glBegin(GL_POLYGON);
	// glColor3f(   0.0,  0.0,  1.0 );
	// coordinate[0]=0.0;coordinate[1]=0.3125;
	//light_vector_generator(coordinate,pos);
	//glTexCoord1f(maxNdotL(normal[1], pos));
	glNormal3fv(normal[1]);
	glVertex3f(  0.5,  0.03125,  0.5 );
	glVertex3f(  0.5,  0.03125, -0.5 );
	glVertex3f( -0.5,  0.03125, -0.5 );
	glVertex3f( -0.5,  0.03125,  0.5 );
	glEnd();
	//memcpy (pos, pos_orig, 3*sizeof(GLfloat));;
	//BOTTOM
	glBegin(GL_POLYGON);
	// glColor3f(   1.0,  0.0,  0.0 );
	// coordinate[1]=-0.3125;
	//light_vector_generator(coordinate,pos);
	//glTexCoord1f(maxNdotL(normal[4], pos));
	glNormal3fv(normal[4]);
	glVertex3f(  0.5, -0.03125, -0.5 );
	glVertex3f(  0.5, -0.03125,  0.5 );
	glVertex3f( -0.5, -0.03125,  0.5 );
	glVertex3f( -0.5, -0.03125, -0.5 );
	glEnd();
/*
	glDisable(GL_TEXTURE_1D);

	glEnable(GL_LIGHTING);
*/

}

void create_textured_brick()
{
	GLfloat normal[6][3]={
				{1,0,0},
				{0,1,0},
				{0,0,1},
				{-1,0,0},
				{0,-1,0},
				{0,0,-1}
	};
	// glLoadIdentity();
 	// glLoadMatrixf(prevmatrix);
	 	// glColor3f( 0.4, 0.5, 0.2 );     
	//BAck
	
	glBegin(GL_POLYGON);
	glNormal3fv(normal[5]);
 	glVertex3f(  0.5, -0.03125, -0.5 );  
	glVertex3f(  0.5,  0.03125, -0.5 );  
	glVertex3f( -0.5,  0.03125, -0.5 );  
	glVertex3f( -0.5, -0.03125, -0.5 );  
	glEnd();

	//FRONT
	glBegin(GL_POLYGON);
	// glColor3f(   0.2,  0.3, 0.9 );
	glNormal3fv(normal[2]);
	glVertex3f(  0.5, -0.03125, 0.5 );
	glVertex3f(  0.5,  0.03125, 0.5 );
	glVertex3f( -0.5,  0.03125, 0.5 );
	glVertex3f( -0.5, -0.03125, 0.5 );
	glEnd();

	//RIGHT
	glBegin(GL_POLYGON);
	// glColor3f(  1.0,  0.0,  1.0 );
	glNormal3fv(normal[0]);
	glVertex3f( 0.5, -0.03125, -0.5 );
	glVertex3f( 0.5,  0.03125, -0.5 );
	glVertex3f( 0.5,  0.03125,  0.5 );
	glVertex3f( 0.5, -0.03125,  0.5 );
	glEnd();

	//LEFT
	glBegin(GL_POLYGON);
	// glColor3f(   0.0,  1.0,  0.0 );
	glNormal3fv(normal[3]);
	glVertex3f( -0.5, -0.03125,  0.5 );
	glVertex3f( -0.5,  0.03125,  0.5 );
	glVertex3f( -0.5,  0.03125, -0.5 );
	glVertex3f( -0.5, -0.03125, -0.5 );
	glEnd();
// 
	// glEnable(GL_TEXTURE_2D);
	// int texture_id= load_bmp("criss_cross.bmp",1);
	//TOP
	glBegin(GL_POLYGON);
	// glColor3f(   0.0,  0.0,  1.0 );
	glNormal3fv(normal[1]);

	glTexCoord2f(1, 0);
	glVertex3f(  0.5,  0.03125,  0.5 );
	glTexCoord2f(1, 1);
	glVertex3f(  0.5,  0.03125, -0.5 );
	glTexCoord2f(0, 1);
	glVertex3f( -0.5,  0.03125, -0.5 );
	glTexCoord2f(0, 0);
	glVertex3f( -0.5,  0.03125,  0.5 );
	glEnd();
	//BOTTOM
	glBegin(GL_POLYGON);
	// glColor3f(   1.0,  0.0,  0.0 );
	glNormal3fv(normal[4]);
	glTexCoord2f(1, 1);
	glVertex3f(  0.5, -0.03125, -0.5 );
	glTexCoord2f(1, 0);
	glVertex3f(  0.5, -0.03125,  0.5 );
	glTexCoord2f(0, 0);
	glVertex3f( -0.5, -0.03125,  0.5 );
	glTexCoord2f(0, 1);
	glVertex3f( -0.5, -0.03125, -0.5 );
	glEnd();
	glDisable(GL_TEXTURE_2D);
}