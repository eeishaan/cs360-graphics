uniform sampler2D texUnit;
uniform sampler2D paperTex;
uniform sampler2D perlinTex;
uniform sampler2D hatchTex;
float avg(vec4 colour)
{
	return (colour.x+colour.y+colour.z)/3;
}
float edgeFind(vec2 wobblevert)
{
	vec2 curr = vec2(gl_FragCoord.xy) ;//+ wobblevert*1000;
	vec2 newCoord;float newIntens;
	float agg=0.0;
	float currIntens=avg(texture2D(texUnit,vec2(curr.x/1000,curr.y/1000)));

	newCoord = vec2(curr.x-1,curr.y);
	newIntens = avg(texture2D(texUnit,vec2(newCoord.x/1000,newCoord.y/1000)));
	agg += abs(newIntens - currIntens );

	newCoord = vec2(curr.x-1,curr.y-1);
	newIntens = avg(texture2D(texUnit,vec2(newCoord.x/1000,newCoord.y/1000)));
	agg += abs(newIntens - currIntens );

	newCoord = vec2(curr.x-1,curr.y+1);
	newIntens = avg(texture2D(texUnit,vec2(newCoord.x/1000,newCoord.y/1000)));
	agg += abs(newIntens - currIntens );

	newCoord = vec2(curr.x+1,curr.y);
	newIntens = avg(texture2D(texUnit,vec2(newCoord.x/1000,newCoord.y/1000)));
	agg += abs(newIntens - currIntens );

	newCoord = vec2(curr.x+1,curr.y+1);
	newIntens = avg(texture2D(texUnit,vec2(newCoord.x/1000,newCoord.y/1000)));
	agg += abs(newIntens - currIntens );

	newCoord = vec2(curr.x+1,curr.y-1);
	newIntens = avg(texture2D(texUnit,vec2(newCoord.x/1000,newCoord.y/1000)));
	agg += abs(newIntens - currIntens );

	newCoord = vec2(curr.x,curr.y-1);
	newIntens = avg(texture2D(texUnit,vec2(newCoord.x/1000,newCoord.y/1000)));
	agg += abs(newIntens - currIntens );

	newCoord = vec2(curr.x,curr.y+1);
	newIntens = avg(texture2D(texUnit,vec2(newCoord.x/1000,newCoord.y/1000)));
	agg += abs(newIntens - currIntens );

	if(agg>0.1)
		return 1;
	return 0.0;
}
void main (void)
{
	vec2 dis;
	vec2 coord = vec2(gl_FragCoord.xy);
	
	
	

	/*coord.x= mod(coord.x,1000);
	coord.y= mod(coord.y,1000);
	*/
	// coord.x = coord.x%1000;
	// coord.y=coord.y%1000;
	// vec4 texColor = texture2D(texUnit,coord);
	/*vec4 texColor = texture2D(paperTex,coord);
	coord.x+=0.1;
	coord.y+=0.1;
	vec4 distortion = texture2D(paperTex,coord);
	*/
///////////////////////////////edge darkening + wobbling///////////////////////////
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

	float d=5.1;
	if(edgeFind(wobblevert)==1)
		tempColor =  tempColor*(1-(1-tempColor )*(d-1));

/////////////////////////////pigment dispesion////////////////////////////////////////


	/*if(avg(texture2D(texUnit,newCoord))>1.000005 || avg(texture2D(texUnit,newCoord))<0.999995 )
	{
		float d= 1+ 0.5*(avg(texture2D(perlinTex,newCoord))-0.5);

		// gl_FragColor = texture2D(texUnit,coord)*(1-(1-texture2D(texUnit,coord) )*(d-1));
		// vec4 tempColor =texture2D(texUnit,coord);
		// if(edgeFind()==1)
			// gl_FragColor = tempColor*(1-(1-tempColor )*(d-1));
		tempColor = tempColor*(1-(1-tempColor )*(d-1)); //for turbulent flow

		d =  1+ 0.5*(avg(texture2D(paperTex,newCoord))-0.5);
		tempColor = tempColor*(1-(1-tempColor )*(d-1)); //for pigment flow

	}
	else
		tempColor += wobbleColour;*/
	// else
		// tempColor = vec4(1.0,1.0,1.0,1.0);
		gl_FragColor = tempColor ;//+ 0.1*wobbleColour;


	// else
		// gl_FragColor = wobbling;	

//////////////////////////////hatching//////////////////////


	/*if(edgeFind()==1)
		gl_FragColor = vec4(0.0,0.0,0.0,1.0);
		// gl_FragColor = texture2D(texUnit,coord);
	else
		gl_FragColor = vec4(1.0,1.0,1.0,1.0);*/

}
