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
#ifndef __MATH_C_INCLUDED__   // if x.h hasn't been included yet...
#define __MATH_C_INCLUDED__ 
#include <math.h>
#endif
#ifndef __Math_Constants
#define __Math_Constants
#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define DEF_D 1
#endif
#ifndef _BMP_LOADER_
#define _BMP_LOADER_
#include "load_bmp.h"
#endif
void create_upper_cylinder();
