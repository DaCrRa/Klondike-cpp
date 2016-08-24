/*
 * GameAction.h
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_GAMEACTION_H_
#define SRC_INC_GAMEACTION_H_

#include <GameAction.h>

#include <memory>
#include <assert.h>

class ForwardGameActionVisitor;

class ForwardGameAction;
typedef std::shared_ptr<ForwardGameAction> ForwardGameActionPtr;

class ForwardGameAction : public GameAction {
public:
    virtual void accept(ForwardGameActionVisitor* visitor) = 0;
    virtual ForwardGameActionPtr duplicate() = 0;
    virtual void undoAction() = 0;
    virtual ~ForwardGameAction() {}
};

#endif /* SRC_INC_GAMEACTION_H_ */
