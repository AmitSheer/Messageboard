/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

	ariel::Board board;
	board.post(/*row=*/1, /*column=*/2, Direction::Horizontal, "abcd");
	cout << board.read(/*row=*/0, /*column=*/3, Direction::Vertical, /*length=*/3) << endl;
		// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	board.post(/*row=*/0, /*column=*/4, Direction::Vertical, "xyz");
	cout << board.read(/*row=*/1, /*column=*/2, Direction::Horizontal, /*length=*/6) << endl;
		// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

//    board.post(/*row=*/0, /*column=*/4, Direction::Horizontal, "xy\ndsdfsdf");
//	cout << board.read(/*row=*/0, /*column=*/4, Direction::Horizontal, /*length=*/11) << endl;
    board.show(); // shows the board in a reasonable way. For example:
//		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________
}

