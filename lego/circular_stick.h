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

#ifndef __Math_Constants
#define __Math_Constants
#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define DEF_D 1
#endif


void create_circular_stick(GLfloat r,GLfloat h);
