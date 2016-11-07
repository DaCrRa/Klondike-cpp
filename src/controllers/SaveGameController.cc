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
    return saver.existsGameWithName(name);
}

bool SaveGameController::save(const std::string& name) {
    assert(!name.empty());
    return saver.save(name);
}

void SaveGameController::accept(ControllerVisitor* v) {
    v->visit(this);
}
