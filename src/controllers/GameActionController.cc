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

void GameActionController::doAction(GameActionPtr action) {
	action->accept(this);
}

void GameActionController::visit(StockAction* stockAction) {
	game->getStock()->move();
}

void GameActionController::visit(Move* move) {
	//TODO
}

Stock* GameActionController::getStock() {
	return game->getStock();
}

std::vector<MoveOrigin*> GameActionController::getAvailableOrigins() {
	std::vector<MoveOrigin*> availableOrigins;
	if (game->getStock()->hasCardAvailable()) {
		availableOrigins.push_back(game->getStock());
	}
	return availableOrigins;
}
