/*
 * Stroustrup - Programming Principles & Practice
 *
 * Chapter 27 Exercise 2
 *
 * Complete the intrusive list example and test it using every function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct List {
    struct Link* first;
    struct Link* last;
};

struct Link {
    struct Link* pre;
    struct Link* suc;
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

void init(struct List* lst)
    /* initialize *lst to the empty list */
{
    assert(lst);
    lst->first = lst->last = 0;
}

struct List* create()
    /* make a new empty list on free store */
{
    struct List* lst = (struct List*) malloc (sizeof(struct List));
    init(lst);
    return lst;
}

void clear(struct List* lst)
    /* free all elements of lst */
{
    assert(lst);
    {
        struct Link* curr = lst->first;
        while (curr) {
            struct Link* next = curr->suc;
            free(curr);
            curr = next;
        }
        lst->first = lst->last = 0;
    }
}

void destroy(struct List* lst)
    /* free all elements of lst, then free lst */
{
    assert(lst);
    clear(lst);
    free(lst);
}

void push_back(struct List* lst, struct Link* p)
    /* add p at end of lst */
{
    assert(lst);
    {
        struct Link* last = lst->last;
        if (last) {                     /* add p after last */
            last->suc = p;
            p->pre = last;
        }
        else {                          /* p is the first element */
            lst->first = p;
            p->pre = 0;
        }
        lst->last = p;                  /* p is the new last element */
        p->suc = 0;
    }
}

void push_front(struct List* lst, struct Link* p)
    /* add p at front of lst */
{
    assert(lst);
    struct Link* first = lst->first;

    if (first)
        first->pre = p;
    else
        lst->last = p;

    lst->first = p;
    p->suc = first;
    p->pre = 0;
}

/* insert q before p in lst: */
void insert(struct List* lst, struct Link* p, struct Link* q)
{
    assert(lst);
    if (p) {
        q->pre = p->pre;
        if (p->pre)
            p->pre->suc = q;
        p->pre = q;
    }
    else {
        lst->first = lst->last = q;
        q->pre = 0;
    }
    q->suc = p;
}

struct Link* erase(struct List* lst, struct Link* p)
    /* remove p from lst:
     * return a pointer to the link after p
     */
{
    assert(lst);
    if (p == 0) return 0;                   /* OK to erase (0) */

    if (p == lst->first) {
        if (p->suc) {
            lst->first = p->suc;            /* the successor becomes first */
            p->suc->pre = 0;
            return p->suc;
        }
        else {
            lst->first = lst->last = 0;     /* the list becomes empty */
            return 0;
        }
    }
    else if (p == lst->last) {
        if (p->pre) {
            lst->last = p->pre;         /* the predecessor becomes last */
            p->pre->suc = 0;
        }
        else {
            lst->first = lst->last = 0;     /* the list becomes empty */
            return 0;
        }
    }
    else {
        p->suc->pre = p->pre;
        p->pre->suc = p->suc;
        return p->suc;
    }
}

/* return link n "hops" before or after p: */
struct Link* advance(struct Link* p, int n)
{
    if (n > 0) {
        while (n > 0) {
            if (p->suc == 0) return p;
            p = p->suc;
            --n;
        }
    }
    else {
        while (n < 0) {
            if (p->pre == 0) return p;
            p = p->pre;
            ++n;
        }
    }
    return p;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

struct Name {
    struct Link lnk;            /* the Link required by List operations */
    char* p;                    /* the name string */
};

struct Name* make_name(char* n)
{
    struct Name* p = (struct Name*) malloc(sizeof(struct Name));
    p->p = n;
    return p;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

void print_list(struct List* lst)
{
    assert(lst);
    int count = 0;
    struct Link* curr;
    for (curr = lst->first; curr != 0; curr = curr->suc) {
        ++count;
        printf("element %d: %s\n", count, ((struct Name*) curr)->p);
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 

int main()
{
    int count = 0;
    struct List names;              /* make a list */
    struct Link* curr;
    init(&names);

    /* make a few Names and add them to the list: */
    push_back(&names, (struct Link*)make_name("Nora"));
    push_back(&names, (struct Link*)make_name("Jacob"));
    push_back(&names, (struct Link*)make_name("Caitlin"));

    /* remove the second name (with index 1): */
    erase(&names, advance(names.first, 1));

    curr = names.first;             /* write out all names */
    for (; curr != 0; curr = curr->suc) {
        count++;
        printf("element %d: %s\n", count, ((struct Name*) curr)->p);
    }

    /* Extra tests */
    printf("FURTHER TESTING\n");
    struct List games;
    init(&games);

    insert(&games, games.first, (struct Link*)make_name("Tomb Raider"));
    push_back(&games, (struct Link*)make_name("The Last of Us"));
    insert(&games, advance(games.first, 1), (struct Link*)make_name("Halo"));
    push_front(&games, (struct Link*)make_name("God of War"));

    print_list(&games);
}
