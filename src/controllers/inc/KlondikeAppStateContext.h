/*
 * KlondikeAppStateContext.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_KLONDIKEAPPSTATECONTEXT_H_
#define SRC_CONTROLLERS_INC_KLONDIKEAPPSTATECONTEXT_H_

#include <KlondikeAppState.h>
#include <Klondike.h>
#include <GameActionHistoryController.h>
#include <BestScoresController.h>

#include <assert.h>

class NoMoreControllersException : public std::exception {
public:
    const char* what() const throw() {
        return "No more controllers!";
    }
};

class KlondikeAppStateContext {
private:
    std::shared_ptr<Klondike> game;
    std::shared_ptr<GameActionHistoryController> historyController;
    std::shared_ptr<BestScoresController> bestScoresController;
    KlondikeAppStatePtr state;
public:
    KlondikeAppStateContext(KlondikeAppStatePtr initialState) :
        state(initialState),
        bestScoresController(new BestScoresController(game)) {
        assert(state);
    }
    void setState(KlondikeAppStatePtr nextState) {
        assert(nextState);
        state = nextState;
    }
    void resetState() {
        state.reset();
    }
    std::shared_ptr<Klondike>& getGame() {
        return game;
    }
    std::shared_ptr<GameActionHistoryController>& getHistoryController() {
        return historyController;
    }
    std::shared_ptr<BestScoresController>& getBestScoresController() {
        return bestScoresController;
    }
    ControllerPtr getNextController() {
        if(!state) {
            throw NoMoreControllersException();
        }
        return state->getController(*this);
    }
};

#endif /* SRC_CONTROLLERS_INC_KLONDIKEAPPSTATECONTEXT_H_ */
