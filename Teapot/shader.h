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

#include <string.h>
// #include <iostream>
#include <fstream>
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


