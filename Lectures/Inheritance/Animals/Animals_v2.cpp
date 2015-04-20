#include <string>
#include <iostream>
using namespace std;

class Cat {
protected:
   string mSpecies;
public:
   Cat(const string &spec) : mSpecies(spec) {cout << "I am a " << spec << endl;}
   virtual void Speak() {cout << "Meow" << endl;}

   string GetSpecies() {return mSpecies;}
};

class Lion : public Cat {
protected:
   bool mIsKing;
public:
   Lion(bool isKing) : Cat("Lion"), mIsKing(isKing) {}
   virtual void Speak() {cout << mSpecies << " says " << "Roar!" << endl;}
};

class Tiger : public Cat {
protected:
   int mNumberOfStripes;
public:
   Tiger(int stripes) : Cat("Tiger"), mNumberOfStripes(stripes) {}
   virtual void Speak() {cout << mSpecies << " says " << "Chuff!" << endl;}
};

class Liger : public Lion, public Tiger {
public:
   Liger() : Lion(true), Tiger(10) {
      //mSpecies = "Liger";
      // error: mSpecies is ambiguous... why?
   }
};


int mains() {
   Liger a;
   cout << "Speak, Liger!";
   //auto x = &a;

   
   //pc->Speak();
   // error: Speak() is ambiguous.

   // Can I take a pointer to a Ligon as a Lion* or Tiger*?
   Tiger *pt = &a;
   pt->GetSpecies();
   //Lion *pl = &a;

   // Can I take a pointer to a Ligon as a Cat*?
   
   

   return 0;
}
