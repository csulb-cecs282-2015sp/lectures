#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include <iostream>
#include <string>

using namespace std;

void PrintShape(Shape *s);

int main(int argc, char* argv[]) {
   // Declare some variables of the Shape classes.
   Circle c(0, 0, 5);
   Rectangle r(0, 10, 20, 10);
   Shape s("Trapezoid", 0, 0);

   // We will now print out some information about a Shape object. Since we want
   // to work with all Shape-derived classes, we take a Shape* parameter via the
   // magic of polymorphism.
   PrintShape(&c);
   PrintShape(&r);
   PrintShape(&s);
}


// Note that the parameter is of type Shape*. All the compiler knows is that the
// parameter is of a class that derives from Shape, or is a Shape itself.
void PrintShape(Shape *s) {
   // Print the name of the shape and its center point.
   cout << s->GetShapeName() << " at (" << s->GetCenterX() << ", " << 
    s->GetCenterY() << ")";

   // Suppose I now want to print the area of the Shape.
   // Can I just do this?
   // cout << s->GetArea();


   // Since the Shape class does not have a GetArea function, the compiler
   // will not let me call GetArea, even if we *know* that s points to something
   // that DOES have a GetArea.


   // First attempt at printing the area: downcasting.
   // Ask the shape for its name, and then down-cast the pointer to an 
   // appropriate type.
   if (s->GetShapeName() == "Circle") {
      Circle *cPtr = (Circle*)s; // cast s to a Circle pointer
      cout << "; area " << cPtr->GetArea() << endl;
   }
   else if (s->GetShapeName() == "Rectangle") {
      Rectangle *rPtr = (Rectangle*)s;
      cout << "; area " << rPtr->GetArea() << endl;
   }
   // What are the weaknesses of this approach?










   // Second attempt: add a GetArea function to the Shape class.



   // Now I can call GetArea on a Shape pointer!
   cout << "; area " << s->GetArea() << endl;
   // What is the output? Why?





   // This takes us to virtual functions.
   // 1. Add keyword "virtual" to Shape's GetArea function. What does this mean?




   // 2. Now call GetArea on the Shape pointer. Whose GetArea is called?
   cout << "; area " << s->GetArea() << endl;




   // 3. Is there a reasonable default implementation of GetArea? Should generic
   //    Shape objects really have an area? Does it make sense to construct full
   //    objects of type Shape? What can we do about this?















}