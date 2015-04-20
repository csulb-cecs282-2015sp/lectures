#include <string>
#include <sstream>
#include <iostream>
using namespace std;


class Lion {
protected:
   bool mIsKing;
   string mSpecies;

public:
   Lion(bool isKing) : mIsKing(isKing), mSpecies("Lion") {}
   void Roar() {cout << "Roar" << endl;}
   string GetSpecies() {return mSpecies;}
};

class Tiger {
protected:
   int mNumberOfStripes;
   string mSpecies;

public:
   Tiger(int stripes) : mNumberOfStripes(stripes), mSpecies("Tiger") {}
   void Chuff() {cout << "Chuff" << endl;}
   string GetSpecies() {return mSpecies;}
};

class Liger : public Lion, public Tiger {
public:
   Liger() : Lion(true), Tiger(10) {}
   operator string() {
      ostringstream o;
      o << "I am a Liger with " << mNumberOfStripes << " stripes. I am " << 
       (mIsKing ? "the king." : "not the king. ");

      return o.str();
   }
};


int _main() {
   Liger a;
   cout << (string)a << endl;
   cout << a.Lion::GetSpecies() << endl;
   //error: Liger::GetSpecies is ambiguous.
   return 0;
}
