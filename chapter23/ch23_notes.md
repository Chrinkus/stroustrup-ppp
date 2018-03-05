# Programming Principles & Practice

## Chapter 23 - Text Manipulation

1. We find text everywhere. Websites, manuals, code, menus, books, everywhere.
2. The Standard Library text analysis tools are std::string and std::regex.
3. insert() typically adds at it's position, moving the element that was previously in that position later in the collection.
4. Unicode is a computing industry standard for the consistent encoding, representation, and handling of text expressed in most of the world's writing systems.
5. You can convert to and from string representations by utilizing string streams.
6. The difference between `cin >> s` and `getline(cin,s)` is that getline() will preserve whitespace but using cin with the >> operator will ignore it.
7. The standard streams are istream, istringstream, ifstream, iostream, ostream, ostringstream, ofstream, stringstream and fstream.
8. A map key is the 'name' that you be used to access and sort the data/value you want to store.
9. You can iterate over the elements of a map the same way as any container, with iterators to the begin() and end().
10. A map will not have duplicate keys, a multimap may. Due to potentially having duplicate keys, a multimap does not have a subscript access operator.
11. A forward iterator needs ++, a read/write \*, equality == and inequality !=.
12. When searching text for a field such as Address:, Submit:, or From:, a non-existent field is the failure to find the field whereas an empty field is when the field is found but there is no data in it.
13. Without an escape character it would be difficult to express the difference between character classes and the actual characters.
14. To get a regular expression into a regex variable you can initialize it with a literal string, a raw literal string, or assign a string. Note that unless you initialize with a raw string literal you must double escape your escapes and quotes.
```
std::regex reg1 {"\\s\\w{3}\\s"};       // literal: must escape escapes
std::regex reg2 {R"(\s\w{3}\s)"};       // raw literal: regular escapes
std::regex reg3;                        

std::string pat = "\\s\\w{3}\\s";       // std::string init: same as literal
reg3 = pat; 
```
15. The pattern `\w+\s\d{4}` matches one or more alphanumeric characters followed by a space, followed by 4 digits. Examples would be "christmas 2018", "Feb 1979", and "8904 8904". Using a string literal to initialize that would require double escapes: `\\w+\\s\\d{4}`.
16. You can assign a string to a regular expression object to check if it is valid.
17. The regex\_search() function searches through a string for a match to an expression.
18. The regex\_match() function tests a string for a complete match of its pattern.
19. The '.' character either must be escaped with a \\ in most cases or just as is inside of [].
20. You can ask for at least three of something by appending `{3,}` to whatever you're searching for.
21. The number 7 IS a `\w` character. So is the underscore.
22. Upper case characters can be searched for with `\u`.
23. You can specify your own character set inside of a set of []'s.
24. To extract an integer value from a field you can either read it into a stringstream and then attempt to read it out to an int or you can use a regular expression to isolate and capture the digit. In such a case you still need to convert from string to integer but its easier to filter out the unwanted parts with a regex.
25. A floating point number can be represented as such: `\d+\.\d+`. Some instances may allow zero or more digits before the decimal so `\d*\.\d+` would be appropriate.
26. To extract a floating point value from a match you would need to convert the match to a string stream and read from the stream into a double.
27. A sub match is any paren-enclosed capture groups within a regex. They may be accessed in order from left to right starting at index 1 of the `match_results` object.

