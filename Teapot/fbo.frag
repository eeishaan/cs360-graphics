varying vec2 UV;

uniform sampler2D texUnit;
 
void main(){
    gl_FragColor = texture( texUnit, UV + 0.005*vec2( sin(1000.0*UV.x),cos(1000.0*UV.y)) ).xyz;
}