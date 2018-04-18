# Programming Principles & Practice

## Chapter 25 - Embedded Systems Programming

1. An embedded system is can be a small computer that controls the operation of a device or multiple computers in a larger system. Some examples include:
    - a car
    - a phone
    - an Arduino
    - a baby monitor
    - an airplane
    - a watch
    - a camera
    - a remote control
    - a tv
    - a video game system
2. Embedded systems can have some of the following characteristics:
    - reliability is critical
    - resources are limited
    - real-time response is critical
    - system may have to function uninterrupted for years
    - hands-on maintenance is infeasable or rare
3. Predictability in embedded systems means a given operation takes the same amount of time to execute everytime it is executed on a given computer and if all such operations take the same amount of time. This can refer to algorithms measured in Big O notation, and some less predictable standard operations (new, delete).
4. Hands-on maintenance can be difficult for a number of reasons: the computer is remote (up North, middle of Ocean, out in space), the computer is difficult to get to directly (on top of something tall, in the bottom of a pit), or there are too many (mass produced devices without internet access).
5. Optimizing for system performance can slow down the production, introduce too many low-level facilities, and be difficult to reason about. Writing at a low abstraction can make changes difficult.
6. High levels of abstraction are easier to reason about, easier to change, and actually easier to optimize by the compiler.
7. Transient errors only occur once in a while and may have nothing to do with the actual software. They can be difficult to diagnose and replicate.
8. To survive failure systems may be equipped with double redundancy systems that take over when the primary system fails. Systems may either self-diagnose or be observed by other systems also.
9. Catastrophic physical failures such as industrial accidents or werewolf attacks are difficult to defend against. Luckily they are also not subtle and will more than likely be investigated immediately.
10. Domain knowledge consists of knowing the system, its environment, and the use of the system.
11. Domain knowledge is needed to best manage resources, predict failure conditions, understand the causes and results of failures, and provide extra information about what systems are able to observe our system.
12. A sub-system may be another embedded system that handles a specific task. If a task is critical it may have redundancy oversight.
13. The three types of storage are stack memory, static memory, and dynamic memory.
14. We would like to use dynamic memory when created objects must survive their scopes.
15. We need the operators `new` and `delete` to use the free store and together they can cause un-predictable execution times, memory fragmentation, and subsequently, exceptions.
16. We can safely use `new` to allocate some memory at start-up.
17. The issue with `std::vector` in embedded systems is that it uses the free store behind the scenes.
18. The problem with exceptions in embedded systems is not knowing how long it will take to reach a catch clause or if one even exists.
19. Recrusive function calls are functions that call themselves as a part of their algorithm. Recursive functions can exhaust the stack memory especially if memory is limited. Many recursive algorithms can be replaced by an iterative loop.
20. Memory fragmentation is the creation of small holes in memory that are not large enough to be used but are stuck between two long-surviving objects. These holes can add up over time and further limit the amount of memory available in an embedded system.
21. A garbage collector in programming is a process that deletes unreferenced objects. Garbage collectors may also perform memory compacting though this is itself an expensive process.
22. A memory leak occurs when an object that no longer has any live references is still occupying memory. Since there are no pointers or references to it, we cannot delete the object and it will occupy that memory until the system is rebooted. Memory leaks can add up over time and result in a large amount of un-usable, dead memory.
23. A resource is anything we acquire during a program that we have to give back such as a socket or a lock but most often memory.
24. A resource leak is when we forget to give back a resource. This can lead to resource exhaustion if we continually acquire a resource (ie socket) without giving it back.
25. It is hard to move objects around in memory because its hard to know how many other objects hold references to a given object without spending a significant amount of memory to keep track of them.
26. A stack is a data structure that follows a FIFO principle. The next item added to the stack goes on top and when we remove an item we remove the top first.
27. A pool is a collection of objects that are the same size. Allocating from a pool and deallocating do not cause holes because all objects are the same size.
28. Stacks always grow or shrink at the same point (on the top) so there cannot be any holes created by "leap-frogging" smaller sections of memory. Pools only allocate objects that are the same size so there are no smaller holes.
29. A `reinterpret_cast` can be necessary to use a low-level physical resource. It can be nasty because it forces an address to be treated like whatever we cast it to so we better be right.
30. Pointers can be dangerous as function arguments if we're passing a pointer to an array since we lose the size through passing. We may also pass the wrong element type expecting polymorphism to save us. Lastly, when passing pointers we must be ready to check that they're not a `nullptr` since that is a possibility.
```c++
void dont_do_it(Shape* p, int sz)
    // no test against nullptr
{
    for (int i = 0; i < sz; ++i) p[i].draw();
}

void f(Shape* q, std::vector<Circle>& vc)
{
    Shape s1[10];
    // initialize (did we really fill s1?)
    dont_do_it(&vc[0], (int)vc.size());     // wrong type (Circle)
    dont_do_it(s1, 10);                     // magic '10'
    Shape* p1 = new Rectangle{Point{0,0}, Point{10,20}};
    dont_do_it(p1, 1);                      // ok but size really?
    delete p1;
    dont_do_it(p1, 1);                      // passed nullptr
}
```
31. Same as above. In particular, managing a size value or variable manually is error prone. Also, passing a pointer of a container of a derived type to a function expecting a container of the base type can cause serious issues if the derived class has extra data members and thus occupies more memory.
32. Often, the alternative to using pointers to arrays in interfaces is to use an abstraction such as std::vector. This may not be feasible in an embedded system. A std::array can be used but it will own and manage the lifetimes of its contents. The text defines an Array\_ref container class that does what we want.
33. The "first law of computer science" is that every problem is solved by another indirection.
34. A bit is the smallest sized location in memory. It may either be a '0' or a '1'.
35. A byte is a sequence of 8 bits.
36. Bytes usually consist of 8 bits but there are alternatives in older systems or smaller embedded systems.
37. We have 6 bitwise operations:
    - or, and, exclusive or, left shift, right shift, and compliment
38. The exclusive or operation sets a bit if one of its operands has that bit set but not if both do. This is useful in graphics and encryption code.
39. We can represent a set of bits with a hexadecimal digit that represents the state of 4 bits.
40. We number bits from right to left in a byte.
41. We also number bytes from right to left in a word.
42. A word is the size of an address or instruction in a system.
43. A word will have either 32 or 64 bits in a word in 2018.
44. The decimal value of 0xf7 is 247.
45. The hex value 0xab represents the bit sequence '10101011'.
46. A bitset is useful when we need more than 8\*sizeof(long) bits but can be used for lesser quantities too.
47. An unsigned int doesn't reserve a bit for the sign and is able to store one more magnitude of 2 than a signed int.
48. You would prefer an unsigned int if you knew that your value could not be negative or if the extra capacity was desired.
49. If you were looping over a very large number of elements you could use the size\_type of the container or `auto`.
50. The value of an unsigned int assigned -3 (assuming 4-byte ints) is 2 less than 2^32-1.
```c++
unsigned int x = -3;    //  x == 4 294 967 293
```
51. We would want to fiddle with bits if some of the natural objects in our application are bits (flags). We also may want to extract data out of a byte stream or encrypt some output.
52. A bitfield is a facility that allows us to mix numbers and bit flags together in an object.
53. Bitfields are often used when interfacing with hardware.
54. Encryption is the disguising of information with an algorithm that is known by the sender and receiver but preferably not an interceptor. In the case that an encryption may be known to third parties, a key may be used by the principle participants to further disguise the communication.
55. You can definitely encrypt a photo.
56. TEA stands for Tiny Encryption Algorithm.
57. You can write a number to output in hexadecimal notation by using `std::hex` from `<iomanip>` in the output stream.
58. Coding standards aim to reduce the number of errors caused by "clever" code writers and also make software easier to maintain since it shares a unified style.
59. A universal coding standard is impossible because there are conventions that have perfectly reasonable implementations that people can't agree on.
60. A good coding standard gives reasons for 'don't's and where possible, suggestions for substitutions.
61. An inappropriate coding standard may cause extra work for the developer and introduce the types of errors that coding standards aim to eliminate.
62. Ten coding rules that I have found useful are:
    - each new statement starts on a new line (easier to read)
    - any function or class should fit on a screen and serve a single logical purpose (easier to understand the purpose of a function)
    - no macros shall be used (macros are goofy)
    - comments shall not be of the /\* type (consistent)
    - identifiers shall have descriptive names (reasonability)
    - spaces between operands in expressions (easier to read)
    - use classes if data members are private, structs if they're public (gives reason for choice)
    - variables shall be initialized (source of errors)
    - `new` and `delete` shall be abstracted into classes (prevents leaks)
    - identifiers shall have clearly unique names (readability)
63. All capital identifiers are generally reserved for macros.
