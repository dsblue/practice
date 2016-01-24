#include <stdio.h>
#include <assert.h>

/**
 * defined in base64.s in ARM asm
 */
void base64_asm(char *, char*);

static char base64Table[64] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3',
        '4', '5', '6', '7', '8', '9', '+', '/'
};

/**
 *  C function to compute the base64 string for a binary input
 */
static void base64_c(char *in, char *out) {
    int i = 2;
    int temp = 0;

    while (*in) {
        temp = temp | ((*in) << (i * 8));

        i--;
        if (i == -1) {
            i = 2;

            (*out) = base64Table[(temp >> 18) & 0x3f];
            out++;
            (*out) = base64Table[(temp >> 12) & 0x3f];
            out++;
            (*out) = base64Table[(temp >> 6) & 0x3f];
            out++;
            (*out) = base64Table[temp & 0x3f];
            out++;
            temp = 0;
        }
        in++;
    }

    if (i == 0) {
        // 2 bytes
        (*out) = base64Table[(temp >> 18) & 0x3f];
        out++;
        (*out) = base64Table[(temp >> 12) & 0x3f];
        out++;
        (*out) = base64Table[(temp >> 6) & 0x3f];
        out++;
        (*out) = '=';
        out++;
    } else if (i == 1) {
        // One Byte
        (*out) = base64Table[(temp >> 18) & 0x3f];
        out++;
        (*out) = base64Table[(temp >> 12) & 0x3f];
        out++;
        (*out) = '=';
        out++;
        (*out) = '=';
        out++;
    }
    (*out) = 0;
}

static char out[100];
static char s1[] = "Man";
static char s2[] = "any carnal pleasure.";
static char s3[] = "any carnal pleasure";
static char s4[] = "any carnal pleasur";

int main(int argc, char *args[]) {

    // Test cases from Wikipedia
    base64_asm(s1, out);
    printf("%s\n", s1);
    printf("%s\n", out);
    assert(0 == strcmp(out, "TWFu"));

    base64_asm(s2, out);
    printf("%s\n", s2);
    printf("%s\n", out);
    assert(0 == strcmp(out, "YW55IGNhcm5hbCBwbGVhc3VyZS4="));

    base64_asm(s3, out);
    printf("%s\n", s3);
    printf("%s\n", out);
    assert(0 == strcmp(out, "YW55IGNhcm5hbCBwbGVhc3VyZQ=="));

    base64_asm(s4, out);
    printf("%s\n", s4);
    printf("%s\n", out);
    assert(0 == strcmp(out, "YW55IGNhcm5hbCBwbGVhc3Vy"));

}