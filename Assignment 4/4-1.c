#include <stdio.h>
/* goto version of C function:
 
long sum(long from, long to) {
	long result = 0;
	loop:
		result += from;
		++from;
	if (from <= to) goto loop;
	return result;
}*/

long sum(long from, long to) {
	long result = 0;
	
	__asm__("movq %0, %%rdi # from in rdi;"::"r"(from)); //move from into rdi
	__asm__("movq %0, %%rsi # to in rsi;":: "r" (to)); //move to into rsi
	__asm__("movq %0, %%rax # result in rax;"::"r"(result)); //move result to rax

	//implementation of goto code into x86-64
	//implement this using 1 label and 4 instructions
	//2 addq, 1 cmpq, 1 jle
	__asm__(
	".LOOP:"// loop label
	"addq %rdi, %rax;"// result += from, since result in %rax and from in %rdi
	"addq $1, %rdi;" // incrementing from by +1
	"cmpq %rsi, %rdi;"// setting flags for comparison of to and from
	"jle .LOOP;"// looks at flags to see if from <= to, if so go to loop label
	".END:"


	);
	__asm__("movq %%rax, %0 #result in rax;":"=r" (result));
	return result;
	


}

int main() {
	printf("sum(1, 6): %ld\n", sum(1, 6));
	printf("sum(3, 5): %ld\n", sum(3, 5));
	printf("sum(5, 3): %ld\n", sum(5, 3));
}
