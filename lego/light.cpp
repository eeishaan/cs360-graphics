#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
int rotate_y=0;
int rotate_x=0;
void init(void) 
{
   glMatrixMode(GL_MODELVIEW);
  
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}
void setEye()
{
    glRotatef(rotate_x,1,0,0);
    glRotatef(rotate_y,0,1,0);
}
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   setEye();
   glutSolidSphere (1.0, 20, 16);
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
         1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
         1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void specialKeys( int key, int x, int y ) 
{
 
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
  glutPostRedisplay();
 
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();

   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutSpecialFunc(specialKeys);
   
   glutMainLoop();
   return 0;
}