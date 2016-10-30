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
public:
    void onActionDone(ForwardGameActionPtr action);
    void onActionUndone(ForwardGameActionPtr action);
    bool hasUndoableActions();
    ForwardGameActionPtr getNextUndoableAction() const;
};

#endif /* SRC_CONTROLLERS_GAMEACTIONHISTORYCONTOLLER_H_ */
