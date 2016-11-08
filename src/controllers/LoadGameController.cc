/*
 * LoadGameController.cpp
 *
 *  Created on: 8 Nov 2016
 *      Author: dancre
 */

#include <LoadGameController.h>

void LoadGameController::accept(ControllerVisitor* v) {
    v->visit(this);
}

