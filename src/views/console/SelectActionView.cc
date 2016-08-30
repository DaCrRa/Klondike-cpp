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

void SelectActionView::getAction(ForwardGameActionPtr& c) {
    try {
        std::map<char, ForwardGameActionPtr> possibleActions({
            { 'm', ForwardGameActionPtr(new Move()) }
        });
        ForwardGameActionPtr stockAction(new StockAction(actionController->getGame()->getStock()));
        if (stockAction->canBeDone()) {
            possibleActions.insert({ 's', stockAction});
        }
        GameActionPtr undoAction(new UndoGameAction());
        ItemSelectionDialog<ForwardGameActionPtr> dialog("Select action: ",
                std::move(possibleActions),
                'c');
        c = dialog.getSelectedItem();
    } catch (CancelledDialogException& e) {
        throw NoActionException();
    }
    completeActionInfo(c);
}

void SelectActionView::completeActionInfo(ForwardGameActionPtr& action) {
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


