varying vec3 normal, lightDir; 
// varying vec2 texCoord; 
// uniform sampler2D texture;
 
void main() 
{ 
        float intensity; 
        vec3 n; 
        vec4 _color; 
        n = normalize(normal); 
        intensity = dot(lightDir, n); 
        float alpha = (1 + intensity)/2;

        vec3 cc=vec3(0.4,0.4,0.4);
        // vec3 cw=vec3(0.5,0.5,0.9);
        vec3 cw=vec3(0.8,0.8,0.8);
        // vec3 cw=vec3(0.8,0.6,0.6);

        gl_FragColor = vec4(alpha*cw + (1-alpha)*cc,1.0);
        

        /*if (intensity > 0.98) 
                // _color = vec4(1.0,1.0,1.0,1.0); 
                _color = vec4(0.8,0.8,0.8,1.0); 
        else if (intensity > 0.5) 
                _color = vec4(0.8,0.8,0.8,1.0); 
        else if (intensity > 0.35) 
                _color = vec4(0.4,0.4,0.4,1.0); 
        else 
                _color = vec4(0.0,0.0,0.0,1.0);   */      
}