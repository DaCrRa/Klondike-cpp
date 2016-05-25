/*
 * Logic.cpp
 *
 *  Created on: 22 de may. de 2016
 *      Author: dancre
 */

#include <Logic.h>

#include <assert.h>

Logic::Logic() :
    actionControllerCatalog(game),
    startController(game, actionControllerCatalog) {}

Controller* Logic::getNextController() {
    // game in progress?
    if (game && !game->isPaused()) {
        std::shared_ptr<GameActionController> selectedGameActionController = actionControllerCatalog.getSelectedGameActionController();
        selectedGameActionController->setGame(game.get());
        return selectedGameActionController.get();
    }
    if (startController.continueApp()) {
        return &startController;
    }
    throw NoMoreControllersException();
}

