#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "Shape.h"
#include <string>
#include <iostream>

class Triangle : public Shape { // Triangle "is-a" Shape
private:
   double mBase;
   double mHeight;

public:
   Triangle(double upperLeftX, double upperLeftY, double base, double height)
    : Shape("Triangle", upperLeftX + base / 2, upperLeftY - height / 2),
      mBase(base), mHeight(height) {
      std::cout << "Construct Triangle" << std::endl;
   }

   double GetArea() const {
      return 0.5 * mBase * mHeight;
   }
};

#endif