/*
 * UserSelectedMove.h
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_USERSELECTEDMOVE_H_
#define SRC_MODEL_INC_USERSELECTEDMOVE_H_

#include <GameAction.h>
#include <Move.h>

#include <assert.h>

class UserSelectedMove: public GameAction {
private:
    MovePtr m;
    ForwardGameActionObserverPtr observer;
protected:
    void action();
public:
    UserSelectedMove(ForwardGameActionObserverPtr o) :
        observer(o) {
        assert(observer);
    }
    bool canBeDone();
    void setScoreDelta(int d) {
        GameAction::setScoreDelta(d);
        m->setScoreDelta(d);
    }
    void acceptGameActionVisitor(GameActionVisitor* visitor);
    void setMove(MovePtr m);
    ForwardGameActionObserverPtr getFwdGameActionObserver();
    MovePtr getMove();
};

#endif /* SRC_MODEL_INC_USERSELECTEDMOVE_H_ */
