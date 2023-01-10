#include <stdio.h>
#define N 4
typedef long array_t[N][N];

void transpose(array_t a) {
    for (long i = 0; i < N; ++i){
	    for (long j = 0; j < i; ++j){
		    long t1 = a[i][j];
		    long t2 = a[j][i];
		    a[i][j] = t2;
		    a[j][i] = t1;
	    }
    }
}

void transposeOpt(array_t a) {
    for (long i = 0; i < N; ++i){
	    long *rowp = &a[i][0]; // row pointer
	    long *columnp = &a[0][i]; // column pointer
	    for (long j = 0; j < i; ++j){
		long t1 = *columnp;
		long t2 = *rowp;
		*rowp = t1;
		*columnp = t2;
		rowp ++;
	    	columnp += 4;
	}
    }
}
//TODO:
//comment out optimized code below
//alter C code above so that it is optimized
/*optimized inner loop code in x86-64
 This is more optimized due to pointer arithmetic and dereferencing rather than array look ups to reference elements of array
 * .L3:
 * 	movq (%rax), %rcx  // t1 = a[i][j] , getting value at loc in array
 * 	movq (%rdx), %rsi  // t2 = a[j][i]
 * 	movq %rsi, (%rax) // a[i][j] = t2 
 * 	movq %rcx, (%rdx) // a[j][i] = t1
 * 	addq $8, %rax  // going 8 bytes over to next long in subarray
 * 	addq $32, %rdx // goes 32 bytes over to next subarray
 * 	cmpq %r9, %rax //our inner loop comparison, is j < i
 * 	jne .L3
 */

int main() {
    array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    array_t b = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

void print_array(array_t c){
    for (int i = 0; i < N; ++i){
	    if (i == 0){
		printf("{{");}
	    else {
		printf("{");}
	    for (int j = 0; j < N; ++j){
		    if (j == N-1 & i == N-1){
			    printf("%ld}", c[i][j]);}
		    else if (j == N-1) {
			    printf("%ld}, ", c[i][j]);}
		    else{
		    printf("%ld, ", c[i][j]);}
	    }
    } printf("}\n");
}
    printf("Printing transpose() output:\n");
    transpose(a);
    print_array(a);
    printf("Printing transposeOpt() output:\n");
    transposeOpt(b);
    print_array(b);

	return 0;
}
