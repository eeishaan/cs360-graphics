varying vec3 normal;

void main()
{
	normal = normalize(gl_Normal);
	gl_Position = ftransform();

}