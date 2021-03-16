//
// Created by amit on 16/03/2021.
//

#include "doctest.h"
#include <string>
#include <vector>
using namespace std;
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;
TEST_CASE("adding new message to board"){
    SUBCASE("adding message to empty board horizontal"){
        Board board;
        board.post(0,0,Direction::Horizontal,"hello");
        CHECK(board.read(0,0,Direction::Horizontal,5)==string("hello"));
    }
    SUBCASE("adding message to empty board vertical"){
        Board board;
        board.post(0,0,Direction::Vertical,"hello");
                CHECK(board.read(0,0,Direction::Vertical,5)==string("hello"));
    }
    SUBCASE("adding message to empty board"){
        Board board;
        board.post(0,0,Direction::Horizontal,"hello");
                CHECK(board.read(0,0,Direction::Horizontal,5)==string("hello"));
    }

}