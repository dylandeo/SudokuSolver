#include "SudokuSolver.hpp"
#include <iostream>

int main()
{
    SudokuSolver test=SudokuSolver("puzzle1.csv");
    test.display();
    std::cout<<test.isPuzzleSolvable()<<std::endl<<std::endl;


    SudokuSolver test2=SudokuSolver("impossible.csv");
    test2.display();
    std::cout<<test2.isPuzzleSolvable()<<std::endl<<std::endl;

    SudokuSolver test3=SudokuSolver("test.csv");
    test3.display();
    std::cout<<test3.isPuzzleSolvable()<<std::endl<<std::endl;

    SudokuSolver default_grid=SudokuSolver();
    default_grid.display();
    std::cout<<default_grid.isPuzzleSolvable()<<std::endl<<std::endl;

    return 0;
}