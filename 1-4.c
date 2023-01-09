#include <stdio.h>

void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; i++) {
        printf(" %.2X", start[i]);
    }
    printf("\n");
}

void printInt(int x) {
   printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
    printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x) {
    printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x) {
    printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x) {
    printBytes((unsigned char *) &x, sizeof(double));
}

void printLongLong(long long x) {
    printBytes((unsigned char *) &x, sizeof(long long));
}

int main() {
    //Int, Short, Long, and LongLong all appear to be showing the same hex value, they just differ in size/ amount of bits the value carries. The float and double types look different from the rest because they are in IEEE format
    printInt(30);  
    printFloat(30);
    printShort(30);
    printLong(30);
    printDouble(30);
    printLongLong(30);
}
