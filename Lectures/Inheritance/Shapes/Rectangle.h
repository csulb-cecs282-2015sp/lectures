#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "Shape.h"
#include <string>
#include <iostream>

class Rectangle : public Shape { // Rectangle "is-a" Shape
private:
   double mWidth;
   double mHeight;

public:
   Rectangle(double upperLeftX, double upperLeftY, double width, double height)
      : Shape("Rectangle", upperLeftX + width / 2, upperLeftY - height / 2),
      mWidth(width), mHeight(height) {
      std::cout << "Construct Rectangle" << std::endl;
   }

   double GetArea() const {
      return mWidth * mHeight;
   }

   // Space for later.
   virtual ~Rectangle() {
      std::cout << "Destruct Rectangle" << std::endl;
   }















};
#endif