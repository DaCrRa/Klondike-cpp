/*
 * GameActionController.cpp
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#include <GameActionController.h>

#include <Move.h>

void GameActionController::accept(ControllerVisitor* visitor) {
    visitor->visit(this);
}

Klondike* GameActionController::getGame() {
    return game;
}

void GameActionController::setGame(Klondike* k) {
    game = k;
}

void GameActionController::doAction(GameActionPtr action) {
    action->accept(this);
}

void GameActionController::visit(StockAction* stockAction) {
    game->getStock()->move();
}

void GameActionController::visit(Move* move) {
    move->doMove();
}
