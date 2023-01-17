/* 
 * Filename: Assn1_Q3.c
 *
 * Description:
 *
 * Auhtors: Sepehr Ahmadipourshirazi
 * Student decimalber: 301408650
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

// Question 3 a.
void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++){
      printf("%p", &start[i]);
      printf(" 0x%.2x", start[i]);
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
    for (i = 0; i < len; i++){
        printf("%p", &(*start));
        printf(" 0x%.2x", (*start++));
        printf("\n");
    }
    printf("\n");
    return;
}

// Question 3 d.
void show_bits(int decimal) {

    int size = sizeof(decimal) - 1;

    for (int i = 8 * size; i >= 0; i--) {
        (decimal & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
    return;
}

// Question 3 e.
int mask_LSbits(int n) {
    //first we find the max binary representation using n bits
    int max_binary_representation = (2^n) -1;


    int size = sizeof(max_binary_representation) - 1;

    for (int i = 7 * size; i >= 0; i--) {
        (max_binary_representation & (1 << i)) ? putchar('1') : putchar('0');
    }

    //then we use the show bits method to convert the max representation to binary
    printf("the binary representation is:");


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
