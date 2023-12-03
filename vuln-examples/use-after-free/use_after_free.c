/*
Example of Use After Free Vulnerability
Description: program tries to utilize memory after it has been released
Author: aanderson
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = malloc(10 * sizeof(char));
    free(ptr);
    sprintf(ptr, "hello");
    printf("ptr content: %s\n", ptr);
    return 0;
}