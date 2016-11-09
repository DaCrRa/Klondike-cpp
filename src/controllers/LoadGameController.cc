/*
 * LoadGameController.cpp
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#include <LoadGameController.h>
#include <UserGameActionController.h>

std::vector<std::string> LoadGameController::listSavedGames() {
    return loader.listSavedGames();
}

bool LoadGameController::loadGame(std::string& gameName) {
    gameSessionStarter.startSession(
        std::shared_ptr<UserGameActionController>(new UserGameActionController(eventObserver)));
    eventObserver.gameStarted();
    return true;
}

void LoadGameController::accept(ControllerVisitor* v) {
    v->visit(this);
}

