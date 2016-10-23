/*
 * GameActionHistoryContoller.cc
 *
 *  Created on: 23 Oct 2016
 *      Author: dancre
 */

#include <iostream>
#include <GameActionHistoryController.h>

void GameActionHistoryController::onActionDone(ForwardGameActionPtr action) {
    lastAction = action;
}

ForwardGameActionPtr GameActionHistoryController::getLastAction() {
    return lastAction;
}
