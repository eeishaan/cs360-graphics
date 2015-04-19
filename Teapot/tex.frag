#version 330
 
layout (std140) uniform Material {
    vec4 diffuse;
    vec4 ambient;
    vec4 specular;
    float shininess;
};
 
layout (std140) uniform Lights {
    vec3 l_dir;    // camera space
};
 
in Data {
    vec3 normal;
    vec4 eye;
    vec2 texCoord;

} DataIn;
 
uniform sampler2D texUnit;
 

 
void main() {
 
    // set the specular term to black
    vec4 spec = vec4(0.0);
	vec4 sil_color = vec4(0.0, 0.0, 0.0, 1.0);
    
    // normalize both input vectors
    vec3 n = normalize(DataIn.normal);
    vec3 e = normalize(vec3(DataIn.eye));
 
    float intensity = max(dot(n,l_dir), 0.0);
 
    // if the vertex is lit compute the specular color
    if (intensity > 0.0) 
	{
	    // compute the half vector
        vec3 h = normalize(l_dir + e);  
        // compute the specular term into spec
        float intSpec = max(dot(h,n), 0.0);
        spec = specular * pow(intSpec,shininess);

    }

/*    vec4 texColor = texture(texUnit, DataIn.texCoord);
    DataIn.texCoord=vec2(intensity,0);
*/
	vec4 texColor = texture(texUnit, DataIn.texCoord);
    vec4 diffColor = intensity *  diffuse * texColor;
    vec4 ambColor = ambient * texColor;
    gl_FragColor = texColor;
    gl_FragColor = max(diffColor + spec, ambColor);
	if (intensity < 0.3) gl_FragColor = sil_color;

	// gl_FragColor = texture2D(texUnit, DataIn.texCoord);
}