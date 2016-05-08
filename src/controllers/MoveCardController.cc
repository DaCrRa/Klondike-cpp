/*
 * MoveCardController.cpp
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#include <MoveCardController.h>

MoveCardController::MoveCardController(Klondike* k) :
	game(k) {}


Klondike* MoveCardController::getGame() {
	return game;
}

std::vector<MoveOrigin*> MoveCardController::getAvailableOrigins() {
	std::vector<MoveOrigin*> availableOrigins;
	if (game->getStock()->hasCardAvailable()) {
		availableOrigins.push_back(game->getStock());
	}
	return availableOrigins;
}

std::vector<MoveDest*> MoveCardController::getAvailableDests(MoveOrigin* o) {
	std::vector<MoveDest*> availableDests;
	for (std::vector<Foundation>::iterator it = game->getFoundations().begin() ; it != game->getFoundations().end() ; ++it) {
		if (it->accept(o->showAvailableCard())) {
			availableDests.push_back(it.base());
		}
	}
	return availableDests;
}

