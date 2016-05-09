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
	for (std::vector<MoveOrigin*>::iterator it = game->getAllMoveOrigins().begin() ; it != game->getAllMoveOrigins().end() ; ++it) {
		if ((*it)->hasCardAvailable()) {
			availableOrigins.push_back(*it);
		}
	}
	return availableOrigins;
}

std::vector<MoveDest*> MoveCardController::getAvailableDests(MoveOrigin* o) {
	std::vector<MoveDest*> availableDests;
	for (std::vector<MoveDest*>::iterator it = game->getAllMoveDests().begin() ; it != game->getAllMoveDests().end() ; ++it) {
		if ((*it)->accept(o->showAvailableCard())) {
			availableDests.push_back(*it);
		}
	}
	return availableDests;
}

