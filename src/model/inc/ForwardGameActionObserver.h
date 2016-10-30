/*
 * ForwardGameActionObserver.h
 *
 *  Created on: 23 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_FORWARDGAMEACTIONOBSERVER_H_
#define SRC_MODEL_INC_FORWARDGAMEACTIONOBSERVER_H_

#include <memory>

class ForwardGameActionObserver;
typedef std::shared_ptr<ForwardGameActionObserver> ForwardGameActionObserverPtr;

#include <ForwardGameAction.h>

class ForwardGameActionObserver {
public:
    virtual void onActionDone(ForwardGameActionPtr action) = 0;
    virtual void onActionUndone(ForwardGameActionPtr action) = 0;
    virtual ~ForwardGameActionObserver() {}
};

#endif /* SRC_MODEL_INC_FORWARDGAMEACTIONOBSERVER_H_ */
