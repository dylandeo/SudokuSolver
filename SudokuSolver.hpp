/*
DYLAN DEOKINANDAN
PROJECT 6
MAY 2, 2023

THIS IS THE HEADER FILE FOR SudokuSolver
IT INCLUDES THE SUDOKU NAMESPACE WITH A STRUCT LOCATION
IT ALSO GIVES ALL PRIVATE AND PUBLIC DATA MEMBERS OF THE CLASS SudokuSolver
*/
#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_
#include <string>


//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
namespace Sudoku
{ 
  struct Location
  {
    int row=0;
    int col=0;
  };
}

class SudokuSolver
{
public:

//Add your public members here
/**
 * the default constructor initializes an emtpy board, that is, a board filled with zeros 
 * (an array of 9 arrays, each filled with 9 zeros). This board will be marked unsolvable.  
*/
SudokuSolver();

/**
 * the parameterized constructor reads the input file to initialize the board. 
 * The input files consist of 9 digits on each row separated by commas, and 9 rows separated 
 * by new line characters \n, corresponding to a sudoku board.
 * Empty squares contain the digit 0. After reading the puzzle, the constructor tries to solve
 * it and records whether the puzzle has a solution or not.
*/
SudokuSolver(std::string input_file);

/**
 * isPuzzleSolvable() returns true if the puzzle is solvable, false otherwise.
 * We suggest you keep track of this when solving the problem at construction, rather than solving 
 * the puzzle again each time this function is called.
*/
bool isPuzzleSolvable();

/**
 * records the puzzle as being solvable.
*/
void setSolvable();

/**
 * returns the  2D pointer array representing the puzzle
*/
int** getPuzzleNumbers();

/*
sets the  2D pointer array representing the puzzle to the value of the parameter 
*/
void setPuzzleNumbers(int** puzzle);

/*
returns a Location object with the coordinates of the first 0 found in the 2D pointer array, 
meaning that it is an empty square in the sudoku board. To find the first empty square you must read 
the 2D array from top-left (0,0) to bottom right (8,8), one row at a time. Set the row and col of the Location 
to the indices at which the first 0 is found in the 2D array.
If there are no empty squares the Location object should have row and col values of -1.
*/
Sudoku::Location returnNextEmpty() const;

/**
 * returns true if the value parameter (which can take on values 1-9) can legally be placed at the given location in the 
 * 2D array without breaking the rules of sudoku. It returns false if placing value at location is not a legal move. 
 * Remember, in order to be a valid move, the value must be unique with a row, column, and sub-grid.
*/
bool checkLegalValue(int value, Sudoku::Location location);

/*
will display the board
*/
void display();

/**
 * Prints X if a number is 0, prints the number ohterwise
*/
void print_X(int num);

/*
recursively solves the puzzle
*/
bool solver();

private:
//Add your private members here
bool is_solvable_;//says if puzzle is solvable
int** puzzle_numbers_;//the numbers of the grid






};

#endif