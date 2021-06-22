#include "pawn.h"

using namespace std;


Pawn:: Pawn(int col, int row, Colour colour): Cpiece(col,row,colour){}

string Pawn::get_chess_type(){
    return namepiece;
}

int Pawn::getability(){
    return ability;
}

bool Pawn::is_mv_valid(std::vector<std::vector<Cpiece*> > &board, int d_col, int d_row){
    if ((d_col >= 8) || (d_row >= 8)) return false; 
    if ((d_col < 0) || (d_row < 0)) return false; //really need?

    int curr_col = this->getcol();
    int curr_row = this->getrow();

    // move one step forward
    if ((d_col == curr_col)&&(d_row + 1 == curr_row)) return true;

    // pawn capturing move
    if (((d_col + 1 == curr_col) && (d_row + 1 == curr_row)) || ((d_col - 1 == curr_col) && (d_row + 1 == curr_row))) {
        if (board[d_row][d_col]){
            if (this->getcolour() != board[d_row][d_col]->getcolour()){
                return true;
            }
        }
    }

    // first move

    if (this->not_moved_ever()){
        if ((d_col == curr_col)&&(d_row + 2 == curr_row)) {
            return true;
        }
    }

    // enpassant
    if (d_row == 2){
        if (board[d_row + 1][d_col]){
            if (this->getcolour() != board[d_row][d_col]->getcolour()){
                if (this->getenp()){
                    return true;
                }
            }
        }
    }

    if (d_row ==5){
         if (board[d_row - 1][d_col]){
            if (this->getcolour() != board[d_row][d_col]->getcolour()){
                if (this->getenp()){
                    return true;
                }
            }
        }       

    }
    return false;

}





vector<Position> Pawn:: valid_mv (std::vector<std::vector<Cpiece*> > &board, Colour colour){
    // construct a vector containing possible positions
    vector<Position> possible_pos;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(is_mv_valid (board, i, j)){
                Position tmp = Position(i,j);
                possible_pos.emplace_back(tmp);
            }
        }
    }
}
