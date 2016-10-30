/*
 * GameActionHistoryContoller.cc
 *
 *  Created on: 23 Oct 2016
 *      Author: dancre
 */

#include <iostream>
#include <GameActionHistoryController.h>

void GameActionHistoryController::onActionDone(ForwardGameActionPtr action) {
    actionHistory.push_back(action);
}

ForwardGameActionPtr GameActionHistoryController::getNextUndoableAction() const {
    return actionHistory.back();
}

void GameActionHistoryController::onActionUndone(ForwardGameActionPtr action) {
    actionHistory.pop_back();
}

bool GameActionHistoryController::hasUndoableActions() {
    return !actionHistory.empty();
}
