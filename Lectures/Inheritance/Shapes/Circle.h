#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "Shape.h"
#include <string>
#include <iostream>

#define _USE_MATH_DEFINES // for M_PI
#include <math.h>

class Circle : public Shape { // Circle "is-a" Shape
private:
   double mRadius;

public:
   Circle(double centerX, double centerY, double radius)
    : Shape("Circle", centerX, centerY), mRadius(radius) {
       std::cout << "Construct Circle" << std::endl;
   }

   double GetArea() const {
      return M_PI * mRadius * mRadius;
   }

   // Space for later.
















};
#endif