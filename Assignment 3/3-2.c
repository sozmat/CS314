#include <stdio.h>

long f(long x, long y, long z){
	z += y;			// addq	%rsi, %rdx
	x *= z;			// imulq %rdx, %rdi
	z <<= 63;		// salq $63, %rdx 
	z >>= 63;		//sarq $63, %rdx
	long result = x;	// movq %rdi, %rax 
	result ^= z;		//xorq %rdx, %rax
	return result;
	// return x *(y +z); 	this would be functionally equivalent, just gives different assembly instructions
}

int main() {
printf("%ld\n", f(1, 2, 4));
printf("%ld\n", f(3, 5, 7));
printf("%ld\n", f(10, 20, 30));
}
