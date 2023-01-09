#include <stdio.h>

unsigned int extract(unsigned int x, int i) {
	unsigned int mask = 0x000000FF; //mask to isolate just the byte we want
	signed int shifted = x >> (i << 3); //putting our byte in position 0
	signed int y = mask & shifted; //creating signed var with extracted bit
	signed int final = y << 24; //shifting extracted bit to byte pos 3 so we can do sign extension in next step
	signed int final_final = final >> 24; //do sign extension with arithmetic operation >>
	return final_final;
}


int main() {

    printf("0x%.8X\n", extract(0x12345678, 0));
    printf("0x%.8X\n", extract(0xABCDEF00, 2));

}
