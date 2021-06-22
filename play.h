#ifndef PLAY_H
#define PLAY_H
#include <iostream>
#include <vector>
#include <memory>
#include <cstddef>
#include "cpiece.h"
#include "state.h"
#include "king.h"
#include "subject.h"
#include "observer.h"


class Textdisplay;
class Graphicsdisplay;

class Play: public Subject<State> { // need to add inher relationship
    Cpiece* whiteKing = nullptr;
    Cpiece* blackKing = nullptr;
    std::vector<std::vector<Cpiece*> > theBoard;  // The actual board.
    std::unique_ptr<Textdisplay> td; // The text display.
    std::unique_ptr<Graphicsdisplay> gd; // The text display. *Edit needed
    std::vector<std::shared_ptr<Cpiece> > whitePieces;//White's pieces
    std::vector<std::shared_ptr<Cpiece> > blackPieces;//Black's pieces

public:
    Play();
    ~Play();

    void init(); 
    void boardSet();
    void clearBoard();

    void pieceSet(int col, int row, std::string name, Colour colour); 

    bool kingBlack_alive();
    bool kingWhite_alive();
    //check if white king is under attack
    bool attackWhite();
    //check if black king is under attack
    bool attackBlack();

    //check if white player has a valid move in the next play
    // method is used to check checkmate and stalemate
    bool checkmateWhite();

    //check if black player has a valid move in the next play
    // method is used to check checkmate and stalemate
    bool checkmateBlack();

    // bool expose_king(int c_orig,int r_orig,int c_dest,int r_dest,Colour colour);
    // *Edit needed
    bool isBlocked(int currCol, int currRow, int colDest, int rowDest);
    void pieceMove(int currCol,int currRow,int colDest,int rowDest);
    void pieceRemove(int col, int row);

    void checkStatus(Colour colour);

    void randomMode(Colour colour);
    void attackMode(Colour colour);
    void defendMode(Colour colour);
    void smartMode(Colour colour);

    friend std::ostream &operator<<(std::ostream &out, const Play &play);

};

#endif

