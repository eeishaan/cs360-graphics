#include "shader.h"

static char* textFileRead(const char *fileName) {
	char* text;
  	ifstream is(fileName, ios::in);
	if(!is)
	{
		printf("Unable to open file\n");
		return NULL;
	}
	is.seekg (0, is.end);
    int length = is.tellg();
    is.seekg (0, is.beg);

    // allocate memory:
    text = (char*)malloc(sizeof(char) * (length + 1));

    // read data as a block:
    is.read (text,length);
    text[length]='\0';
    is.close();
	return text;
}

/*Shader::Shader() {
    
}

Shader::Shader(const char *vsFile, const char *fsFile) {
    init(vsFile, fsFile);
}
*/
void Shader::init(const char *vsFile, const char *fsFile) 
{
	shader_vp = glCreateShader(GL_VERTEX_SHADER);
	shader_fp = glCreateShader(GL_FRAGMENT_SHADER);
    
	const char* vsText = textFileRead(vsFile);
	const char* fsText = textFileRead(fsFile);	
    
    if (vsText == NULL || fsText == NULL) {
        printf("Either vertex shader or fragment shader file not found.\n");
        return;
    }
    
	glShaderSource(shader_vp, 1, &vsText, 0);
	glShaderSource(shader_fp, 1, &fsText, 0);
    
	glCompileShader(shader_vp);
	glCompileShader(shader_fp);

	GLint logLength;
    glGetShaderiv(shader_fp, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar* log = (GLchar*)malloc(logLength);
        glGetShaderInfoLog(shader_fp, logLength, &logLength, log);
        printf("Shader compile log:\n%s\n", log);
        free(log);
    }

	glGetShaderiv(shader_vp, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar* log = (GLchar*)malloc(logLength);
        glGetShaderInfoLog(shader_vp, logLength, &logLength, log);
        printf("Vertex Shader compile log:\n%s\n", log);
        free(log);
    }    
	// glUseProgram(shader_id);
	shader_id = glCreateProgram();
	// locations[0] = glGetUniformLocation(shader_id, "texUnit");
	/*GLint texUnitLoc = glGetUniformLocation(shader_id, "texUnit");
    GLint texUnitLoc1 = glGetUniformLocation(shader_id, "paperTex");
	*/// glUniform1i(texUnitLoc,0);

	// printf("Appying paperTex\n");
    // locations[1]= glGetUniformLocation(shader_id, "paperTex");
	// glUniform1i(texUnitLoc1,1);
	//glProgramUniform1i(shader_id, texUnitLoc , 0);
	//glProgramUniform1i(shader_id, texUnitLoc1 , 1);
	// glProgramUniform1i(shader_id, texUnitLoc , 1);
	// glUseProgram(0);
	glAttachShader(shader_id, shader_fp);
	glAttachShader(shader_id, shader_vp);
	glLinkProgram(shader_id);
}

/*Shader::~Shader() {
	glDetachShader(shader_id, shader_fp);
	glDetachShader(shader_id, shader_vp);
    
	glDeleteShader(shader_fp);
	glDeleteShader(shader_vp);
	glDeleteProgram(shader_id);
}*/

unsigned int Shader::id() {
	return shader_id;
}

void Shader::bind() {
	glUseProgram(shader_id);
}

void Shader::unbind() {
	glUseProgram(0);
}
