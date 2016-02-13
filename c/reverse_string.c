#include <string.h>

void reverseStringInPlace(char *string) {

    size_t len = strlen(string);
    size_t i = 0;

    while (i < len/2) {
        char temp = string[i];
        string[i] = string[len-i-1];
        string[len-i-1] = temp;
        i++;
    }

}