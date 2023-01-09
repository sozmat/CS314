#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y){
    
    unsigned int ymask = 0xFFFFFFFF >> 24; //bit mask to isolate byte 0

    unsigned int xmask = 0xFFFFFFFF << 8; //bit mask to isolate bytes 3-1

    return (x & xmask) | (y & ymask); //use & to isolate correct bytes for x and y, then use OR to combine then together
}

int main() {
    printf("0x%X\n", combine(0x12345678, 0xABCDEF00));
    printf("0x%X\n", combine(0xABCDEF00, 0x12345678));
}
