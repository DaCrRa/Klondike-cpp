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

SelectActionView::SelectActionView(MoveCardController* c) :
	moveCardView(c) {

	availableActions.insert(std::pair<char, GameActionPtr>('s', GameActionPtr(new StockAction())));
	availableActions.insert(std::pair<char, GameActionPtr>('m', GameActionPtr(new Move())));

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
	moveCardView.completeMove(move);
}


