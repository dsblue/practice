#include "gen.h"
#include <stdlib.h>

int generate_random_array_int(int **array, int length) {

    if (length <= 0 )
        return -1;

    *array = (int *)malloc((size_t)length);

    if (*array <= 0)
        return ((int)(*array));

    int i;
    for (i=0;i<length;i++) {
        (*array)[i] = rand() % 1000;
    }

    return 0;
}

