# Programming Principles & Practice

## Chapter 18 - Vectors and Arrays

1. Caveat emptor means buyer beware and probably refers to the programmer choosing to use arrays over vectors for "performance" reasons.
2. The default meaning of copying class objects is "copy all the data members".
3. The default meaning of copying class objects is appropriate with object values but not pointer members.
4. A copy constructor is a constructor to be called when a class is declared and initially filled with the contents of anoter vector. To prevent messing with pointers new elements are created and copied into.
5. Copy assignment is called when an existing class object is assigned the contents of another.
6. The assignment operator is an overload of '=' whereas the constructor is a variant of the regular constructor taking a class object reference.
7. A shallow copy only copies the pointer whereas a deep copy copies what the pointer points to. Copy constructors and assignments provide deep copies.
8. The copy of a vector has the same but separate size and elements.
9. The seven essential operations for a class are a constructor from one or more arguments, a default constructor, copy constructor/assignment, move constructor/assignment, and a destructor.
10. An explicit constructor is used for single argument constructors to prevent implicit conversions of that type of argument to the class.
11. Same as above.
12. An array is a homogenous sequence of objects allocated in contiguous memory.
13. You can cop an array either with a for loop and individual element copying or by using standard language features such as memcpy and copy.
14. An array is initialized type varname[size] = { initial values }. Size is optional.
15. We should prefer a pointer over a reference argument when nullptr is a valid argument and we should remember to check for it (17.9.1).
16. A C-style string is a 0-terminated character array.
17. A palindrome is a word or phrase spelled the same in forward or reverse.
