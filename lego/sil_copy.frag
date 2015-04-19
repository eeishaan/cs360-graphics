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
	
	

	// vec2 newCoord = coord + vec2(texture2D(paperTex,coord)*0.05);
	coord.x = coord.x/1000;
	coord.y=coord.y/1000;
	// vec2 wobblevert = vec2(texture2D(paperTex,coord)*0.1);
	vec4 wobbleColour = texture2D(paperTex,coord);
	vec2 wobblevert = vec2(texture2D(paperTex,coord)*0.035);
	// wobblevert.x=wobblevert.x/1000;
	// wobblevert.y=wobblevert.y/1000;

	vec2 newCoord = coord ;//+ wobblevert;
	// gl_FragCoord.x = gl_FragCoord.x + wobblevert.x*1000;
	// gl_FragCoord.y = gl_FragCoord.y + wobblevert.y*1000;

	vec4 wobbling  = texture2D(texUnit,newCoord);

	vec4 tempColor = wobbling;

		gl_FragColor = tempColor ;//+ 0.1*wobbleColour;



}
