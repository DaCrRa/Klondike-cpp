/*
 * GameCompletedState.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_
#define SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_

#include <AppState.h>

#include <BestScoresController.h>
#include <EventObserver.h>

class GameCompletedState : public AppState {
private:
    EventObserver& eventObserver;
    std::shared_ptr<BestScoresController>& bestScoresController;
public:
    GameCompletedState(AppStatesBuilder& sb,
                       EventObserver& o,
                       std::shared_ptr<BestScoresController>& bsc);
    ControllerPtr getController();
    AppStatePtr transitionToNoGameInProgress();
};

#endif /* SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_ */
