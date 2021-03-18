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

/**
 * updates the dimensions of the board
 * @param horizontal
 * @param vertical
 * @param d - direction
 * @param len - length of the word
 */
void ariel::Board::update_bounderys(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int len) {
    unsigned int lenWithHorizontal=0;
    unsigned int lenWithVertical=0;
    if(d == Direction::Horizontal){
        lenWithHorizontal=horizontal+1;
        lenWithVertical=len+vertical;
    }else if(d == Direction::Vertical){
        lenWithHorizontal=horizontal+len;
        lenWithVertical=1+vertical;
    }
    if (lenWithHorizontal > horizontal_end) {
        horizontal_end = lenWithHorizontal;
    }
    if (horizontal < horizontal_start) {
        horizontal_start = horizontal;
    }
    if (lenWithVertical > vertical_end) {
        vertical_end = lenWithVertical;
    }
    if (vertical < vertical_start) {
        vertical_start = vertical;
    }
    board.resize(horizontal_end,"_");
    for (auto ptr = board.begin(); ptr < board.end(); ptr++){
        (*ptr).resize(vertical_end,'_');
    }

}

/**
 * write new text on the board
 * over writes existing text
 * @param horizontal
 * @param vertical
 * @param d
 * @param message - message to write
 */
void ariel::Board::post(unsigned int horizontal, unsigned int vertical, Direction d, const std::string &message){
    switch (d) {
        case Direction::Horizontal:
            update_bounderys(horizontal,vertical,d,message.length());
            board.at(horizontal).replace(vertical,message.length(),message);
            break;
        case Direction::Vertical:
            update_bounderys(horizontal,vertical,d,message.length());
            for (unsigned int i = 0; i <message.length() ; ++i) {
                board.at(horizontal+i).at(vertical)=message[i];
            }
            break;
        default:
            throw std::out_of_range("invalid Direction type");
    }
}

/**
 * reads the text in the horizontal direction
 * @param horizontal
 * @param vertical
 * @param len - of the word to read
 * @return the text in that location
 */
std::string ariel::Board::readHorizontal(unsigned int horizontal, unsigned int vertical, unsigned int len) {
    vector<string> str_from_board(1,"_");
    str_from_board.at(0).resize(len,'_');
    if(horizontal+1>(int)horizontal_end){return str_from_board.at(0);}
    for (unsigned int i=0; i < len && i+vertical<vertical_end; ++i) {
        str_from_board.at(0).at(i)=board.at(horizontal).at(vertical+i);
    }
    return str_from_board.at(0);
}
/**
 * read in the vertical direction of the board
 * @param horizontal
 * @param vertical
 * @param len of the word to read
 * @return the text in that location
 */
std::string ariel::Board::readVertical(unsigned int horizontal, unsigned int vertical, unsigned int len) {
    vector<string> str_from_board(1,"_");
    str_from_board.at(0).resize(len,'_');
    if(vertical+1>(int)vertical_end){return str_from_board.at(0);}
    for (unsigned int i=0; i < len && i+horizontal<horizontal_end; ++i) {
        str_from_board.at(0).at(i)=board.at(horizontal+i).at(vertical);
    }
    return str_from_board.at(0);
}
/**
 * calls the read function of each direction
 * @param horizontal
 * @param vertical
 * @param d
 * @param length
 * @return the text found in the coordination's, direction and length inputted by the user
 */
std::string ariel::Board::read(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int length) {
    switch (d) {
        case Direction::Horizontal:
            return readHorizontal(horizontal,vertical,length);
        case Direction::Vertical:
            return readVertical(horizontal,vertical,length);
        default:
            throw std::out_of_range("invalid Direction type");
    }
}

void ariel::Board::show() {
    for (unsigned int i = horizontal_start; i < horizontal_end; ++i) {
        std::cout << string(board.at(i).substr(vertical_start,vertical_end-vertical_start)) << endl;
    }
}
