#ifndef BISHOP_H
#define BISHOP_H

#include "cpiece.h"
#include <string>
#include <stack>

class Bishop : public Cpiece {

   std::string namepiece = "Bishop"; // type of this piece
   int ability = 25; // attack ability
   std::stack <Bishop> S_bishop;

public:

   // ctor
   Bishop(int, int, Colour);
   // dtor
   ~Bishop();

   std::string get_chess_type() override;
   int getability() override;
   std::vector<Position> valid_mv (std::vector<std::vector<Cpiece*> > &, Colour) override;
   bool is_mv_valid(std::vector<std::vector<Cpiece*> > &, int, int) override;

};




#endif
