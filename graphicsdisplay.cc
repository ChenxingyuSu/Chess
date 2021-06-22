#include "graphicsdisplay.h"



Graphicsdisplay::Graphicsdisplay(){
	int cellnum = 8;
	int totalwid = 100; // initialize 100 width totally
	int size = totalwid / (cellnum + 2);

	for (int i = 0; i < totalwid; i++) {
		for (int j = 0; j < totalwid; j++) {
			if ((i + j) % 2 == 0){ //if the sum of row and column is even
				xw.fillRectangle(i, j, size, size, Xwindow::Green);
			} else { // if the sum of the row and column is odd
				xw.fillRectangle(i, j, size, size, Xwindow::Blue);
			}
		}
	}
	// graphicsdisplay the left number row
	xw.drawString(0, totalwid,"8", Xwindow::Black);
	xw.drawString(size, totalwid,"7", Xwindow::Black);
	xw.drawString(size * 2, totalwid,"6", Xwindow::Black);
	xw.drawString(size * 3, totalwid,"5", Xwindow::Black);
	xw.drawString(size * 4, totalwid,"4", Xwindow::Black);
	xw.drawString(size * 5, totalwid,"3", Xwindow::Black);
	xw.drawString(size * 6, totalwid,"2", Xwindow::Black);
	xw.drawString(size * 7, totalwid,"1", Xwindow::Black);

	//graphicsdisplay the bottom character column
	xw.drawString(totalwid - size, size * 8,"a", Xwindow::Black);
	xw.drawString(totalwid - size, size * 7,"b", Xwindow::Black);
	xw.drawString(totalwid - size, size * 6,"c", Xwindow::Black);
	xw.drawString(totalwid - size, size * 5,"d", Xwindow::Black);
	xw.drawString(totalwid - size, size * 4,"e", Xwindow::Black);
	xw.drawString(totalwid - size, size * 3,"f", Xwindow::Black);
	xw.drawString(totalwid - size, size * 2,"g", Xwindow::Black);
	xw.drawString(totalwid - size, size,"h", Xwindow::Black);
}



Graphicsdisplay::notify(Subject <State> &whoNotified){
	int cellnum = 8;
	int totalwid = 100;
	int size = totalwid / (cellnum + 2);

	int column = whoNotified.getState().next_column;
	int row = whoNotified.getState().next_row;
	Colour ccolour = whoNotified.getState().colour;
	int prev_c = whoNotified.getState().column;
	int prev_r = whoNotified.getState().row;
	Statetype st = whoNotified.getState().type;
	string namespace = whoNotified.getState().name;

	string signal;

	if (namespace == "King"){ // when the piece is a king
		if (ccolour == Colour::Black) signal = "k"; //black king
		else signal = "K"; // white king
	} else if(namespace == "Queen") { //when the piece is a queen
		if (ccolour == Colour::Black) signal = "q"; //black queen 
		else signal = "Q"; // white queen
	} else if(namespace == "Bishop"){ // when the piece is a bishop
		if (ccolour == Colour::Black) signal = "b"; // black bishop
		else signal = "B"; // white bishop
	} else if (namespace == "Knight"){ // when the piece is a knight
		if (ccolour == Colour::Black) signal = "n"; // black knight
		else signal = "N";// white knight
	} else if (namespace == "Rook"){ // when the piece is a rook
		if (ccolour == Colour::Black) signal = "r";// black rook
		else signal = "R";// white rook
	} else if (namespace == "Pawn"){// when the piece is a pawn
		if (ccolour == Colour::Black) signal = "p";// black pawn
		else signal = "P";// white pawn
	}

	if (st == Statetype::Newpiece){// if the statetype is a Newpiece
		xw.drawString(column * size, row * size, signal, Xwindow::Black);
	} else if (st == Statetype::Removepiece){ // if the statetype is a Removepiece
		if ((column + row) % 2 == 0){ // if the sum of the row and column is even
			xw.fillRectangle(column * size, row * size, size, size, Xwindow::Green);
		} else {	// if the sum of the row and column is odd
			xw.fillRectangle(column * size, row * size, size, size, Xwindow::Blue);
		}
	} else { // if the statetype is a Movepiece
		if ((prev_r + prev_c) % 2 == 0){ // if the sum of previous row and column is even
			xw.fillRectangle(prev_c * size, prev_r * size, size, size, Xwindow::Green);
		} else {	// if the sum of previous row and column is odd
			xw.fillRectangle(prev_c * size, prev_r * size, size, size, Xwindow::Blue);
		}

		xw.drawString(column * size, row * size, signal, Xwindow::Black);
	}

}
