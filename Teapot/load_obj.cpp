#include "load_obj.h"

/*bool load_obj(
    const char * path,
    std::vector < glm::vec3 > & out_vertices,
    std::vector < glm::vec2 > & out_uvs,
    std::vector < glm::vec3 > & out_normals
)
{*/
void load_obj(const char* filename, vector<glm::vec4> &vertices, vector<glm::vec3> &normals, vector<GLushort> &elements) {

	/*std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;
*/
	FILE * file = fopen(path, "r");
	if( file == NULL )
	{
	    printf("Impossible to open the file !\n");
	    return false;
	}
	while( 1 )
	{

        char line[128];
        // read the first word of the line
        int res = fscanf(file, "%s", line);
        if (res == EOF)
                break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader
        
        if ( strcmp( line, "v" ) == 0 )
        {
               /* glm::vec3 vertex;
                fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
                temp_vertices.push_back(vertex);*/
                istringstream s(line.substr(2));
              glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
              vertices.push_back(v);
        }
      /*  else if ( strcmp( lineHeader, "vt" ) == 0 )
        {
                glm::vec2 uv;
                fscanf(file, "%f %f\n", &uv.x, &uv.y );
                uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
                temp_uvs.push_back(uv);
        }
      */  /*else if ( strcmp( lineHeader, "vn" ) == 0 )
        {
                glm::vec3 normal;
                fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
                temp_normals.push_back(normal);
        }*/
        else if ( strcmp( line, "f" ) == 0 )
        {
               /* std::string vertex1, vertex2, vertex3;
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
                if (matches != 9)
                {
                        printf("File can't be read by our simple parser :-( Try exporting with other options\n");
                        return false;
                }
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices    .push_back(uvIndex[0]);
                uvIndices    .push_back(uvIndex[1]);
                uvIndices    .push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);*/
                 istringstream s(line.substr(2));
                GLushort a,b,c;
                s >> a; s >> b; s >> c;
                a--; b--; c--;
                elements.push_back(a); elements.push_back(b); elements.push_back(c);
        }
        /*else
        {
                // Probably a comment, eat up the rest of the line
                char stupidBuffer[1000];
                fgets(stupidBuffer, 1000, file);
        }*/
        else if (line[0] == '#') { /* ignoring this line */ }
        else { /* ignoring this line */ }
	}

	/*for( unsigned int i=0; i<vertexIndices.size(); i++ )
	{

        // Get the indices of its attributes
        unsigned int vertexIndex = vertexIndices[i];
        unsigned int uvIndex = uvIndices[i];
        unsigned int normalIndex = normalIndices[i];
        
        // Get the attributes thanks to the index
        glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
        glm::vec2 uv = temp_uvs[ uvIndex-1 ];
        glm::vec3 normal = temp_normals[ normalIndex-1 ];
        
        // Put the attributes in buffers
        out_vertices.push_back(vertex);
        out_uvs.push_back(uv);
        out_normals .push_back(normal);

	}

    return true;*/
}
void load_obj(const char* filename, vector<glm::vec4> &vertices, vector<glm::vec3> &normals, vector<GLushort> &elements) {
  ifstream in(filename, ios::in);
  if (!in) { cerr << "Cannot open " << filename << endl; exit(1); }
 
  string line;
  while (getline(in, line)) {
    if (line.substr(0,2) == "v ") {
      istringstream s(line.substr(2));
      glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
      vertices.push_back(v);
    }  else if (line.substr(0,2) == "f ") {
      istringstream s(line.substr(2));
      GLushort a,b,c;
      s >> a; s >> b; s >> c;
      a--; b--; c--;
      elements.push_back(a); elements.push_back(b); elements.push_back(c);
    }
    else if (line[0] == '#') { /* ignoring this line */ }
    else { /* ignoring this line */ }
  }
 
  normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
  for (int i = 0; i < elements.size(); i+=3) {
    GLushort ia = elements[i];
    GLushort ib = elements[i+1];
    GLushort ic = elements[i+2];
    glm::vec3 normal = glm::normalize(glm::cross(
      glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
      glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
    normals[ia] = normals[ib] = normals[ic] = normal;
  }
}