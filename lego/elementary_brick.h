#ifndef __X_H_INCLUDED__   // if x.h hasn't been included yet...
#define __X_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>

#endif
#ifndef __essentials_included__
#define __essentials_included__
#include "small_brick.h"
#include "upper_cylinder.h"
#include "boundary.h"
#include "lower_cylinder.h"
#endif
class elementary_brick
{
public:
	GLfloat point[3];
	GLint length;
	GLfloat prevMatrix[16];
	GLint colour;
	void draw_elementary_brick();
};
