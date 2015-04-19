#include "load_bmp.h"

GLint load_bmp(char* imagepath, int tex_number)
{
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	FILE * file = fopen(imagepath,"rb");
	if (!file)  
	{	
		printf("Image could not be opened\n"); 
		return 0;
	}
	if ( fread(header, 1, 54, file)!=54 )
	{ // If not 54 bytes read : problem
	    printf("Not a correct BMP file\n");
	    return false;
	}
	if ( header[0]!='B' || header[1]!='M' )
	{
    	printf("Not a correct BMP file\n");
		return 0;
	}
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way

	data = new unsigned char [imageSize];
 
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
	 
	//Everything is in memory now, the file can be closed
	fclose(file);

	GLuint textureID;
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0+tex_number);
	 
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	 
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

}

GLint load_bmp_1d(char* imagepath)
{
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	FILE * file = fopen(imagepath,"rb");
	if (!file)  
	{	
		printf("Image could not be opened\n"); 
		return 0;
	}
	if ( fread(header, 1, 54, file)!=54 )
	{ // If not 54 bytes read : problem
	    printf("Not a correct BMP file\n");
	    return false;
	}
	if ( header[0]!='B' || header[1]!='M' )
	{
    	printf("Not a correct BMP file\n");
		return 0;
	}
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way

	data = new unsigned char [imageSize];
 
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
	 
	//Everything is in memory now, the file can be closed
	fclose(file);
	/*int stripeImageWidth = 32;
	GLubyte   stripeImage[3*stripeImageWidth];
	for (int j = 0; j < stripeImageWidth; j++) 
	{
	    stripeImage[3*j] = j*255/32; // use a gradient instead of a line
	    stripeImage[3*j+1] = 255;
	    stripeImage[3*j+2] = 255;
	}*/
	// glDisable(GL_TEXTURE_2D);
	// glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	GLuint textureID;
	// glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glGenTextures(1, &textureID);
	 
 	glDisable( GL_TEXTURE_GEN_S ); 
	glDisable(GL_TEXTURE_2D);
	glEnable( GL_TEXTURE_1D );
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_1D, textureID);	
	// glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
	// Give the image to OpenGL
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, width, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	// glTexImage1D(GL_TEXTURE_1D, 0, 3, stripeImageWidth, 0, GL_RGB, GL_UNSIGNED_BYTE,stripeImage);
	
	glDisable(GL_LIGHTING);
	

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	// glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	 
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return 100;
}
GLfloat maxNdotL(GLfloat n[3], GLfloat l[3])
{
	printf("The dot product is : %lf\n",l[0]*n[0]+l[1]*n[1]+l[2]*n[2] );
    if ((l[0]*n[0]+l[1]*n[1]+l[2]*n[2]) > 0.000000)
	{
		// printf("maxNdotL returned %lf\n",0.0 ); 
		return (l[0]*n[0]+l[1]*n[1]+l[2]*n[2]);
	}  	
	// printf("maxNdotL returned %lf\n",0.0 ); 
	return 0.0; 
}
void normalize(GLfloat* pos)
{
	// printf("In normalize : Light coordinate is %lf, %lf, %lf\n",pos[0],pos[1],pos[2]);
	GLfloat divider = sqrt(pos[0]*pos[0] + pos[1]*pos[1] + pos[2]*pos[2]);
	pos[0]/=divider;
	pos[1]/=divider;
	pos[2]/=divider;
}
void light_vector_generator(GLfloat* coordinate, GLfloat* light)
{
	light[0]-=coordinate[0];
	light[1]-=coordinate[1];
	light[2]-=coordinate[2];
	normalize(light);
}
void avg_coordinate(GLfloat* c1,GLfloat* c2 ,GLfloat* c3,GLfloat* c4,GLfloat* new_c)
{
	for(int i=0;i<2;++i)
	{
		new_c[i]=(c1[i]+c2[i]+c3[i]+c4[i])/4;
	}
}
