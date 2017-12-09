# Programming Principles & Practice

## Chapter 17 - Vector & Free Store

1. Data structures with varying numbers of elements are dynamic and can be used in a great many ways.
2. Code storage for the actual code, static storage for global variables, stack (or automatic) storage for functions, function arguments and local variables, and free store or the "heap".
3. The free store is also known as the heap. It is the amount of memory not used for any other purpose.
4. The dereference operator provides access to the value stored at the location identified by a pointer.
5. An address points to a location in memory. It is stored in a pointer.
6. A pointer knows where the object begins and what its type is. If the object is a container the pointer has no idea how large it is.
7. A pointer stores an address that points to a location in memory.
8. A leak occurs when memory is allocated but not returned before the object it belongs to is destroyed.
9. A resource is memory.
10. We initialize a pointer with an asterisk following a type. A pointer is initialized that addresses the location in memory where the object is stored.
11. A null pointer is an "empty" value to assign to a pointer. We use it when a pointer sometimes points to an object and sometimes doesn't.
12. We need a pointer when we're requisitioning resources from the free store.
13. A destructor automatically cleans up our resource allocations when objects are destroyed either by going out of scope or being explicitly deleted.
14. If a class has a virtual function it needs a virtual destructor.
15. Member destructors are automatically called when the object containing the member is destroyed.
16. A cast is used to subvert the type safety system. It is best used only when interacting with another language that doesn't know about C++ types.
17. We can access a member of a class through a pointer with the arrow operator (->).
18. A doubly linked list's elements have a reference to the next and previous objects in the list.
19. The identifier "this" is a pointer that points to the object for which a member function is called.
