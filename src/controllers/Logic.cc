/*
 * Logic.cpp
 *
 *  Created on: 22 de may. de 2016
 *      Author: dancre
 */

#include <Logic.h>

#include <assert.h>

Logic::Logic() : startController(game) {}

Controller* Logic::getNextController() {
	// game in progress?
	if (game && !game->isPaused()) {
		assert(startController.getSelectedGameActionController() != nullptr);
		return startController.getSelectedGameActionController();
	}
	if (startController.continueApp()) {
		return &startController;
	}
	throw NoMoreControllersException();
}

