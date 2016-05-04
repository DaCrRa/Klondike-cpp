/*
 * SelectActionView.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#include <SelectActionView.h>

#include <StockAction.h>
#include <Move.h>

#include <iostream>

SelectActionView::SelectActionView() {
	availableActions.insert(std::pair<char, GameActionPtr>('s', GameActionPtr(new StockAction())));
	availableActions.insert(std::pair<char, GameActionPtr>('m', GameActionPtr(new Move())));
}

GameActionPtr SelectActionView::getAction() {
	std::map<char, GameActionPtr>::iterator selected = availableActions.end();
	while (selected == availableActions.end()) {
		std::cout << "Select action: ";
		char userInput;
		std::cin >> userInput;
		selected = availableActions.find(userInput);
	}
	return selected->second;
}
