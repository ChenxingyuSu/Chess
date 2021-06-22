#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>

#include "play.h"
#include "observer.h"
#include "state.h"
#include "subject.h"

class Textdisplay :public Observer<State> {
  std::vector<std::vector<char> > theDisplay;
 public:
  Textdisplay();

  void notify(Subject <State> &whoNotified) override;

  friend std::ostream &operator<<(std::ostream &out, const Textdisplay &td);
};

#endif
