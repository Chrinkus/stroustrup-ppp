# Programming Principles and Practice Using C++

## Chapter 3 - Objects, Types and Values

1. Prompt means to ask the user for input.
2. The `>>` or "get from" operator reads a value into a variable.
3. After prompting the user for an integer value you can:
```c++
int number;
cin >> number;
```
4. \n is called the "newline" character and it is like typing in a carriage return.
5. An input is terminated into a string by white space.
6. An integer is also terminated by white space.
7. Like this: `cout << "Hello, " << first_name << "!\n";`
8. An object is some memory that holds a value of a specific type.
9. A literal string is delimited by double quotes. A variable may refer to, or contain, a literal string. `string string_variable = "Literal string";`
10. Strings and chars?
11. A variable is a named object.
12. A char is typically a single byte, an int is 4 bytes and a double is 8 bytes.
13. We use bytes which are 8 bits.
14. The `=` is an assignment operator and the `==` is used to compare.
15. A definition is a statement that introduces a new name into a program and sets aside memory for a variable.
16. An initialization states the type of a variable, gives it a name, and may fill it with a value. Assignment, on the other hand, is used to fill an initialized variable with a new value.
17. String concatenation is the joining of two strings where two strings `"Howdy"` and `"partner"` are combined with the `+` operator. The resulting string becomes `"Howdypartner"`. Concatenation will combine the strings as is, it will not add whitespace between the joined strings so that must be planned for. The strings may be literal strings or the contents of a string type variable.
18. Legal variable names: They're all suspect for the following reasons.
```c++
This_little_pig     // Leading capital reserved for defined types only
This_1_is fine      // Spaces are no good
2_For_1_special     // Leading numbers are bad 'mkay?
latest thing        // Sneaky space
the_$12_method      // $ is not a valid name char
_this_is_ok         // Leading underscores are reserved for system entities
MiniMineMine        // Tough to read, potentially confusing
number              // actually this is apparently ok..
correct?            // Question mark ees no good, senior
```
19. Examples of legal names that may cause confusion are: origin0, little1, variations on a name such as call, call1, CallAll.
20. Meaningful names are good choices, names that indicate what type the value might be, and its potential use.
21. Type safety is using objects only according to the rules for their type. By not being type-safe we may produce unpredictable values and results.
22. Conversion from a double to an int may cause overflow of the int for large numbers, or loss of accuracy due to truncation of any decimal portions.
23. We can convert types to larger memory types but must be careful when down converting to a smaller memory type. We must avoid narrowing.
