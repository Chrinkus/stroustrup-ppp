# Programming Principles & Practice

## Chapter 14 - Graphics Class Design

1. An application domain is the total environment that our programs seek to model a part of.
2. Identical operations should have the same name, though seemingly similar functions may require differing names to help identify their nuances better.
3. We name classes, functions and objects, either standalone or class members.
4. The Shape class ties our derived shapes to a Window object, handles styling and keeps track of a sequence of points to draw from.
5. An abstract class descibes the behaviours of a type of thing, of which there are specific instances of.
6. To make a class abstract you can make its constructors protected or declare pure virtual functions.
7. Access control is the defining of members as private, protected or public. This may also be used when inheriting from a base class.
8. Making a data member private prevents any outside access or alteration of it.
9. A virtual function is a default behaviour that may be over-written when more specific behaviour is required.
10. A base class is a parent class that a class inherits from.
11. A class is derived if it inherits from a base class.
12. Object layout refers to how objects are stored in memory.
13. Not sure, though would like to know..
14. An inheritance diagram is tree like and shows the parent/child relationships between base and derived classes.
15. A protected member may be accessed by derived classes but not externally, private members are visible only to the class they belong to.
16. The public and protected members of a base class may be accessed by a derived class.
17. Pure virtual functions must be overridden to initialize a derived class.
18. You would make a member function virtual if it was known that derived classes would want their own implementations of that function but still wanted to be able to call it in the other base class member functions.
19. You would make a virtual member function pure if you wanted to force a class to be treated as abstract.
20. Overriding provides a local version of a virtual function to be called in place of the base class's version.
21. Interface inheritance allows the base class to utilize member functions that it has no idea about, implementation inheritance provides generic, shared functionality across derived classes to minimize repetition of identical functionality.
22. Object-oriented programming is the use of inheritance, polymorphism and encapsulation to solve problems.
