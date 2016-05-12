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
#include <MoveCardView.h>

#include <iostream>

SelectActionView::SelectActionView(UserGameActionController* c) :
	actionController(c)
{

}

void SelectActionView::getAction(GameActionPtr& c) {
	std::map<char, GameActionPtr> availableActions;
	availableActions.insert(std::pair<char, GameActionPtr>('s', GameActionPtr(new StockAction())));
	availableActions.insert(std::pair<char, GameActionPtr>('m', GameActionPtr(new Move())));
	ItemSelectionDialog<GameActionPtr> dialog("Select action: ", availableActions, 'c');
	c = dialog.getSelectedItem();
	completeActionInfo(c);
}

void SelectActionView::completeActionInfo(GameActionPtr& action) {
	action->accept(this);
}

void SelectActionView::visit(StockAction* stockAction) {
	// Nothing to complete for a StockAction
	std::cout << "Stock action selected!" << std::endl;
}

void SelectActionView::visit(Move* move) {
	MoveCardView moveCardView(actionController);
	moveCardView.completeMove(move);
}


