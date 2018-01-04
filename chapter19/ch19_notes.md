# Programming Principles & Practice

## Chapter 19 - Vector, Templates & Exceptions

1. A dynamic container is useful when the quantity of data is unknown or may change during the lifetime of the program.
2. If we have a robust container it makes sense that we would like to use it for more than one type of data.
3. Allocating enough memory for "everything" is unreasonable and would waste valuable system resources.
4. We don't allocate any spare space for a new vector.
5. We must copy vector elements to a new location whenever our vector grows to the size of our 'space' member.
6. Reserve(), resize() and push_back() can change the size of our vector after construction as well as an assignment to another, larger vector.
7. After a copy the value of a vector is a separate exact copy of the target vector.
8. The copy operation and the move operation define copying for our vector(?).
9. The default meaning for copying class objects is to copy all the members including pointer addresses.
10. A template is a type parameterized.
11. The two most useful types of template arguments are types and integers.
12. Generic programming is writing a program that works with a variety of types presented as arguments, as long as those argument types meet specific syntactic and semantic requirements.
13. Generic programming has compile-time resolution of objects and OOP uses runtime-resolution of objects.
14. Array is an efficient, fixed size container. Vector is a dynamic, less-efficient container.
15. The std::array does not decay to a pointer when passed as a function argument.
16. Reserve() only allocates more space while resize() actually initializes the space and the extra space is a part of the vector.
17. A resource is something limited that we can use such as memory, threads, files, sockets(?) that we must give back for an efficient program to run.
18. A resource leak is allocated resources that aren't given back before the objects with handles to them are destroyed.
19. RAII stands for resource acquisition is initialization. It is a guideline that suggests we encapsulate resource acquisition inside of constructors and return resources in destructors. It addresses the possibility of forgetting to return resources manually by automating the return.
20. A unique_ptr is an RAII-compliant pointer. It is an object that holds a pointer that will clean up after itself when it goes out of scope.
