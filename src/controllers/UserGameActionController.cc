/*
 * UserGameActionController.cpp
 *
 *  Created on: 12 de may. de 2016
 *      Author: dancre
 */

#include <UserGameActionController.h>

void UserGameActionController::acceptGameActionControllerVisitor(GameActionControllerVisitor* visitor) {
    visitor->visit(this);
}

std::shared_ptr<GameActionHistoryController> UserGameActionController::getGameActionHistoryController() {
    return historyController;
}

std::vector<MoveOrigin*> UserGameActionController::getPossibleMoveOrigins() {
    MoveOrigFinder originFinder;
    game->accept(&originFinder);
    return originFinder.getPossibleOrigins();
}

void UserGameActionController::MoveOrigFinder::visitStock(Stock* stock) {
    if (stock->hasCardAvailable()) {
        possibleOrigins.push_back(stock);
    }
}

void UserGameActionController::MoveOrigFinder::visitTableauPile(TableauPile* tp) {
    if (tp->hasCardAvailable()) {
        possibleOrigins.push_back(tp);
    }
}

void UserGameActionController::MoveOrigFinder::visitFoundation(Foundation* f) {
    if (f->hasCardAvailable()) {
        possibleOrigins.push_back(f);
    }
}
