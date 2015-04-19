#ifndef __X_H_INCLUDED__   // if x.h hasn't been included yet...
#define __X_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>

#endif
#ifndef __MATH_C_INCLUDED__   // if x.h hasn't been included yet...
#define __MATH_C_INCLUDED__ 
#include <math.h>
#endif
#ifndef _BMP_LOADER_
#define _BMP_LOADER_
#include "load_bmp.h"
#endif
void create_slope(GLfloat* matrix, GLint breadth);