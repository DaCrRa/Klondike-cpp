/*
 * SelectActionView.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#include <SelectActionView.h>

#include <ItemSelectionDialog.h>
#include <StockAction.h>
#include <Move.h>

#include <iostream>

SelectActionView::SelectActionView(GameActionController* c) :
	controller(c) {

	availableActions.insert(std::pair<char, GameActionPtr>('s', GameActionPtr(new StockAction())));
	availableActions.insert(std::pair<char, GameActionPtr>('m', GameActionPtr(new Move())));

	origins.insert(std::pair<MoveOrigin*, char>(controller->getStock(), 's'));
}

GameActionPtr SelectActionView::getAction() {
	ItemSelectionDialog<GameActionPtr> dialog("Select action: ", availableActions, 'c');
	GameActionPtr selectedAction = dialog.getSelectedItem()->duplicate();
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
	std::map<char, MoveOrigin*> possibleOrigins = getPossibleOrigins();
	ItemSelectionDialog<MoveOrigin*> dialog("Move from: ", possibleOrigins, 'c');
	move->setOrigin(dialog.getSelectedItem());
	std::cout << "Move to: ";
	char userToInput;
	std::cin >> userToInput;
}

std::map<char, MoveOrigin*> SelectActionView::getPossibleOrigins() {
	std::map<char, MoveOrigin*> possibleOrigins;
	std::vector<MoveOrigin*> availableOrigins = controller->getAvailableOrigins();
	for (std::vector<MoveOrigin*>::iterator it = availableOrigins.begin(); it != availableOrigins.end(); ++it) {
		possibleOrigins[origins[*it]] = *it;
	}
	return possibleOrigins;
}


