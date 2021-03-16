//
// Created by amit on 16/03/2021.
//
#pragma once
#include <vector>
#include <string>
#include "Direction.hpp"
namespace ariel{
    class Board{
    private:
            std::vector<std::string> board;
            int horizontal_start;
            int horizontal_end;
            int vertical_start;
            int vertical_end;
    public:
        Board() noexcept: board(0,"_"){};
        void post(unsigned int horizontal, unsigned int vertical, Direction d, std::string message);
        std::string read(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int length);
        void show();
    };
//    Board::Board() noexcept:board(0,"_") {};
}