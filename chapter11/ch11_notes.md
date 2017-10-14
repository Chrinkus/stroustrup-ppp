# Programming Principles & Practice

## Chapter 11 - Customizing Input and Output

1. I/O is tricky for programmers because our programs are made to serve humans who have different opinions of what is and is not sensible for formating.
2. The notation `<< hex` changes the format of numeric outputs to hexadecimal.
3. Hexadecimal numbers can represent the state of 4 bits. Two hexadecimals can represent a byte and so on.
4. For formatting integers you may choose to represent them as decimal, hexadecimal or octal.
5. A manipulator is a command thrown into a stream to change its behaviour.
6. The prefix for decimal is `dec`, for hexadecimal is `hex`, and for octal is `oct`.
7. The default ouptut format of floating-point values is `defaultfloat`.
8. Fields are the `setprecision()` equivalent for integers.
9. `setprecision()` formats the floating point output to a desired number of decimal places AND rounds beyond that. `setw()` will determine how many characters to take up when outputting strings and ints.
10. File modes can be used to alter how we interact with the bytes of a file that we access.
11. `setw()` does not stick.
12. Character I/O works with values as strings whereas binary I/O deals with values as they're stored in memory.
13. It can be advantageous to work with binary when the file is an image or a sound file as they are represented only as bits.
14. String streams can be useful for extracting numeric values from a string and for formatting output for a system that expects a simple string argument.
15. A file position is a location within a file that you can selectively edit. Every file that is open for reading has a "read/get" position and every file open for writing has a "write/put" position.
16. It is unknown how each individual system will react to an attempt at reading beyond the end of file.
17. We would prefer to read an entire line of input if the line itself was meant to be taken as a whole as in messaging between users. Another instance would be when our definition of whitespace was not consistent with the regular stream's definition.
18. `isalnum(c)` returns a bool indicating whether the provided character is either a letter or a number.
