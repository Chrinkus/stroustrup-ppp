/*
 * Stroustrup - Programming Principles & Practice
 *
 * Chapter 27 Exercise 9
 *
 * Read a sequence of words from stdin and write them to stdout in 
 * lexicographical order.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_COUNT 10            /* number of strings to read in */
#define MAX_SIZE 30             /* largest expected string */

int cmp_string(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

int main()
{
    char* strings[MAX_COUNT];
    int count, i, c;

    printf("ENTER 10 WORDS TO SORT:\n");
    for (count = 0; count < MAX_COUNT; ++count) {
        char* buf = (char*)malloc(MAX_SIZE);

        for (i = 0; (c = getchar()) && c != '\n'; ++i)
            buf[i] = c;
        buf[i] = '\0';

        strings[count] = buf;
    }

    qsort(strings, MAX_COUNT, sizeof(char*), cmp_string);

    printf("SORTED WORDS:\n");
    for (i = 0; i < MAX_COUNT; ++i)
        printf("%s\n", strings[i]);
}
