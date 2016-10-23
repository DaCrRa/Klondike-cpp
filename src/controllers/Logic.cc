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
    startController(game, actionControllerCatalog),
    bestScoresController(game) {}

Controller* Logic::getNextController() {
    // game in progress?
    if (game && game->isCompleted()) {
        bestScoresController.registerScore();
        return &bestScoresController;
    }
    if (game && !game->isPaused()) {
        std::shared_ptr<GameActionController> selectedGameActionController = actionControllerCatalog.getSelectedGameActionController();
        return selectedGameActionController.get();
    }
    if (startController.continueApp()) {
        return &startController;
    }
    throw NoMoreControllersException();
}

