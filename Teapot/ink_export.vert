uniform mat4 ModelViewMatrix;
uniform mat4 ProjModelViewMatrix;
uniform mat4 NormalMatrix;

varying vec3 position, normal;

void main(void)
{
	normal = (NormalMatrix * vec4(gl_Normal, 1.0)).xyz;
	position = (ModelViewMatrix * vec4(gl_Vertex, 1.0)).xyz;
	gl_Position = ProjModelViewMatrix * vec4(gl_Vertex, 1.0);
}