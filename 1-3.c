#include <stdio.h>

int oddBit(unsigned int x){
    // 0xAAAAAAAA is our mask, has 1 at every odd index, 0 at even index
    unsigned int masked = x & 0xAAAAAAAA; //ensure 1's are only at odd index
    return (0 || masked); //if there is 1 at odd index this will return 1, if not, 0
    

}

int main(){
    printf("%d\n", oddBit(0x1));
    printf("%d\n", oddBit(0x2));
    printf("%d\n", oddBit(0x3));
    printf("%d\n", oddBit(0x4));
    printf("%d\n", oddBit(0xFFFFFFFF));
    printf("%d\n", oddBit(0xAAAAAAAA));
    printf("%d\n", oddBit(0x55555555));
}
