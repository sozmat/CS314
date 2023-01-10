#include <stdio.h>

unsigned int getOffset(unsigned int address){
    //returns the byte offset of the address within its cache block
    return (address << 24) >> 24;
}

unsigned int getSet(unsigned int address) {
    //returns the cache set for the address
    unsigned int mask = 0x00000F00;
    return (mask & address) >> 8;
}

unsigned int getTag(unsigned int address) {
    //returns the cache tag for the address
    return address >> 12;
}


int main(){
	unsigned int address_1 = 0x12345678;
	unsigned int address_2 = 0x87654321;
	printf("0x%x: offset: %x - tag: %x - set: %x\n", address_1, getOffset(address_1), getTag(address_1), getSet(address_1));
	printf("0x%x: offset: %x - tag: %x - set: %x\n", address_2, getOffset(address_2) ,getTag(address_2), getSet(address_2));
	return 0;
}
