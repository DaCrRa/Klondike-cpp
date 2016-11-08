/*
 * EventObserver.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_EVENTOBSERVER_H_
#define SRC_MODEL_INC_EVENTOBSERVER_H_

#include <memory>

class EventObserver;
typedef std::shared_ptr<EventObserver> EventObserverPtr;

class EventObserver {
public:
    virtual void gameStarted() = 0;
    virtual void saveGameRequested() = 0;
    virtual void loadGameRequested() = 0;
    virtual void gamePauseRequested() = 0;
    virtual void gameResumeRequested() = 0;
    virtual void gameCompleted() = 0;
    virtual void exitRequested() = 0;
    virtual ~EventObserver() {}
};



#endif /* SRC_MODEL_INC_EVENTOBSERVER_H_ */
