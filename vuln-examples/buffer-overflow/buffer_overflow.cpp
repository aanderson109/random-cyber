/*
Example of a Buffer Overflow Vulnerability
Description: attempts to copy a string that is larger than the buffer size
Author: aanderson
*/


#include <iostream>
#include <cstring>

int main() {
    char buffer[10];
    std::strcpy(buffer, "this string is way too long for the buffer");
    std::cout << "buffer content: " << buffer << std::endl;
    return 0;
}