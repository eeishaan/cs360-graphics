#ifndef __X_H_INCLUDED__   // if x.h hasn't been included yet...
#define __X_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>

#endif 

#ifndef _BMP_LOADER_
#define _BMP_LOADER_
#include "load_bmp.h"
#endif



using namespace std;
void create_small_brick(GLfloat* matrix); //this only creates a small brick of 1x1 and nothing else, you have to tranform it on ur own
void create_textured_brick();