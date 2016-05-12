/*
 * UserGameActionController.cpp
 *
 *  Created on: 12 de may. de 2016
 *      Author: dancre
 */

#include <UserGameActionController.h>

UserGameActionController::UserGameActionController(Klondike* game) :
GameActionController(game)
{

}

void UserGameActionController::acceptGameActionControllerVisitor(GameActionControllerVisitor* visitor) {
	visitor->visit(this);
}

