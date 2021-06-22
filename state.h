#ifndef STATE_H
#define STATE_H
#include <string>

enum class StateType { NewPiece, RemovePiece, MovePiece };
enum class Colour { NoColour, Black, White };


struct State {
  int column,row;
  int next_column, next_row;
  std::string name;
  StateType type;  
  Colour colour;  
};

#endif

