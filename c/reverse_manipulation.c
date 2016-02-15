#include <string.h>

/**
 * Reverse a string in-place
 */
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

/**
 * Saw this as an example interview question:
 * Replace the string 'AB' with 'C' in-place
 */
void replaceSubString(char *str) {

    char *in = str;
    char *out = str;

    while (*in != 0) {
        if (in[0] == 'A' && in[1] == 'B') {
            *out = 'C';
            in++;
        } else {
            *out = *in;
        }
        in++;
        out++;
    }

    *out = 0;
}