/*
 * StatesBuilder.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_STATESBUILDER_H_
#define SRC_CONTROLLERS_INC_STATESBUILDER_H_

#include <GameActionController.h>
#include <GameActionHistoryController.h>
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
    AppStatePtr gameCompleted;
    AppStatePtr exitState;
    std::shared_ptr<GameActionController> gameActionController;
public:
    AppStatesBuilder(EventObserver& observer,
                     std::shared_ptr<Klondike>& game,
                     std::shared_ptr<GameActionHistoryController>& historyController,
                     std::shared_ptr<BestScoresController>& bestScoresController) :
        initialState(new NoGameInProgressState(*this, observer, GameStatePtr(new NoGameStartedState()))),
        gamePaused(new NoGameInProgressState(*this, observer, GameStatePtr(new GameStartedState()))),
        gameCompleted(new GameCompletedState(*this, observer, bestScoresController)),
        exitState(new ExitState(*this)) {}
    void setGameActionController(std::shared_ptr<GameActionController> gac) {
        assert(gac);
        gameActionController = gac;
    }
    AppStatePtr getInitialState() {
        return initialState;
    }
    AppStatePtr getPausedState() {
        return gamePaused;
    }
    AppStatePtr getGameInProgressState() {
        assert(gameActionController);
        return AppStatePtr(new GameInProgressState(*this, gameActionController));
    }
    AppStatePtr getGameCompletedState() {
        return gameCompleted;
    }
    AppStatePtr getExitState() {
        return exitState;
    }
};

#endif /* SRC_CONTROLLERS_INC_STATESBUILDER_H_ */
