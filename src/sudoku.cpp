//
// Created by floris on 7/15/25.
//

#include "sudoku.h"

#include <cassert>

sudoku::sudoku(std::string& s) {
    assert(s.size() == sudoku_size);
    for (int i = 0; i < sudoku_size; ++i) {
        const int value{s[i] - '0'};
        m_value_array[i] = value;
    }
}

int *sudoku::operator[](int idx) {
    return m_value_array.begin() + idx * length;
}

bool sudoku::isHorizontalCorrect(int y) {
    std::array<bool, length + 1> seen;
    seen.fill(false);
    for (int i = 0; i < length; ++i) {
        const int valAt{(*this)[y][i]};
        if (valAt == 0) {
            continue;
        }
        if (seen[valAt]) {
            return false;
        }
        seen[valAt] = true;
    }
    return true;
}

bool sudoku::isVerticalCorrect(int x) {
    std::array<bool, length + 1> seen;
    seen.fill(false);
    for (int i = 0; i < length; ++i) {
        const int valAt{(*this)[i][x]};
        if (valAt == 0) {
            continue;
        }
        if (seen[valAt]) {
            return false;
        }
        seen[valAt] = true;
    }
    return true;
}

bool sudoku::isChunckCorrect(int nChunck) {
    const int offset_y{(nChunck / 3) * length / 3};
    const int offset_x{(nChunck % 3) * length / 3};
    std::array<bool, length + 1> seen;
    seen.fill(false);

    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            const int valAt{(*this)[offset_y + y][offset_x + x]};
            if (valAt == 0) {
                continue;
            }
            if (seen[valAt]) {
                return false;
            }
            seen[valAt] = true;
        }
    }
    return true;
}

bool sudoku::isCorrect() {
    for (int i = 0; i < length; ++i) {
        if (!this->isChunckCorrect(i)) {
            return false;
        }
    }
    for (int i = 0; i < length; ++i) {
        if (!this->isHorizontalCorrect(i)) {
            return false;
        }
    }
    for (int i = 0; i < length; ++i) {
        if (!this->isVerticalCorrect(i)) {
            return false;
        }
    }
    return true;
}

void sudoku::print() {
    std::cout << "\n---------------------\n";
    for (int y = 0; y < length; ++y) {
        for (int x = 0; x < length; ++x) {
            std::cout << (*this)[y][x] << ' ';
            if ((x + 1) % 3 == 0) {
                std::cout << "|";
            }
        }
        if ((y + 1) % 3 == 0) {
            std::cout << "\n---------------------";
        }
        std::cout << '\n';
    }
}

void sudoku::place(int val) {
    for (int i = 0; i < sudoku_size; ++i) {
        if (m_value_array[i] == 0) {
            m_value_array[i] = val;
            return;
        }
    }
    throw;
}

bool sudoku::is_full() {
    for (int i = 0; i < sudoku_size; ++i) {
        if (m_value_array[i] == 0) {
            return false;
        }
    }
    return true;
}
