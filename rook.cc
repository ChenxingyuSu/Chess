#include "rook.h"
#include <vector>

using namespace std;

Rook::Rook(int c, int r, Colour colour): Cpiece(c,r,colour){}

string Rook::get_chess_type(){
    return namepiece;
}

int Rook::getability(){
    return ability;
}

// check whether the move instruction is valid for ROOK 
bool Rook::is_mv_valid(std::vector<std::vector<Cpiece*> > & board, int d_col, int d_row){
    // check whether it exceeds the board
    if ((d_col >= 8) || (d_row >= 8)) return false;
    if ((d_col < 0) || (d_row < 0)) return false;

    int curr_col = this->getcol();
    int curr_row = this->getrow();
    // first check whether it is not in the vertical or horinzontal direction
    if ((curr_col != d_col) && (curr_row != d_row)) return false;
    // then check whether it is not in the same place
    if ((curr_col == d_col) && (curr_row == d_row)) return false;
    // check if there has any block between two coords

    // move front
    if ((curr_col == d_col) && (curr_row > d_row)) {
        for(int i = curr_row - 1; i > d_row; i--){
            if (!board[i][d_col]){ // do not have piece
                continue;
            }
            else{
                return false;
            }
        }
        if (board[d_row][d_col]){
            if (this->getcolour() == board[d_row][d_col]->getcolour()){
                return false;
            }
        }
        return true;
    }

    // move back
    else if ((curr_col == d_col) && (curr_row < d_row)) {
       for (int i = curr_row + 1; i < d_row; i++){
           if (!board[i][d_col]){ // do not have piece
                continue;
            }
            else{
                return false;
            }
       }
       if (board[d_row][d_col]){
            if (this->getcolour() == board[d_row][d_col]->getcolour()){
                return false;
            }
        }
        return true;
    }

    // move left
    else if ((curr_row == d_row) && (curr_col > d_col)) {
        for (int i = curr_col - 1; i > d_row; i--){
            if(!board[d_row][i]){
                continue;
            }
            else{
                return false;
            }
        }
        if (board[d_row][d_col]){
            if (this->getcolour() == board[d_row][d_col]->getcolour()){
                return false;
            }
        }
        return true;
    }
    // move right
    else{
        for(int i = curr_col + 1; i < d_row; i++){
            if(!board[d_row][i]){
                continue;
            }
            else{
                return false;
            }
        }
        if (board[d_row][d_col]){
            if (this->getcolour() == board[d_row][d_col]->getcolour()){
                return false;
            }
        }
        return true;
    }

}


vector<Position> Rook:: valid_mv (std::vector<std::vector<Cpiece*> > & board, Colour colour){
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
