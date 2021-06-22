#include "king.h"
#include <math.h>
#include <vector>

using namespace std;

King:: King(int col, int row, Colour colour): Cpiece(col,row,colour){}



string King::get_chess_type(){
    return namepiece;
}

int King::getability(){
    return ability;
}

bool King::is_mv_valid(std::vector<std::vector<Cpiece*> > & board, int d_col, int d_row){
    if ((d_col >= 8) || (d_row >= 8)) return false; 
    if ((d_col < 0) || (d_row < 0)) return false; //really need?

    int curr_col = this->getcol();
    int curr_row = this->getrow();

    // move one square in any direction && no same colour

    // CASE TOP
    if ((d_row - curr_row == -1) && ((d_col == curr_col + 1) || (d_col == curr_col - 1) || (d_col == curr_col))){
        if (board[d_row][d_col]){ // have piece
            if (this->getcolour() == board[d_row][d_col]->getcolour()){ // same colour
                return false;
            }
        }
        else return true;
    }

    // CASE MIDDLE
    if ((d_row - curr_row == 0) && ((d_col == curr_col + 1) || (d_col == curr_col - 1))){
        if (board[d_row][d_col]){ // have piece
            if (this->getcolour() == board[d_row][d_col]->getcolour()){ // same colour
                return false;
            }
        }
        else return true;
    }    

    // CASE BELOW
    if ((d_row - curr_row == 1) && ((d_col == curr_col + 1) || (d_col == curr_col - 1) || (d_col == curr_col))){
        if (board[d_row][d_col]){ // have piece
            if (this->getcolour() == board[d_row][d_col]->getcolour()){ // same colour
                return false;
            }
        }
        else return true;
    }    

    // CASTLING (Two Sides may happens)
    
    if (this->not_moved_ever()) {
        if (d_row == curr_row) {
            if (d_col == 1) {
                if(board[d_row][0]){
                    if(board[d_row][0]->not_moved_ever()){
                        if(!(underthreat(board,curr_col,curr_row) || underthreat(board,d_col,d_row) 
                        || underthreat(board,(curr_col + d_col)/2,curr_row) || underthreat(board,0,curr_row))){
                            if(board[d_row][1] == nullptr && board[d_row][2] == nullptr){
                                return true;
                            }
                        }
                    }
                }
            }else if (d_col == 5){
                if(board[d_row][7]){
                    if(board[d_row][7]->not_moved_ever()){
                        if(!(underthreat(board,curr_col,curr_row) || underthreat(board,d_col,d_row) 
                        || underthreat(board,(curr_col + d_col)/2,curr_row) || underthreat(board,7,curr_row))){
                            if(board[d_row][6] == nullptr && board[d_row][5] == nullptr && board[d_row][4] == nullptr){
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    
}




vector<Position> King:: valid_mv (std::vector<std::vector<Cpiece*> > &board, Colour colour){
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
