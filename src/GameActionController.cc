/*
 * GameActionController.cpp
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#include <GameActionController.h>

GameActionController::GameActionController(Klondike* g) :
	game(g) {

}

void GameActionController::accept(ControllerVisitor* visitor) {
	visitor->visit(this);
}

void GameActionController::doAction(GameAction* action) {
	action->accept(this);
}

void GameActionController::visit(StockAction* stockAction) {
	game->getStock()->move();
}
