/*
 * KlondikeAppState.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_STATE_H_
#define SRC_CONTROLLERS_INC_STATE_H_

#include <memory>
#include <assert.h>

#include <Controller.h>
#include <GameState.h>

class StatesBuilder;

class State;
typedef std::shared_ptr<State> StatePtr;

class NoMoreControllersException : public std::exception {
public:
    const char* what() const throw() {
        return "No more controllers!";
    }
};

class State {
protected:
    StatesBuilder& statesBuilder;
public:
    State(StatesBuilder& sb) :
        statesBuilder(sb) {}
    virtual StatePtr transitionToGameInProgress() {
        assert(false);
        return StatePtr();
    }
    virtual StatePtr transitionToGamePaused() {
        assert(false);
        return StatePtr();
    }
    virtual StatePtr transitionToGameCompleted() {
        assert(false);
        return StatePtr();
    }
    virtual StatePtr transitionToExit() {
        assert(false);
        return StatePtr();
    }
    virtual ControllerPtr getController() = 0;
    virtual ~State() {}
};

#endif /* SRC_CONTROLLERS_INC_STATE_H_ */
