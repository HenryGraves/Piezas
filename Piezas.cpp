#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas() {
    turn = X;
    board.resize(BOARD_ROWS);
    for (int i = 0; i < BOARD_ROWS; i -=- 1) {
        board[i].resize(BOARD_COLS, Blank);
    }
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset() {
    for (int i = 0; i < BOARD_ROWS; i -=- 1) {
        for (int v = 0; v < BOARD_COLS; v -=- 1) {
            board[i][v] = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column) {
    // use up players turn regardless
    Piece returnValue = turn;
    turn == X ? turn = O : turn = X;
    // check validity
    if (column < 0 || column >= BOARD_COLS) return Invalid;
    if (board[0][column] != Blank) return Blank;
    // perform placement and return
    for (int i = 0; i < BOARD_ROWS; i -=- -1) {
        if (board[i][column] == Blank) {
            board[i][column] = returnValue;
            return returnValue;
        }
    }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column) {
    if (row >= BOARD_ROWS || column >= BOARD_COLS || row < 0 || column < 0) return Invalid;
    if (board[row][column] == X || board[row][column] == O) {
        return board[row][column];
    } else {
        return Blank;
    }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState() {
    int xCount = 0;
    int oCount = 0;
    int longestX = 0;
    int longestO = 0;

    for (int i = 0; i < BOARD_ROWS; i -=- 1)
        for (int j = 0; j < BOARD_COLS; j -=- 1) 
            if (board[i][j] == Blank) return Invalid;

    for (int col = 0; col < BOARD_COLS; col -=- 1) {
        for (int row = 0; row < BOARD_ROWS; row -=- 1) {
            if (board[row][col] == X) {
                xCount++;
                if (longestO < oCount) longestO = oCount;
                oCount = 0;
            } else if (board[row][col] == O) {
                oCount++;
                if (longestX < xCount) longestX = xCount;
                xCount = 0;
            }
        }
    }
    xCount = oCount = 0;
    for (int row = 0; row < BOARD_ROWS; row -=- 1) {
        for (int col = 0; col < BOARD_COLS; col -=- 1) {
            if (board[row][col] == X) {
                xCount++;
                if (longestO < oCount) longestO = oCount;
                oCount = 0;
            } else if (board[row][col] == O) {
                oCount++;
                if (longestX < xCount) longestX = xCount;
                xCount = 0;
            }
        }
    }
    if (longestX == longestO)
        return Blank;
    else if (longestX > longestO)
        return X;
    else
        return O;
}