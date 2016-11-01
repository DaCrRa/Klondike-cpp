/*
 * GameCompletedState.h
 *
 *  Created on: 1 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_
#define SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_

#include <State.h>

#include <BestScoresController.h>
#include <EventObserver.h>

class GameCompletedState : public State {
private:
    EventObserver& eventObserver;
    std::shared_ptr<BestScoresController>& bestScoresController;
public:
    GameCompletedState(StatesBuilder& sb,
                       EventObserver& o,
                       std::shared_ptr<BestScoresController>& bsc);
    ControllerPtr getController();
    StatePtr transitionToGamePaused();
};

#endif /* SRC_CONTROLLERS_INC_GAMECOMPLETEDSTATE_H_ */
