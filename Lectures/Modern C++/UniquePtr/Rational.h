#ifndef __RATIONAL_H
#define __RATIONAL_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Rational {
private:
   int mNumerator, mDenominator;
   int GCD(int x, int y) {
      //cout << x << ":" << y << endl;
      if (y > x)
         return GCD(y, x);
      if (y == 0)
         return x;
      return GCD(y, x % y);
   }

   void Normalize() {
      if (mDenominator < 0) {
         mNumerator *= -1;
         mDenominator *= -1;
      }
      int g = GCD(abs(mNumerator), abs(mDenominator));
      if (g > 1) {
         mNumerator /= g;
         mDenominator /= g;
      }
   }

public:
   Rational() : mNumerator(0), mDenominator(1) {
   }

   Rational(int n, int d) : mNumerator(n), mDenominator(d) {
      Normalize();
      std::cout << "Construct Rational " << (string)*this << std::endl;
   }

   Rational(const Rational &other) : mNumerator(other.mNumerator), mDenominator(other.mDenominator) {
      Normalize();
   }

   ~Rational() {
      std::cout << "Destruct Rational " << (string)*this << std::endl;
   }

   Rational &operator=(const Rational &rhs) {
      mNumerator = rhs.mNumerator;
      mDenominator = rhs.mDenominator;
      return *this;
   }

   operator double() const {
      return (double)mNumerator / mDenominator;
   }

   operator string() const {
      return ToString();
   }
   
   void SetNumerator(int n) {
      mNumerator = n;
      Normalize();
   }

   void SetDenominator(int n) {
      mNumerator = n;
      Normalize();
   }

   friend ostream& operator<<(ostream &lhs, const Rational &rhs);



   friend Rational operator+(const Rational &lhs, const Rational &rhs) {
      return Rational(lhs.mNumerator * rhs.mDenominator + lhs.mDenominator * 
         rhs.mNumerator, lhs.mDenominator * rhs.mDenominator);
   }


   friend Rational operator-(const Rational &lhs, const Rational &rhs) {
      return lhs + (-rhs);
   }


   friend Rational operator-(const Rational &rhs) {
      return Rational(-rhs.mNumerator, rhs.mDenominator);
   }


   friend Rational operator*(const Rational &lhs, const Rational &rhs) {
      return Rational(lhs.mNumerator * rhs.mNumerator, lhs.mDenominator * rhs.mDenominator);
   }


   friend Rational operator/(const Rational &lhs, const Rational &rhs) {
      return Rational(lhs.mNumerator * rhs.mDenominator, lhs.mDenominator * rhs.mNumerator);
   }

   friend bool operator==(const Rational &lhs, const Rational &rhs) {
      return lhs.mNumerator == rhs.mNumerator && lhs.mDenominator == rhs.mDenominator;
   }

   friend bool operator!=(const Rational &lhs, const Rational &rhs) {
      return !(lhs == rhs);
   }

   friend bool operator<(const Rational &lhs, const Rational &rhs) {
      return lhs.mNumerator * rhs.mDenominator < rhs.mNumerator * lhs.mDenominator;
   }

   friend bool operator<=(const Rational &lhs, const Rational &rhs) {
      return lhs < rhs || lhs == rhs;
   }

   friend bool operator>(const Rational &lhs, const Rational &rhs) {
      return !(lhs < rhs || lhs == rhs);
   }

   friend bool operator>=(const Rational &lhs, const Rational &rhs) {
      return !(lhs < rhs);
   }

   friend ostream &operator<<(ostream &lhs, const Rational &rhs) {
      lhs << (string)rhs;
      return lhs;
   }

   string ToString() const {
      ostringstream os;
      if (mDenominator == 1) os << mNumerator;
      else
         os << mNumerator << '/' << mDenominator;
      return os.str();
   }


};


#endif

