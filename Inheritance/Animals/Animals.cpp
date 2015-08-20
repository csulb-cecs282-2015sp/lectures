#include <string>
#include <sstream>
#include <iostream>
using namespace std;


class Lion {
protected:
   bool mIsKing;

public:
   Lion(bool isKing) : mIsKing(isKing) {}
   void Roar() {cout << "Roar" << endl;}
};

class Tiger {
protected:
   int mNumberOfStripes;

public:
   Tiger(int stripes) : mNumberOfStripes(stripes) {}
   void Chuff() {cout << "Chuff" << endl;}
};

class Liger : public Lion, public Tiger {
public:
   Liger() : Lion(true), Tiger(10) {}
   operator string() {
      ostringstream o;
      o << "I am a Liger with " << mNumberOfStripes << " stripes. I am " << 
       (mIsKing ? "the king." : "not the king.");
      return o.str();
   }
};


int __main() {
   Liger a;
   a.Roar();
   a.Chuff();
   cout << (string)a << endl;

   return 0;
}
