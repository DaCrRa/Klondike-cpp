/*
 * StatesBuilder.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_STATESBUILDER_H_
#define SRC_CONTROLLERS_INC_STATESBUILDER_H_

#include <AppState.h>
#include <NoGameInProgress.h>
#include <GameInProgressState.h>
#include <GameCompletedState.h>
#include <ExitState.h>
#include <NoGameStartedState.h>
#include <GameStartedState.h>

class AppStatesBuilder {
private:
    AppStatePtr initialState;
    AppStatePtr gamePaused;
    AppStatePtr gameInProgress;
    AppStatePtr gameCompleted;
    AppStatePtr exitState;
public:
    AppStatesBuilder(EventObserver& observer,
                  std::shared_ptr<Klondike>& game,
                  std::shared_ptr<GameActionHistoryController>& historyController,
                  std::shared_ptr<BestScoresController>& bestScoresController) :
        initialState(new NoGameInProgressState(*this, observer, GameStatePtr(new NoGameStartedState()))),
        gamePaused(new NoGameInProgressState(*this, observer, GameStatePtr(new GameStartedState()))),
        gameInProgress(new GameInProgressState(*this, observer, game, historyController)),
        gameCompleted(new GameCompletedState(*this, observer, bestScoresController)),
        exitState(new ExitState(*this)) {}
    AppStatePtr getInitialState() {
        return initialState;
    }
    AppStatePtr getPausedState() {
        return gamePaused;
    }
    AppStatePtr getGameInProgressState() {
        return gameInProgress;
    }
    AppStatePtr getGameCompletedState() {
        return gameCompleted;
    }
    AppStatePtr getExitState() {
        return exitState;
    }
};

#endif /* SRC_CONTROLLERS_INC_STATESBUILDER_H_ */
