#include "cpiece.h"

using namespace std;

// first, the ctor
Cpiece:: Cpiece(int col, int row, Colour colour): col(col), row(row), colour(colour){}

int Cpiece::getrow(){
    return row;
}

void Cpiece::setrow(int curr_row){
    row = curr_row;
}

int Cpiece::getcol(){
    return col;
}

void Cpiece::setcol(int curr_col){
    col = curr_col;
}

Colour Cpiece::getcolour(){
    return colour;
}

bool Cpiece::alive_or_not(){
    return alive;
}

void Cpiece::set_to_death(){
    alive = false;
}


void Cpiece::set_to_alive(){
    alive = true;
}

bool Cpiece::not_moved_ever(){
     return have_not_moved;
}
void Cpiece::set_never_moved(){
     have_not_moved = true;
}
void Cpiece::set_moved(){
    have_not_moved = false;
}

bool Cpiece::getenp(){
    return enpassant;

}
void Cpiece::set_enp_t(){
    enpassant = true;
}
void Cpiece::set_enp_f(){
    enpassant = false;   
}

// under attack by others
bool underthreat (std::vector<std::vector<Cpiece*> > &board,int col, int row){
   // check whether there exists a piece on the board that have a valid move to the king position
   

   for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){ 
            if (board[i][j]){
                if(board[i][j]->is_mv_valid (board, col, row)){
                    return true;
                }
            }
        }
    }
    return false;

 }