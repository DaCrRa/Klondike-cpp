/*
 * GamePausedState.h
 *
 *  Created on: 31 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_GAMEPAUSEDSTATE_H_
#define SRC_CONTROLLERS_INC_GAMEPAUSEDSTATE_H_

#include <StartController.h>
#include <State.h>

class GamePausedState : public State {
private:
    EventObserver& eventObserver;
public:
    GamePausedState(StatesBuilder& sb, EventObserver& observer);
    ControllerPtr getController();
    StatePtr transitionToExit();
    StatePtr transitionToGameInProgress();
};

#endif /* SRC_CONTROLLERS_INC_GAMEPAUSEDSTATE_H_ */
