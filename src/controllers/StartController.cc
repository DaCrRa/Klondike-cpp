/*
 * StartController.cpp
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#include <StartController.h>
#include <UserGameActionController.h>
#include <RandomGameActionController.h>

#include <assert.h>

StartController::StartController(Klondike* k) :
	game(k)
{

}

void StartController::startGame() {
	assert(selectedGameActionController);
	game->initialize();
}

std::vector<std::shared_ptr<GameActionController> > StartController::getGameActionControllers() {
	return std::vector<std::shared_ptr<GameActionController> >({
		std::shared_ptr<GameActionController>(new UserGameActionController(game)),
		std::shared_ptr<RandomGameActionController>(new RandomGameActionController(game))
	});
}

void StartController::setSelectedGameActionController(const std::shared_ptr<GameActionController>& controller) {
	selectedGameActionController = controller;
}

GameActionController* StartController::getSelectedGameActionController() {
	return selectedGameActionController.get();
}

void StartController::accept(ControllerVisitor* v) {
	v->visit(this);
}
