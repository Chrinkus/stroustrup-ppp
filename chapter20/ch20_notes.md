# Programming Principles and Practice

## Chapter 20 - Containers and Iterators

1. Code written by different people can look different for many reasons. Problems often have different solutions, many of which are acceptable. A language like C++ is big and has multiple classes that do similar things. Different programmers have different histories and thus may approach problems from an angle that makes sense in a different language (that may not have pointers). This is a broad question..
2. We can ask many things of data, largest value, average, search for a value, count the number of occurances of a value..
3. We can store data sequentially in a vector or array if the order is important, or in a list if we expect to be inserting and removing data from the middle.
4. We can find, sort, and sum a collection of data.
5. We can store data in different ways if we want fast access to elements or if we desire the ability to change the collection easily.
6. A sequence in the STL is a collection of data with a beginning and an end.
7. An iterator is an object that identifies an element of a sequence.
8. We can move an iterator to the next element in a container with the ++ operation.
9. We can move an iterator to the previous element in a container with the -- operation.
10. An iterator should throw an exception if you try to move it beyond the end of a sequence.
11. You can move a random-access and a bidirectional iterator backwards.
12. By separating data from algorithms we can write a single algorithm for multiple types of containers with multiple types of data.
13. The STL is the Standard Template Library designed by Alex Stepanov.
14. A linked-list is a container where each link has a pointer to the next element in the list, and sometimes also to the previous element. This type of container supports easy insertion and deletion of elements anywhere in the list unlike vector which only supports an efficient addition and removal at the end. Linked-lists do suffer when it comes to efficient access to items in the list as the entire list may need to be traversed where a vector provides direct access to its elements via sub-scripting.
15. A link in a linked-list contains the value of the element, a pointer to the next link, and optionally a link to the previous link.
16. In a linked list, insert() adds a link to the list by modifying the pointers of the previous and next elements of the list. Erase() does the same thing, removing a link by tying the previous value to the erased link's next value.
17. A sequence can be found to be empty if the begin() iterator equals the end() iterator.
18. A list iterator provides insert(), erase(), and both forward begin/end sequences and reverse begin/end sequences. The iterator also allows us to step through the list with advance().
19. You can iterate over a container in the STL with begin() and end() iterators.
20. Vector can do everything that we need to do. String can do everything vector can do and more, when it comes to text manipulation. But we don't need the more, we just need character storage and vector is better at that than strings are.
21. Use a list when you want to add and remove elements from within the container, not just at the end.
22. A container stores a sequence of objects.
23. begin() should provide an iterator to the first element of a container and end() should provide an iterator to one past the end of a container.
24. The STL provides vector, list, map, array, set, deque, unordered_map and other variations of these main containers.
25. Iterator categories define extra operations that an iterator may perform beyond the basic begin/end traversal. Categories are input, output, forward, bidirectional, and random-access.
26. Random-access iterators provide subscripted access to elements as in an array or vector.
