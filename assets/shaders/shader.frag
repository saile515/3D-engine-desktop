varying highp vec3 vLighting;
varying highp vec2 vTexturePosition;

uniform sampler2D uSampler;

void main(void) {
    highp vec4 texelColor = texture2D(uSampler, vTexturePosition);

    gl_FragColor = vec4(texelColor.rgb * vLighting, texelColor.a);  
}