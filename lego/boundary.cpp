#include "boundary.h"

void draw_boundary(GLfloat width,GLfloat length,GLfloat breadth,GLfloat height,GLint flag)
{
	// glScalef(0.25,0.25,0.25);
	/*int x =load_bmp_1d("color.bmp");
	GLfloat pos[3];
	glGetLightfv(GL_LIGHT0,GL_POSITION,pos);
	GLfloat new_c[3];
	GLfloat pos_orig[3];
	//memcpy (pos_orig, pos, 3*sizeof(GLfloat));;
*/
	// normalize(pos);
	// setEye();
	GLfloat coordinates[16][3]={
									{0,0,0},
									{width,0,-1*width},
									{width,0,-1*(length-width)},
									{0,0,-1*length},
									{width,-1*height,-1*width},//4
									{width, -1*height, -1*(length-width)},//5
									{0, -1*height, -1*length},//6
									{0.0,-1*height,0.0},//7
									{breadth-width,0,-1*width},//8
									{breadth,0,0},//9
									{breadth-width,-1*height,-1*width},//10
									{breadth,-1*height,0},//11
									{breadth-width,0,-1*(length-width)},//12
									{breadth-width,-1*height,-1*(length-width)},//13
									{breadth,-1*height,-1*length},//14
									{breadth,0,-1*length}//15


	};

	GLfloat normal[6][3]={
				{1,0,0},
				{0,1,0},
				{0,0,1},
				{-1,0,0},
				{0,-1,0},
				{0,0,-1}
	};
	// glColor3f( 1.0, 1.0, 0.2 );     
	// glColor3f( 0.4, 0.5, 0.2 );     
	/*glBegin(GL_POLYGON);//ist right //Begin quadrilateral coordinates
		glVertex3fv(  coordinates[0] );  
		glVertex3fv(coordinates[7]);//7
		glVertex3fv(coordinates[4]);//4
		glVertex3fv(coordinates[1]);//1
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));*/
 	// //glColor3f( 0.4, 0.5, 0.5 ); 
	if(flag!=1)
	{
		glBegin(GL_POLYGON);//1st inner //Begin quadrilateral coordinates
			glNormal3fv(normal[0]);
			//avg_coordinate(coordinates[1],coordinates[4],coordinates[5],coordinates[2],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[0], pos));

			glVertex3fv(coordinates[1]);//1
			glVertex3fv(coordinates[4]);//4
			glVertex3fv(coordinates[5]);//5
			glVertex3fv(coordinates[2]); //2
		glEnd();
		//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
	 	// //glColor3f( 0.1, 0.5, 0.2 ); 
		/*glBegin(GL_POLYGON); //1st left//Begin quadrilateral coordinates
			glVertex3fv(coordinates[2]); //2
			glVertex3fv(coordinates[5]);//5
			glVertex3fv(coordinates[6]);//6
			glVertex3fv(coordinates[3]);//3
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));*/

	 	// //glColor3f( 0.4, 0.2, 0.2 ); 
		glBegin(GL_POLYGON); //1st outer//Begin quadrilateral coordinates
			glNormal3fv(normal[3]);
			//avg_coordinate(coordinates[3],coordinates[6],coordinates[7],coordinates[0],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[3], pos));

			glVertex3fv(coordinates[3]);//3
			glVertex3fv(coordinates[6]);//6
			glVertex3fv(coordinates[7]);//7
			glVertex3fv( coordinates[0] );  
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
		glBegin(GL_POLYGON);//1st top //Begin quadrilateral coordinates
			//glNormal3f(0,0,0);
			glVertex3fv(  coordinates[0] );  
			glVertex3fv(coordinates[1]);//1
			glVertex3fv(coordinates[2]); //2
			glVertex3fv(coordinates[3]);//3
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

		glBegin(GL_POLYGON); //1st bottom
			glNormal3fv(normal[4]);
			//avg_coordinate(coordinates[7],coordinates[4],coordinates[5],coordinates[6],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[4], pos));

			glVertex3fv(coordinates[7]);//7
			glVertex3fv(coordinates[4]);//4
			glVertex3fv(coordinates[5]);//5
			glVertex3fv(coordinates[6]);//6
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

	}
	
	//glColor3f( 0.1, 0.5, 0.2 );     
	if(flag!=2)
	{
		glBegin(GL_POLYGON); //top 2nd
		//glNormal3f(0,0,0);
		// glNormal3fv(normal[1]);
			glVertex3fv(coordinates[0]);
			glVertex3fv(coordinates[1]);//1
			glVertex3fv(coordinates[8]);//8
			glVertex3fv(coordinates[9]); //9
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

		glBegin(GL_POLYGON);//bottom 2nd
			glNormal3fv(normal[4]);
			//avg_coordinate(coordinates[7],coordinates[4],coordinates[10],coordinates[11],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[4], pos));

			glVertex3fv(coordinates[7]);//7
			glVertex3fv(coordinates[4]);//4
			glVertex3fv(coordinates[10]);//10
			glVertex3fv(coordinates[11]); //11
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

		/*glBegin(GL_POLYGON);
			//glNormal3f(0,0,0);
			 //left 2nd
			glVertex3fv(  coordinates[0] );  
			glVertex3fv(coordinates[7]);//7
			glVertex3fv(coordinates[4]);//4
			glVertex3fv(coordinates[1]);//1
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));*/

		/*glBegin(GL_POLYGON);//right 2nd
			//glNormal3f(0,0,0);
			glVertex3fv(coordinates[8]);//8
			glVertex3fv(coordinates[9]); //9
			glVertex3fv(coordinates[11]); //11
			glVertex3fv(coordinates[10]);//10
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));*/

		glBegin(GL_POLYGON);//outer 2nd
			glNormal3fv(normal[2]);
			//avg_coordinate(coordinates[9],coordinates[11],coordinates[7],coordinates[0],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[2], pos));

			glVertex3fv(coordinates[9]); //9
			glVertex3fv(coordinates[11]); //11
			glVertex3fv(coordinates[7]);//7
			glVertex3fv(coordinates[0] );		  
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

		glBegin(GL_POLYGON);//inner 2nd
			glNormal3fv(normal[5]);
			//avg_coordinate(coordinates[4],coordinates[1],coordinates[8],coordinates[10],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[5], pos));

			glVertex3fv(coordinates[4]);//4
			glVertex3fv(coordinates[1]);//1
			glVertex3fv(coordinates[8]);//8
			glVertex3fv(coordinates[10]);//10
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
	}
	
	//glColor3f( 0.4, 0.1, 1);     

/*	glBegin(GL_POLYGON); //3rd left
		//glNormal3f(0,0,0);
		glVertex3fv(coordinates[8]);//8
		glVertex3fv(coordinates[9]); //9
		glVertex3fv(coordinates[11]); //11
		glVertex3fv(coordinates[10]);//10
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
	glBegin(GL_POLYGON); //3rd right
		//glNormal3f(0,0,0);
		glVertex3fv(coordinates[12]); //12
		glVertex3fv(coordinates[13]); //13
		glVertex3fv(coordinates[15]);//15
		glVertex3fv(coordinates[14]);//14
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));*/
	if(flag!=3)
	{
		glBegin(GL_POLYGON);//3rd top
		//glNormal3f(0,0,0);
		// glNormal3fv(normal[1]);
			glVertex3fv(coordinates[8]);//8
			glVertex3fv(coordinates[9]); //9
			glVertex3fv(coordinates[15]);//15
			glVertex3fv(coordinates[12]); //12
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));


		glBegin(GL_POLYGON);//3rd bottom
			glNormal3fv(normal[4]);
			//avg_coordinate(coordinates[11],coordinates[10],coordinates[13],coordinates[14],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[4], pos));

			glVertex3fv(coordinates[11]); //11
			glVertex3fv(coordinates[10]);//10
			glVertex3fv(coordinates[13]); //13
			glVertex3fv(coordinates[14]);//14
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));


		glBegin(GL_POLYGON);//3rd inner
			glNormal3fv(normal[3]);
			//avg_coordinate(coordinates[8],coordinates[10],coordinates[13],coordinates[12],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[3], pos));
			glVertex3fv(coordinates[8]);//8
			glVertex3fv(coordinates[10]);//10
			glVertex3fv(coordinates[13]); //13
			glVertex3fv(coordinates[12]); //12
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
		glBegin(GL_POLYGON);//3rd outer
			glNormal3fv(normal[0]);
			//avg_coordinate(coordinates[9],coordinates[15],coordinates[14],coordinates[11],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[0], pos));

			glVertex3fv(coordinates[9]); //9
			glVertex3fv(coordinates[15]);//15
			glVertex3fv(coordinates[14]);//14
			glVertex3fv(coordinates[11]); //11
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
		
	}
	//glColor3f( 1.0, 1.0, 0.2 );     

	/*glBegin(GL_POLYGON); //4th left
		//glNormal3f(0,0,0);
		glVertex3fv(coordinates[12]); //12
		glVertex3fv(coordinates[13]); //13
		glVertex3fv(coordinates[14]);//14
		glVertex3fv(coordinates[15]);//15
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
	glBegin(GL_POLYGON); //4rth right
		//glNormal3f(0,0,0);
		glVertex3fv(coordinates[2]); //2
		glVertex3fv(coordinates[5]);//5
		glVertex3fv(coordinates[6]);//6
		glVertex3fv(coordinates[3]);//3
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));*/
	if(flag!=4)
	{
		glBegin(GL_POLYGON);//4rth top
		// glNormal3fv(normal[1]);
		//glNormal3f(0,0,0);
			glVertex3fv(coordinates[2]); //2
			glVertex3fv(coordinates[12]); //12
			glVertex3fv(coordinates[15]);//15
			glVertex3fv(coordinates[3]);//3
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));	
		glBegin(GL_POLYGON);//4rth Bottom
			glNormal3fv(normal[4]);
			//avg_coordinate(coordinates[5],coordinates[13],coordinates[14],coordinates[6],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[4], pos));

			glVertex3fv(coordinates[5]);//5
			glVertex3fv(coordinates[13]); //13
			glVertex3fv(coordinates[14]);//14
			glVertex3fv(coordinates[6]);//6
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
		glBegin(GL_POLYGON);//4rht inner
			glNormal3fv(normal[2]);
			//avg_coordinate(coordinates[2],coordinates[5],coordinates[13],coordinates[12],new_c);
			//light_vector_generator(new_c,pos);
			//glTexCoord1f(maxNdotL(normal[2], pos));

			glVertex3fv(coordinates[2]); //2
			glVertex3fv(coordinates[5]);//5
			glVertex3fv(coordinates[13]); //13
			glVertex3fv(coordinates[12]); //12
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

		glBegin(GL_POLYGON); //4rth outer
			glNormal3fv(normal[5]);
			//glTexCoord1f(maxNdotL(normal[5], pos));

			glVertex3fv(coordinates[15]);//15
			glVertex3fv(coordinates[14]);//14
			glVertex3fv(coordinates[6]); //6
			glVertex3fv(coordinates[3]); //3
		glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
	}
	glDisable(GL_TEXTURE_1D);

	glEnable(GL_LIGHTING);
	
	/*glBegin(GL_POLYGON);//3rd outer
		glNormal3fv(normal[0]);
		glVertex3fv(coordinates[9]); //9
		glVertex3fv(coordinates[15]);//15
		glVertex3fv(coordinates[14]);//14
		glVertex3fv(coordinates[11]); //11
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

	glBegin(GL_POLYGON); //3rd left
		//glNormal3f(0,0,0);
		glVertex3fv(coordinates[8]);//8
		glVertex3fv(coordinates[9]); //9
		glVertex3fv(coordinates[11]); //11
		glVertex3fv(coordinates[10]);//10
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

	glBegin(GL_POLYGON);//3rd top
		//glNormal3f(0,0,0);
		// glNormal3fv(normal[1]);
		glVertex3fv(coordinates[8]);//8
		glVertex3fv(coordinates[9]); //9
		glVertex3fv(coordinates[15]);//15
		glVertex3fv(coordinates[3]);//3
		glVertex3fv(coordinates[2]); //2
		glVertex3fv(coordinates[12]); //12
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

	glBegin(GL_POLYGON);//3rd bottom
		glNormal3fv(normal[4]);
		glVertex3fv(coordinates[10]);//10
		glVertex3fv(coordinates[11]); //11
		glVertex3fv(coordinates[14]);//14
		glVertex3fv(coordinates[6]);//6
		glVertex3fv(coordinates[5]);//5
		glVertex3fv(coordinates[13]); //13
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));
	glBegin(GL_POLYGON); //4rth outer
		glNormal3fv(normal[5]);
		glVertex3fv(coordinates[15]);//15
		glVertex3fv(coordinates[3]);//3
		glVertex3fv(coordinates[2]); //2
		glVertex3fv(coordinates[12]); //12
	glEnd();
//memcpy (pos, pos_orig, 3*sizeof(GLfloat));

	glBegin(GL_POLYGON);//4rht inner
		glNormal3fv(normal[2]);
		glVertex3fv(coordinates[2]); //2
		glVertex3fv(coordinates[5]);//5
		glVertex3fv(coordinates[13]); //13
*/
}