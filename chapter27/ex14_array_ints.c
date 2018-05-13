/*
 * Stroustrup - Programming Principles & Practice
 *
 * Chapter 27 Exercise 14
 *
 * Write a funciton to take an int_arr of ints as input and find the smallest and
 * largest elements, median and mean. Return a struct holding the results.
 */

#include <stdlib.h>
#include <stdio.h>

int cmp_int(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int is_odd(int val)
{
    return val % 2 == 1;
}

int get_median(int arr[], int sz)
{
    int mid = sz / 2;

    qsort(arr, sz, sizeof(int), cmp_int);

    if (is_odd(sz)) 
        return arr[mid + 1];
    else
        return (arr[mid] + arr[mid + 1]) / 2;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

struct Results {
    int smallest;
    int largest;
    int median;
    int mean;
};

struct Results* get_results(int int_arr[], int size)
{
    struct Results* res = (struct Results*) malloc(sizeof(struct Results));
    res->smallest = res->largest = int_arr[0];
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        if (int_arr[i] < res->smallest)
            res->smallest = int_arr[i];

        if (int_arr[i] > res->largest)
            res->largest = int_arr[i];

        sum += int_arr[i];
    }

    res->mean = sum / size;

    res->median = get_median(int_arr, size);

    return res;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

int main()
{
    int ai[] = { 8, 1, 13, 21, 2, 34, 5, 3 };
    int sz = sizeof(ai) / sizeof(int);

    for (int i = 0; i < sz; ++i)
        printf("%d ", ai[i]);
    printf("\n");

    struct Results* res = get_results(ai, sz);

    printf("smallest: %d\nlargest: %d\nmean: %d\nmedian: %d\n",
            res->smallest, res->largest, res->mean, res->median);

    for (int i = 0; i < sz; ++i)
        printf("%d ", ai[i]);
    printf("\n");
}
