/*
 * Stroustrup - Programming Principles & Practice
 *
 * Chapter 27 Drill
 *
 * 1. Write the Hello World in C
 *
 * 2. Define variables for Hello and World and concatenate them to output.
 * Using the provided cat() function felt like cheating so I used printf with
 * arguments.
 *
 * 3. Define a C function that takes a char* and an int and prints their values
 * in provided format.
 */

#include <stdlib.h>
#include <stdio.h>

void print_out(const char* p, const int x)
{
    printf("p is\"%s\" and x is %i\n", p, x);
}

int main()
{
    /* Ex 1 */
    printf("Hello World!\n");

    /* Ex 2 */
    char* first = "Hello";
    char* last = "World!";
    printf("%s %s\n", first, last);

    /* Ex 3 */
    print_out("May", 6);
    print_out("Chris", 39);
    print_out("C", 89);
    return 0;
}
