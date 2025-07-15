//
// Created by floris on 7/15/25.
//

#include "search.h"


std::variant<void *, sudoku> sudoku_search_helper(sudoku &s) {
    if (s.is_full()) {
        return s;
    }
    for (int i = 1; i < 10; ++i) {
        sudoku s_copy = s;
        s_copy.place(i);
        if (s_copy.isCorrect()) {
            auto val = sudoku_search_helper(s_copy);
            if (std::holds_alternative<sudoku>(val)) {
                return std::get<sudoku>(val);
            }
        }
    }
    return nullptr;
}

sudoku sudoku_search(sudoku &s) {
    auto val = sudoku_search_helper(s);
    if (std::holds_alternative<sudoku>(val)) {
        return std::get<sudoku>(val);
    }
    throw "Sudoku solution was not found";
}
