#ifndef __TRIANGLE_H
#define __TRIANGLE_H
class RightTriangle {
private:
   double mHeight, mBase;

public:
   virtual double GetArea() const {
      return .5 * mHeight * mBase;
   }
};

#endif