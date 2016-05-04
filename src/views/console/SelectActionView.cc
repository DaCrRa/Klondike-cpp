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
	GameActionPtr selectedAction = selected->second->duplicate();
	completeActionInfo(selectedAction);
	return selectedAction;
}

void SelectActionView::completeActionInfo(GameActionPtr& action) {
	action->accept(this);
}

void SelectActionView::visit(StockAction* stockAction) {
	// Nothing to complete for a StockAction
	std::cout << "Stock action selected!" << std::endl;
}

void SelectActionView::visit(Move* move) {
	std::cout << "Move from: ";
	char userFromInput;
	std::cin >> userFromInput;
	if (userFromInput >= 'A' && userFromInput <= 'D') {
		std::cout << "will index foundations" << std::endl;
	} else if (userFromInput >= '1' && userFromInput <= '7') {
		std::cout << "will index tableau piles" << std::endl;
	}
	std::cout << "Move to: ";
	char userToInput;
	std::cin >> userToInput;
}
