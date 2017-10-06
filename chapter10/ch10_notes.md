# Programming Principles and Practice

## Chapter 10 - Input and Output Streams

1. Devices are interfaced via drivers by the system. We can then access the drivers through an I/O library that makes I/O as similar from one device to another as possible.
2. An `istream` gets character sequences from somewhere (a file, keyboard, etc) and turns those sequences into values of various types.
3. An `ostream` turns values into character sequences and sends them somewhere (a file, console, etc.).
4. A file is a persistent storage space that stores data in a sequence of bytes.
5. A file format is a set of rules that determines how the bytes of a file should be interpreted by the system.
6. Four devices that require I/O are a refridgerator, a temperature sensor, a router, and a car.
7. The four steps to read a file are know the name, open the file, read from the file, and close it.
8. The four steps to write to a file are to know the name, open the file, write to the file, and close it.
9. The four stream states are: 
    - `good()` the operations succeeded
    - `eof()` the end of the file has been found
    - `fail()` something unexpected happened (wrong type read)
    - `bad()` something unexpected and serious happened (hardware related?)
10. Solving input errors:
    - user typing out of range value
        - `if (min <= n && n <= max) return`
        - check the range and either prompt for another input or throw
    - getting no value (end of file)
        - `if (ist.eof()) return`
        - check istream for end of file and return
    - user typing wrong type
        - `if (ist.fail()) ist.clear()`
        - check for fail status and reset the stream, ask for a better value
11. Input is usually harder than output because it comes from a user or a foreign system with irregular formatting.
12. Output can be difficult because different users would like their output to appear differently from each other.
13. We want to establish our input or output before computation so that we know we can open the file location and don't go through the processes for nothing.
14. The memeber function `clear()` is used to return the stream state to good or to explicitly set the stream state to any of the 4 states witn `ios_base`.
15. For user defined types the usual use of `<<` and `>>` is for specific I/O of the type. How we want to read the type in and how we would like to write it out.
