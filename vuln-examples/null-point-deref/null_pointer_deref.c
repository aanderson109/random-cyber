/*
Example of Null Pointer Dereference Vulnerability
Description: process() method dereferences a pointer w/o checking if it's null
Author: aanderson
*/

#include <stdio.h>

void process(int *ptr) {
    int value = *ptr;
    printf("value is %d\n", value);
}

int main() {
    int *ptr = NULL;
    process(ptr);   //passes the null pointer
    return 0;
}