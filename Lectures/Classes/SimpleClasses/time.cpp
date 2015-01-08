#include <iostream>
#include <iomanip> // for setfill and setw
using namespace std;

// create a simple structure for representing a time, with int values for 
// hour/min/sec. 
struct Time {
   int hour;   // 0-23
   int minute; // 0-59
   int second; // 0-59

}; // the semicolon is necessary


// some functions for later
void ChangeTime(Time t);
void PrintTime(Time t);
void BetterChangeTime(Time *t);
void BetterPrintTime(const Time &t);

int main_(int argc, char* argv[]) {
   // I can now declare variables of type Time
   Time timeObject;
   // I can also declare arrays, pointers, and references to Time objects
   Time timeArray[3];
   Time &timeRef = timeObject;
   Time *timePtr = &timeObject;
   // what does this look like on the stack?


   // you can access each member of an object with the period operator .
   
   cout << timeObject.hour << endl;
   // like all variables, objects initially have garbage values for their members.

   // to initialize the object, assign to its members
   timeObject.hour = 17;
   timeObject.minute = 15;
   timeObject.second = 30; // what time is this?

   // can do the same with the array elements, references, and pointers
   timeArray[0].hour = 10;
   timeRef.minute = 0; // who does this also affect?
   (*timePtr).second = 50; // * has a lower precedence than ., so you must 
                           // use parentheses for order of operations

   // C++ introduces an operator for accessing the members of a pointer
   timePtr->hour = 13; // the "arrow" operator; minus-greater  ->

   ChangeTime(timeObject);
   PrintTime(timeObject);
   
   BetterChangeTime(&timeObject); // or BetterChangeTime(timePtr);
   BetterPrintTime(timeObject);


   // some weaknesses of C-style structs
   
   // 1. no stopping me from giving invalid values to the members
   timeObject.hour = 28;
   timeObject.minute = -5;

   // 2. if I change the implementation of the struct (e.g., have the Time be 
   // represented as a count of milliseconds since midnight), everyone who 
   // uses the struct has to change accordingly.

   // 3. cannot output the struct as a whole, must do it piecewise
   // cout << timeObject << endl; // error: no << operator for Time

   // 4. likewise, cannot input the struct as a whole
   // cin >> timeObject; // error: no >> operator for Time

   // 5. cannot compare two structs directly
   // Time another;
   // if (another == timeObject) {
         // error: no == operator for Time and Time
   // }


   // how does C++ address these concerns?
}

void ChangeTime(Time t) {
   // change the object to 10:10:10
   t.hour = 10;
   t.minute = 10;
   t.second = 10;
}

void PrintTime(Time t) {
   // print the Time in the format hh:mm:ss
   cout << t.hour << ":" << t.minute << ":" << t.second << endl;
   // output: 13:0:50 -- not 10:10:10???
}

void BetterChangeTime(Time *t) { // why a pointer???
   t->hour = 1;
   t->minute = 1;
   t->second = 10;
}

void BetterPrintTime(const Time &t) { // why a const reference?
   cout << setw(2) << // require two columns for the next int found
    setfill('0') <<   // fill empty spaces with '0'
    t.hour << ":" << 
    setw(2) << // must repeat the setw before each variable we want formatted
    t.minute << ":" << 
    setw(2) << t.second << endl; 
}