#include "upper_cylinder.h"



void create_upper_cylinder(GLfloat* matrix)
{
  glLoadIdentity();
  // setEye();
  glLoadMatrixf(matrix);
  int th2, ph2;double i, j, k;
  double height=0.1;
  double radius=0.3;
  double centre_x=0;
  double centre_y=0;
  double centre_z=0;
  /*GLfloat normal[6][3]={
        {1,0,0},
        {0,1,0},
        {0,0,1},
        {-1,0,0},
        {0,-1,0},
        {0,0,-1}
  };
  */    glBegin(GL_QUAD_STRIP);
      for (j=0;j<=360;j+=DEF_D) 
      {
           // glColor3f(0,1,0);
           
           //glColor3f(0,1,0);
           glNormal3f(Cos(j),0,Sin(j));
           glVertex3f((radius)*Cos(j)+centre_x,0+centre_y,(radius)*Sin(j)+centre_z);
           glNormal3f(Cos(j),0,Sin(j));
           glVertex3f((radius)*Cos(j)+centre_x,(2*height) +centre_y,(radius)*Sin(j)+centre_z);
      }
      glEnd();

      glNormal3f(0,1,0);   
      // glEnable(GL_TEXTURE_2D);
      // int texture_id= load_bmp("lego_texture5.bmp",1);
      // for (i=0;i<=2*height;i=i+2*height) 
      // {
        i=2*height;
          glBegin(GL_TRIANGLE_FAN);
          // glColor3f(0,0,1);
          glTexCoord2f(0.5, 0.5);
          glVertex3f(0+centre_x,i+centre_y,0+centre_z);
          for (k=0;k<=360;k+=DEF_D) 
          {
              glTexCoord2f(0.5+0.5*Cos(-k), 0.5+0.5*Sin(-k));
              glVertex3f((radius)*Cos(k)+centre_x,i+centre_y,(radius)*Sin(k)+centre_z);
          }
          glEnd();
      // }
      glDisable(GL_TEXTURE_2D);
   centre_z=centre_y=centre_x=0;
}