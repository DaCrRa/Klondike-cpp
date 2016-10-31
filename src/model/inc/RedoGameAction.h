/*
 * RedoGameAction.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_REDOGAMEACTION_H_
#define SRC_MODEL_INC_REDOGAMEACTION_H_

#include <GameAction.h>
#include <ForwardGameAction.h>

class RedoGameAction: public GameAction {
private:
    ForwardGameActionPtr forwardGameAction;
protected:
    void action();
public:
    RedoGameAction(ForwardGameActionPtr actionToRedo) :
        forwardGameAction(actionToRedo) {};
    bool canBeDone();
    ForwardGameActionPtr getForwardGameAction();
    void acceptGameActionVisitor(GameActionVisitor* visitor);
};

#endif /* SRC_MODEL_INC_REDOGAMEACTION_H_ */
