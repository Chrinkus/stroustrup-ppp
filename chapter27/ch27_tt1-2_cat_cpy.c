/*
 * Stroustrup - Programming Principles & Practice
 *
 * Chapter 27 Try This - cat & bs_strcpy
 *
 * Test cat(). Fix errors.
 * 
 * Test bs_strcpy implementation and explain.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* bs_strcpy(char* p, const char* q)
    /* Assign the char that q points to to p and increment both p and q.
     * Do this as long as the value assigned to p is not the null terminator.
     */
{
    while ((*p++ = *q++));
    return p;
}

char* cat(const char* id, const char* addr)
{
    int sz = strlen(id) + strlen(addr) + 2; /* sz = id + addr + 2 (@,\0)    */
    char* res = (char*) malloc(sz);         /* allocate sz bytes            */
    bs_strcpy(res,id);                      /* copy id into res             */
    res[strlen(id)] = '@';                  /* replace nullchar with @      */
    bs_strcpy(res + strlen(id) + 1, addr);  /* copy addr into res after @   */
    /*res[sz-1] = 0; should not be necessary, we have addr's already        */
    return res;
}

int main()
{
    printf("Hello C89!\n");
    char* email = cat("chrinkus", "hotmail");
    printf("%s\n", email);
    return 0;
}
