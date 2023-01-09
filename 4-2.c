#include <stdio.h>

long fact(long x) {
	if (x <= 1) {
		return 1;
	}
	return x * fact(x-1);
}

/* instructions that modify the stack pointer %rsp
 * after the call function, all of these instructions get pushed onto stack since they are the instructions in the procedure that is being called,in this case recursively
 call fact
 pushq %rbx
 popq %rbx
 ret
 size of stack frame is 8 bytes
 */

int main() {
	printf("%ld\n", fact(1));
	printf("%ld\n", fact(3));
	printf("%ld\n", fact(5));
}
