/*
 * LoadGameController.cpp
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#include <LoadGameController.h>

std::vector<std::string> LoadGameController::listSavedGames() {
    return loader.listSavedGames();
}

void LoadGameController::accept(ControllerVisitor* v) {
    v->visit(this);
}

