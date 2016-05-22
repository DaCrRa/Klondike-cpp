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

StartController::StartController(std::shared_ptr<Klondike>& k) :
	game(k)
{

}

void StartController::startGame() {
	assert(selectedGameActionController);
	game = std::shared_ptr<Klondike>(new Klondike());
	selectedGameActionController->setGame(game.get());
	game->initialize();
}

void StartController::resumeGame() {
	assert(game->isPaused());
	game->togglePause();
}

bool StartController::isGameInProgress() {
	return (bool)game;
}

std::vector<std::shared_ptr<GameActionController> > StartController::getGameActionControllers() {
	return std::vector<std::shared_ptr<GameActionController> >({
		std::shared_ptr<GameActionController>(new UserGameActionController()),
		std::shared_ptr<RandomGameActionController>(new RandomGameActionController())
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
