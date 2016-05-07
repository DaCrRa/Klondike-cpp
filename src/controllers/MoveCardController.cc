/*
 * MoveCardController.cpp
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#include <MoveCardController.h>

MoveCardController::MoveCardController(Klondike* k) :
	game(k) {}


Stock* MoveCardController::getStock() {
	return game->getStock();
}

std::vector<MoveOrigin*> MoveCardController::getAvailableOrigins() {
	std::vector<MoveOrigin*> availableOrigins;
	if (game->getStock()->hasCardAvailable()) {
		availableOrigins.push_back(game->getStock());
	}
	return availableOrigins;
}

std::vector<MoveDest*> MoveCardController::getAvailableDests(MoveOrigin* o) {
	// TODO
	return std::vector<MoveDest*>();
}

