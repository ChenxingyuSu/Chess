#ifndef KNIGHT_H
#define KNIGHT_H

#include "cpiece.h"
#include <string>
#include <stack>

class Knight : public Cpiece {

   std::string namepiece = "Knight"; // type of this piece
   int ability = 5; // attack ability
   std::stack <Knight> S_knight;

public:

   // ctor
   Knight(int, int, Colour);
   // dtor
   ~Knight();

   std::string get_chess_type() override;
   int getability() override;
   std::vector<Position> valid_mv (std::vector<std::vector<Cpiece*> > &, Colour) override;
   bool is_mv_valid(std::vector<std::vector<Cpiece*> > &, int, int) override;

};




#endif
