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

int ScoreController::calculateScoreDelta(GameActionPtr gameAction) {
    GameActionScoreCalculator calculator;
    gameAction->accept(&calculator);
    return calculator.getScoreDelta();
}

void ScoreController::updateScore(GameActionPtr gameAction) {
    game->updateScore(calculateScoreDelta(gameAction));
}

