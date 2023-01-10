#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned char b){
    unsigned int shift = i << 3;  //amount of bits we need to shift over
    unsigned int mask = 0xff << shift; //left-shift to create mask
    return ((b << shift) & mask) | (~mask & x); //shift b over so in correct byte, AND with mask so we extract just the bytes we want, then we reverse the mask so that we will be extracting the other bytes we want and OR them both together  
}

int main(){
    printf("0x%X\n", replace(0x12345678, 3, 0xAB));
    printf("0x%X\n", replace(0x12345678, 0, 0xAB));
}
