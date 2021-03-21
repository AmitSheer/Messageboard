//
// Created by amit on 16/03/2021.
//

#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <array>

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
    int lenWithHorizontal=0;
    int lenWithVertical=0;
    if(d == Direction::Horizontal){
        lenWithHorizontal=(int)horizontal+1;
        lenWithVertical=(int)(len+vertical);

    }else if(d == Direction::Vertical){
        lenWithHorizontal=(int)(horizontal+len);
        lenWithVertical=1+(int)vertical;
    }
    if(this->horizontal_start==INT32_MAX&&this->horizontal_end==-1&&this->vertical_start==INT32_MAX&&this->vertical_end==-1) {
        this->horizontal_start = horizontal;
        this->horizontal_end = lenWithHorizontal;
        this->vertical_start=vertical;
        vertical_end = lenWithVertical;
        board.insert(board.begin(),(unsigned int)horizontal_end-horizontal_start,"_");

    }else{
        if (lenWithHorizontal > horizontal_end) {
            board.insert(board.end(),  ((unsigned int)lenWithHorizontal - (unsigned int)horizontal_end), "_");
            horizontal_end = lenWithHorizontal;
        }
        if(horizontal<horizontal_start){
            board.insert(board.begin(), horizontal_start - horizontal, "_");
            this->horizontal_start=horizontal;
        }

        if (vertical < vertical_start) {
            vertical_start = vertical;
        }
        if (lenWithVertical > vertical_end) {
            this->vertical_end = lenWithVertical;
        }
    }
        for (auto ptr = board.begin(); ptr < board.end(); ptr++){
            (*ptr).resize((unsigned int)vertical_end-vertical_start,'_');
        }
}
void ariel::Board::postHorizontal(unsigned int horizontal, unsigned int vertical, const std::string& message) {
    board.at(horizontal-horizontal_start).replace(vertical-vertical_start,message.length(),message);
}

void ariel::Board::postVertical(unsigned int horizontal, unsigned int vertical, std::string message) {
    for (unsigned int i = 0; i <message.length() ; ++i) {
        board.at(horizontal-horizontal_start+i).at(vertical-vertical_start)=message[i];
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
            postHorizontal(horizontal,vertical,message);
            break;
        case Direction::Vertical:
            update_bounderys(horizontal,vertical,d,message.length());
            postVertical(horizontal,vertical,message);
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
    if(horizontal+1>horizontal_end||horizontal<horizontal_start){return str_from_board.at(0);}
    for (unsigned int i=0; i < len; ++i) {
        try{
            str_from_board.at(0).at(i)=board.at(horizontal-horizontal_start).at(vertical-vertical_start+i);
        } catch (const std::exception& e) {
        }
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
    if(vertical+1>(int)vertical_end||vertical<vertical_start){return str_from_board.at(0);}
    for (unsigned int i=0; i < len && horizontal+i<horizontal_end; ++i) {
        try {
            str_from_board.at(0).at(i) = board.at(horizontal-horizontal_start + i).at(vertical-vertical_start);
        } catch (const std::exception& e) {

        }
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
//    const std::array<char,7> special_char = {'\n','\'','\r','\a','\t','\\'};
//    const std::array<string,6> special_char_nutral = {"\n","\'","\\r","\\a","\\t"};
    for (auto & item : board) {
//        for(int i=0;i<special_char.size();++i){
//        }
//        item.replace(item.begin(), item.end(), special_char.at(0), special_char_nutral.at(0));
        std::cout << string(item) << endl;
    }
}
