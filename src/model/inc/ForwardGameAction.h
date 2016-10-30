/*
 * GameAction.h
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_GAMEACTION_H_
#define SRC_INC_GAMEACTION_H_

#include <memory>
#include <assert.h>

class ForwardGameAction;
typedef std::shared_ptr<ForwardGameAction> ForwardGameActionPtr;

#include <GameAction.h>
#include <ForwardGameActionObserver.h>


class ForwardGameActionVisitor;

class ForwardGameAction : public GameAction,
    public std::enable_shared_from_this<ForwardGameAction> {
private:
    ForwardGameActionObserverPtr observer;
protected:
    virtual void forwardAction() = 0;
    void action() {
        forwardAction();
        if (observer) {
            observer->onActionDone(shared_from_this());
        }
    }
public:
    ForwardGameAction(ForwardGameActionObserverPtr o) :
        observer(o) {};
    void acceptGameActionVisitor(GameActionVisitor* visitor) {
        visitor->visit(this);
    }
    void setObserver(ForwardGameActionObserverPtr observer) {
        this->observer = observer;
    }
    virtual void accept(ForwardGameActionVisitor* visitor) = 0;
    virtual ForwardGameActionPtr duplicate() = 0;
    virtual void undoAction() = 0;
    virtual ~ForwardGameAction() {}
};

#endif /* SRC_INC_GAMEACTION_H_ */
