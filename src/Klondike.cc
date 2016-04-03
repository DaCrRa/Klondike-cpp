/*
 * Klondike.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Klondike.h>

void Klondike::initialize() {
	for (int i = 0; i < 7; i++) { //TODO magic number
		for (int j = 0; j < i + 1; j++) {
			tableau[i].addToCovered(deck.removeTop());
		}
		tableau[i].turnUp();
	}
}

bool Klondike::isCompleted() {
	bool completed = true;
	for (int i = 0; i < 4 && completed; i++) { //TODO magic number
		completed &= foundations[i].isCompleted();
	}
	return completed;
}
