/* 
 * Filename: Assn1_Q3.c
 *
 * Description:
 *  An application that contains methods for showing the bytes, binary representation of a number and a mask
 *  with the n least significant bits set (to 1) .
 *
 * Authors: Anne Lavergne, Sepehr Ahmadipourshirazi
 * Student decimalber: 301408650
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char *byte_pointer;

// Question 3 a.
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
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
// (for example going from 00000020709ffd10 to 00000020709ffd11) we see that 0x39 shows up before 0x30, meaning that the compiler puts the least significant byte(39) at the
// Lowest memory address before 30.


// Question 3 c.
void show_bytes_2(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
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

        //shifting 1 to the left i times, and we apply the and operator between 1 and the same bit
        // in the decimal input. We then output 1 if decimal has a 1 at that byte and wise versa for 0.
        (decimal & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
    return;
}

// Question 3 e.
int mask_LSbits(int n) {

    //variable size is the same as w which is 32 bits in this case
    int size = sizeof(n) * 8;

    if (n <= 0) {
        return 0;
    } else if (n < size) {
        //we return a vale of a binary number with the 1 shifted to the left n times
        //we add the -1 so that it matches the formula
        return ((1 << n) - 1);
    } else {
        //the msb is 1 therefore, we have a negative value
        //if all bits are 1s, we get -(2^w) + (2^w - 1) which is equal to -1
        return -1;
    }
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

