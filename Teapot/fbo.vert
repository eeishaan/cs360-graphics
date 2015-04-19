#version 330
 
layout (std140) uniform Matrices {
    mat4 m_pvm;
    mat4 m_viewModel;
    mat3 m_normal;
};
 
layout (std140) uniform Lights {
    vec3 l_dir;    // camera space
};
 
in vec4 position;   // local space
in vec3 normal;     // local space
in vec2 texCoord;
 
// the data to be sent to the fragment shader
varying vec2 UV;
void main () {
 
    UV=texCoord;
 
    gl_Position = m_pvm * position; 
}