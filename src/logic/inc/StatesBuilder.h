/*
 * StatesBuilder.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_STATESBUILDER_H_
#define SRC_CONTROLLERS_INC_STATESBUILDER_H_

#include <State.h>
#include <GamePausedState.h>
#include <GameInProgressState.h>
#include <GameCompletedState.h>
#include <ExitState.h>
#include <NoGameStartedState.h>
#include <GameStartedState.h>

class StatesBuilder {
private:
    StatePtr initialState;
    StatePtr gamePaused;
    StatePtr gameInProgress;
    StatePtr gameCompleted;
    StatePtr exitState;
public:
    StatesBuilder(EventObserver& observer,
                  std::shared_ptr<Klondike>& game,
                  std::shared_ptr<GameActionHistoryController>& historyController,
                  std::shared_ptr<BestScoresController>& bestScoresController) :
        initialState(new GamePausedState(*this, observer, GameStatePtr(new NoGameStartedState()))),
        gamePaused(new GamePausedState(*this, observer, GameStatePtr(new GameStartedState()))),
        gameInProgress(new GameInProgressState(*this, observer, game, historyController)),
        gameCompleted(new GameCompletedState(*this, observer, bestScoresController)),
        exitState(new ExitState(*this)) {}
    StatePtr getInitialState() {
        return initialState;
    }
    StatePtr getPausedState() {
        return gamePaused;
    }
    StatePtr getGameInProgressState() {
        return gameInProgress;
    }
    StatePtr getGameCompletedState() {
        return gameCompleted;
    }
    StatePtr getExitState() {
        return exitState;
    }
};

#endif /* SRC_CONTROLLERS_INC_STATESBUILDER_H_ */
