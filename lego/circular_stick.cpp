#include "circular_stick.h"

void create_circular_stick(GLfloat r,GLfloat half_height)
{
  // glLoadIdentity();
  // setEye();
  // glLoadMatrixf(matrix);
  int th2, ph2;GLfloat i, j, k;
  GLfloat height=half_height;
  GLfloat radius=r;
  GLfloat centre_x=0;
  GLfloat centre_y=0;
  GLfloat centre_z=0;
  /*GLfloat normal[6][3]={
        {1,0,0},
        {0,1,0},
        {0,0,1},
        {-1,0,0},
        {0,-1,0},
        {0,0,-1}
  };
  */    
      glBegin(GL_QUAD_STRIP);
      for (j=90;j<=270;j+=DEF_D) 
      {
           glNormal3f(Cos(j),0,Sin(j));
           glVertex3f((radius)*Cos(j)+centre_x,0+centre_y,(radius)*Sin(j)+centre_z);
           glNormal3f(Cos(j),0,Sin(j));
           glVertex3f((radius)*Cos(j)+centre_x,(2*height) +centre_y,(radius)*Sin(j)+centre_z);
      }
      glEnd();

      glNormal3f(0,1,0);   
      // glEnable(GL_TEXTURE_2D);
      // int texture_id= load_bmp("lego_texture5.bmp");
      // for (i=0;i<=2*height;i=i+2*height) 
      // {
        i=2*height;
          glBegin(GL_TRIANGLE_FAN);
          glVertex3f(0+centre_x,i+centre_y,0+centre_z);
          for (k=90;k<=270;k+=DEF_D) 
          {
              glVertex3f((radius)*Cos(k)+centre_x,i+centre_y,(radius)*Sin(k)+centre_z);
          }
          glEnd();
      glNormal3f(0,-1,0);   

          i=0;
          glBegin(GL_TRIANGLE_FAN);
          glVertex3f(0+centre_x,i+centre_y,0+centre_z);
          for (k=90;k<=270;k+=DEF_D) 
          {
              glVertex3f((radius)*Cos(k)+centre_x,i+centre_y,(radius)*Sin(k)+centre_z);
          }
          glEnd();
   // centre_z=centre_y=centre_x=0;	


          // glLoadIdentity();
  // setEye();
  // glLoadMatrixf(matrix);
  
}
