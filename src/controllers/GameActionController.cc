/*
 * GameActionController.cpp
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#include <ForwardGameActionController.h>
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

void GameActionController::doAction(ForwardGameActionPtr action) {
    scoreController.calculateScoreDelta(action);
    action->doAction();
    scoreController.updateScore();
}
