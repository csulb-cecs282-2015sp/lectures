#ifndef __SHAPE_H
#define __SHAPE_H

#include <iostream>
#include <string>

// A simple base class for representing 2-dimensional shapes.
class Shape {
private:
   // every Shape has a center coordinate, and a name describing the shape.
   double mCenterX;
   double mCenterY;
   std::string mShapeName;

public:
   // The base class constructor initializes the center location and the name.
   Shape(const std::string &shapeName, double centerX, double centerY) :
    mShapeName(shapeName), mCenterX(centerX), mCenterY(centerY) {
       std::cout << "Construct Shape" << std::endl;
   }

   // Simple accessors.
   double GetCenterX() const {
      return mCenterX;
   }

   double GetCenterY() const {
      return mCenterY;
   }

   std::string GetShapeName() const {
      return mShapeName;
   }

   // We will add things here later.
   virtual double GetArea() const = 0;
   
   virtual ~Shape() {
      std::cout << "Destruct Shape" << std::endl;
   }
















};

#endif