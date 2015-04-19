varying vec3 vNormal;
varying vec3 vVertex;
varying vec3 lightPos;   
// varying vec3 specular;         
void main(void)
{
	vVertex = gl_Vertex.xyz;
	vNormal = gl_Normal;
	lightPos=vec3(gl_LightSource[0].position);
	// specular = gl_FrontMaterial.specular;
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}