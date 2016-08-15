/*
 * BestScoresController.cc
 *
 *  Created on: 15 de ago. de 2016
 *      Author: dancre
 */

#include <BestScoresController.h>

void BestScoresController::accept(ControllerVisitor* visitor) {
    visitor->visit(this);
}

std::shared_ptr<Klondike>& BestScoresController::getGame() {
    return game;
}
