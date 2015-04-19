#include "utility.h"
void drawAxes() 
{
      /*  Length of axes */
	double len = 50.0;
    // glColor3f(1.0,1.0,1.0);
	glLineWidth (2.0);
	glBegin(GL_LINES);
		// glColor3f(1, 0, 0);
		glVertex3d(0,0,0);
		glVertex3d(len,0,0);
		// glColor3f(0, 1, 0);
		glVertex3d(0,0,0);
		glVertex3d(0,len,0);
		// glColor3f(0, 0, 1);
		glVertex3d(0,0,0);
		glVertex3d(0,0,len);
	glEnd();
	// glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    	/*  Label axes */
 /*   glRasterPos3d(len,0,0);//print("X");
    glRasterPos3d(0,len,0);//  print("Y");
    glRasterPos3d(0,0,len);//  print("Z");*/
}

void set_material_properties(GLint color_option)
{

	float colorBlue[4][4] = {
							{ 0.0f, 0.0f, 1.0f, 1.0f },
							// {0.2, 0.2, 0.2, 1.0},
							{ 0.0f, 1.0f, 0.0f, 1.0f},
							// {0.8, 0.8, 0.8, 1.0},
							{ 1.0f, 0.0f, 0.0f, 1.0f},
							{ 1.0f, 1.0f, 0.0f, 1.0f}
						};
/*	float colorBlue1[4][3] = {
		{ 0.0f, 0.0f, 1.0f },
		// {0.2, 0.2, 0.2, 1.0},
		{ 0.0f, 1.0f, 0.0f},
		// {0.8, 0.8, 0.8, 1.0},
		{ 1.0f, 0.0f, 0.0f},
		{ 1.0f, 1.0f, 0.0f}
	};
	glColor3fv(colorBlue1[color_option]);*/
	float diffuseReflection[4][4]= {
							{ 0.2f, 0.2f, 0.2f, 0.6f },
							// {0.2, 0.2, 0.2, 1.0},
							{ 0.0f, 0.1f, 0.0f, 0.1f},
							// {0.8, 0.8, 0.8, 1.0},
							{ 0.1f, 0.0f, 0.0f, 0.1f},
							{ 0.1f, 0.1f, 0.1f, 0.1f}
						};

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,colorBlue[color_option] );//ambientReflection);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuseReflection[0]);
	
	// glLoadIdentity();
	
	float specReflection[] = {0, 0, 0, 1};//{ 0.8f, 0.8f, 0.8f, 1.0f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specReflection);
	// drawAxes();
	// glMateriali(GL_FRONT, GL_SHININESS, 2);
}
void set_lights()
{
	// glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	// glEnable(GL_LIGHT1);
	// glEnable(GL_LIGHT2);
	// glEnable(GL_COLOR_MATERIAL);
	/*GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	// GLfloat ambientLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// GLfloat diffuseLight[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position[] = { -1.5f, 10.0f, -4.0f, 1.0f };*/
	// GLfloat position[] = { -1.5f, -1.5f, -1.5f, 1.0f };
	// GLfloat position[] = { 1000.0f, 100.0f, -100.0f, 0 };
	// GLfloat position[] = { 70.0f, 10.0f, 0.0f, 0 };
	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	// GLfloat ambientLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// GLfloat diffuseLight[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// GLfloat position[] = { -1.5f, 10.0f, -4.0f, 1.0f };
	// GLfloat position[] = { -1.5f, -1.5f, -1.5f, 1.0f };
	// GLfloat position[] = { 1000.0f, 100.0f, -100.0f, 0 };
	GLfloat position[] = { 0.0, 5.0f, 5.0f, 0 };

	
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

/*	GLfloat position1[]={ 100.0f,0.0f,0.0f,1.0f};
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);

	GLfloat position2[]={ 0.0f,0.0f,100.0,1.0f};
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT2, GL_POSITION, position2);*/

}
void screenshot (char filename[160],int x, int y)
{
	long imageSize = x * y * 3;
	unsigned char *data = new unsigned char[imageSize];
	glReadPixels(0,0,x,y, GL_BGR,GL_UNSIGNED_BYTE,data);// split x and y sizes into bytes
	int xa= x % 256;
	int xb= (x-xa)/256;int ya= y % 256;
	int yb= (y-ya)/256;//assemble the header
	unsigned char header[18]={0,0,2,0,0,0,0,0,0,0,0,0,(char)xa,(char)xb,(char)ya,(char)yb,24,0};

	fstream File(filename, ios::out | ios::binary);
	File.write (reinterpret_cast<char *>(header), sizeof (char)*18);
	File.write (reinterpret_cast<char *>(data), sizeof (char)*imageSize);
	File.close();
	
	delete[] data;
	data=NULL;
}