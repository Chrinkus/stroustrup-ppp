# Programming Principles & Practice

## Chapter 7 - Completing A Program

1. We continue to work on programs after an initial version works because then we may begin to experiment with the problem and find ways to better satisfy users.
2. The calculator does not quit after an error because we are catching that error before it propagates.
3. We created a constant called 'number' because using the char '8' was cryptic and unintuitive.
4. We split main to separate the two functions it was actually performing. The new Calculate function performs the actual work, main just starts the program, queues up Calculate and ends.
5. We split up code into multiple functions to simplify it. Ideally, a function performs a single logical action.
6. Comments are for explaining things that code expresses poorly such as intent. Describing what the code should do or laying out a grammar are good comments.
7. Narrow\_cast attempts to fit a value into a possibly unfit type. If any loss of data occurs an error is thrown.
8. Symbolic constants are used to represent a value that may not be clear in it's purpose or whose actual value may change.
9. Code layout is important because difficult to read code hides errors. A consideration should be made to have functions fit onto a single screen for ease of review.
10. We handle '%' of floating point numbers with the "fmod" function. It can also be calculated as `x%y==x-y*int(x/y)`.
11. is\_declared returns a boolean value indicating whether a given variable name has been declared already.
12. The kind member of the 'let' Token is 'L'. This value is detected by get() and a symbolic constant is referenced that contains 'let'.
13. Calculator names must contain only alphabetical characters or digits though they may not begin with a digit.
14. By building incrementally, different parts may be tested incremetally helping to isolate errors.
15. You can start to test as soon as your program can be made to produce output.
16. You retest whenever you change anything.
17. If an existing function performs multiple actions it can be split into smaller functions.
18. Give variables nouns as names such as x, value, and player. Functions are named with verbs such as get, putback, and pluralize.
19. Comments are added to explain well what can't be clearly explained in code.
20. Intent should be in comments, descriptions of expressions that are obvious to someone who understands the language are not necessary.
21. When the program performs its task with minimal errors, is relatively intuitive, and handles nonsensical inputs effectively it can be finished.
