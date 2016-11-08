/*
 * GamePausedState.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_NOGAMEINPROGRESSSTATE_H_
#define SRC_CONTROLLERS_INC_NOGAMEINPROGRESSSTATE_H_

#include <StartController.h>
#include <GameState.h>
#include <AppState.h>

class NoGameInProgressState : public AppState {
private:
    std::shared_ptr<Klondike>& game;
    std::shared_ptr<GameActionHistoryController>& historyController;
    GameActionControllerHolder& holder;
    EventObserver& eventObserver;
    GameStatePtr gameState;
public:
    NoGameInProgressState(AppStatesBuilder& sb,
                          std::shared_ptr<Klondike>& g,
                          std::shared_ptr<GameActionHistoryController>& historyController,
                          GameActionControllerHolder& holder,
                          EventObserver& eventObserver,
                          GameStatePtr gameState);
    ControllerPtr getController();
    AppStatePtr transitionToExit();
    AppStatePtr transitionToGameInProgress();
    AppStatePtr transitionToSavingGame();
    AppStatePtr transitionToLoadingGame();
};

#endif /* SRC_CONTROLLERS_INC_NOGAMEINPROGRESSSTATE_H_ */
