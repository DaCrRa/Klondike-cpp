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
