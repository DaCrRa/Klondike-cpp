/*
 * ScoreController.cpp
 *
 *  Created on: 6 de ago. de 2016
 *      Author: dancre
 */

#include <ScoreController.h>

ScoreController::ScoreController(std::shared_ptr<Klondike>& g) :
    game(g)
{

}

void ScoreController::calculateScoreDelta(GameActionPtr gameAction) {
    gameActionScoreCalculator = std::make_shared<GameActionScoreCalculator>();
    gameAction->accept(gameActionScoreCalculator.get());
}

void ScoreController::updateScore() {
    game->updateScore(gameActionScoreCalculator->getScoreDelta());
}

