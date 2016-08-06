/*
 * GameActionControllerCatalog.cpp
 *
 *  Created on: 24 de may. de 2016
 *      Author: dancre
 */

#include <GameActionControllerCatalog.h>
#include <UserGameActionController.h>
#include <RandomGameActionController.h>

#include <assert.h>

GameActionControllerCatalog::GameActionControllerCatalog(std::shared_ptr<Klondike>& game) :
    availableControllers({
    std::make_shared<UserGameActionController>(game),
    std::make_shared<RandomGameActionController>(game)
}),
selected(0) {}

const std::vector<std::shared_ptr<GameActionController> >& GameActionControllerCatalog::getAvailableGameActionControllers() {
    return availableControllers;
}

void GameActionControllerCatalog::selectGameActionController(size_t selected) {
    assert(selected < availableControllers.size());
    this->selected = selected;
}

std::shared_ptr<GameActionController> GameActionControllerCatalog::getSelectedGameActionController() {
    assert(selected < availableControllers.size());
    return availableControllers[selected];
}

