# Programming Prinicples & Practice

## Chapter 24 - Numerics

1. Scientists, engineers and statisticians all use numerics.
2. Precision is the accuracy of a value compared to the calculation that produced it.
3. Overflow occurs when an integer becomes too large or too small for it's stated type. The value will distort as the bits roll over and produce, usually, a significantly erroneous result.
4. Common sizes for doubles are 8 bytes and ints are 4 bytes.
5. Overflow can be detected when the values of integer types are significantly off from what is expected. Also knowing the size of your types and the largest and smallest values that may fit in those types will help to identify potential overflows before they happen.
6. Numeric limits can be found in <limits>, <climits>, <limits.h> & <float.h>.
7. An array is a contiguous sequence of elements. A row may be a reference to a single array or an array element in a 2-dimensional array (an array of arrays). A column would be all of the same indexed elements in the rows of a 2-dimensional array.
8. A C-style multidimensional array is an array of arrays.
9. The desirable  properties of a Matrix library would include a similar layout to pen and paper representations of matrices, appropriate subscripting, easy to use row operations, and the ability to multiply matrices.
10. A dimension of a matrix would be one of the "sides" in a 2-dimensional matrix.
11. Matrixes may have any number of dimensions though most of the time 4 dimensions seem to be the reasonable maximum (3D space in time).
12. A slice is a portion of a matrix. A slice may be a single row or the same columns from multiple rows.
13. A broadcast operation takes the values of one Matrix, applies a function to each element and writes to another Matrix without altering the original Matrix.
14. Fortran-style subscripting uses parenthesis and is used the same way mathematical coordinates are written: `m(3,4,5)`. C-style subscripting utilizes the square brackets and limits each set of brackets to a single value `m[3][4][5]`. Both of the above operations access the 5th element of the 4th Matrix in the 3rd row of m.
15. You can apply basic operations to the matrix itself like `m *= 3`. This will multiply each value in the matrix by 3. For more complicated operations the apply member function may be used to alter the Matrix.
16. A fused operation performs two operations in a single step. The Matrix operation scale\_and\_add performs a multiplication and addition.
17. Dot product is similar to inner\_product. It provides the sum of the products of corresponding elements in two Matrixes.
18. Linear algebra concerns the study of linear equations, linear functions, and their representations through matrices and vector spaces.
19. Gaussian elimination is a method for simplifying linear equations.
20. A pivot is a point around which things rotate. In linear algebra the pivot is the element in a row that lies on the diagonal.
21. Random numbers are a sequence of numbers that conform to some distribution and where you cannot predict the next number given the previous ones.
22. A uniform distribution produces random numbers in a range where all intervals of the same length are equally probable.
23. The standard mathematical functions are found in <cmath> and provided for types float, double, long double and complex.
24. The imaginary part of a complex number is the real number that scales i.
25. The square root of -1 is i, the pure imaginary unit.
