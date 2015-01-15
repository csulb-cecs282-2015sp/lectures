#include <iostream>
using namespace std;

// Some "interesting" behavior...
int main() {
   int x = 5;
   int arr[] = {1, 2, 3, 4};
   
   cout << "The variable x has value " << x << endl;

   arr[6] = 10;

   cout << "After changing a value in arr, the variable x now has value " << x << endl;

   if (x != 5) {
       cout << "???" << endl;
   }
}