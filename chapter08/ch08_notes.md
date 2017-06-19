# Programming Principles & Practice

## Chapter 8 - Technicalities: Functions, etc.

1. A declaration is an interface that tells you how you can use a name, a definition sets aside memory and possible fills it.
2. A function declaration doesn't have a body, a function definition does.
3. A variable declaration uses 'extern' to add a usable name to a scope, a variable definition does not preface its type and name with 'extern'. It may include an assignment to a value.
4. The calculator functions in Chapter 6 need to be declared first because they call circularly.
5. The expression 'int a;' is a definition.
6. It is a good idea to initialize variables as they're declared because otherwise that spot in memory will have an unpredictable value.
7. A function declaration indicates a return type, a name, and the types of any expected arguments.
8. Indentation makes code easier to read for the programmer.
9. Header files are used to define interfaces to useful facilities that are defined elsewhere.
10. A declaration is usable within the scope it is declared within.
11. The kinds of scopes include the global scope, a namespace scope, a class scope, local scope, and statement scope.
12. A class scope exists in the area of text within a class as opposed to the local scope of blocks and functions.
13. A programmer should minimize the number of global variables to mitigate the chance of name clashes.
14. Pass by value provides a copy of a variable to a function, pass by reference provides access to the variable.
15. Pass by reference allows the original variable to be changed, pass by const reference avoids copying variables but prevents the arguments from being changed.
16. A swap() changes two values. The standard library provides a swap function for all types that can be copied.
17. You would likely not define a function with a `vector<double>` by value parameter. Instead use `vector<double>&` to pass a reference and save the unnecessary copying.
18. An undefined order of evaluation is any expression that references the same variable multiple times and changes it. `int x = ++i + ++i;` is confusing, what will the last `i` actually be?
19. `x&&y` means x AND y, `x||y` means x OR y.
20. Functions within classes are common, classes within classes are acceptable but complicated. Functions within functions will not compile, and classes within functions are iffy.
21. An activation record contains a copy of all of the function's parameters and local variables plus "implementation stuff" that the function uses to return to its caller.
22. A call stack is a system for tracking function calls. It keeps them in order to structure the way in which functions return their values into each other's scopes. Last in, first out.
23. A 'namespace' is a contained environment where variables live. Their meaning is assured within their namespace but out of it they cease to exist.
24. Unlike classes, which seek to organize closely related values and functions, a namespace can contain a broader range of values. A namespace may contain several classes, functions and local variables.
25. A 'using' declaration is attached to a specific function or variable from a specified namespace. It allows the use of that function or variable as if it were native to the current namespace.
26. A 'using' directive in a header is hidden and can make it difficult to know which names are already in scope.
27. The namespace 'std' contains all of the facilities of the C++ standard library.
