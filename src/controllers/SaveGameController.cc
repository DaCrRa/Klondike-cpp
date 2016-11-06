/*
 * SaveGameController.cpp
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#include <SaveGameController.h>

#include <assert.h>
#include <algorithm>

bool SaveGameController::existsGameWithName(const std::string& name) {
    assert(!name.empty());
    return std::find(savedGamesNames.begin(), savedGamesNames.end(), name)
           != savedGamesNames.end();
}

void SaveGameController::save(const std::string& name) {
    assert(!name.empty());
    savedGamesNames.push_back(name);
}

void SaveGameController::accept(ControllerVisitor* v) {
    v->visit(this);
}
