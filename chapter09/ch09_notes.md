# Programming Principles and Practice

## Chapter 9 - Technicalities: Classes etc.

1. Classes have an interface and an implementation.
2. An interface is public and represents how a class is "used". The implementation is private and produces the appropriate results in the interface. The implementation may be refined over time as long as the interface continues to produce appropriate results.
3. The original Date struct has all of its members public. They are able to be accessed and changed without using the interface. This is a problem if the values must be checked for validity.
4. By having a defined constructor, we make it impossible to initialize an invalid Date. By relying on an "init" second step, we allow potential errors to be made.
5. An invariant is a rule for what constitutes a valid value.
6. If functions are short and can be defined in 5 lines or less (pref less), then they can be written into the class definition. If they are longer then they may be declared in the class but defined elsewhere to keep the class definition short enough to easily read.
7. Operator overloading is used when we want to provide conventional notation for a type we design. An example is a smart incrementer for the Month enumerator that uses the `++Month` syntax as you would expect with a wrap from 12 to 1.
8. The public interface to a class should be only as big as is necessary. It shouldn't overwhelm the user with functionality, it should be easy to learn and easy to remember.
9. Adding `const` right after the argument list in a member function indicates that the member function can be called for a const object.
10. Functions that can be written to work on classes using the class interface are best declared and defined outside of the class to eliminate possible errors and minimize the amount of code to be debugged.
