# Programming Principles & Practice

## Chapter 13 - Graphics Classes

1. A graphics library can be huge. By using a small subset we can become comfortable with some tools then learn to use more as needed.
2. We're using about 20 graphics classes to achieve admirable results.
3. Simple_window.h, Window.h, Graph.h, Point.h & GUI.h
4. Rectangle, Polygon, Closed_poly, Circle, Ellipse all define closed shapes.
5. Using Line for all shapes would be too wordy, too much code.
6. The arguments to Point indicate x & y coordinates on the screen.
7. The components of Line_style are the style type, such as solid or dashed, and line width in pixels.
8. The components of Color are the basic colors and a "dark" option. Colors may also be indicated by integer or RGB value.
9. RGB is a method of creating colors by mixing in Red, Green and Blue respectfully.
10. Two Line objects are independent of each other, whereas two lines in a Lines collection may be styled together.
11. Color and Line_style are defined for every shape.
12. A Closed_polyline with 5 points has 5 sides.
13. You don't see anything if you do not attach to the window.
14. A Rectangle knows about being a rectangle. This includes some algorithms for determining if a given point is inside a rectangle.
15. A Polygon must not have lines that intersect, where a Closed_polyline may.
16. The outline is on top of the fill.
17. A Triangle class is not defined because there's no obvious benefit?
18. Call the move() member function to change the location of a Shape.
19. We can create a Text "Shape" and attach it near our Shape to be labelled.
20. You can set the font, size, and color of a Text string.
21. The font is how the text looks, we care because of course we do.
22. We can use Vector_ref to group multiple Shapes together for applying style and attaching to the Window.
23. A circle has a radius, an ellipse has a major and a minor radius.
24. There is no compile or runtime error for a bad image file reference, the image itself will not dispaly and a message will appear in the Window indicating the problem.
25. You can use the mask member function to display only part of an image.
