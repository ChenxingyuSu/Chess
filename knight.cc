#include "knight.h"
#include <vector>
#include <math.h>

using namespace std;

Knight:: Knight(int col, int row, Colour colour): Cpiece(col,row,colour){}

string Knight::get_chess_type(){
    return namepiece;
}

int Knight::getability(){
    return ability;
}

bool Knight::is_mv_valid(std::vector<std::vector<Cpiece*> > &board, int d_col, int d_row){
    // check whether it exceeds the board
    if ((d_col >= 8) || (d_row >= 8)) return false;
    if ((d_col < 0) || (d_row < 0)) return false;

    int curr_col = this->getcol();
    int curr_row = this->getrow();

    if(((abs(d_col - curr_col) == 1) && (abs(d_row - curr_row) == 2)) ||((abs(d_col - curr_col) == 2) && (abs(d_row - curr_row) == 1))){
        if (board[d_row][d_col]){
            if (this->getcolour() == board[d_row][d_col]->getcolour()){
                return false;
            }
        }
        return true;

    }
    else return false;

}


vector<Position> Knight:: valid_mv (std::vector<std::vector<Cpiece*> > &board, Colour colour){
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

