# Programming Prinicples and Practice

## Chapter 21 - Algorithms and Maps

1. Examples of useful STL algorithms include container sorting, copying and element finding. There are also numeric algorithms for performing operations on one or more containers.
2. The find() algorithm returns an iterator to the first instance of an element within a container. If the element is not found, the end() is returned.
```
std::vector<char> vc { 'a', 'b', 'c', 'd', 'e' };

auto it = std::find(vc.begin(), vc.end(), 'c'); // it points to 3rd element
it = std::find(vc.begin(), vc.end(), 'a');      // it points to 1st element
it = std::find(vc.begin(), vc.end(), 'z');      // it points to vc.end()

if (it != vc.end()) { /* the element was found! */ }
```
3. The count\_if() algorithm returns the number of elements within a sequence for which a predicate is true. The return value is a signed interger type.
4. The sort(b,e) uses a bubble sort as its sorting criterion.
5. An STL algorithm usually takes the begin() and end() iterators of a container as input.
6. An STL algorithm takes only the begin() iterator of a container for outputting to.
7. An STL algorithm will indicate "not found" by returning an iterator to the end() of the container it took as input.
8. A function object is a class with a calling operator (). It may be stateful.
9. A function object may be stateful, may allow the changing of its state, and may sometimes result in faster execution than a normal function.
10. A predicate is a comparison that returns true or false.
11. The accumulate(b, e, i) numeric algorithm takes an initial value and adds the elements of the provided sequence to it. The final sum is returned. Accumulate may also take a fourth argument in the form of a binary operation for other "accumulations".
12. The inner\_product(b, e, b2, i) numeric algorithm operates on two sequences, multiplying each element by its corresponding element in the second sequence and summing the results. There is a more generic overload that takes two additional binary operations to replace the multiplication and addition of the base algorithm.
13. An associative container maps keys to values. Examples include map, unordered\_map, and set.
14. A list is not an associative container as it only stores an element in a sequence, not a key for random access.
15. The basic ordering property of a binary tree is: `left->first<first && first<right->first`. So for every node, its left sub-node has a key that is less than the node's key and its right sub-node key is greater than the node's key.
16. A binary tree is roughly balanced when each sub-tree has approximately as many nodes as every other sub-tree that's equally distant from the root.
17. An element in a map stores its key, the value and pointers to two descendent nodes. That amounts to two words of overhead (16 bytes).
18. A vector element only takes up enough space for its value.
19. A person might prefer an unordered\_map if they will be doing a lot of lookups in a large sequence and they don't need ordered traversal.
20. A set is similar to a map without values, only keys.
21. A multimap may contain duplicate keys.
22. We could just write a loop for copying but STL algorithms are as fast as can be written by hand and are debugged and optimized for us.
23. A binary search cuts a sorted sequence in half and then in half again, comparing along the way to determine which half to look at next.
