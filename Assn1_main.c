#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer, size_t);
void show_bytes_2(byte_pointer, size_t);
void show_bits(int);
void show_int(int);
void show_float(float);
void show_pointer(void *);
int  mask_LSbits(int);

int main() {
    int ival = 12345;
    float fval = (float) ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);

    show_bits(ival);
    show_bits(-ival);

    printf("the mask value for 1 is %d" , mask_LSbits(1));
    printf("\n");
    printf("the mask value for 2 is %d" , mask_LSbits(2));
    printf("\n");
    printf("the mask value for 31 is %d" , mask_LSbits(31));
    printf("\n");
    printf("the mask value for 32 is %d" , mask_LSbits(55));

    return 0;

}