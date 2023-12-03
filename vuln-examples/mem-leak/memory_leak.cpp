/*
Example of Memory Leak Vulnerability
Description: allocated memory is never released
Author: aanderson
*/

#include <iostream>

int main() {
    int *ptr = new int[10];
    std::cout << "memory allocated" << std::endl;
    return 0;
}