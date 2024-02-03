/*
Dylan Deokinandan
PROJECT 6
MAY 2, 2023

THIS IS THE IMPLEMENTATION OF SUDOKU SOLVER
THE PUZZLE GETS SOLVED (OR NOT SOLVED) WITH 
EACH CALL OF A PARAMTERIZED CONSTRUCTOR. THIS CONSTRUCTOR 
UTILIZES HELPER FUNCTIONS THAT USE RECURSION AND BACKTRACKING
 TO INPUT A POSSIBLE SOLUTION TO THE PUZZLE
*/
#include "SudokuSolver.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

SudokuSolver::SudokuSolver()
{
    puzzle_numbers_=new int*[9];
    //creates rows
    for(int i=0; i<9; i++)
    {
        puzzle_numbers_[i]=new int[9];
        //creates columns
        for(int j=0; j<9; j++)
        {
            //sets each cell equal to 0
            puzzle_numbers_[i][j]=0;
        }
    }
    is_solvable_=false;
}

SudokuSolver::SudokuSolver(std::string input_file)
{
    std::ifstream input;
    input.open(input_file);
    puzzle_numbers_ = new int*[9];

    int i=0;
    while(input.good())
    {
        std::string row;
        while(getline(input,row))
        {
            std::string column;
            std::stringstream ss(row);//reads in each row

            puzzle_numbers_[i] = new int[9];
            //goes through columns
            for(int j=0; j<8; j++)
            {
                std::getline(ss,column,',');
                puzzle_numbers_[i][j]=stoi(column);//asigns cell to the input value
            }
            std::getline(ss,column);
            puzzle_numbers_[i][8]=stoi(column);
            i++;
        }
    }
    
    if(solver())
    {
        setSolvable();
    }
    else
    {
        is_solvable_=false;
    }
}

bool SudokuSolver::isPuzzleSolvable()
{
    return is_solvable_;
}

void SudokuSolver::setSolvable()
{
    is_solvable_=true;
}

int** SudokuSolver::getPuzzleNumbers()
{
    return puzzle_numbers_;
}

void SudokuSolver::setPuzzleNumbers(int** puzzle)
{
    puzzle_numbers_=puzzle;
}

Sudoku::Location SudokuSolver::returnNextEmpty() const
{
    Sudoku::Location cell;
    cell.row=-1;
    cell.col=-1;

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(puzzle_numbers_[i][j]==0)
            {
            cell.row=i;
            cell.col=j;
            return cell;
            }
        }
    }
    return cell;
}

bool SudokuSolver::checkLegalValue(int value, Sudoku::Location location)
{
    for(int i=0; i<9; i++)
    {
        if(puzzle_numbers_[location.row][i]==value)
        {
            return false;
        }
    }

    for(int j=0; j<9; j++)
    {
        if(puzzle_numbers_[j][location.col]==value)
        {
            return false;
        }
    }

    int row_start=floor(location.row/3)*3;//gets the mini 3x3 grid start_row
    int column_start=floor(location.col/3)*3;//gets the mini 3x3 grid start_column

    //loops through mini 3x3 and checks if the given value is legal to play
    for(int i=row_start; i<row_start+3; i++)
    {
        for(int j=column_start; j<column_start+3; j++)
        {
            if(puzzle_numbers_[i][j]==value)
            {
                return false;
            }
        }
    }
    return true;//if it reaches here, then we know the value is legal
}

void SudokuSolver::display()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if((j==3) || (j==6))//separates the board vertically for every 3rd column
            {
                std::cout<<" | ";
                print_X(puzzle_numbers_[i][j]);
                std::cout<<" ";
            }
            else if(j==8)
            {
                if(i==2||i==5)
                {
                    print_X(puzzle_numbers_[i][j]);
                    std::cout<<std::endl<<"- - - - - - - - - - - -";
                }
                else
                {
                    print_X(puzzle_numbers_[i][j]);
                }
            }
            else
            {
                print_X(puzzle_numbers_[i][j]);
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

void SudokuSolver::print_X(int num)
{
    if(num==0)
    {
        std::cout<<"X";
    }
    else
    {
        std::cout<<num;
    }
}

bool SudokuSolver::solver()
{
    Sudoku::Location cell=returnNextEmpty();

    if((cell.row == -1) && (cell.col == -1))
    {
        return true;
    }

    for(int i=1; i<=9; i++)
    {
        if(checkLegalValue(i,cell))
        {
            puzzle_numbers_[cell.row][cell.col]=i;
            if(solver())
            {
                return true;
            }
        }
    }
    puzzle_numbers_[cell.row][cell.col]=0;
    return false;//if no numbers were valid, the puzzle cannot be solved
}