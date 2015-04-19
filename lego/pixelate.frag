uniform sampler2D texUnit;
uniform sampler2D paperTex;
uniform sampler2D perlinTex;
uniform sampler2D hatchTex;
float avg(vec4 colour)
{
	return (colour.x+colour.y+colour.z)/3;
}

void main (void)
{
	vec2 dis;
	vec2 coord = vec2(gl_FragCoord.xy);
	
	coord.x = coord.x/1000;
	coord.y=coord.y/1000;
	// vec2 newCoord = coord -100000;
	gl_FragColor = texture2D(texUnit,coord -100000);

}
