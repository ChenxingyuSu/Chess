#ifndef KING_H
#define KING_H

#include "cpiece.h"
#include <string>
#include <stack>

class King : public Cpiece {

   std::string namepiece = "King"; // type of this piece
   int ability = 100; // attack ability
   std::stack <King> S_king;

public:

   // ctor
   King(int, int, Colour);
   // dtor
   ~King();

   std::string get_chess_type() override;
   int getability() override;
   std::vector<Position> valid_mv (std::vector<std::vector<Cpiece*> > &, Colour) override;
   bool is_mv_valid(std::vector<std::vector<Cpiece*> > &, int, int) override;

};






#endif






