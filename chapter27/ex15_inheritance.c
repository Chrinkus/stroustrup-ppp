/*
 * Stroustrup - Programming Principles & Practice
 *
 * Chapter 27 Exercise 15
 *
 * Simulate single inheritance in C.
 */

#include <stdio.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Base;                            /* forward declaration */

struct Base_vtbl {
    void (*ctor)(struct Base*);         /* constructor */
    void (*set)(struct Base*, int);
    int (*get)(struct Base*);
};

struct Base {
    int data;
    struct Base_vtbl* vtbl;
};

void base_ctor(struct Base*);
void base_set(struct Base*, int);
int base_get(struct Base*);

struct Base_vtbl b_vtbl = { &base_ctor, &base_set, &base_get };

void base_ctor(struct Base* b)
{
    b->vtbl = &b_vtbl;
    b->data = 37;
}

void base_set(struct Base* b, int val)
{
    b->data = val;
}

int base_get(struct Base*b)
{
    return b->data;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

struct  Derived;

struct Derived_vtbl {
    void (*ctor)(struct Derived*);
    void (*set)(struct Derived*, int);
    int (*get)(struct Derived*);
};

struct Derived {
    struct Base base;
    struct Derived_vtbl* vtbl;
};

void derived_ctor(struct Derived*);
void derived_set(struct Derived*, int);
int derived_get(struct Derived*);

struct Derived_vtbl d_vtbl = { &derived_ctor, &derived_set, &derived_get };

void derived_ctor(struct Derived* d)
{
    base_ctor((struct Base*)d);
    d->vtbl = &d_vtbl;
}

void derived_set(struct Derived* d, int val)
{
    d->base.data += val;
}

int derived_get(struct Derived* d)
{
    return d->base.data;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main()
{
    struct Base b1;
    base_ctor(&b1);

    printf("Base class initial value: %d\n", b1.vtbl->get(&b1));

    b1.vtbl->set(&b1, 67);

    printf("Base class set value: %d\n", b1.vtbl->get(&b1));

    struct Derived d1;
    derived_ctor(&d1);

    printf("Derived class initial value: %d\n", d1.vtbl->get(&d1));

    d1.vtbl->set(&d1, -19);

    printf("Derived class set value: %d\n", d1.vtbl->get(&d1));
}
