#ifndef __GLEW_INCLUDED__   // if x.h hasn't been included yet...
#define __GLEW_INCLUDED__   //   #define this so the compiler knows it has been included
#include <GL/glew.h>
#include <GL/glext.h>
#endif

#ifndef __X_H_INCLUDED__   // if x.h hasn't been included yet...
#define __X_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#endif



#ifndef __string_INCLUDED__   // if x.h hasn't been included yet...
#define __string_INCLUDED__ 
#include <string.h>
#endif
// #include <iostream>
#ifndef _fstream_included_
#define _fstream_included_
#include <fstream>
#endif
using namespace std;

// #include <stdlib.h>
class Shader {
public:
	/*Shader();
	Shader(const char *vsFile, const char *fsFile);
	*/// ~Shader();
	
    void init(const char *vsFile, const char *fsFile);
    
	void bind();
	void unbind();
	
	unsigned int id();
	
private:
	unsigned int shader_id;
	unsigned int shader_vp;
	unsigned int shader_fp;
};


