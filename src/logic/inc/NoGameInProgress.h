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
    EventObserver& eventObserver;
    GameStatePtr gameState;
public:
    NoGameInProgressState(AppStatesBuilder& sb,
                          EventObserver& observer,
                          GameStatePtr gs);
    ControllerPtr getController();
    AppStatePtr transitionToExit();
    AppStatePtr transitionToGameInProgress();
    AppStatePtr transitionToSavingGame();
};

#endif /* SRC_CONTROLLERS_INC_NOGAMEINPROGRESSSTATE_H_ */
