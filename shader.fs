#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform float widthpf;
uniform float heightpf;
/*
uniform float scalef;
*/
const int scale = 4;

out vec4 finalColor;

void main()
{
    int i = int(fragTexCoord.x * widthpf);
    int j = int(fragTexCoord.y * heightpf);
    vec2 pos = vec2(float(i/scale) / widthpf * float(scale), float(j/scale) / heightpf * float(scale));
    finalColor = vec4(vec3(0.0), 1.0);
    if ((j - 1) % scale < scale * 3 / 4) {
        if ((i - 1) % scale < scale * 1 / 4)
            finalColor.r = texture(texture0, pos).r;
        else if ((i - 1) % scale < scale * 2 / 4)
            finalColor.g = texture(texture0, pos).g;
        else if ((i - 1) % scale < scale * 3 / 4)
            finalColor.b = texture(texture0, pos).b;
    }
}
