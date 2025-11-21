#version 330 core

in vec2 fragPos;
out vec4 FragColor;

uniform vec4 colour;    // Rectangle color RGBA

void main() {
    FragColor = colour;
}