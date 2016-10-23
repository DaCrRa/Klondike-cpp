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

class GameActionHistoryController : public ForwardGameActionObserver {
private:
    ForwardGameActionPtr lastAction;
public:
    void onActionDone(ForwardGameActionPtr action);
    ForwardGameActionPtr getLastAction();
};

#endif /* SRC_CONTROLLERS_GAMEACTIONHISTORYCONTOLLER_H_ */
