uniform sampler2D texUnit;
uniform sampler2D perlinTex;
// uniform int limit;

// precision highp float;
float avg(vec4 colour)
{
    return (colour.x+colour.y+colour.z)/3;
}
float edgeFind()
{
    vec2 curr = vec2(gl_FragCoord.xy);// + wobblevert*1000;
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
const vec2 src_size = vec2 (1000.0, 1000.0);

void main (void) 
{
    vec2 coord = gl_FragCoord.xy/src_size;
/*
    vec4 wobbling  = texture2D(texUnit,coord);

    vec4 tempColor = wobbling;
*/
  
     int limit =15;
    float n = float((limit + 1) * (limit + 1));
    vec3 mean[4];
    vec3 square_sum[4];
    for (int k = 0; k < 4; ++k) {
        mean[k] = vec3(0.0);
        square_sum[k] = vec3(0.0);
    }

    for (int j = -limit; j <= 0; ++j)  {
        for (int i = -limit; i <= 0; ++i)  {
            vec3 c = texture2D(texUnit, coord + vec2(i,j) / src_size).rgb;
            mean[0] += c;
            square_sum[0] += c * c;
        }
    }

    for (int j = -limit; j <= 0; ++j)  {
        for (int i = 0; i <= limit; ++i)  {
            vec3 c = texture2D(texUnit, coord + vec2(i,j) / src_size).rgb;
            mean[1] += c;
            square_sum[1] += c * c;
        }
    }

    for (int j = 0; j <= limit; ++j)  {
        for (int i = 0; i <= limit; ++i)  {
            vec3 c = texture2D(texUnit, coord + vec2(i,j) / src_size).rgb;
            mean[2] += c;
            square_sum[2] += c * c;
        }
    }

    for (int j = 0; j <= limit; ++j)  {
        for (int i = -limit; i <= 0; ++i)  {
            vec3 c = texture2D(texUnit, coord + vec2(i,j) / src_size).rgb;
            mean[3] += c;
            square_sum[3] += c * c;
        }
    }


    float min_sigma2 = 1e+2;
    for (int k = 0; k < 4; ++k) {
        mean[k] /= n;
        square_sum[k] = abs(square_sum[k] / n - mean[k] * mean[k]);

        float sigma2 = square_sum[k].r + square_sum[k].g + square_sum[k].b;
        if (sigma2 < min_sigma2) {
            min_sigma2 = sigma2;
            gl_FragColor = vec4(mean[k], 1.0);
        }
    }
    float d= 1+ 0.5*(avg(texture2D(perlinTex,coord))-0.5);
    gl_FragColor = gl_FragColor*(1-(1-gl_FragColor )*(d-1));
     /*d=5.1;
    if(edgeFind()==1)
        gl_FragColor =  gl_FragColor*(1-(1-gl_FragColor )*(d-1));
*/
   

}