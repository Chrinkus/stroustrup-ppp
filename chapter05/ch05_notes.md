#Programming Principles & Practice

## Chapter 5 - Errors

1. Four major types of errors are:
    - Compile-time errors
        - compiler-found errors such as syntax and type errors
            - missing ;'s or trying to read string as int
    - Link-time errors
        - errors found when linker tries to combine object files
            - found if program can't locate function definitions
    - Run-time errors
        - found while running the program
            - can be thrown when a function is passed incorrect args
    - Logic errors
        - when programs don't produce the desired results
            - faulty solution to programming problem
2. We don't need to worry about misbehaving hardware or system software.
3. Completed programs should produce the desired results for all legal inputs and give reasonable error messages for illegal inputs.
4. To eliminate errors in programs and produce acceptable results we can approach program design in three ways:
    - Organize software to minimize errors
    - Eliminate most errors through debugging and testing
    - Ensure remaining errors are not serious
5. Debugging takes time.
6. A syntax error is an error that violates the language rules.
    - Incorrect capitalization of types
    - forgetting semi-colons
    - not closing a pair
    - incorrectly designing a construct
    - using wrong type of brackets/parenthesis
7. Type errors occur when the type we declare is not the type that we assign to a variable. Or if we attempt to use a variable in a way that's not acceptable for its type.
    - assigning a string to an int
    - attempting to divide strings
    - incorrect number of function arguments
    - incorrect types of function arguments
    - misspelling a function name suggesting another function
8. Linker errors
