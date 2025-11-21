#version 330 core

layout (location = 0) in vec2 position;

uniform vec2 translation; // Position in world space
uniform vec2 scale;       // Width and height
uniform mat4 projection;  // Orthographic projection

out vec2 fragPos;

void main() {
    vec2 pos = position * scale + translation;
    gl_Position = projection * vec4(pos, 0.0, 1.0);
    fragPos = position * 2.0 - vec2(1.0, 1.0);
}
