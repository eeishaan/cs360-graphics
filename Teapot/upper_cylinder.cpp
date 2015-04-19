#include "upper_cylinder.h"


void set_light_v(GLfloat *light_pos,GLfloat *v)
{
  for (int i = 0; i < 3; ++i)
  {
    /* code */
    v[i]=light_pos[i]-v[i];
  }
}

GLfloat get_dot(GLfloat point[3],GLfloat light_point[3],GLfloat normal[3])
{
  set_light_v(light_point,point);
  //Now the point is set to the light vector
  normalize(point);
  //we get normalized normal
  return maxNdotL(point, normal);
}
void create_upper_cylinder()
{

/*  glMatrixMode(GL_TEXTURE);
  glLoadIdentity();
  glScalef(5, 5, 5);
  glMatrixMode(GL_MODELVIEW);*/
  int th2, ph2;double i, j, k;
  double height=0.1;
  double radius=0.3;
  double centre_x=0;
  double centre_y=0;
  double centre_z=0;


  GLdouble proj_x, proj_y, proj_z;


  GLint viewport[4];
  GLdouble mvmatrix[16], projmatrix[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
  glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
  

  // glEnable(GL_TEXTURE_2D);
  // int texture_id= load_bmp("stipple.bmp");
  return;
/*  unsigned char *data;
  unsigned char *data1;
  // unsigned char *data2;
  // unsigned char *data3;
  // GLint params[4][2];
  GLint params[2][2];
*/
  // GLint x = load_picture("stipple.bmp",params[0], data);
  // printf("X :%d\n",x );
  // load_picture("stipple.bmp",params[0], data);
  // GLint y =load_picture("cross.bmp",params[1], data1);
  // printf("Y :%d\n",y );
  // load_picture("stipple.bmp",params[0], data);


  GLfloat light_pos[3],light_v[3];
  glGetLightfv(GL_LIGHT0,GL_POSITION,light_pos);
  gluUnProject(light_pos[0],light_pos[1],light_pos[2],mvmatrix, projmatrix, viewport, &proj_x, &proj_y, &proj_z);

  // printf("Light pos is : %lf, %lf, %lf\n",proj_x, proj_y, proj_z );
 /* gluProject(light_pos[0],light_pos[1],light_pos[2], mvmatrix, projmatrix, viewport, &proj_x, &proj_y, &proj_z);
  */
  
  light_pos[0]=proj_x;
  light_pos[1]=proj_y;
  light_pos[2]=proj_z;

  GLfloat temp[3];
  GLfloat dot;
  /*for (int i = 0; i < 3; ++i)
  {
     code 
    temp[i]=light_pos[i];
  }*/

  // normalize(temp);
  
  glBegin(GL_QUAD_STRIP);
  for (j=0;j<=360;j+=DEF_D) 
  {
      temp[0]=Cos(j);
      temp[1]=0;
      temp[2]=Sin(j);
     
      // glColor3f(0,1,0);
       
      //glColor3f(0,1,0);
    /* 


      gluProject(light_v[0],light_v[1],light_v[2], mvmatrix, projmatrix, viewport, &proj_x, &proj_y, &proj_z);
      proj_x /= 500;
      proj_y /= 500;
      
      set_light_v(light_pos,light_v);
     normalize(light_v);
      // normalize(temp);
      dot = NdotL(temp,light_v);
      if(dot>0.4 && dot<0.7)
      {
        printf("COnditon first\n");
          x =load_bmp("stipple.bmp");
    */  /*  glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, params[0][0], params[0][0], 0, GL_BGR, GL_UNSIGNED_BYTE, data);
   
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    *//*  }
      else if((dot < 0.4) && (dot > -0.1))
      {
        printf("COnditon Second\n");
        x =load_bmp("cross.bmp");
          glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, params[1][0], params[1][0], 0, GL_BGR, GL_UNSIGNED_BYTE, data1);
   
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

      }
      */

      light_v[0]=(radius)*Cos(j);
      light_v[1]=0;
      light_v[2]=(radius)*Sin(j);
     
      dot = get_dot(light_v,light_pos,temp); 
      // printf("%s\n", );
      // glTexCoord2f(j/360,0);
      if(dot>0.2)
        glTexCoord2f(1-dot,0);
      else
        glTexCoord2f(0,0);
      glNormal3f(Cos(j),0,Sin(j));
      glVertex3f((radius)*Cos(j),0,(radius)*Sin(j));
      
      /*light_v[0]=(radius)*Cos(j);
      light_v[1]=2*height;
      light_v[2]=(radius)*Sin(j);
      gluProject(light_v[0],light_v[1],light_v[2], mvmatrix, projmatrix, viewport, &proj_x, &proj_y, &proj_z);
      proj_x /= 500;
      proj_y /= 500;
     
      set_light_v(light_pos,light_v);
  */ /*   temp[0]=Cos(j); ///Already done
      temp[1]=0;
      temp[2]=Sin(j);*/
      // normalize(light_v);
      // normalize(temp);
  /*    dot = maxNdotL(temp,light_v);
      if(dot>0.4 && dot<0.7)
      {
        printf("COnditon first\n");
          x =load_bmp("stipple.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, params[0][0], params[0][0], 0, GL_BGR, GL_UNSIGNED_BYTE, data);
   
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      }
      else if((dot < 0.4) && (dot > -0.1))
      {
        printf("COnditon Second\n");
        x =load_bmp("cross.bmp");
/*          glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, params[1][0], params[1][0], 0, GL_BGR, GL_UNSIGNED_BYTE, data1);
   
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    }
   */ 
    // glTexCoord2f(proj_x, proj_y);
      // glTexCoord2f(0.5+0.5*Cos(j), 0.5+0.5*Sin(j));
      // glTexCoord2f(j/360,1);

      light_v[0]=(radius)*Cos(j);
      light_v[1]=(2*height);
      light_v[2]=(radius)*Sin(j);
     
      dot = get_dot(light_v,light_pos,temp); 

      // glTexCoord2f(j/360,0);
      if(dot>0.2)
        glTexCoord2f(1-dot,1);
      else
        glTexCoord2f(0,0);
      
      glNormal3f(Cos(j),0,Sin(j));
      glVertex3f((radius)*Cos(j),(2*height),(radius)*Sin(j));
     

      // set_light_v(light_pos,light_v);
  }
  glEnd();

 /* glNormal3f(0,1,0);   
  temp[0]=0;
  temp[1]=1;
  temp[2]=0;
    
  // for (i=0;i<=2*height;i=i+2*height) 
  // {
    i=2*height;
      glBegin(GL_TRIANGLE_FAN);
      // glColor3f(0,0,1);
      // glTexCoord2f(0.5, 0.5);

      light_v[0]=0;
      light_v[1]=i;
      light_v[2]=0;
      dot = get_dot(light_v,light_pos,temp); 
      glTexCoord2f(1-dot,0);
      glVertex3f(0,i,0);
      for (k=0;k<=360;k+=DEF_D) 
      {
          light_v[0]=(radius)*Cos(k);
          light_v[1]=i;
          light_v[2]=(radius)*Sin(k);
          dot = get_dot(light_v,light_pos,temp); 
          glTexCoord2f(1-dot,0);

          // glTexCoord2f(0.5+0.5*Cos(-k), 0.5+0.5*Sin(-k));
          glVertex3f((radius)*Cos(k),i,(radius)*Sin(k));
      }
      glEnd();*/
  // }
  glDisable(GL_TEXTURE_2D);
  centre_z=centre_y=centre_x=0;
}
