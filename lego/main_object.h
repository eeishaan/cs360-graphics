#ifndef __X_H_INCLUDED__   // if x.h hasn't been included yet...
#define __X_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#endif
#include "elementary_brick.h"
#include "sloping_brick.h"
#include "base_plate.h"
#include "window.h"
#include "fence.h"
#ifndef _utility_included_
#define _utility_included_
#include "utility.h"
#endif
#include <list>
using namespace std;

class main_object
{
public:	
	std::list<elementary_brick> elementary_brick_list;
	std::list<sloping_brick> sloping_brick_list;
	std::list<base_plate> base_plate_list;
	std::list<window> window_list;
	std::list<fence> fence_list;
// public:
	void add_elementary_brick(GLfloat* point,int length, GLfloat* prevMatrix,GLint colour); //creates a new brick and add it to the list of bricks
	void elementary_list_draw(GLfloat* prevState);

	void add_sloping_brick(GLfloat* point,int length, GLfloat* prevMatrix,int type,GLint colour);
	void sloping_list_draw(GLfloat* prevState);

	void add_base_plate(GLfloat* point,int length, GLfloat* prevMatrix,GLint colour);
	void base_plate_draw(GLfloat* prevState);

	void add_window(GLfloat* point, GLfloat* prevMatrix,GLint colour);
	void window_draw(GLfloat* prevState);

	void add_fence(GLfloat* point, GLint length, GLfloat* prevMatrix,GLint colour);
	void fence_draw(GLfloat* prevState);

};