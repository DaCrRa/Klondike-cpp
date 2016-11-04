/*
 * GameInProgress.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_
#define SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_

#include <GameActionController.h>
#include <AppState.h>

class GameInProgressState: public AppState {
private:
    std::shared_ptr<GameActionController> gameActionController;
public:
    GameInProgressState(AppStatesBuilder& sb, std::shared_ptr<GameActionController> gac);
    ControllerPtr getController();
    AppStatePtr transitionToNoGameInProgress();
    AppStatePtr transitionToGameCompleted();
};

#endif /* SRC_CONTROLLERS_INC_GAMEINPROGRESSSTATE_H_ */
