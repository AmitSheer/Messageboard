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
        Board(){}
        void post(int horizontal, int vertical, Direction d, std::string message);
        std::string read(int horizontal, int vertical, Direction d, int length);
        void show();
    };
}