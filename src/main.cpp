#include <iostream>

#include "search.h"
#include "sudoku.h"

int main() {
    std::string sudoku_code;
    std::cout << "Paste your sudoku-code: ";
    std::cin >> sudoku_code;
    sudoku sk{sudoku_code};
    std::cout << "searching...\n";
    sudoku_search(sk).print();
    return 0;
}
