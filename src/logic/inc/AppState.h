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

class AppStatesBuilder;

class AppState;
typedef std::shared_ptr<AppState> AppStatePtr;

class NoMoreControllersException : public std::exception {
public:
    const char* what() const throw() {
        return "No more controllers!";
    }
};

class AppState {
protected:
    AppStatesBuilder& statesBuilder;
public:
    AppState(AppStatesBuilder& sb) :
        statesBuilder(sb) {}
    virtual AppStatePtr transitionToGameInProgress() {
        assert(false);
        return AppStatePtr();
    }
    virtual AppStatePtr transitionToNoGameInProgress() {
        assert(false);
        return AppStatePtr();
    }
    virtual AppStatePtr transitionToGameCompleted() {
        assert(false);
        return AppStatePtr();
    }
    virtual AppStatePtr transitionToExit() {
        assert(false);
        return AppStatePtr();
    }
    virtual AppStatePtr transitionToSavingGame() {
        assert(false);
        return AppStatePtr();
    }
    virtual AppStatePtr transitionToLoadingGame() {
        assert(false);
        return AppStatePtr();
    }

    virtual ControllerPtr getController() = 0;
    virtual ~AppState() {}
};

#endif /* SRC_CONTROLLERS_INC_STATE_H_ */
