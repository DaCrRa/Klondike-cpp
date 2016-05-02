/*
 * SelectActionView.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#include <SelectActionView.h>

#include <iostream>

SelectActionView::SelectActionView() {
	availableActions.insert(std::pair<char, GameAction*>('s', &stockAction));
}

GameAction* SelectActionView::getAction() {
	std::map<char, GameAction*>::iterator selected = availableActions.end();
	while (selected == availableActions.end()) {
		std::cout << "Select action: ";
		char userInput;
		std::cin >> userInput;
		selected = availableActions.find(userInput);
	}
	return selected->second;
}
