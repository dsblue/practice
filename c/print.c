#include "print.h"
#include <stdio.h>

void print_array_int(int array[], int length) {
    if (length <= 0) return;

    printf("%d", array[0]);
    int i;
    for (i=0;i<length;i++) {
        printf(",%d", array[i]);
    }
    printf("\n");

}
