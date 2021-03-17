//
// Created by amit on 16/03/2021.
//

#include <string>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

void ariel::Board::update_bounderys(unsigned int horizontal, unsigned int vertical) {
    if (horizontal > horizontal_end) {
        horizontal_end = horizontal;
    }
    if (horizontal < horizontal_start) {
        horizontal_start = horizontal;
    }
    if (vertical > vertical_end) {
        vertical_end = vertical;
    }
    if (vertical < vertical_start) {
        vertical_start = vertical;
    }
    board.resize(horizontal_end,"_");
    for (auto ptr = board.begin(); ptr < board.end(); ptr++){
        (*ptr).resize(vertical_end,'_');
    }

}


void ariel::Board::post(unsigned int horizontal, unsigned int vertical, Direction d, const std::string &message){
    unsigned int lenWithStartingPointHorizontal = message.length()+horizontal;
    unsigned int lenWithStartingPointVertical = message.length()+vertical;
    switch (d) {
        case Direction::Horizontal:
            update_bounderys(horizontal+1,lenWithStartingPointVertical);
            board.at(horizontal).replace(vertical,message.length(),message);
            break;
        case Direction::Vertical:
            update_bounderys(lenWithStartingPointHorizontal,vertical+1);
            for (unsigned int i = 0; i <message.length() ; ++i) {
                board.at(horizontal+i).at(vertical)=message[i];
            }
            break;
    }
}


std::string ariel::Board::readHorizontal(unsigned int horizontal, unsigned int vertical, unsigned int len) {
    /**
     * read from specific row
     */
    vector<string> str_from_board(1,"_");
    str_from_board.at(0).resize(len,'_');
    if(horizontal+1>(int)horizontal_end){return str_from_board.at(0);}
    for (unsigned int i=0; i < len && i+vertical<vertical_end; ++i) {
        str_from_board.at(0).at(i)=board.at(horizontal).at(vertical+i);
    }
    return str_from_board.at(0);
}
std::string ariel::Board::readVertical(unsigned int horizontal, unsigned int vertical, unsigned int len) {
    vector<string> str_from_board(1,"_");
    str_from_board.at(0).resize(len,'_');
    if(vertical+1>(int)vertical_end){return str_from_board.at(0);}
    for (unsigned int i=0; i < len && i+horizontal<horizontal_end; ++i) {
        str_from_board.at(0).at(i)=board.at(horizontal+i).at(vertical);
    }
    return str_from_board.at(0);
}
std::string ariel::Board::read(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int length) {
    switch (d) {
        case Direction::Horizontal:
            return readHorizontal(horizontal,vertical,length);
        case Direction::Vertical:
            return readVertical(horizontal,vertical,length);
        default:
            //TODO: add test for invalid Direction type
            throw std::out_of_range("invalid Direction type");
    }
}

void ariel::Board::show() {
    for (unsigned int i = horizontal_start; i < horizontal_end; ++i) {
        std::cout << board.at(i).substr(vertical_start,vertical_end-vertical_start-1).data() << endl;
    }
}
