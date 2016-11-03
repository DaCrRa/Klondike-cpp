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

#include <GameState.h>

class GamePausedState : public State {
private:
    EventObserver& eventObserver;
    GameStatePtr gameState;
public:
    GamePausedState(StatesBuilder& sb,
                    EventObserver& observer,
                    GameStatePtr gs);
    ControllerPtr getController();
    StatePtr transitionToExit();
    StatePtr transitionToGameInProgress();
};

#endif /* SRC_CONTROLLERS_INC_GAMEPAUSEDSTATE_H_ */
