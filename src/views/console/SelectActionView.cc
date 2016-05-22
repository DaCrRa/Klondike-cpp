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
	try {
		ItemSelectionDialog<GameActionPtr> dialog("Select action: ",
			std::map<char, GameActionPtr>({
				{ 's', GameActionPtr(new StockAction()) },
				{ 'm', GameActionPtr(new Move()) }
			}),
		'c');
		c = dialog.getSelectedItem();
	} catch (CancelledDialogException& e) {
		throw NoActionException();
	}
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
	try {
		MoveCardView moveCardView(actionController);
		moveCardView.completeMove(move);
	} catch (std::exception& e) {
		throw IncompleteMoveException();
	}
}


