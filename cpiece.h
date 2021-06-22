#ifndef CPIECE_H
#define CPIECE_H
#include <vector>
#include <string>
#include "state.h"
#include "position.h"
#include <stack>


// this is an abstract class that will be inherited by all the types of chess

class Cpiece {
    int col; // which row is this chess on
    int row; // which column is this chess on
    
    // the colour of this chess and initialize it into Nocolour

    Colour colour = Colour:: NoColour ; 


    // used for history records

    // std::stack <Cpiece*> s; (bonus)

    bool have_not_moved = true; // have this chess moved yet
    bool alive = true; // is this chess still alive
    bool enpassant = true; // whether can we active the enpassant rule


    public:


    // non-virtual member functions
    // first, as always, the ctor!  

    //ctor
    Cpiece(int, int, Colour); 

    int getrow();
    void setrow (int);
    int getcol();
    void setcol(int);
    Colour getcolour();
    bool alive_or_not();
    void set_to_death();
    void set_to_alive();
    bool not_moved_ever();
    void set_never_moved();
    void set_moved();
    bool getenp();
    void set_enp_t();
    void set_enp_f();    



    // virtual basic functions

    virtual ~Cpiece(); // dtor of an abstract class is virtual
    virtual std::string get_chess_type() = 0; // tell which type is the chess
    virtual int getability () = 0; // get the attack ability of the chess
    // get the vector storing the valid move position for a chesspiece based on the basic rule
    virtual std::vector<Position> valid_mv(std::vector<std::vector<Cpiece*> > &, Colour) = 0;
    // tell whether the move is valid or not
    virtual bool is_mv_valid(std::vector<std::vector<Cpiece*> > &, int, int) = 0;
    
};

bool underthreat (std::vector<std::vector<Cpiece*> > &,int,int);

#endif