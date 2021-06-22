#ifndef QUEEN_H
#define QUEEN_H

#include "cpiece.h"
#include <string>
#include <stack>

class Queen : public Cpiece {

   std::string namepiece = "Queen"; // type of this piece
   int ability = 50; // attack ability
   std::stack <Queen> S_queen;

public:

   // ctor
   Queen(int, int, Colour);
   // dtor
   ~Queen();

   std::string get_chess_type() override;
   int getability() override;
   std::vector<Position> valid_mv (std::vector<std::vector<Cpiece*> > &, Colour) override;
   bool is_mv_valid(std::vector<std::vector<Cpiece*> > &, int, int) override;

};




#endif
