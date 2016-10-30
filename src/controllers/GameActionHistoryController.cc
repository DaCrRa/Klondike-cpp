/*
 * GameActionHistoryContoller.cc
 *
 *  Created on: 23 Oct 2016
 *      Author: dancre
 */

#include <iostream>
#include <GameActionHistoryController.h>

void GameActionHistoryController::onActionDone(ForwardGameActionPtr action) {
    historyPosition = actionHistory.insert(historyPosition, action);
    actionHistory.erase(historyPosition + 1, actionHistory.end());
    historyPosition = actionHistory.end();
}

ForwardGameActionPtr GameActionHistoryController::getNextUndoableAction() const {
    return *(historyPosition - 1);
}

void GameActionHistoryController::onActionUndone(ForwardGameActionPtr action) {
    historyPosition--;
}

bool GameActionHistoryController::hasUndoableActions() {
    return historyPosition != actionHistory.begin();
}
