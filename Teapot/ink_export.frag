varying vec3 position, normal;

void main(void)
{
	vec3 N = normalize(normal);

	float light = 0.5 + max(0.0, pow(dot(vec3(1.0, 0.0, 0.0), N)*3.0, 4.0))*0.5;

	float v = dot(normalize(-position), N);
	v = clamp(pow(v*3.0, 20.0), 0.0, 1.0)*light;
	gl_FragColor = vec4(v, v, v, 1.0);
}
