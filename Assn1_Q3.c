/* 
 * Filename: Assn1_Q3.c
 *
 * Description:
 *
 * Auhtors: Sepehr Ahmadipourshirazi
 * Student number: 301408650
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

// Question 3 a.
void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++){
      printf("%p", &start[i]);
      printf(" 0x%x ", start[i]);
      printf(" %b ", start[i]);
      printf("\n");
  }
  printf("\n");
  return;
}

// Question 3 b.
// The compiler is little endian:
// Explanation: For example, ival converted to hexadecimal is 3039. From the print output, we notice that as the memory address increments,
// (going from 00000020709ffd10, 00000020709ffd11) we see that 39 shows up before 30, meaning that the compiler puts the least significant byte(39) at the
// Lowest memory address before 30.


// Question 3 c.
void show_bytes_2(byte_pointer start, size_t len) {
  size_t i;

  unsigned char ptr = start[0];

    for (i = 0; i < len; i++) {
        printf(" %.2x", &ptr);
    }
  printf("\n");
  return;
}

// Question 3 d.
void show_bits(int decimal) {
	
  // put your code here!

  return; 
}	


// Question 3 e.
int mask_LSbits(int n) {
	
  // put your code here!

  // feel free to modify this return statement
  return 0; 
}

void show_int(int x) {
  printf("\nival = %d\n", x); 
  show_bytes((byte_pointer) &x, sizeof(int)); 
  show_bytes_2((byte_pointer) &x, sizeof(int)); 
  return;	
}

void show_float(float x) {
  printf("fval = %f\n", x); 	
  show_bytes((byte_pointer) &x, sizeof(float));
  show_bytes_2((byte_pointer) &x, sizeof(float)); 
  return;	
}

void show_pointer(void *x) {
  printf("pval = %p\n", x); 
  show_bytes((byte_pointer) &x, sizeof(void *));
  show_bytes_2((byte_pointer) &x, sizeof(void *));
  return;	
}
