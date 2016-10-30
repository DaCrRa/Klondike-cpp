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
#include <UserSelectedMove.h>
#include <MoveCardView.h>

#include <iostream>

SelectActionView::SelectActionView(UserGameActionController* c) :
    actionController(c)
{

}

void SelectActionView::getAction(GameActionPtr& c) {
    try {
        std::map<char, GameActionPtr> possibleActions({
            {   'm', GameActionPtr(new UserSelectedMove(
                    ForwardGameActionObserverPtr(actionController->getGameActionHistoryController())))
            }
        });

        GameActionPtr stockAction(new StockAction(actionController->getGame()->getStock(),
                                  ForwardGameActionObserverPtr(actionController->getGameActionHistoryController())));

        if (stockAction->canBeDone()) {
            possibleActions.insert({'s', stockAction});
        }

        if (actionController->getGameActionHistoryController()->hasUndoableActions()) {
            possibleActions.insert({'u',
                                    GameActionPtr(
                                        new UndoGameAction(actionController->getGameActionHistoryController()->getNextUndoableAction())
                                    )
                                   });
        }

        ItemSelectionDialog<GameActionPtr> dialog("Select action: ",
                std::move(possibleActions),
                'c');
        c = dialog.getSelectedItem();

    } catch (CancelledDialogException& e) {
        throw NoActionException();
    }
    completeActionInfo(c);
}

void SelectActionView::completeActionInfo(GameActionPtr& action) {
    action->acceptGameActionVisitor(this);
}

void SelectActionView::visit(UserSelectedMove* userSelectedMove) {
    try {
        MoveCardView moveCardView(actionController);
        moveCardView.completeMove(userSelectedMove);
    } catch (std::exception& e) {
        throw IncompleteMoveException();
    }
}

void SelectActionView::visit(ForwardGameAction* fwdGameAction) {
    std::cout << "Stock action selected!" << std::endl;
}

void SelectActionView::visit(UndoGameAction* undoGameAction) {
    // Nothing to complete for a UndoGameAction
    std::cout << "Undo last action..." << std::endl;
}

