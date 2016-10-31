/*
 * GameActionHistoryContoller.h
 *
 *  Created on: 23 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_GAMEACTIONHISTORYCONTOLLER_H_
#define SRC_CONTROLLERS_GAMEACTIONHISTORYCONTOLLER_H_

#include <ForwardGameAction.h>
#include <ForwardGameActionObserver.h>

#include <vector>

class GameActionHistoryController : public ForwardGameActionObserver {
private:
    std::vector<ForwardGameActionPtr> actionHistory;
    std::vector<ForwardGameActionPtr>::iterator historyPosition;
public:
    GameActionHistoryController() :
        historyPosition(actionHistory.end()) {}
    void onActionDone(ForwardGameActionPtr action);
    void onActionUndone(ForwardGameActionPtr action);
    void onActionRedone(ForwardGameActionPtr action);
    bool hasUndoableActions();
    bool hasRedoableActions();
    ForwardGameActionPtr getNextUndoableAction() const;
    ForwardGameActionPtr getNextRedoableAction() const;
};

#endif /* SRC_CONTROLLERS_GAMEACTIONHISTORYCONTOLLER_H_ */
