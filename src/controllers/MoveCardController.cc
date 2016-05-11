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
	return game->getPossibleMoveOrigins();
}

std::vector<MoveDest*> MoveCardController::getAvailableDests(MoveOrigin* o) {
	return game->getPossibleMoveDests(o);
}

