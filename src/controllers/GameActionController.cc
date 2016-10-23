/*
 * GameActionController.cpp
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#include <GameActionController.h>
#include <GameActionScoreCalculator.h>
#include <Move.h>

GameActionController::GameActionController(std::shared_ptr<Klondike>& g) :
    game(g) {}

void GameActionController::accept(ControllerVisitor* visitor) {
    visitor->visit(this);
}

std::shared_ptr<Klondike>& GameActionController::getGame() {
    return game;
}

void GameActionController::doAction(GameActionPtr action) {
    GameActionScoreCalculator gameActionScoreCalculator;
    action->acceptGameActionVisitor(&gameActionScoreCalculator);
    action->doAction();
    game->updateScore(gameActionScoreCalculator.getScoreDelta());
}
