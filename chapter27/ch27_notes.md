# Programming Principles & Practice

### Chapter 27 - The C Programming Language

1. C is somewhat of a subset of C++.
2. Dennis Ritchie invented C.
3. K&R is a highly regarded C language textbook.
4. C and C++ were invented at the Computer Science Research Center at Bell Labs.
5. C++ is a superset of C with a few cases where they are incompatible.
6. The incompatibility arises from C++ stricter type checking.
7. Some missing features from C that C++ posesses are:
    - classes and member functions
    - derived classes and virtual functions
    - templates and inline functions
    - exceptions
    - function overloading
    - new/delete
    - references
    - const, constexpr
    - bool
    - static\_cast, reinterpret\_cast, and const\_cast
8. The ISO "owns" C and C++.
9. Standard Library components that cannot be used in C include:
    - vector
    - map
    - string
    - regex
    - iostream
    - STL algorithms
10. All of the C standard library components are available in C++.
11. The C++ method of declaring functions is referred to as prototype functions in C and is the way to achieve function argument type checking.
12. Missing C++ function features in C include:
    - function argument type checking
    - lambda functions
    - function objects
    - member functions
13. To allow a C function to be callable from C++ we declare with `extern "C"`.
14. To allow a C++ function to be callable from C we define the function in C++ with the same `extern "C"` tag.
```
// in C++
extern "C" double sqrt(double);

void my_cpp_fct()
{
    double sr = sqrt(2);
}

// declaring a C++ function callable from C
extern "C" int call_f(S* p, int i)
{
    return p->f(i);
}

/* in C */
int call_f(S* p, int i);

/* define p and i somehow */
int x = call_f(p, i);
```
15. I'm not sure what "layout compatible" means.
16. A structure tag is required for referencing structs in C since once declared, all struct identifiers live in a separate namespace.
17. Twenty C++ keywords that are not keywords in C are: class, constexpr, delete, new, inline, mutable, namespace, noexcept, private, public, protected, const\_cast, reinterpret\_cast, static\_cast, try, typename, using, virtual, true and false.
18. `int x;` is a definition in C++ and a declaration in C.
19. C-style casts convert a value `v` to a type `T` as such: `(T)v`. This is hard to find in code and if it is the cause of an error. The only place it seems to be OK is when allocating memory with `malloc`.
20. When allocating with `malloc`, the pointer type returned is a `void*`. This pointer can be implicitly converted by assignment:
```
int* p = malloc(/* some size */);
```
In C++ this implicit cast is not permitted. Instead use an explicit C-style cast as suggested above:
```
int* p = (int*) malloc(/*some size */);
```
21. Enums in C require enum tags similar to structs. Also in C you can assign an int to an enum without a cast:
```
enum color { red, blue, green };
int x = green;          /* OK in C and C++ */
enum color col = 7;     /* OK in C; error in C++ */
```
22. Since there aren't proper namespaces in C, name clashes are avoided by assigning unique identifiers, often prepending meaningful prefixes to common names.
23. The three most common C functions for free store access and use are malloc, calloc, and realloc.
24. A C-style string is a 0 terminated sequence of characters.
25. For C-style strings, == compares the pointers whereas strcmp() compares the actual strings.
26. To copy a C-style string a suitably-sized target string is required then the string is copied one char at a time.
27. To find the length of a C-style string call strlen() on it. The value returned is the length of the characters excluding the terminating 0.
28. A large array of ints is copied one at a time and destination must be sized large enough to receive the data.
29. The nice thing about `printf()` is that it accepts parameters to insert into the output in indicated spots. It unfortunately is not type checked so may exhibit undefined behaviour when non-matching typed values are assigned.
30. Apparently `gets()` is a major cause of code hacks in that it will readily overwrite data when its buffer is filled. Instead we ought to use `getchar()`.
31. We can open a file with `fopen()` passing the name of the file and "r" to indicate reading mode.
32. In C, const is never a compile-time designation.
33. Macros do not obey the usual scope and type rules.
34. Macros are used to define constants, control conditional compilation, define function-like constructs and "improve" the syntax.
35. An include guard is a Macro that ensures a header will only be included once during compilation.
