# Programming Principles & Practice

## Chapter 12: A Display Model

1. We use the study of graphics to explore several important areas of software design, programming, and programming language facilities.
2. We try not to use graphics when..?
3. We get to "see" the results of our programming study.
4. A window is an area of the screen that our program uses to display output.
5. Our interface classes are found in the "Graph_lib" namespace.
6. We need the Graph.h header and a window, either Simple_window.h or just Window.h.
7. Simple_window is the easiest to use.. apparently.
8. Window would be the minimal window.
9. A window label is the name in the title bar of our window.
10. Window::set_label(string) is used to label our window.
11. Coordinates work by defining an x and y point. In graphics display the top-left corner is 0,0 with x extending to the right, and y extending down.
12. We can display a Rectangle or a Circle and many others.
13. Window::attach(Shape) attaches a shape to our window.
14. You could use a Closed_poly shape to make a hexagon.
15. You can write text by using the Text Shape.
16. You can add a picture to your display using an Image shape.
17. Perhaps you set your width and height to 0, or your top left anchor is off the screen.
18. You may not have attached your shapes to the window, or not called the `Simple_window::wait_for_button()` command to display your attachments.
