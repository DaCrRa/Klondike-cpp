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

