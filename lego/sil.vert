varying vec3 vNormal;
varying vec3 vVertex;
varying vec3 lightPos;   
// varying vec3 specular;         
void main(void)
{
	vec3 lightdir;
	float costerm=0.0;
	vVertex = gl_Vertex.xyz;
	vNormal = gl_Normal;
	lightPos=vec3(gl_LightSource[0].position);

	lightdir = normalize(lightPos);
	costerm = max(dot(normalize(gl_NormalMatrix * gl_Normal), lightdir), 0.0);

	vec4 diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;

	vec4 ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
	vec4 globalAmbient = gl_LightModel.ambient * gl_FrontMaterial.ambient;
	

	gl_FrontColor = costerm*diffuse + ambient+ globalAmbient;//gl_Color;
	gl_FrontSecondaryColor =  gl_SecondaryColor;
	gl_BackColor = costerm*diffuse + ambient+ globalAmbient;// gl_Color;
	gl_BackSecondaryColor = gl_SecondaryColor;
	/*if(costerm>0.0)
	{
		float half_costerm = max(dot(normal, gl_LightSource[0].halfVector.xyz),0.0);
		gl_FrontColor += gl_FrontMaterial.specular * gl_LightSource[0].specular *pow(half_costerm,gl_FrontMaterial.shininess);
		// gl_BackColor += gl_FrontMaterial.specular * gl_LightSource[0].specular *pow(half_costerm,gl_FrontMaterial.shininess);
	}*/
	// gl_FrontColor + = gl_FrontMaterial.specular;
	/*gl_FrontColor = gl_Color;
	gl_FrontSecondaryColor =  gl_SecondaryColor;
	gl_BackColor =  gl_Color;
	gl_BackSecondaryColor = gl_SecondaryColor;*/
	
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}