#if ( (defined(__MACH__)) && (defined(__APPLE__)) )   
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#else
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>
#endif
#ifndef _BMP_LOADER_
#define _BMP_LOADER_
#include "load_bmp.h"
#endif
#include "string.h"
/*#ifndef _UTILITY_INCLUDED_
#define _UTILITY_INCLUDED_
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#endif
#ifndef _glm_included_
#define _glm_included_
#include "glm/glm/glm.hpp"
#endif*/

#include "shader.h"
// #include "upper_cylinder.h"
float win_width = 1000;
float win_height = 1000;
GLfloat zoom_level=1;
/*GLint locations[2];
GLint locations1[2];*/

Shader shader,shader1;
double rotate_y=0; 
double rotate_x=0;
GLfloat angle = 0.0; //set the angle of rotation
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
	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	// GLfloat ambientLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// GLfloat diffuseLight[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	// GLfloat position[] = { -1.5f, 10.0f, -4.0f, 1.0f };
	// GLfloat position[] = { -1.5f, -1.5f, -1.5f, 1.0f };
	// GLfloat position[] = { 1000.0f, 100.0f, -100.0f, 0 };
	GLfloat position[] = { 0.0, 5.0f, 5.0f, 0 };

	// GLfloat position[] = { 70.0f, 10.0f, 0.0f, 0 };
	
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
void setEye()
{
    glRotatef(rotate_x,1,0,0);
    glRotatef(rotate_y,0,1,0);
}
void drawAxes() 
{	      /*  Length of axes */
	double len = 50.0;
    	// glColor3f(1.0,1.0,1.0);
	glLineWidth (2.0);
	glBegin(GL_LINES);
		glColor3f(1, 0, 0);
		glVertex3d(0,0,0);
		glVertex3d(len,0,0);
		glColor3f(0, 1, 0);
		glVertex3d(0,0,0);
		glVertex3d(0,len,0);
		glColor3f(0, 0, 1);
		glVertex3d(0,0,0);
		glVertex3d(0,0,len);
	glEnd();
		// glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    	/*  Label axes */
 		/*   glRasterPos3d(len,0,0);//print("X");
	    glRasterPos3d(0,len,0);//  print("Y");
	    glRasterPos3d(0,0,len);//  print("Z");*/
}
void init(char **argv) {
    // glEnable(GL_DEPTH_TEST);
    // glDepthFunc(GL_LESS);
    set_lights();

    // shader.init("v2.vert", "v2.frag");
    // shader.init("v1.vert", "v1.frag");
    // shader1.init("fbo3.vert", "toonigy.frag");
    // shader.init("sil.vert", "sil.frag");
    // shader.init("sil.vert", "sil.frag");
    // shader.init("tex.vert", "tex.frag");
    // shader.init("ink.vert", "ink.frag");
    // shader.init("ink_export.vert", "ink_export.frag");
    //shader.init("forum.vert", "forum.frag");
    // shader.init("fbo.vert", "fbo.frag");
    
    // shader1.init("v2.vert", "v2.frag");
    // shader1.init("v1.vert", "v1.frag");
    // shader1.init("sil.vert", "sil.frag");
    // shader1.init("tex.vert", "tex.frag");
    // shader1.init("fbo2.vert", "fbo2.frag");
    // shader1.init("fbo3.vert", "forum_fbo.frag");
   // shader1.init("fbo3.vert", "fbo3.frag");
    // shader1.init("fbo3.vert", "oil.frag");
    // shader1.init("fbo3.vert", "toonigy.frag");
    // shader1.init("fbo3.vert", "pixelate.frag");
    // shader1.init("ink.vert", "ink.frag");
    // shader1.init("ink_export.vert", "ink_export.frag");
    // shader1.init("forum.vert", "forum.frag");
    // shader1.init("fbo.vert", "fbo.frag");

	if(strcmp("water",argv[1])==0)
	{
	    shader.init("sil.vert", "sil.frag");
	    // shader.init("forum.vert", "forum.frag");
	    shader1.init("fbo3.vert", "fbo3.frag");
	    // shader.init("v1.vert", "v1.frag");
	}
	else if(strcmp("toon",argv[1])==0)
	{
 	    shader.init("sil.vert", "sil.frag");
	    // shader.init("forum.vert", "forum.frag");
	    shader1.init("fbo3.vert", "sil_copy.frag");
	}
	else if(strcmp("technical",argv[1])==0)
	{
// 	    shader.init("sil.vert", "sil.frag");
	    shader.init("forum.vert", "forum.frag");
	    shader1.init("fbo3.vert", "forum_fbo.frag");
	}
	else if(strcmp("oil",argv[1])==0)
	{
 	    shader.init("sil.vert", "sil.frag");
	   // shader.init("sil.vert", "oil.frag");
	    shader1.init("fbo3.vert", "oil.frag");
	}
	else if(strcmp("water_technical",argv[1])==0)
	{
	   shader.init("forum.vert", "forum.frag");
	   // shader.init("sil.vert", "oil.frag");
	    shader1.init("fbo3.vert", "fbo3.frag");
	}
	else if(strcmp("pixelate",argv[1])==0)
	{
	  // shader.init("forum.vert", "forum.frag");
	    shader.init("sil.vert", "sil.frag");
	    shader1.init("fbo3.vert", "pixelate.frag");
	}
	else
	{
//	   shader.init("forum.vert", "forum.frag");
	   shader.init("sil.vert", "sil.frag");
	    // shader.init("fo`rum.vert", "forum.frag");
	    shader1.init("fbo3.vert", "fbo3.frag");
	}

    

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
void gen_frame_buffer()
{

	// The framebuffer, which regroups 0, 1, or more textures, and 0 or 1 depth buffer.
	GLuint FramebufferName = 0;
	glGenFramebuffers(1, &FramebufferName);
	glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);
	// The texture we're going to render to
	GLuint renderedTexture;
	glGenTextures(1, &renderedTexture);
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glActiveTexture(GL_TEXTURE0);
	// glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, renderedTexture);
	// Give an empty image to OpenGL ( the last "0" )
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, win_height, win_width, 0,GL_RGB, GL_UNSIGNED_BYTE, 0);
	// Poor filtering. Needed !
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// The depth buffer
	GLuint depthrenderbuffer;
	glGenRenderbuffers(1, &depthrenderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, depthrenderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, win_height, win_width);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer);

	// Set "renderedTexture" as our colour attachement #0
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, renderedTexture, 0);
	// Set the list of draw buffers.
	GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
	glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers

	// Always check that our framebuffer is ok
	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			printf("Problem with framebuffer\n");
	// Render to our framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// glViewport(0,0,1024,768); // Render on the whole framebuffer, complete from the lower left corner to the upper right
}

void cube (void) 
{

	/*glRotatef(angle, 1.0, 0.0, 0.0); //rotate on the x axis
	glRotatef(angle, 0.0, 1.0, 0.0); //rotate on the y axis
	glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis
	glColor4f(1.0, 0.0, 0.0, 1.0);
	*/
    // shader.init("sil.vert", "sil.frag");
	
	gen_frame_buffer();
    shader.bind();
    // drawAxes();
    glRotatef(90,1,0,0);
    glScalef(0.5,0.5,0.5);
	glColor3f(0.0, 0.0, 0.8);
    glutSolidTorus(0.5,1.5,10,20);
    glRotatef(-90,1,0,0);
	glTranslatef(0,2,0);
    glColor3f(0.8,0.8,0.2);
	glutSolidTeapot(2);

	GLUquadricObj* quadratic=gluNewQuadric();          // Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(quadratic, GLU_SMOOTH);   // Create Smooth Normals ( NEW )
	gluQuadricTexture(quadratic, GL_TRUE); 
    glScalef(2,2,2);
	
	glColor3f(0.1,0.3,0.2);
	glTranslatef(3.0f, 1.0f, 1.0f);
	glRotatef(-90,1.0f, 0.0f, 0.0f); 
	gluCylinder(quadratic, 0.3f, 0.5f, 0.5f, 32, 32);
	glTranslatef(0.0f, 0.0f, -0.5f);
	gluCylinder(quadratic, 0.7f, 0.3f, 0.5f, 32, 32);
	glTranslatef(0.0f, 0.0f, -2.0f);
	gluCylinder(quadratic, 0.3f, 0.7f, 2.0f, 32, 32);
	gluDisk(quadratic, 0.0f, 0.3f, 32, 32); 
	
	glRotatef(90,1.0f, 0.0f, 0.0f); 
	glTranslatef(0,3.2,0);
	glColor3f(0.8, 0.0, 0.0);
	glutSolidIcosahedron();
	glColor3f(0.2,0.2,0.2);
	// glLoadIdentity();
	/*glTranslatef(-3,-3.5,1);
	glScalef(100,0.1,100);
	glutSolidCube(1);
	glTranslatef(100,1,1);
*/	/*glScalef(0.5,0.5,0.5);
	glColor3f(0.0, 0.8, 0.2);
	glTranslatef(-2,-4,3);
    glutSolidDodecahedron();
	glTranslatef(1,0,2);
	glColor3f(0.0, 0.8, 0.0);
    glutSolidTetrahedron();
    */
    shader.unbind();	
    // screenshot();
	// glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // shader.init("tex.vert", "tex.frag");
	// load_paper_texture();
    // glBindTexture(GL_TEXTURE_2D,0);
    glLoadIdentity();
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	GLint x = load_bmp("paper1.bmp",1);
	// GLint x = load_bmp("paper.bmp",1);
	// x = load_bmp("noise.bmp",2);
	x = load_bmp("fine_noise.bmp",2);
	// x = load_bmp("perlin.bmp",2);
	x = load_bmp("hatch.bmp",3);
	// GLint z =load_bmp("test.bmp",0);
    // shader.init("fbo3.vert", "fbo3.frag",locations1);
	// shader.init("fbo3.vert","fbo3.frag");
	shader1.bind();
	GLuint t1Location = glGetUniformLocation(shader1.id(), "texUnit");
	GLuint t2Location = glGetUniformLocation(shader1.id(), "paperTex");
	GLuint t3Location = glGetUniformLocation(shader1.id(), "perlinTex");
	GLuint t4Location = glGetUniformLocation(shader1.id(), "hatchTex");

	glActiveTexture(GL_TEXTURE0);
	glUniform1i(t1Location, 0);
	glActiveTexture(GL_TEXTURE0+1);
	glUniform1i(t2Location, 1);
	glActiveTexture(GL_TEXTURE0+2);
	glUniform1i(t3Location, 2);
	glActiveTexture(GL_TEXTURE0+3);
	glUniform1i(t4Location, 3);

	glutSolidTeapot(2);
	glTranslatef(3,3,3);
	glutSolidIcosahedron();
      
	shader1.unbind();
	// shader1.unbind();

	// glDisable(GL_TEXTURE_2D);

   /* 
    glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, renderedTexture);
	glActiveTexture(GL_TEXTURE0);    
	*/
	// GLint var = glGetUniformLocationARB(yourShaderProgram, "yourSampler");
	// glUniform1i(var, 1);
	// glLoadIdentity();																																													
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
void display (void) {
	// glClearColor (0.0,0.0,0.0,1.0);
	glDisable(GL_LIGHTING);
    
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	glMatrixMode(GL_PROJECTION);
	// drawAxes( );
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (5.0*zoom_level, 5.0*zoom_level, 5.0*zoom_level, 0.0, 0.0, 0.0, -0.5,0.707106781, -0.5);
	// gluLookAt (5.0, 5.0, 5.0, 0.0, 0.0, 0.0, -0.5,0.707106781, -0.5);
	setEye();
    // glColor3f(1,1,1);

    // set_material_properties(1);
    // shader.bind();
    // glScalef(5,5,5);
	cube();
	// load_obj();
    // shader.unbind();
	glFlush();
    glutSwapBuffers();
	angle += 0.01f;
}
void specialKeys( int key, int x, int y ) 
{
 
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
  glutPostRedisplay();
 
}
void keyboard(unsigned char key,int x,int y)
{

	if(key==56 )
		zoom_level+=0.25;
	else if(key == 50 )
		zoom_level-=0.25;
		
	glutPostRedisplay();

}
void reshape (int w, int h) {
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv) {
  	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize (1000, 1000); 
	glutInitWindowPosition (0,0);

	glutCreateWindow ("LeGO");
  	GLenum err = glewInit();

    init(argv);
	glClearColor(1.0,1.0,1.0,0.0);
	glutKeyboardFunc(keyboard);
    
    glutDisplayFunc(display);
	// glutIdleFunc(display);
	
    glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);

    // 
    
    glutMainLoop();
    
    return 0;
}

