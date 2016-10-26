/*
 * UndoGameAction.h
 *
 *  Created on: 30 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_UNDOGAMEACTION_H_
#define SRC_MODEL_INC_UNDOGAMEACTION_H_

#include <GameAction.h>
#include <ForwardGameAction.h>

class UndoGameAction: public GameAction {
private:
    ForwardGameActionPtr forwardGameAction;
protected:
    void action();
public:
    UndoGameAction(ForwardGameActionPtr actionToUndo) :
        forwardGameAction(actionToUndo) {};
    bool canBeDone();
    ForwardGameActionPtr getForwardGameAction();
    void acceptGameActionVisitor(GameActionVisitor* visitor);
};

#endif /* SRC_MODEL_INC_UNDOGAMEACTION_H_ */
