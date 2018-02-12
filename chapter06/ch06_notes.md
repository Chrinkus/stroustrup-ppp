# Programming Principles & Practice

## Chapter 6 - Writing a Program

1. Programming is understanding refers to the need to understand a problem well to solve it, and by the time you debug and have a quality program you REALLY understand the problem.
2. The simple calculator should be able to accept multiple operations in a single expression including addition, subtraction, multiplication and division.
3. You can break a problem up into smaller manageable parts by considering what, if any, libraries may help you and how they would fit. Also by attempting to separately describe smaller parts of the overall solution.
4. By narrowing your criteria to solving a smaller portion of the larger problem you get to better know and understand the bigger. Building a small, effective prototype gives you a good base for the eventual program.
5. Feature creep can add length to a project and make the program much harder to debug. It is better to solve the necessary problem then add features in a later iteration.
6. The three phases of software development are Analysis, Design, and Implementation.
7. Use cases define ways in which a user will interact with the program.
8. Testing with various inputs helps us to determine whether our program works as it should with good and bad inputs.
9. A Number is a floating point literal, a Primary is a Number or the ()'s in an expression, an Expression and a Term are similar differing in their operators.
10. (17+4)/(5-1) '(' is a primary followed by 17 which is an expression. The addition preceding the 4 makes it a term, meaining 17 + 4 is an expression. The ')' is a primary that closes an expression. How this then becomes a Term is not understood by me at the moment. Thout (17+4) becomes a term since it divides by a primary ('('). Then (5-1) creates an expression which is a primary(?) in the division term?
10. 21/4 - 21 is a Number which is a Primary which is a Term. Since it is followed by a '/' we check to see if a Primary follows the slash. 4 is a Number which is a Primary which satisfies our rule. A Term is a Term divided by a Primary.
11. We don't have a function called a number because C++ has its own built in methods of detecting whether a value is a number.
12. A Token is a sequence of characters that represent something we consider a unit.
13. A grammar is a set of simple rules that define a general and elegant notation for familiar processes(?). A grammar rule is a condition that relates to other conditions and forms a grammar.
14. A class is a user defined type. It gives us the ability to define the types we need to solve a problem as opposed to memorizing thousands of preset types.
15. When the class is defined, its members may be assigned a default value in either the public or private part of the initiation.
16. If we don't use the extra token we checked for + or - we put it back into the stream so that it doesn't disappear.
17. "Looking ahead" in this program involves inspecting the Tokens next in the stream to determine our order of operations.
18. putback() returns a value to the input stream.
19. The remainder operation is specific to integers and thus not supported by the doubles that we've been defining.
20. We use 'kind' to read the type of Token we are dealing with. If that Token is a number the value is stored in the 'value' member. All Tokens have a 'kind' but only numbers (of kind '8') have a 'value'.
21. Public interfaces are the convenient ways in which we can work with the type and private contains the implementation details that using the type does not require access to.
22. If there is a token in the buffer when get() is called then the buffer token will be returned and the 'full' boolean will be reset to false.
23. The ';' and 'q' cases were added to Token\_stream::get to provide the user with the ability to explicitly print or quit.
24. We should be testing anytime we have a section of the program that may produce a result or computation.
25. A "user defined type" is a class and we use it to flexibly add types when we require them.
26. A class.
27. Libraries have typically been written and tested to be reliable and fast. They can save us time that will allow us to work on other parts of the program.
