/*
 * SaveGameController.cpp
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#include <SaveGameController.h>

#include <assert.h>

bool SaveGameController::nameCanBeUsed(const std::string& name) {
    return true;
}

void SaveGameController::save(const std::string& name) {
    assert(nameCanBeUsed(name));
    eventObserver.gameSaved();
}

void SaveGameController::accept(ControllerVisitor* v) {
    v->visit(this);
}
