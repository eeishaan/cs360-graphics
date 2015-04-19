#ifndef __X_H_INCLUDED__   // if x.h hasn't been included yet...
#define __X_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>

#endif
#ifndef _fstream_included_
#define _fstream_included_
#include <fstream>
#endif
#ifndef __MATH_C_INCLUDED__   // if x.h hasn't been included yet...
#define __MATH_C_INCLUDED__ 
#include <math.h>
#endif
#ifndef __string_INCLUDED__   // if x.h hasn't been included yet...
#define __string_INCLUDED__ 
#include <string.h>
#endif
GLint load_bmp(char *, int );
GLfloat maxNdotL(GLfloat*, GLfloat*);
void normalize(GLfloat* );
GLint load_bmp_1d(char* );
void light_vector_generator(GLfloat* coordinate, GLfloat* light);
void avg_coordinate(GLfloat*,GLfloat*,GLfloat*,GLfloat*,GLfloat*);
GLint load_picture(char* imagepath,GLint* params, unsigned char *data);
GLfloat NdotL(GLfloat n[3], GLfloat l[3]);
