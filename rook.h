#ifndef ROOK_H
#define ROOK_H

#include "cpiece.h"
#include <string>
#include <stack>

class Rook : public Cpiece {

   std::string namepiece = "Queen"; // type of this piece
   int ability = 10; // attack ability
   std::stack <Rook> S_rook;

public:

   // ctor
   Rook(int, int, Colour);
   // dtor
   ~Rook();

   std::string get_chess_type() override;
   int getability() override;
   std::vector<Position> valid_mv (std::vector<std::vector<Cpiece*> > &, Colour) override;
   bool is_mv_valid(std::vector<std::vector<Cpiece*> > &, int, int) override;

};




#endif
