#include "textdisplay.h"

Textdisplay::Textdisplay() {
	//build a new display with char
	for (int i = 0; i < 8; i++) {
		std::vector<char> v; // build a row with character
		if (i % 2 == 0) { // if the line number is even
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0){// if the column number is even
					v.emplace_back('_');
				} else { // if the column number is odd
					v.emplace_back(' ');
				}
			}
		} else { // if the line number is odd
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0){ // if the column number is even
					v.emplace_back(' ');
				} else { // if the column number is odd
					v.emplace_back('_');
				}
			}
		}
		theDisplay.emplace_back(v); // push every row into 2D vector
	}
	// textdisplay the left number row
	theDisplay.at(0).at(9)= '8';
	theDisplay.at(1).at(9)= '7';
	theDisplay.at(2).at(9)= '6';
	theDisplay.at(3).at(9)= '5';
	theDisplay.at(4).at(9)= '4';
	theDisplay.at(5).at(9)= '3';
	theDisplay.at(6).at(9)= '2';
	theDisplay.at(7).at(9)= '1';
	// textdisplay the botton character column
	theDisplay.at(9).at(7)= 'a';
	theDisplay.at(9).at(6)= 'b';
	theDisplay.at(9).at(5)= 'c';
	theDisplay.at(9).at(4)= 'd';
	theDisplay.at(9).at(3)= 'e';
	theDisplay.at(9).at(2)= 'f';
	theDisplay.at(9).at(1)= 'g';
	theDisplay.at(9).at(0)= 'h';
	// textdisplay the pieces on black
	theDisplay.at(0).at(0)= 'r';
	theDisplay.at(0).at(7)= 'r';
	theDisplay.at(0).at(1)= 'n';
	theDisplay.at(0).at(6)= 'n';
	theDisplay.at(0).at(2)= 'b';
	theDisplay.at(0).at(5)= 'b';
	theDisplay.at(0).at(3)= 'k';
	theDisplay.at(0).at(4)= 'q';
	for (int i = 0; i < 8; i++) {
		theDisplay.at(0).at(i) = 'p';
	}
	// textdisplay the pieces on white
	theDisplay.at(7).at(0)= 'R';
	theDisplay.at(7).at(7)= 'R';
	theDisplay.at(7).at(1)= 'N';
	theDisplay.at(7).at(6)= 'N';
	theDisplay.at(7).at(2)= 'B';
	theDisplay.at(7).at(5)= 'B';
	theDisplay.at(7).at(3)= 'K';
	theDisplay.at(7).at(4)= 'Q';
	for (int i = 0; i < 8; i++) {
		theDisplay.at(7).at(i) = 'P';
	}

}



void Textdisplay::notify(Subject <State> &whoNotified){

	int column = whoNotified.getState().next_column;
	int row = whoNotified.getState().next_row;
	Colour ccolour = whoNotified.getState().colour;
	int prev_c = whoNotified.getState().column;
	int prev_r = whoNotified.getState().row;
	StateType st = whoNotified.getState().type;
	std::string name = whoNotified.getState().name;

	if (st == StateType::NewPiece) { // when the piece is a newpiece
		if (name == "King"){ // when the piece is a king
			if (ccolour== Colour::White) theDisplay.at(row).at(column) = 'K'; // white king
			else theDisplay.at(row).at(column) = 'k'; //black king
		} else if(name == "Queen"){ // when the piece is a queen
			if (ccolour== Colour::White) theDisplay.at(row).at(column) = 'Q'; // white queen
			else theDisplay.at(row).at(column) = 'q'; //black queen
		} else if (name == "Bishop"){ // when the piece is a bishop
			if (ccolour== Colour::White) theDisplay.at(row).at(column) = 'B'; // white bishop
			else theDisplay.at(row).at(column) = 'b'; //black bishop
		} else if(name == "Knight"){ // when the piece is a knight
			if (ccolour== Colour::White) theDisplay.at(row).at(column) = 'N'; // white knight
			else theDisplay.at(row).at(column) = 'n'; //black knight
		} else if (name == "Rook") { // when the piece is a rook
			if (ccolour== Colour::White) theDisplay.at(row).at(column) = 'R'; // white rook
			else theDisplay.at(row).at(column) = 'r'; //black rook
		} else if(name == "Pawn") { // when the piece is a pawn
			if (ccolour== Colour::White) theDisplay.at(row).at(column) = 'P'; // white pawn
			else theDisplay.at(row).at(column) = 'p'; //black pawn
		}
	} else if(st == StateType::RemovePiece){ // when the piece is a removepiece
		// change the cell into original state
		if((row + column) % 2 == 0) { 
			theDisplay.at(row).at(column) = '_';
		} else {
			theDisplay.at(row).at(column) = ' ';
		}
	} else { // when the piece is a movepiece
		theDisplay.at(row).at(column) = theDisplay.at(prev_r).at(prev_c);
		// change the cell into original state
		if((prev_c + prev_r) % 2 == 0) {
			theDisplay.at(prev_r).at(prev_c) = '_';
		} else {
			theDisplay.at(prev_r).at(prev_c) = ' ';
		}
	}
}

std::ostream &operator<<(std::ostream &out, const Textdisplay &td) {
	for (int i = 0; i < 10 ; i++) {
		for (int j = 0; j < 10 ; j++) {
			out<< td.theDisplay.at(i).at(j); //print out the current position
		}
		out << std::endl; // change to next line
	}
	return out;
}












