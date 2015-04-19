varying vec3 vNormal;
varying vec3 vVertex;
uniform sampler2D texUnit;
uniform sampler2D paperTex;
// varying vec3 specular;         
varying vec3 lightPos;            
#define shininess 20.0
void main (void)
{
         
	// Material Color:
	// vec4 color0 = vec4(0.8, 0.0, 0.0, 1.0);
	vec4 color0 =vec4(gl_Color);
	// Silhouette Color:
	vec4 sil_color = vec4(0.0, 0.0, 0.0, 1.0);
	         
	// vec3 eyePos = gl_ModelViewProjectionMatrix * vVertex;
	// lightPos =vec3(gl_LightSource[0].position);
	vec3 eyePos = vec3(0.0,0.0,5.0);
	// vec3 eyePos = gl_Position;
	// lightPos = vec3(0.0,5.0,5.0);	
	vec3 Normal = normalize(gl_NormalMatrix * vNormal);
	vec3 EyeVert = normalize(eyePos - vVertex);
	vec3 LightVert = normalize(lightPos - vVertex);
	vec3 EyeLight = normalize(LightVert+EyeVert);
	// Specular Color:
	// vec4 specular_color = vec4(0.8, 0.0, 0.0, 1.0);
	vec4 specular_color = color0;
	// vec4 specular_color = specular;// * gl_LightSource[0].specular * pow(max(dot(Normal,vec3(gl_LightSource[0].halfVector) ), 0.0) , gl_FrontMaterial.shininess);      
	// vec4 ambient_color = gl_FrontMaterial.ambient * gl_LightSource[0].ambient + gl_LightModel.ambient * gl_FrontMaterial.ambient;
	// vec4 diffuse_color =  gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
	// float diffuse_value = max(dot(Normal, vec3(gl_LightSource[0].position)), 0.0);


	// Lighting

	//vec3 EyeLight=LightVert;
	// Simple Silhouette
	float sil = max(dot(Normal,EyeVert), 0.0);
	if (sil < 0.3) gl_FragColor = sil_color;
	else 
  	{
	   // gl_FragColor = ambient_color + diffuse_color * diffuse_value + specular_color;
  		gl_FragColor=color0;
	   // Specular part
	   float spec = pow(max(dot(Normal,EyeLight),0.0), shininess);
	   // float spec = pow(max(dot(Normal,EyeLight),0.0), gl_FrontMaterial.shininess);
	   if (spec < 0.2) gl_FragColor *= 0.8;
	   else gl_FragColor = specular_color;
	   // Diffuse part
	   float diffuse = max(dot(Normal,LightVert),0.0);
	   if (diffuse < 0.5) gl_FragColor *=0.8;

	}

}