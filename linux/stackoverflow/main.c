#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const char string[] = "This is a string...";

int main(int vargc, char **args) {
	printf("%s %llx\n", string, (unsigned long long)&string[0]);

	return 0;
}
