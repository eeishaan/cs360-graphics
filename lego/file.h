#ifndef _fstream_included_
#define _fstream_included_
#include <fstream>
#endif
#ifndef __main_object_h
#define __main_object_h
#include "main_object.h"
#endif
using namespace std;
void save_to_file(main_object* data);
void read_from_file(main_object* data);