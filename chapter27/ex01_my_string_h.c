/*
 * Stroustrup - Programming Principles & Practice
 *
 * Chapter 27 Exercise 1
 *
 * Implement versions of strlen(), strcmp() and strcpy().
 */

#include <stdlib.h>
#include <stdio.h>

/* strlen() - counts characters */
size_t my_strlen(const char* s)
{
    size_t count = 0;
    while (*s++) ++count;
    return count;
}

/* strcmp() - compares 2 strings */
int my_strcmp(const char* s1, const char* s2)
{
    /* increment ptrs till no match or end of s1 */
    while (*s1 && *s1 == *s2) {
        ++s1;
        ++s2;
    }

    /* check status of where pointers stopped */
    if (*s1 < *s2)
        return -1;                              /* s1 comes before s2 */
    else if (*s1 > *s2)
        return 1;                               /* s2 comes before s1 */
    else if (my_strlen(s1) != my_strlen(s2))    /* is s2 longer? */
        return -1;                              /* if so, s1 comes before s2 */
    else
        return 0;                               /* they're equal */
}

/* strcpy() - copys second string into first (returns last position?) */
char* my_strcpy(char* s1, const char* s2)
{
    while ((*s1++ = *s2++)) ;
    return s1;
}

int main()
{
    char* s1 = "slack";
    int len = my_strlen(s1);
    printf("my_strlen(): %s is %d characters long.\n", s1, len);

    char* s2 = "short";
    char* s3 = "super long";
    char* s4 = "slack";

    int cmp1 = my_strcmp(s1, s2);
    int cmp2 = my_strcmp(s2, s3);
    int cmp3 = my_strcmp(s1, s4);
    printf("my_strcmp(): after: %d, before: %d, and equal: %d\n",
            cmp1, cmp2, cmp3);

    char* s5 = (char*) malloc(my_strlen(s3) + my_strlen(s1) + 2);
    my_strcpy(s5, s3);
    s5[my_strlen(s3)] = ' ';
    my_strcpy(s5 + my_strlen(s3) + 1, s1);
    printf("%s\n", s5);

    char s6[my_strlen(s5)];
    my_strcpy(s6, s5);
    printf("%s\n", s6);
}
