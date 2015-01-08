#include "GlobalFunctions.h"



void FunctionC() {
   globalX = 1000; // can't find globalX in scope of this function... but it's global!
}