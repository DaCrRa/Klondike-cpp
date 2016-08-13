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
    gameAction->accept(this);
    return 0;
}

void ScoreController::updateScore(GameActionPtr gameAction) {
    game->updateScore(calculateScoreDelta(gameAction));
}

#include <iostream>
void ScoreController::visit(StockAction* stockAction) {
    std::cout << "calculate score for stock action @@@@@@@@@@" << std::endl;
}

void ScoreController::visit(Move* move) {
    MoveScoreCalculator calculator;
    move->acceptOriginVisitor(&calculator);
}
