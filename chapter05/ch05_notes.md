# Programming Principles & Practice

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
    - misspelling a function name suggesting another function (linker?)
8. Linker errors occur when there are discrepancies between translation units in a program.
    - multiple declarations of the same function name
    - misspelling a function name implying an undeclared function(type?)
    - forgetting to include a resource and trying to use it
9. Logic errors are detected by the user when a program either doesn't produce any output or incorrect output. This is usually due to either poor design or understanding of how the language will process instructions.
    - passing a negative value to sqrt()
    - neglecting to return a value
    - initializing variables to values that will not be overwritten
10. Four sources of error outlined in the text are:
    - Bad input
    - setting variables to default values that will not be overwritten
    - not understanding how a function will behave given specific values
    - forgetting to define a function or including it
11. Estimation should allow us to predict what our output should look like. If our estimation is off, we should seek to improve our own estimation algorithms. It is recommended to write out ideas and solutions on paper to help the programmer work through a problem.
12. When the caller has to handle a run-time error, it must do so everytime the function is called and with deep knowledge of how the function works. If a callee, or the actual function is designed to handle run-time errors then the handling code only has to be written in one place and may be changed relatively easily at a later date.
13. Using exceptions allows us to detect errors in the callee and handle the error in the caller, which is the best of both worlds, error-wise.
14. You can test if an input operation succeeded by checking on the state of `cin`.
15. If a function detects an error it can't handle, it doesn't `return` normally, it throws an exception. Further up the call chain, the application code can catch the error and decide what to do with such inputs.
16. Trying to reference the index `[v.size()]` of vector v will throw a range-error as the `size()` property of a vector is one element larger than the last index due to vectors being 0-indexed.
17. A pre-condition tests the arguments coming into the function and a post-condition tests the return value before supplying it to the caller.
```c++
int weight_pushed(int weight, int reps)
{
    if (weight <= 0 || reps <= 0) error("Didn't do anything!");
    int pushed_weight = weight * reps;
    if (pushed_weight > 2240) error("Too much tonnage!");
    return pushed_weight;
}
```
18. You would not test a pre-condition if there was no chance of bad arguments being supplied to your code.
19. You could probably omit the post-condition test if the computation was trivial.
20. Debugging goes through three general stages: get the program to compile, get the program to link, and get the program to do what's intended.
21. Commenting helps to debug by making the program easier to read to the person debugging.
22. Testing differs from debugging in that testing involves running your code with a large number of possible inputs to see if the results match what the program should be outputting.
