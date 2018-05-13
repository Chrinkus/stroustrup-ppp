/*
 * Stroustrup - Programming Principles & Practice
 *
 * Chapter 27 Exercise 12
 *
 * Implement a C-style string, int lookup table with operations for finding,
 * inserting and removing pairs.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Pair {
    const char* string;
    int value;
};

struct Pair* make_pair(const char* s, int val)
{
    struct Pair* p = (struct Pair*) malloc(sizeof(struct Pair));
    p->string = s;
    p->value = val;
    return p;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

struct Table {
    struct Pair* elem;      // start of array
    size_t sz;              // size of table
    size_t cap;             // capacity of table
};

struct Table* create_table()
{
    struct Table* p = (struct Table*) malloc(sizeof(struct Table));
    p->elem = 0;
    p->sz = 0;
    p->cap = 0;
    return p;
}

void increase_size(struct Table* tab)
{
    const size_t base_size = 8;

    if (tab->cap == 0) {                /* tab->cap == 0, empty table */
        tab->elem = (struct Pair*) malloc(sizeof(struct Pair) * base_size);
        tab->cap = base_size;
        return;
    }
    else if (tab->sz == tab->cap) {     /* table memory is full, get more */
        tab->elem = (struct Pair*) realloc(tab->elem,
                sizeof(struct Pair) * tab->cap * 2);
        tab->cap *= 2;
        return;
    }
}

struct Pair* find(const struct Table* tab, const char* pc)
{
    for (struct Pair* p = tab->elem; p != tab->elem + tab->sz; ++p)
        if (strcmp(pc, p->string) == 0)
            return p;
    return 0;
}

void insert(struct Table* tab, const char* pc, int i)
{
    increase_size(tab);
    tab->elem[tab->sz] = *make_pair(pc, i);
    ++(tab->sz);
}

void cs_remove(struct Table* tab, const char* pc)
{
    struct Pair* p = find(tab, pc);
    if (!p) return;                     /* ok to remove absent pair */

    /* copy backward till end: */
    for ( ; p != tab->elem + (tab->sz - 1); ++p) {
        p->string = (p + 1)->string;
        p->value = (p + 1)->value;
    }
    --(tab->sz);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void print_table(const struct Table* tab)
{
    for (int i = 0; i < tab->sz; ++i)
        printf("element %d: %s, %d\n", i, tab->elem[i].string,
                tab->elem[i].value);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main()
{
    struct Pair* test = make_pair("Thursday", 5);

    printf("Pair test: %s, %d\n", test->string, test->value);

    printf("Table of release dates\n");
    struct Table* release_dates = create_table();

    insert(release_dates, "Final Fantasy VII", 1997);
    insert(release_dates, "Chrono Trigger", 1995);
    insert(release_dates, "Dragon Quest VIII", 2004);
    insert(release_dates, "World of Warcraft", 2004);
    insert(release_dates, "Paper Mario", 2001);

    print_table(release_dates);

    printf("Remove test\n");
    cs_remove(release_dates, "World of Warcraft");

    print_table(release_dates);

    printf("Table reallocation test\n");

    insert(release_dates, "Tomb Raider", 1996);
    insert(release_dates, "Tomb Raider II", 1997);
    insert(release_dates, "Tomb Raider Legend", 2006);
    insert(release_dates, "Rise of the Tomb Raider", 2015);

    printf("Current table capacity (8): %zu\n", release_dates->cap);

    insert(release_dates, "Shadow of the Tomb Raider", 2018);

    printf("Current table capacity (16): %zu\n", release_dates->cap);

    print_table(release_dates);
}
