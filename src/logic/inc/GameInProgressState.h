/*
 * GameInProgress.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_
#define SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_

#include <GameActionControllerHolder.h>
#include <AppState.h>

class GameInProgressState: public AppState {
private:
    GameActionControllerHolder& gameActionControllerHolder;
public:
    GameInProgressState(AppStatesBuilder& sb, GameActionControllerHolder& gameActionControllerHolder);
    ControllerPtr getController();
    AppStatePtr transitionToNoGameInProgress();
    AppStatePtr transitionToGameCompleted();
};

#endif /* SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_ */
