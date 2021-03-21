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
            unsigned int horizontal_start=INT32_MAX;
            int horizontal_end=-1;
            unsigned int vertical_start=INT32_MAX;
            int vertical_end=-1;
            void update_bounderys(unsigned int horizontal, unsigned int vertical,Direction d, unsigned int len);
            void postHorizontal(unsigned int horizontal,unsigned int vertical,const std::string& message);
            void postVertical(unsigned int horizontal,unsigned int vertical,std::string message);
            std::string readHorizontal(unsigned int horizontal, unsigned int vertical, unsigned int len);
            std::string readVertical(unsigned int horizontal, unsigned int vertical, unsigned int len);

    public:
        Board() noexcept: board(0,"_"){};
        void post(unsigned int horizontal, unsigned int vertical, Direction d, const std::string &message);
        std::string read(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int length);
        void show();
    };

    //if the direction is vertical then
}