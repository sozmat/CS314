#include <stdio.h>

unsigned int mask(int n){
    //return a bit mask containing 1s for the least-significant n bits
    unsigned int mask = (0XFFFFFFFF << n);
    return (~mask);
}

int main() {

    printf("0x%X\n", mask(1));
    printf("0x%X\n", mask(2));
    printf("0x%X\n", mask(3));
    printf("0x%X\n", mask(5));
    printf("0x%X\n", mask(8));
    printf("0x%X\n", mask(16));
    printf("0x%X\n", mask(31));
}
