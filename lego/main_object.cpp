#include "main_object.h"

void main_object::add_elementary_brick(GLfloat* point, int length, GLfloat* prevState,GLint colour)
{
	elementary_brick new_brick;
	new_brick.point[0] = point[0];
	new_brick.point[1] = point[1];
	new_brick.point[2] = point[2];
	new_brick.length = length;
	new_brick.colour=colour;
	for(int i=0;i<16;++i)
	{
		new_brick.prevMatrix[i] = prevState[i];
	}
	elementary_brick_list.push_back(new_brick);
}

void main_object::elementary_list_draw(GLfloat* prevState)
{
	std::list<elementary_brick>::iterator it;
	GLfloat matrix[16]; 	
	for(it=elementary_brick_list.begin();it!=elementary_brick_list.end();++it)
	{
		
		/*glLoadIdentity();
		glLoadMatrixf(prevState);
		glLoadMatrixf(it->prevMatrix);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		*/
		for(int i=0;i<16;++i)
		{
			it->prevMatrix[i] = prevState[i];
			// new_brick.prevMatrix[i] = prevState[i];
		}
		set_material_properties(it->colour);//in utility.cpp

		// it->prevMatrix
		it->draw_elementary_brick();
	}
}

void main_object::add_sloping_brick(GLfloat* point, int length, GLfloat* prevState,int type,GLint colour)
{
	sloping_brick new_brick;
	new_brick.point[0] = point[0];
	new_brick.point[1] = point[1];
	new_brick.point[2] = point[2];
	new_brick.length = length;
	new_brick.type = type;
	new_brick.colour=colour;

	for(int i=0;i<16;++i)
	{
		new_brick.prevMatrix[i] = prevState[i];
	}
	sloping_brick_list.push_back(new_brick);
}

void main_object::sloping_list_draw(GLfloat* prevState)
{
	std::list<sloping_brick>::iterator it;
	GLfloat matrix[16]; 	
	for(it=sloping_brick_list.begin();it!=sloping_brick_list.end();++it)
	{
		
		/*glLoadIdentity();
		glLoadMatrixf(prevState);
		glLoadMatrixf(it->prevMatrix);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		*/
		for(int i=0;i<16;++i)
		{
			it->prevMatrix[i] = prevState[i];
			// new_brick.prevMatrix[i] = prevState[i];
		}
		// it->prevMatrix
		set_material_properties(it->colour);//in utility.cpp
		
		it->draw_sloping_brick();
	}
}

void main_object::add_base_plate(GLfloat* point, int length, GLfloat* prevState,GLint colour)
{
	base_plate new_brick;
	new_brick.point[0] = point[0];
	new_brick.point[1] = point[1];
	new_brick.point[2] = point[2];
	new_brick.length = length;
	new_brick.colour=colour;

	// new_brick.type = type;
	for(int i=0;i<16;++i)
	{
		new_brick.prevMatrix[i] = prevState[i];
	}
	base_plate_list.push_back(new_brick);
}

void main_object::base_plate_draw(GLfloat* prevState)
{
	std::list<base_plate>::iterator it;
	GLfloat matrix[16]; 	
	for(it=base_plate_list.begin();it!=base_plate_list.end();++it)
	{
		
		/*glLoadIdentity();
		glLoadMatrixf(prevState);
		glLoadMatrixf(it->prevMatrix);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		*/
		for(int i=0;i<16;++i)
		{
			it->prevMatrix[i] = prevState[i];
			// new_brick.prevMatrix[i] = prevState[i];
		}
		set_material_properties(it->colour);//in utility.cpp
		// it->prevMatrix
		it->draw_base_plate();
	}
}

void main_object::add_window(GLfloat* point, GLfloat* prevState,GLint colour)
{
	window new_brick;
	new_brick.point[0] = point[0];
	new_brick.point[1] = point[1];
	new_brick.point[2] = point[2];
	new_brick.colour=colour;

	for(int i=0;i<16;++i)
	{
		new_brick.prevMatrix[i] = prevState[i];
	}
	window_list.push_back(new_brick);
}

void main_object::window_draw(GLfloat* prevState)
{
	std::list<window>::iterator it;
	GLfloat matrix[16]; 	
	for(it=window_list.begin();it!=window_list.end();++it)
	{
		
		/*glLoadIdentity();
		glLoadMatrixf(prevState);
		glLoadMatrixf(it->prevMatrix);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		*/
		for(int i=0;i<16;++i)
		{
			it->prevMatrix[i] = prevState[i];
			// new_brick.prevMatrix[i] = prevState[i];
		}
		set_material_properties(it->colour);//in utility.cpp
		// it->prevMatrix
		it->draw_window();
	}
}

void main_object::add_fence(GLfloat* point,GLint length, GLfloat* prevState,GLint colour)
{
	fence new_brick;
	new_brick.point[0] = point[0];
	new_brick.point[1] = point[1];
	new_brick.point[2] = point[2];
	new_brick.length=length;
	new_brick.colour=colour;

	for(int i=0;i<16;++i)
	{
		new_brick.prevMatrix[i] = prevState[i];
	}

	fence_list.push_back(new_brick);
}

void main_object::fence_draw(GLfloat* prevState)
{
	std::list<fence>::iterator it;
	GLfloat matrix[16]; 	
	for(it=fence_list.begin();it!=fence_list.end();++it)
	{
		
		/*glLoadIdentity();
		glLoadMatrixf(prevState);
		glLoadMatrixf(it->prevMatrix);
		glGetFloatv (GL_MODELVIEW_MATRIX, matrix);
		*/
		for(int i=0;i<16;++i)
		{
			it->prevMatrix[i] = prevState[i];
			// new_brick.prevMatrix[i] = prevState[i];
		}
		set_material_properties(it->colour);//in utility.cpp
		// it->prevMatrix
		it->draw_fence();
	}
}