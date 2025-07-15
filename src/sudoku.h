//
// Created by floris on 7/15/25.
//

#ifndef SUDOKU_H
#define SUDOKU_H
#include <array>
#include <string>
#include <iostream>


class sudoku {
public:
    sudoku(std::string& s);

    int *operator[](int idx);

    bool isCorrect();

    void print();

    void place(int i);

    bool is_full();

private:
    bool isChunckCorrect(int nChunck);

    bool isVerticalCorrect(int x);

    bool isHorizontalCorrect(int y);

    constexpr static int length{9};
    constexpr static int sudoku_size{81};
    std::array<int, sudoku_size> m_value_array;
};


#endif //SUDOKU_H
