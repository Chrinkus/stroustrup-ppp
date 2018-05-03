# Programming Principles & Practice

### Chapter 26 - Testing
1. Apps and their potential for disaster if there was a bug:
    - Vim - no loss, swp files!
    - Gears of War - no 10000 kills achievement
    - Baby Monitor - turns off randomly and I miss my kids crying
2. We can't know that we've found all of the bugs, only do our best.
3. Unit testing tests units, such as functions or classes. System tests test the interconnectedness of units.
4. Regression testing is the re-running of old tests after adding new functionality and tests to ensure we haven't broken anything.
5. The purpose of testing is to break our code and make it more resilient.
6. For a binary search to check it's requirements, that the iterators point to
a sequence and that sequence is sorted, would take enough work and time to make the algorithm inefficient to use.
7. We look for edge cases when testing. The beginning, end, middle of sequences. Also empty sequences and sequences with repeated values.
8. Bugs are most likely to occur at the beginning and end of a sequence.
9. Testing for large values can expose overflow errors. If the question is instead referencing large sequences we can see how our algorithm scales to larger sets.
10. Embedding tests into our source files adds extra code (static memory) and can slow down the execution of our application.
11. If we design the tests for our own code then we may overlook the same bug twice. Generating many random tests is a way to cover our blindside.
12. It is harder to test a program using a GUI because many of the outputs are graphical in nature and thus tough to automate the testing of.
13. To test a unit in isolation you need a specification of what the unit is meant to do, some mock data, and a known output for comparing against.
14. If you have a number of tests that you can run, if you port your application to another system the tests can reveal any inconsistencies in the interfaces.
15. Ideally a function has clear parameters, return values and a singular behaviour. A class may be a sub-class, require state, and have many member functions to test.
16. Tests should be repeatable so that you can use them again(?).
17. When a test relies on unchecked assumptions (ex: the sequence must be sorted) the tester may wrap the function in another test that also tests the assumptions. This wrapper may be activated only when testing so that the wrapper doesn't affect final app performance.
18. A designer can think about their code from the perspective that it will be tested and design it to be easier to test.
19. Debugging is solving problems after they occur, often at the system level. Testing is ensuring the parts do what they're supposed to do and hopefully prevents large system bugs.
20. Performance matters when a program needs to be faster.
21. You can create performance bottle-necks with code that unneccessarily reads the same sequence multiple times to retrieve the same result, and re-calculating values that you already have the answer for in previous code.
