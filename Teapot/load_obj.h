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
#ifndef _UTILITY_INCLUDED_
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
#endif
using namespace std;
// include
bool load_obj(const char * path,std::vector < glm::vec3 > & out_vertices,std::vector < glm::vec2 > & out_uvs,std::vector < glm::vec3 > & out_normals);