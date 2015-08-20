#ifndef __OTHELLOBOARD_H
#define __OTHELLOBOARD_H

#include <vector>
#include "OthelloMove.h"

const int BOARD_SIZE = 8;

/*
An OthelloBoard encapsulates data needed to represent a single game of Othello.
This includes the state of the board, tracking the current player, and keeping
a history of moves on the board.
*/
class OthelloBoard {

public:
   /*
   You can use the symbols OthelloBoard::Player::BLACK or WHITE instead of
   1 or -1.
   */
   enum Player { EMPTY = 0, BLACK = 1, WHITE = -1 };

   // Default constructor initializes the board to its starting "new game" state
   OthelloBoard();

   /*
   Fills in a vector with all possible moves on the current board state for
   the current player. The moves should be ordered based first on row, then on
   column. Example ordering: (0, 5) (0, 7) (1, 0) (2, 0) (2, 2) (7, 7)
   If no moves are possible, then a single OthelloMove representing a Pass is
   put in the vector.
   Any code that calls ApplyMove is responsible for first checking that the
   requested move is among the possible moves reported by this function.

   Precondition: the vector is empty.
   Postcondition: the vector contains all valid moves for the current player.
   */
   void GetPossibleMoves(std::vector<OthelloMove *> *list) const;

   /*
   Applies a valid move to the board, updating the board state accordingly.
   You may assume that this move is valid, and is consistent with the list
   of possible moves returned by GetAllMoves. Make sure you account for changes
   to the current player, pass count, and board value.
   */
   void ApplyMove(OthelloMove *move);

   /*
   Undoes the last move applied to the board, restoring it to the state it was
   in prior to the most recent move (including whose turn it is, what the
   board value is, and what the pass count is).
   */
   void UndoLastMove();

   /*
   Returns a pointer to a vector of all moves applied to this board. The last
   move in the vector is the most recent move applied to the board. You cannot
   modify or delete any of the pointers in this vector; they belong to the
   board. (A const vector does not allow modification of the objects returned
   by iterators. You may need to look up the const_iterator and
   const_reverse_iterator classes from vector.)
   */
   inline const std::vector<OthelloMove *>* GetMoveHistory() const {
      return &mHistory;
   }

   /*
   Returns the number of moves that have been applied to the board since the
   beginning of the game.
   */
   inline int GetMoveCount() const {
      return mHistory.size();
   }

   /*
   Creates an OthelloMove object on the heap. Whoever calls this method is
   responsible for managing the move's lifetime (or transferring that task to
   someone else.)
   */
   inline OthelloMove *CreateMove() const {
      return new OthelloMove;
   }

   // Returns the next player to move, i.e., whose turn it is.
   inline int GetNextPlayer() const {
      return mNextPlayer;
   }

   /*
   Returns the current value of the board; +1 for each Black piece, and
   -1 for each White.
   */
   inline int GetValue() const {
      return mValue;
   }

   // Returns true if the game is finished.
   inline bool IsFinished() const {
      return mPassCount == 2;
   }

   // Returns true if the row and col are in the bounds of the game board.
   inline static bool InBounds(int row, int col) {
      /* return true if row and col are in-bounds*/
   }

private:
   // OthelloView needs access to mBoard for printing
   friend class OthelloView;

   // The state of the game board, as in project 1
   char mBoard[BOARD_SIZE][BOARD_SIZE];

   // The next player to move (the next move in ApplyMove is this player's)
   char mNextPlayer;

   // A history of moves applied to the board.
   std::vector<OthelloMove *> mHistory;

   // The current value of the board. Updates after every apply/undo.
   int mValue;

   // The current pass count. Goes up by 1 for a pass, resets to 0 otherwise.
   int mPassCount;
};
#endif