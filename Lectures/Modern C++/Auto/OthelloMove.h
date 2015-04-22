#ifndef __OTHELLOMOVE_H
#define __OTHELLOMOVE_H

#include <string>
#include <vector>

/*
An OthelloMove encapsulates a single potential move on an OthelloBoard. It
is represented internally by a row and column, both 0-based.
*/
class OthelloMove {
private:
   // OthelloBoard is a friend so it can access mRow and mCol.
   friend class OthelloBoard;
	
   /*
   A FlipSet tracks a direction and # of pieces that got flipped when this 
   move was applied. See spec.
   */
   class FlipSet {
   public:
      FlipSet(char sw, char rowD, char colD) : switched(sw), rowDelta(rowD), 
       colDelta(colD) {}

      char switched;
      char rowDelta, colDelta;
   };
   
   // the row and column of the move
   int mRow, mCol;
   // a list of FlipSets representing the enemy pieces flipped by this move
   std::vector<FlipSet> mFlips;


   // KEEP THESE CONSTRUCTORS PRIVATE.
   // Default constructor: initializes this move as a PASS.
   OthelloMove();
   /*
   2-parameter constructor: initializes this move with the given 
   row and column.
   */
   OthelloMove(int row, int col);

   /*
   Adds a FlipSet to the move's vector of sets. Used to keep track of how many
   enemy pieces were flipped in each direction when this move was applied.
   This function is private, but OthelloBoard has friend access.
   */
   void AddFlipSet(FlipSet set) {mFlips.push_back(set);}
    
public:
   /*
   This assignment operator takes a string representation of an Othellomove
   and uses it to initialize the move. The string is in the format
   (r, c); OR is the string "pass". [The user will not enter (-1,-1) to pass
   anymore.]
   */
   OthelloMove& operator=(const std::string &);

   /*
   Compares two OthelloMove objects for equality (if rows and cols are same).
   */
   friend bool operator==(const OthelloMove &lhs, const OthelloMove &rhs);

   /* 
   Converts the OthelloMove into a string representation, one that could be
   used correctly with operator=(string). Returns "pass" if move is a pass.
   */
   operator std::string() const;

   // Returns true if the move represents a Pass.
   // TO DO: fill in this method.
   inline bool IsPass() const {/* return true if this move is a "pass" */}
};
#endif