#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>

#include "play.h"
#include "observer.h"
#include "window.h"

class Graphicsdisplay : public Observer<State> {
	Xwindow* xw;
	std::vector<std::vector<int>> colours;
public:
	Graphicsdisplay();

	void notify(Subject<State> &whoNotified) override;
}


#endif
