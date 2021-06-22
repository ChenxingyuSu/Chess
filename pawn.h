#ifndef PAWN_H
#define PAWN_H

#include "cpiece.h"
#include <string>
#include <stack>

class Pawn : public Cpiece {

   std::string namepiece = "Pawn"; // type of this piece
   int ability = 1; // attack ability
   std::stack <Pawn> S_pawn;

public:

   // ctor
   Pawn(int, int, Colour);
   // dtor
   ~Pawn();

   std::string get_chess_type() override;
   int getability() override;
   std::vector<Position> valid_mv (std::vector<std::vector<Cpiece*> > &, Colour) override;
   bool is_mv_valid(std::vector<std::vector<Cpiece*> > &, int, int) override;

};




#endif
