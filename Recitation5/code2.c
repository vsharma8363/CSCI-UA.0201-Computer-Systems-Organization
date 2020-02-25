// Null pointer (NULL) is a memory location, but when you use "\0", the value of that variable will be null indicating the end of a char sequence in C. Additionally, we need to use *ptr instead of ptr in order to access the individual elements of the string.

#include <stdio.h>

int main() 
{
    char str[] = "Hello";
    char* ptr = str;
    // Change to *ptr and '\0' char indicating value NULL
    while(*ptr != '\0') {
        printf("%c\n", *ptr);
        ptr++;
    }
    return 0; 
} 
