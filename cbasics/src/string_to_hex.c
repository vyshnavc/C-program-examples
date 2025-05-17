#include <stdio.h>

int main() {
    char c[5] = "ABCD";
    char hex[20]; 
    int i, j;

    for (i = 0, j = 0; c[i]; i++, j += 2) {
        sprintf(hex + j, "%X", c[i]);
    }
    hex[j] = '\0';

    printf("Original string: %s\n", c);
    printf("Hexadecimal: %s\n", hex);

    return 0;
}

