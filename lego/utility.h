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
using namespace std;
void drawAxes();
void set_material_properties(GLint colour_option);
void set_lights();
void screenshot(char filename[160],int x, int y);