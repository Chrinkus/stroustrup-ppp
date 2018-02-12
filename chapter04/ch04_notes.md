# Programming Principles & Practice

## Chapter 4 - Computation

1. A computation is the act of producing some outputs from some inputs.
2. The output 49 can be produced from the input 7 and the computation square.
3. Computations should be expressed correctly, simply and efficiently.
4. An expression computes a value from a number of operands.
5. A statement allows us to compute several values, choose from alternatives,
and perform an operation several times.
6. An `lval` is a value that can appear on the left-hand side of an assignment. The increment and assignment operators. Both kinds of operations change the value of the `lval`.
7. A constant expression is a named object to which you can't give a new value after it has been initialized.
8. Literals are values.
9. We don't like literals nested in our code, we prefer to store them in variables and refer to them by name as symbolic constants.
10. A magic constant is a non-obvious literal in code.
11. Operators that can be used on integers and floating point values are regular mathematical operations such as +, -, \*, as well as ++ for incrementing and -- for decrementing. Int's and doubles may also be compared with all of the comparison operators.
12. The modulo operator `%` can only be used on integers.
13. Strings can be operated on using the concatenation `+` operator.
14. A switch statement is especially useful when comparing against many constants.
15. The switch value cannot be a string, the case values must be constant expressions, you cannot use a variable. Forgetting a `break` statement may cause unintentional fall-through.
16. In the header line of a `for` loop, the first expression initializes any relevant variables on initailization, the second expression compares an iterator to a break-loop value at the beginning of every pass through the loop, and the third expression increments the iterator after each pass through the loop.
17. The `while` loop should be used when the timing of the termination condition is not known.
18. You can convert a char to an int to get its integer value.
```c++
char c = 'a';
cout << int{c};
```
19. The function definition `char foo(int x)` means if you pass an int to the `foo` function it will return a character type value.
20. A function should be defined for program when a specific sequence of operations are to be repeated, or when the removal (abstraction) of the sequence from the main program may help to make the program more human readable.
21. You can change the sign of an integer but you can't change the sign of a string?
22. You can concatenate a string with more characters but you can't concat an int?
23. The third element of a `vector` is `[2]`.
24. To print all elements of a vector you can write:
```c++
vector<string> v = { "first", "second", "third" };
for (string s : vec) cout << s;
```
25. The expression `vector<char> alphabet(26);` initializes a vector of 26 ints all set to ''.
26. `push_back()` adds the provided argument to a vector.
27. The vector.size() method returns the length of the vector.
28. Vectors allow us to collect and store a group of related similarly typed values.
29. You can sort the elements of a vector by calling `sort(vector)`.
