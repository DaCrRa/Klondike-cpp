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
#include <SaveGameController.h>
#include <NoGameInProgress.h>
#include <GameInProgressState.h>
#include <GameCompletedState.h>
#include <ExitState.h>
#include <NoGameStartedState.h>
#include <GameStartedState.h>
#include <SavingGameState.h>

class AppStatesBuilder {
private:
    AppStatePtr initialState;
    AppStatePtr gamePaused;
    AppStatePtr gameInProgress;
    AppStatePtr gameCompleted;
    AppStatePtr exitState;
    AppStatePtr savingGameState;
public:
    AppStatesBuilder(EventObserver& observer,
                     std::shared_ptr<Klondike>& game,
                     GameActionControllerHolder& gameActionControllerHolder,
                     std::shared_ptr<GameActionHistoryController>& historyController,
                     std::shared_ptr<BestScoresController>& bestScoresController,
                     std::shared_ptr<SaveGameController>& saveGameController) :
        initialState(new NoGameInProgressState(*this,
                                               game,
                                               historyController,
                                               gameActionControllerHolder,
                                               observer,
                                               GameStatePtr(new NoGameStartedState()))),
        gamePaused(new NoGameInProgressState(*this,
                                             game,
                                             historyController,
                                             gameActionControllerHolder,
                                             observer,
                                             GameStatePtr(new GameStartedState()))),
        gameInProgress(new GameInProgressState(*this, gameActionControllerHolder)),
        gameCompleted(new GameCompletedState(*this, observer, bestScoresController)),
        exitState(new ExitState(*this)),
        savingGameState(new SavingGameState(*this, saveGameController)) {}
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
    AppStatePtr getSavingGameState() {
        return savingGameState;
    }
};

#endif /* SRC_CONTROLLERS_INC_STATESBUILDER_H_ */
