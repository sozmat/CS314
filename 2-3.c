#include <stdio.h>

int le(float x, float y) {
    unsigned int ux = *((unsigned int*) &x); //convert x raw bits
    unsigned int uy = *((unsigned int*) &y); //convert y raw bits
    unsigned int sx = ux >> 31; //extract sign bit of ux
    unsigned int sy = uy >> 31; //extract sign bit of uy
    ux <<= 1; //drop sign bit of ux
    uy <<= 1; //drop sign bit of uy
    //return using sx, sy, ux, and uy, or together all cases that would return 1
    return (ux == 0 && uy == 0) | (ux == uy && uy == ux) | (sx == 1 && sy == 0) | (ux == 0 && uy != 0 && sy != 1);
}

int main() {
 
    printf("%d\n", le(0.0f, 0.0f)); 
    printf("%d\n", le(-0.0f, 0.0f)); 
    printf("%d\n", le(-1.0f, -1.0f)); 
    printf("%d\n", le(1.0f, 1.0f)); 
    printf("%d\n", le(-1.0f, 0.0f)); 
    printf("%d\n", le(0.0f, 1.0f)); 
    printf("%d\n", le(1.0f, 0.0f)); 
    printf("%d\n", le(0.0f, -1.0f)); 
    printf("%d\n", le(-1.0f, -2.0f)); 
 } 
