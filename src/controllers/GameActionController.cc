/*
 * GameActionController.cpp
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#include <GameActionController.h>

#include <Move.h>

GameActionController::GameActionController(std::shared_ptr<Klondike>& g) :
    game(g),
    scoreController(game) {

}

void GameActionController::accept(ControllerVisitor* visitor) {
    visitor->visit(this);
}

std::shared_ptr<Klondike>& GameActionController::getGame() {
    return game;
}

void GameActionController::doAction(GameActionPtr action) {
    action->accept(this);
    scoreController.updateScore(action);
}

void GameActionController::visit(StockAction* stockAction) {
    game->getStock()->move();
}

void GameActionController::visit(Move* move) {
    move->doMove();
}
