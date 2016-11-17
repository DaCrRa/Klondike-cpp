/*
 * StatesBuilder.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_STATESBUILDER_H_
#define SRC_CONTROLLERS_INC_STATESBUILDER_H_

#include <GameActionController.h>
#include <SaveGameController.h>
#include <NoGameInProgress.h>
#include <GameInProgressState.h>
#include <GameCompletedState.h>
#include <ExitState.h>
#include <NoGameStartedState.h>
#include <GameStartedState.h>
#include <SavingGameState.h>
#include <LoadingGameState.h>

class AppStatesBuilder {
protected:
    AppStatePtr initialState;
    AppStatePtr gamePaused;
    AppStatePtr gameInProgress;
    AppStatePtr gameCompleted;
    AppStatePtr exitState;
    AppStatePtr savingGameState;
    std::shared_ptr<LoadingGameState> loadingGameState;

    AppStatesBuilder(EventObserver& observer,
                     std::shared_ptr<AbstractDeckFactory> factory,
                     GameActionControllerHolder& gameActionControllerHolder,
                     GameSessionStarter& starter,
                     std::shared_ptr<BestScoresController>& bestScoresController,
                     std::shared_ptr<SaveGameController>& saveGameController,
                     std::shared_ptr<LoadGameController>& loadGameController) :
        gameInProgress(new GameInProgressState(*this, gameActionControllerHolder)),
        gameCompleted(new GameCompletedState(*this, observer, bestScoresController)),
        exitState(new ExitState(*this)),
        savingGameState(new SavingGameState(*this, saveGameController)),
        loadingGameState(new LoadingGameState(*this, loadGameController)) {}

public:
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
    AppStatePtr getLoadingGameState(AppStatePtr previous) {
        loadingGameState->setPreviousState(previous);
        return loadingGameState;
    }
};

#endif /* SRC_CONTROLLERS_INC_STATESBUILDER_H_ */
